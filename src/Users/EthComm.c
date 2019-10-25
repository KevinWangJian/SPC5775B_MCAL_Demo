/*
 * EthComm.c
 *
 *  Created on: 2019Äê10ÔÂ22ÈÕ
 *      Author: admin
 */

#include "EthComm.h"
#include "StdRegMacros.h"
#include "Eth_Cfg.h"
#include "Eth_GeneralTypes.h"



/*
@brief
@details
@para
@return
*/
void Ethernet_Init(void)
{
	Std_ReturnType retVal;
	uint8_t dummyCnt;
	uint8 MAC_Addr[6];

	/*Set SIU_FECCR register manually to select MII-Lite. API is avalable in MCAL4.3*/
	REG_WRITE32(SIU_FECCR_REG_ADDR, (uint32)0x00000001UL);

	Eth_Init(&EthConfigSet_0);

	dummyCnt = 0;
	retVal = Eth_ControllerInit(CTRL_INDEX, CFG_INDEX);

	if (retVal == E_OK)
	{
		while (dummyCnt < 3U) {
			dummyCnt++;
		}

		dummyCnt = 0;
		retVal = E_NOT_OK;
		retVal = Eth_SetControllerMode(CTRL_INDEX, ETH_MODE_ACTIVE);

		if (retVal == E_OK)
		{
			while (dummyCnt < 3U) {
				dummyCnt++;
			}

			Eth_GetPhysAddr(CTRL_INDEX, &MAC_Addr[0]);

			dummyCnt = 0;
		}
		else
		{
			while (dummyCnt < 3U) {
				dummyCnt++;
			}
		}
	}
	else
	{
		while (dummyCnt < 3U) {
			dummyCnt++;
		}
	}
}







