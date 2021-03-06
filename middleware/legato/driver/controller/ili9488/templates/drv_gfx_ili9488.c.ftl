/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  ILI9488 Display Top-Level Driver Source File

  File Name:
    drv_gfx_ili9488.c

  Summary:
    Top level driver for ILI9488.

  Description:
    Build-time generated implementation for the ILI9488 Driver.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

<#if gfx_hal_le??>

<#assign Val_Width = gfx_hal_le.DisplayWidth>
<#assign Val_Height = gfx_hal_le.DisplayHeight>

<#else>

<#assign Val_Width = DisplayWidth>
<#assign Val_Height = DisplayHeight>

</#if>

#include "definitions.h"

#include "drv_gfx_ili9488_cmd_defs.h"
#include "drv_gfx_ili9488.h"
#include "gfx/interface/drv_gfx_disp_intf.h"

// Default max width/height of ILI9488 frame
#define DISPLAY_DEFAULT_WIDTH   320
#define DISPLAY_DEFAULT_HEIGHT  480

#define DISPLAY_WIDTH   ${Val_Width}
#define DISPLAY_HEIGHT  ${Val_Height}

#define PIXEL_BUFFER_COLOR_MODE GFX_COLOR_MODE_RGB_565

<#if RowColumnExchange == "Reverse">
//Row and column are swapped
#define SCREEN_WIDTH DISPLAY_HEIGHT
#define SCREEN_HEIGHT DISPLAY_WIDTH
<#else>
#define SCREEN_WIDTH DISPLAY_WIDTH
#define SCREEN_HEIGHT DISPLAY_HEIGHT
</#if>

#define ILI9488_NCSAssert(intf)   GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_CLEAR)

#define ILI9488_NCSDeassert(intf) GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_SET)

#ifdef GFX_DISP_INTF_PIN_RESET_Set
#define ILI9488_Reset_Assert()      GFX_DISP_INTF_PIN_RESET_Clear()
#define ILI9488_Reset_Deassert()    GFX_DISP_INTF_PIN_RESET_Set()
#else
#error "ILI9488 reset pin is not configured. Please define GFX_DISP_INTF_PIN_RESET in Pin Settings"
#endif

/** ILI9488_DRV_STATE

  Summary:
    Enum of ILI9488 driver states.
    
*/
typedef enum
{
    INIT = 0,
    IDLE,
    BLIT_COLUMN_CMD,
    BLIT_COLUMN_DATA,
    BLIT_PAGE_CMD,
    BLIT_PAGE_DATA,
    BLIT_WRITE_CMD,
    BLIT_WRITE_DATA,
    BLIT_WAIT,
    ERROR,
} ILI9488_DRV_STATE;


typedef struct 
{
    /* Command */
    uint8_t cmd;
    
    /* Number of command parameters */
    uint8_t parmCount;
    
    /* Command parameters, max of 4 */
    uint8_t parms[4];
} ILI9488_CMD_PARAM;

/** ILI9488_DRV

  Summary:
    Structure contains driver-specific data and ops pointers.
    
*/
typedef struct ILI9488_DRV 
{   
    /* Driver state */
    ILI9488_DRV_STATE state;

    /* Port-specific private data */
    void *port_priv;

    struct
    {
        int32_t x;
        int32_t y;
        gfxPixelBuffer* buf;
    } blitParms;

} ILI9488_DRV;

<#if DisplayInterfaceType == "SPI 4-line">
#define BYTES_PER_PIXEL_BUFFER 3
static uint8_t pixelBuffer[SCREEN_WIDTH * BYTES_PER_PIXEL_BUFFER];
<#else>
<#if ParallelInterfaceWidth == "16-bit">
#define BYTES_PER_PIXEL_BUFFER 2
<#else>
#define BYTES_PER_PIXEL_BUFFER 2
static uint8_t pixelBuffer[SCREEN_WIDTH * BYTES_PER_PIXEL_BUFFER];
</#if>
</#if>
static ILI9488_DRV drv;
static uint32_t swapCount = 0;

/** initCmdParm

  Summary:
    Table of command/parameter(s) used to initialize the ILI9488.

  Description:
    This table contains command/parameter(s) values that are written to the
    ILI9488 during initialization.

  Remarks:
    Add project-specific initialization values for the ILI9488 here.
 */
ILI9488_CMD_PARAM initCmdParm[] =
{
<#if DisplayInterfaceType == "SPI 4-line">
    {ILI9488_CMD_INTERFACE_PIXEL_FORMAT_SET, 1, {ILI9488_COLOR_PIX_FMT_18BPP}},
    {ILI9488_CMD_SET_IMAGE_FUNCTION, 1, {0x00}},
<#else>
<#if ParallelInterfaceWidth == "16-bit">
    {ILI9488_CMD_INTERFACE_PIXEL_FORMAT_SET, 1, {ILI9488_COLOR_PIX_FMT_16BPP}},
    {ILI9488_CMD_SET_IMAGE_FUNCTION, 1, {0x01}},
</#if>
<#if ParallelInterfaceWidth == "8-bit">
    {ILI9488_CMD_INTERFACE_PIXEL_FORMAT_SET, 1, {ILI9488_COLOR_PIX_FMT_16BPP}},
    {ILI9488_CMD_SET_IMAGE_FUNCTION, 1, {0x01}},
</#if>
</#if>
    {ILI9488_CMD_INTERFACE_MODE_CONTROL, 1, {0x00}},
    {ILI9488_CMD_MEMORY_ACCESS_CONTROL, 1, {(
<#if PixelOrder == "BGR">
                                             ILI9488_MADCTL_RGB_BGR_ORDER_CTRL |
</#if>
<#if RowColumnExchange == "Reverse">
                                             ILI9488_MADCTL_ROW_COLUMN_EXCHANGE |
</#if>
<#if ColumnAddressOrder == "Right-To-Left">
                                             ILI9488_MADCTL_COL_ADDR_ORDER |
</#if>
<#if RowAddressOrder == "Bottom-To-Top">
                                             ILI9488_MADCTL_ROW_ADDR_ORDER |
</#if>
                                            0)}},

    {ILI9488_CMD_SLEEP_OUT, 0, {0x00}},
    {ILI9488_CMD_DISPLAY_ON, 0, {0x00}},
};

/* ************************************************************************** */

/**
  Function:
    static void ILI9488_DelayMS(int ms)

  Summary:
    Delay helper function.

  Description:
    This is a helper function for delay using the system tick timer.

  Parameters:
    ms      - Delay in milliseconds

  Returns:
    None.

*/

static inline void ILI9488_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}
/**
  Function:
    static int ILI9488_Reset(void)

  Summary:
    Toggles the hardware reset to the ILI9488.

  Description:
    This function toggles the GPIO pin for asserting reset to the ILI9488.

  Parameters:
    None

  Returns:
    None

*/
static int ILI9488_Reset(void)
{
    ILI9488_Reset_Deassert();
    ILI9488_DelayMS(10);
    ILI9488_Reset_Assert();
    ILI9488_DelayMS(10);
    ILI9488_Reset_Deassert();
    ILI9488_DelayMS(30);

    return 0;
}

static int ILI9488_Init(ILI9488_DRV *drv,
                        ILI9488_CMD_PARAM *initVals,
                        int numVals)
{
    int returnValue = -1;
    unsigned int i;
    GFX_Disp_Intf intf; 
    
    intf = (GFX_Disp_Intf) drv->port_priv;
    
    ILI9488_NCSAssert(intf);    

    for (i = 0; i < numVals; i++, initVals++)
    {
        returnValue = GFX_Disp_Intf_WriteCommand(intf, initVals->cmd);
        if (0 != returnValue)
            break;
        
        while (GFX_Disp_Intf_Ready(intf) == false);
        
        if (initVals->parms != NULL &&
            initVals->parmCount > 0)
        {
            returnValue = GFX_Disp_Intf_WriteData(intf, initVals->parms, initVals->parmCount);
            if (0 != returnValue)
                break;
        
            while (GFX_Disp_Intf_Ready(intf) == false);
        }
        
    }
    
    ILI9488_NCSDeassert(intf); 
    
    return returnValue;
}

gfxResult DRV_ILI9488_Initialize(void)
{
    drv.state = INIT;

    //Open interface to ILI9488 controlgfxR
    drv.port_priv = (void*) GFX_Disp_Intf_Open();
    if (drv.port_priv == 0)
        return GFX_FAILURE;
            
    return GFX_SUCCESS;
}

void DRV_ILI9488_Update(void)
{
    static GFX_Disp_Intf intf; 
    static int row;
<#if ParallelInterfaceWidth == "8-bit" || DisplayInterfaceType == "SPI 4-line">
    int col, dataIdx;
    uint16_t clr;
</#if>
    uint16_t* ptr;
    uint8_t parm[4];
    
    switch (drv.state)
    {
        case INIT:
        {
            // perform driver initialization here
            ILI9488_Reset();

            ILI9488_Init(&drv,
                         initCmdParm,
                         sizeof(initCmdParm)/sizeof(ILI9488_CMD_PARAM));

            drv.state = IDLE;
            
            intf = (GFX_Disp_Intf) drv.port_priv;

<#if TransferMode == "Synchronous">
            while (GFX_Disp_Intf_Ready(intf) == false);
</#if>
            break;
        }
        case BLIT_COLUMN_CMD:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
            
            ILI9488_NCSAssert(intf);
                    
            GFX_Disp_Intf_WriteCommand(intf, ILI9488_CMD_COLUMN_ADDRESS_SET);
                   
            drv.state = BLIT_COLUMN_DATA;
            
<#if TransferMode == "Synchronous">
            while (GFX_Disp_Intf_Ready(intf) == false);
            //Fall through, no break
<#else>
            break;
</#if>
        }
        case BLIT_COLUMN_DATA:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
            
            //Write X/Column Address
            parm[0] = drv.blitParms.x>>8;
            parm[1] = drv.blitParms.x;
            parm[2] = (drv.blitParms.x + drv.blitParms.buf->size.width - 1)>>8;
            parm[3] = (drv.blitParms.x + drv.blitParms.buf->size.width - 1);
            GFX_Disp_Intf_WriteData(intf, parm, 4);
            
            drv.state = BLIT_PAGE_CMD;
            
<#if TransferMode == "Synchronous">
            while (GFX_Disp_Intf_Ready(intf) == false);
            //Fall through, no break
<#else> 
            break;
</#if>
        }
        case BLIT_PAGE_CMD:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
                        
            GFX_Disp_Intf_WriteCommand(intf, ILI9488_CMD_PAGE_ADDRESS_SET);
                   
            drv.state = BLIT_PAGE_DATA;
            
<#if TransferMode == "Synchronous">
            while (GFX_Disp_Intf_Ready(intf) == false);
            //Fall through, no break
<#else>
            break;
</#if>
        }
        case BLIT_PAGE_DATA:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;

            //Write Y/Page Address
            parm[0] = drv.blitParms.y>>8;
            parm[1] = drv.blitParms.y;
            parm[2] = (drv.blitParms.y + drv.blitParms.buf->size.height - 1)>>8;
            parm[3] = (drv.blitParms.y + drv.blitParms.buf->size.height - 1);
            GFX_Disp_Intf_WriteData(intf, parm, 4);
            
            drv.state = BLIT_WRITE_CMD;
                        
<#if TransferMode == "Synchronous">
            while (GFX_Disp_Intf_Ready(intf) == false);
            //Fall through, no break
<#else>
            break;
</#if>  
        }
        case BLIT_WRITE_CMD:
        {
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
            
            //Start Memory Write
            GFX_Disp_Intf_WriteCommand(intf, ILI9488_CMD_MEMORY_WRITE);
                        
            drv.state = BLIT_WRITE_DATA;
            
            row = 0;
                                
<#if TransferMode == "Synchronous">
            while (GFX_Disp_Intf_Ready(intf) == false);
            //Fall through, no break
<#else>
            break;
</#if>
        }
        case BLIT_WRITE_DATA:
        {
<#if TransferMode == "Synchronous">
            drv.state = IDLE;
                
            while (row < drv.blitParms.buf->size.height)
<#else>
            if (GFX_Disp_Intf_Ready(intf) == false)
                break;
            
            if (row < drv.blitParms.buf->size.height)
</#if>
            {
                ptr = gfxPixelBufferOffsetGet_Unsafe(drv.blitParms.buf, 0, row);

<#if ParallelInterfaceWidth == "16-bit" && DisplayInterfaceType != "SPI 4-line">
                GFX_Disp_Intf_WriteData16(intf,
                                        ptr,
                                        drv.blitParms.buf->size.width);
<#else>
                for(col = 0, dataIdx = 0; col < drv.blitParms.buf->size.width; col++)
                {
                    clr = ptr[col];

<#if DisplayInterfaceType == "SPI 4-line">
                    // red channel
                    pixelBuffer[dataIdx++] = (gfxColorChannelRed(clr, PIXEL_BUFFER_COLOR_MODE) << 3);
                    
                    // green channel
                    pixelBuffer[dataIdx++] = (gfxColorChannelGreen(clr, PIXEL_BUFFER_COLOR_MODE) << 2);
                    
                    // blue channel
                    pixelBuffer[dataIdx++] = (gfxColorChannelBlue(clr, PIXEL_BUFFER_COLOR_MODE) << 3);
<#else>
                    pixelBuffer[dataIdx++] = (uint8_t) (clr >> 8);
                    pixelBuffer[dataIdx++] = (uint8_t) (uint8_t) (clr & 0xff);
</#if>
                }

                GFX_Disp_Intf_WriteData(intf,
                                        pixelBuffer,
                                        BYTES_PER_PIXEL_BUFFER *
                                        drv.blitParms.buf->size.width);
</#if>
                
                row++;
<#if TransferMode == "Synchronous">
                while (GFX_Disp_Intf_Ready(intf) == false);
</#if>
            }
<#if TransferMode == "Asynchronous">
            else if (row >= drv.blitParms.buf->size.height)
            {
                ILI9488_NCSDeassert(intf); 
                gfxPixelBuffer_SetLocked(drv.blitParms.buf, GFX_FALSE);
                drv.state = IDLE;
            }
</#if>
            break;
             
        }
        case IDLE:
        case ERROR:            
        default:
        {
            break;
        }        
    }
}

gfxResult DRV_ILI9488_BlitBuffer(int32_t x,
                                 int32_t y,
                                 gfxPixelBuffer* buf)
{
    if(drv.state != IDLE)
        return GFX_FAILURE;

    drv.blitParms.x = x;
    drv.blitParms.y = y;
    drv.blitParms.buf = buf;
    drv.state = BLIT_COLUMN_CMD;

<#if TransferMode == "Synchronous">
    while (drv.state != IDLE)
    {
        DRV_ILI9488_Update();
    }
<#else>
    gfxPixelBuffer_SetLocked(buf, GFX_TRUE);
</#if>
    
    return GFX_SUCCESS;
}

gfxDriverIOCTLResponse DRV_SSD1963_IOCTL(gfxDriverIOCTLRequest req,
                                         void* arg)
{
	switch(request)
	{
		case GFX_IOCTL_GET_COLOR_MODE:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = PIXEL_BUFFER_COLOR_MODE;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_BUFFER_COUNT:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = 1;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_DISPLAY_SIZE:
		{
			disp = (gfxIOCTLArg_DisplaySize*)arg;			
			
			disp->width = SCREEN_WIDTH;
			disp->height = SCREEN_HEIGHT;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_LAYER_COUNT:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = 1;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_ACTIVE_LAYER:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = 0;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_LAYER_RECT:
		{
			rect = (gfxIOCTLArg_LayerRect*)arg;
			
			rect->x = 0;
			rect->y = 0;
			rect->width = SCREEN_WIDTH;
			rect->height = SCREEN_HEIGHT;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_GET_VSYNC_COUNT:
		{
			val = (gfxIOCTLArg_Value*)arg;
			
			val->value.v_uint = swapCount;
			
			return GFX_IOCTL_OK;
		}
		case GFX_IOCTL_LAYER_SWAP:
		{
			swapCount += 1;
			
			return GFX_IOCTL_OK;
		}
		default:
		{
		}
	}
	
	return GFX_IOCTL_UNSUPPORTED;
}
