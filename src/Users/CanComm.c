/*
 * CanComm.c
 *
 *  Created on: 2019Äê11ÔÂ14ÈÕ
 *      Author: admin
 */

#include "CanComm.h"



/*
@brief
@details
@para
@return
*/
void FlexCAN_Init(void)
{
	Can_Init(&CanConfigSet);

	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_1);
	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_2);
	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_3);
	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_4);

	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_1, CAN_T_START);
	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_2, CAN_T_START);
	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_3, CAN_T_START);
	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_4, CAN_T_START);
}

/*
@brief
@details
@para
@return
*/
void FlexCAN_SendMessage(void)
{
	Can_PduType txFrame;
	uint8 TxDATA[8] = {0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11};

	txFrame.id = 0x120;
	txFrame.length = 8;
	txFrame.swPduHandle = 0x1;
	txFrame.sdu = &TxDATA[0];

	Can_Write(CanConf_CanHardwareObject_Can_Network_CANNODE_1_Tx_Std_MailBox_1, &txFrame);
	Can_Write(CanConf_CanHardwareObject_Can_Network_CANNODE_2_Tx_Std_MailBox_1, &txFrame);
	Can_Write(CanConf_CanHardwareObject_Can_Network_CANNODE_3_Tx_Std_MailBox_1, &txFrame);
	Can_Write(CanConf_CanHardwareObject_Can_Network_CANNODE_4_Tx_Std_MailBox_1, &txFrame);
}
