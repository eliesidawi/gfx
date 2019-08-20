/*******************************************************************************
  SSD1963 Display Top-Level Driver Source File

  File Name:
    drv_gfx_ssd1963.c

  Summary:
    Top level driver for SSD1963.

  Description:
    Build-time generated implementation for the SSD1963 Driver.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END
#include "definitions.h"

#include "gfx/interface/drv_gfx_disp_intf.h"
#include "drv_gfx_ssd1963_cmd_defs.h"
#include "drv_gfx_ssd1963_common.h"
#include "drv_gfx_ssd1963.h"

#include "system/time/sys_time.h"

// Number of layers
#define LAYER_COUNT     1

// Default max width/height of SSD1963 frame
#define DISPLAY_DEFAULT_WIDTH   480
#define DISPLAY_DEFAULT_HEIGHT  800

#define DISPLAY_WIDTH   ${DisplayWidth}
#define DISPLAY_HEIGHT  ${DisplayHeight}

#define DISP_HOR_RESOLUTION DISPLAY_WIDTH
#define DISP_VER_RESOLUTION DISPLAY_HEIGHT
#define DISP_HOR_PULSE_WIDTH ${DisplayHorzPulseWidth}
#define DISP_HOR_FRONT_PORCH ${DisplayHorzFrontPorch}
#define DISP_HOR_BACK_PORCH ${DisplayHorzBackPorch}
#define DISP_VER_PULSE_WIDTH ${DisplayVertPulseWidth}
#define DISP_VER_FRONT_PORCH ${DisplayHorzFrontPorch}
#define DISP_VER_BACK_PORCH ${DisplayVertBackPorch}

#define PIXEL_BUFFER_COLOR_MODE LE_COLOR_MODE_RGB_565
#define SCREEN_WIDTH DISPLAY_WIDTH
#define SCREEN_HEIGHT DISPLAY_HEIGHT

#define MASTER_CLK_HZ ${MasterClock}
#define PIXEL_CLOCK_DIVIDER  ${PixelClockPreScaler}
#define BACKLIGHT_PWM_FREQ_HZ ${BacklightPWMFrequency}
#define BACKLIGHT_PWMF_PARM (MASTER_CLK_HZ / (BACKLIGHT_PWM_FREQ_HZ * 256 * 256) - 1)
#define BACKLIGHT_PWM_BRIGHTNESS_PCT ${DefaultBrightness}

#ifdef GFX_DISP_INTF_PIN_RESET_Clear
#define DRV_SSD1963_Reset_Assert()      GFX_DISP_INTF_PIN_RESET_Clear()
#define DRV_SSD1963_Reset_Deassert()    GFX_DISP_INTF_PIN_RESET_Set()
#else
#error "ERROR: GFX_DISP_INTF_PIN_RESET not defined. Please define in Pin Manager."
#define DRV_SSD1963_Reset_Assert()
#define DRV_SSD1963_Reset_Deassert()
#endif

#define DRV_SSD1963_NCSAssert(intf)   GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_CLEAR)

#define DRV_SSD1963_NCSDeassert(intf) GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_SET)

<#if ParallelInterfaceWidth == "8-bit">
static uint8_t pixelBuffer[SCREEN_WIDTH * 3];
</#if>

SSD1963_DRV drv;

static uint32_t swapCount = 0;


/* ************************************************************************** */

/**
  Function:
    static void DRV_SSD1963_DelayMS(int ms)

  Summary:
    Delay helper function.

  Description:
    This is a helper function for delay using the system tick timer.

  Parameters:
    ms      - Delay in milliseconds

  Returns:
    None.

*/

static inline void DRV_SSD1963_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}

/**
  Function:
    static leResult DRV_SSD1963_Reset(void)

  Summary:
    Toggles the hardware reset to the SSD1963.

  Description:
    This function toggles the GPIO pin for asserting reset to the SSD1963.

  Parameters:
    None

  Returns:
    None

*/
static leResult DRV_SSD1963_Reset(void)
{
    DRV_SSD1963_Reset_Assert();
    DRV_SSD1963_DelayMS(10);
    DRV_SSD1963_Reset_Deassert();
    DRV_SSD1963_DelayMS(30);

    return LE_SUCCESS;
}

leResult DRV_SSD1963_Initialize(void)
{
    drv.port_priv = (void *) GFX_Disp_Intf_Open();
    if (drv.port_priv == 0)
        return LE_FAILURE;
    
    return LE_SUCCESS;
}

static leResult DRV_SSD1963_Configure(SSD1963_DRV *drv)
{
    #define HT (DISP_HOR_PULSE_WIDTH+DISP_HOR_BACK_PORCH+DISP_HOR_RESOLUTION+DISP_HOR_FRONT_PORCH)
    #define HPS (DISP_HOR_PULSE_WIDTH+DISP_HOR_BACK_PORCH)

    #define VT (DISP_VER_PULSE_WIDTH+DISP_VER_BACK_PORCH+DISP_VER_RESOLUTION+DISP_VER_FRONT_PORCH)    
    #define VSP (DISP_VER_PULSE_WIDTH+DISP_VER_BACK_PORCH)

    uint8_t  iByte;
    uint32_t lcdc_fpr;  // Mimics LCDC_FPR in the data sheet
    uint8_t parm[8];
    
    GFX_Disp_Intf intf = (GFX_Disp_Intf) drv->port_priv;

    DRV_SSD1963_NCSDeassert(intf);
    DRV_SSD1963_DelayMS(10);

    DRV_SSD1963_NCSAssert(intf);
    DRV_SSD1963_DelayMS(10);

    //Set MN(multipliers) of PLL, VCO = crystal freq * (N+1)
    //PLL freq = VCO/M with 250MHz < VCO < 800MHz
    //The max PLL freq is 110MHz. To obtain 100MHz as the PLL freq do the following:
    parm[0] = 0x1D; // Muliplier M = 29, VCO = 12*(N+1)  = 300 MHz
    parm[1] = 0x2; // Divider N = 2,   PLL = 360/(N+1) = 100MHz
    parm[2] = 0x54; // Validate M and N values ("Effectuate" values)
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_PLL_MN, parm, 3); // Set PLL with OSC = 10MHz (hardware)
    DRV_SSD1963_DelayMS(10);

    parm[0] = 0x01; // enable PLL
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_PLL_START, parm, 1); // Start PLL command
    
    DRV_SSD1963_DelayMS(10);

    parm[0] = 0x03; // now, use PLL output as system clock
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_PLL_START, parm, 1); // Start PLL command again

    DRV_SSD1963_DelayMS(10); // Wait for PLL to lock

    //once PLL locked (at 100MHz), the data hold time set shortest
    GFX_Disp_Intf_WriteCommand(intf,
                            CMD_SOFT_RESET);
    DRV_SSD1963_DelayMS(10);

    lcdc_fpr = ( (uint32_t)((1UL<<20)/PIXEL_CLOCK_DIVIDER) ) - 1 ;
    parm[0] = 0xFF & (lcdc_fpr>>16);
    parm[1] = 0xFF & (lcdc_fpr>>8);
    parm[2] = iByte = 0xFF &  lcdc_fpr;
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_PCLK, parm, 3); // Set Pixel clock to 15 MHz
    
    parm[0] = 0x20; // set 24-bit for TY430TF480272 4.3" panel data latch in rising edge for LSHIFT
    parm[1] = 0x00; // set Hsync+Vsync mode
    parm[2] = (DISP_HOR_RESOLUTION-1)>>8; //Set panel size
    parm[3] = (uint8_t)(DISP_HOR_RESOLUTION-1);
    parm[4] = (DISP_VER_RESOLUTION-1)>>8;
    parm[5] = (uint8_t)(DISP_VER_RESOLUTION-1);
    parm[6] = 0x00; //RGB sequence
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_PANEL_MODE, parm, 7);

    //Set horizontal period
    parm[0] = (HT-1)>>8;
    parm[1] = (uint8_t)(HT-1);
    parm[2] = (HPS-1)>>8;
    parm[3] = HPS-1;
    parm[4] = DISP_HOR_PULSE_WIDTH-1;
    parm[5] = 0x00;
    parm[6] = 0x00;
    parm[7] = 0x00;
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_HOR_PERIOD, parm, 8);
    
    //Set vertical period
    parm[0] = (VT-1)>>8;
    parm[1] = (uint8_t)(VT-1);
    parm[2] = (VSP-1)>>8;
    parm[3] = VSP-1;
    parm[4] = DISP_VER_PULSE_WIDTH-1;
    parm[5] = 0x00;
    parm[6] = 0x00;
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_VER_PERIOD, parm, 7);

    //Set pixel format, i.e. the bpp
    parm[0] = 0x55; // set 16bpp, (565 format) 
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_PIXEL_FORMAT, parm, 1);
    
    //Set pixel data interface
<#if ParallelInterfaceWidth == "16-bit">
    parm[0] = 0x03; //16-bit pixel data
</#if>
<#if ParallelInterfaceWidth == "8-bit">
    parm[0] = 0x00; //8-bit pixel data
</#if>
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_DATA_INTERFACE, parm, 1);

    // Turn on display; show the image on display
    GFX_Disp_Intf_WriteCommand(intf,
                            CMD_ON_DISPLAY); 

    DRV_SSD1963_DelayMS(1);
    
    DRV_SSD1963_NCSDeassert(intf);
    
    return LE_SUCCESS;
}

static void DRV_SSD1963_SetArea(SSD1963_DRV *drv,
                    int16_t start_x,
                    int16_t start_y,
                    int16_t end_x,
                    int16_t end_y)
{
    GFX_Disp_Intf intf = (GFX_Disp_Intf) drv->port_priv;
    uint8_t parm[4];
    
    parm[0] = start_x>>8;
    parm[1] = start_x;
    parm[2] = end_x>>8;
    parm[3] = end_x;
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_COLUMN, parm, 4);
    
    parm[0] = start_y>>8;
    parm[1] = start_y;
    parm[2] = end_y>>8;
    parm[3] = end_y;
    GFX_Disp_Intf_WriteCommandParm(intf, CMD_SET_PAGE, parm, 4);
}

/**
  Function:
    static leResult DRV_SSD1963_BrightnessSet(uint32_t val)

  Summary:
    Driver-specific implementation of GFX HAL brightnessSet function

  Description:
    Sets the SSD1963 PWM Freq and Duty cycle

  Parameters:
    val    - The backlight brightness in %

  Returns:
    * LE_SUCCESS       - Operation successful

*/
static leResult DRV_SSD1963_BrightnessSet(uint32_t brightness)
{
    uint8_t parm[5] = {
                    BACKLIGHT_PWMF_PARM,   // PWMF[7:0] = 2, PWM base freq = PLL/(256*(PWMF + 1))/256
                    (brightness * 0xff / 100), // Set duty cycle, from 0x00 (total pull-down) to 0xFF
                                // (99% pull-up , 255/256)
                    0x01,   // PWM enabled and controlled by host (mcu)
                    0x00,
                    0x00
               };

    if (brightness > 100)
        brightness = 100;

    DRV_SSD1963_NCSAssert((GFX_Disp_Intf) drv.port_priv);

    GFX_Disp_Intf_WriteCommandParm((GFX_Disp_Intf) drv.port_priv,
                                    CMD_SET_PWM_CONF, parm, 5);

    DRV_SSD1963_NCSDeassert((GFX_Disp_Intf) drv.port_priv);
    
    return LE_SUCCESS;
}

/**
  Function:
    static leResult DRV_SSD1963_Update(void)

  Summary:
    Driver-specific implementation of GFX HAL update function.

  Description:
    On GFX update, this function flushes any pending pixels to the SSD1963.

  Parameters:
    None.

  Returns:
    * LE_SUCCESS       - Operation successful
    * LE_FAILURE       - Operation failed

*/
void DRV_SSD1963_Update(void)
{
    if(drv.state == INIT)
    {
        // perform driver initialization here
        DRV_SSD1963_Reset();

        DRV_SSD1963_Configure(&drv);

        DRV_SSD1963_BrightnessSet(BACKLIGHT_PWM_BRIGHTNESS_PCT);

        drv.state = RUN;
    }
}

leColorMode DRV_SSD1963_GetColorMode(void)
{
    return PIXEL_BUFFER_COLOR_MODE;
}

uint32_t DRV_SSD1963_GetBufferCount(void)
{
    return 1;
}

uint32_t DRV_SSD1963_GetDisplayWidth(void)
{
    return SCREEN_WIDTH;
}

uint32_t DRV_SSD1963_GetDisplayHeight(void)
{
    return SCREEN_HEIGHT;
}

uint32_t DRV_SSD1963_GetLayerCount()
{
    return 1;
}

uint32_t DRV_SSD1963_GetActiveLayer()
{
    return 0;
}

leResult DRV_SSD1963_SetActiveLayer(uint32_t idx)
{
    return LE_SUCCESS;
}

leResult DRV_SSD1963_BlitBuffer(int32_t x,
                                int32_t y,
                                lePixelBuffer* buf)
{
<#if ParallelInterfaceWidth == "8-bit">
    int row, col, dataIdx;
    uint16_t clr;
</#if>
    uint16_t* ptr;

    GFX_Disp_Intf intf;
    
    intf = (GFX_Disp_Intf) drv.port_priv;

    DRV_SSD1963_NCSAssert(intf);

    DRV_SSD1963_SetArea(&drv, x, y, x + buf->size.width - 1, y + buf->size.height - 1);

    GFX_Disp_Intf_WriteCommand(intf, CMD_WR_MEMSTART);
<#if ParallelInterfaceWidth == "8-bit">
    for(row = 0; row < buf->size.height; row++)
    {
        ptr = lePixelBufferOffsetGet_Unsafe(buf, 0, row);
        for(col = 0, dataIdx = 0; col < buf->size.width; col++)
        {
            clr = ptr[col];
            pixelBuffer[dataIdx++] = (uint8_t) ((clr & 0xf800) >> 8);
            pixelBuffer[dataIdx++] = (uint8_t) ((clr & 0x07e0) >> 3 );
            pixelBuffer[dataIdx++] = (uint8_t) ((clr & 0x001f) << 3);
        }
        GFX_Disp_Intf_WriteData(intf, pixelBuffer, 3 * buf->size.width);
    }
</#if>
<#if ParallelInterfaceWidth == "16-bit">
    ptr = lePixelBufferOffsetGet_Unsafe(buf, 0, 0);
    GFX_Disp_Intf_WriteData16(intf, (uint16_t *) ptr, buf->size.width * buf->size.height);
</#if>
    
    DRV_SSD1963_NCSDeassert(intf);

    return LE_SUCCESS;
}

void DRV_SSD1963_Swap(void)
{
    swapCount++;
}

uint32_t DRV_SSD1963_GetSwapCount(void)
{
    return swapCount;
}
