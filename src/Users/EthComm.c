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

	Eth_Init(&EthConfigSet_0);

	retVal = Eth_ControllerInit(CTRL_INDEX, CFG_INDEX);

	retVal = Eth_SetControllerMode(CTRL_INDEX, ETH_MODE_ACTIVE);

	/*Set SIU_FECCR register manually to select MII-Lite. API is avalable in MCAL4.3*/
	REG_WRITE32(SIU_FECCR_REG_ADDR, (uint32)0x00000001UL);
}







