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
	Can_Init(&Can_ConfigSet_PC);

	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_1);
	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_2);
	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_3);
	Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_4);

	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_1, CAN_T_START);
	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_2, CAN_T_START);
	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_3, CAN_T_START);
	Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_4, CAN_T_START);
}

