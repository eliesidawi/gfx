# coding: utf-8
##############################################################################
# Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
#
# Subject to your compliance with these terms, you may use Microchip software
# and any derivatives exclusively with Microchip products. It is your
# responsibility to comply with third party license terms applicable to your
# use of third party software (including open source software) that may
# accompany Microchip software.
#
# THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
# EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
# WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
# PARTICULAR PURPOSE.
#
# IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
# INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
# WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
# BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
# FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
# ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
# THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
##############################################################################

componentActivateList = ["smc", "gfx_driver_lcc", "twihs0", "drv_i2c", "drv_i2c0", "tc0", "sys_time"]
componentAutoConnectList = [["gfx_driver_lcc", "SMC_CS", "smc", "smc_cs0"],
						["gfx_hal", "gfx_display_driver", "gfx_driver_lcc", "gfx_driver_lcc"],
						["drv_i2c_0", "drv_i2c_I2C_dependency", "twihs0", "TWIHS0_I2C"],
						["gfx_maxtouch_controller", "i2c", "drv_i2c_0", "drv_i2c"],
						["sys_time", "sys_time_TMR_dependency", "tc0", "TC0_TMR"]]

pinConfig = [{"pin": 11, "name": "EBI_D0", "type": "EBI_D0", "direction": "", "latch": ""},
			{"pin": 38, "name": "EBI_D1", "type": "EBI_D1", "direction": "", "latch": ""},
			{"pin": 39, "name": "EBI_D2", "type": "EBI_D2", "direction": "", "latch": ""},
			{"pin": 40, "name": "EBI_D3", "type": "EBI_D3", "direction": "", "latch": ""},
			{"pin": 41, "name": "EBI_D4", "type": "EBI_D4", "direction": "", "latch": ""},
			{"pin": 58, "name": "EBI_D5", "type": "EBI_D5", "direction": "", "latch": ""},
			{"pin": 54, "name": "EBI_D6", "type": "EBI_D6", "direction": "", "latch": ""},
			{"pin": 48, "name": "EBI_D7", "type": "EBI_D7", "direction": "", "latch": ""},
			{"pin": 4, "name": "EBI_D8", "type": "EBI_D8", "direction": "", "latch": ""},
			{"pin": 6, "name": "EBI_D9", "type": "EBI_D9", "direction": "", "latch": ""},
			{"pin": 7, "name": "EBI_D10", "type": "EBI_D10", "direction": "", "latch": ""},
			{"pin": 10, "name": "EBI_D11", "type": "EBI_D11", "direction": "", "latch": ""},
			{"pin": 27, "name": "EBI_D12", "type": "EBI_D12", "direction": "", "latch": ""},
			{"pin": 28, "name": "EBI_D13", "type": "EBI_D13", "direction": "", "latch": ""},
			{"pin": 49, "name": "EBI_D14", "type": "EBI_D14", "direction": "", "latch": ""},
			{"pin": 45, "name": "EBI_D15", "type": "EBI_D15", "direction": "", "latch": ""},
			{"pin": 82, "name": "EBI_NWR0/NWE", "type": "EBI_NWR0/NWE", "direction": "", "latch": ""},
			{"pin": 15, "name": "GFX_DISP_INTF_PIN_HSYNC", "type": "GPIO", "direction": "Out", "latch": "High"},
			{"pin": 19, "name": "GFX_DISP_INTF_PIN_RESET", "type": "GPIO", "direction": "Out", "latch": "High"},
			{"pin": 67, "name": "GFX_DISP_INTF_PIN_VSYNC", "type": "GPIO", "direction": "Out", "latch": "High"},
			{"pin": 86, "name": "GFX_DISP_INTF_PIN_BACKLIGHT", "type": "GPIO", "direction": "Out", "latch": "High"},
			{"pin": 94, "name": "GFX_DISP_INTF_PIN_DE", "type": "GPIO", "direction": "Out", "latch": "High"},
			{"pin": 91, "name": "TWIHS0_TWD0", "type": "TWIHS0_TWD0", "direction": "", "latch": ""},
			{"pin": 77, "name": "TWIHS0_TWCK0", "type": "TWIHS0_TWCK0", "direction": "", "latch": ""},
			{"pin": 71, "name": "BSP_MAXTOUCH_CHG", "type": "GPIO", "direction": "In", "latch": ""}]
			
sdramPinConfig = [{"pin": 120, "name": "EBI_A2/SDA0", "type": "EBI_A2/SDA0", "direction": "", "latch": ""},
				{"pin": 122, "name": "EBI_A3/SDA1", "type": "EBI_A3/SDA1", "direction": "", "latch": ""},
				{"pin": 124, "name": "EBI_A4/SDA2", "type": "EBI_A4/SDA2", "direction": "", "latch": ""},
				{"pin": 127, "name": "EBI_A5/SDA3", "type": "EBI_A5/SDA3", "direction": "", "latch": ""},
				{"pin": 130, "name": "EBI_A6/SDA4", "type": "EBI_A6/SDA4", "direction": "", "latch": ""},
				{"pin": 133, "name": "EBI_A7/SDA5", "type": "EBI_A7/SDA5", "direction": "", "latch": ""},
				{"pin": 13, "name": "EBI_A8/SDA6", "type": "EBI_A8/SDA6", "direction": "", "latch": ""},
				{"pin": 12, "name": "EBI_A9/SDA7", "type": "EBI_A9/SDA7", "direction": "", "latch": ""},
				{"pin": 76, "name": "EBI_A10/SDA8", "type": "EBI_A10/SDA8", "direction": "", "latch": ""},
				{"pin": 16, "name": "EBI_A11/SDA9", "type": "EBI_A11/SDA9", "direction": "", "latch": ""},
				{"pin": 88, "name": "EBI_SDA10", "type": "EBI_SDA10", "direction": "", "latch": ""},
				{"pin": 22, "name": "EBI_A16/BA0", "type": "EBI_A16/BA0", "direction": "", "latch": ""},
				{"pin": 57, "name": "EBI_SDCK", "type": "EBI_SDCK", "direction": "", "latch": ""},
				{"pin": 84, "name": "EBI_SDCKE", "type": "EBI_SDCKE", "direction": "", "latch": ""},
				{"pin": 18, "name": "EBI_NCS1/SDCS", "type": "EBI_NCS1/SDCS", "direction": "", "latch": ""},
				{"pin": 74, "name": "EBI_CAS", "type": "EBI_CAS", "direction": "", "latch": ""},
				{"pin": 78, "name": "EBI_RAS", "type": "EBI_RAS", "direction": "", "latch": ""},
				{"pin": 108, "name": "EBI_SDWE", "type": "EBI_SDWE", "direction": "", "latch": ""},
				{"pin": 111, "name": "EBI_A0/NBS0/DQM0", "type": "EBI_A0/NBS0/DQM0", "direction": "", "latch": ""},
				{"pin": 106, "name": "EBI_NWR1/NBS1/DQM1", "type": "EBI_NWR1/NBS1/DQM1", "direction": "", "latch": ""}]
				

sam_e70_xplained_utra = bspSupportObj(pinConfig, componentActivateList, None, componentAutoConnectList, None)

addBSPSupport("BSP_SAM_E70_Xplained_Ultra", None, sam_e70_xplained_utra)