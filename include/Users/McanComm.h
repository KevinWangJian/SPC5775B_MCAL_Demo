/*
 * McanComm.h
 *
 *  Created on: 2019Äê9ÔÂ26ÈÕ
 *      Author: admin
 */

#ifndef CDD_MCANCOMM_MCANCOMM_H_
#define CDD_MCANCOMM_MCANCOMM_H_

#ifdef __cplusplus
extern "C" {
#endif



#include <stdio.h>
#include <stdarg.h>

#include "Mcal.h"
#include "typedefs.h"
#include "Std_Types.h"
#include "Can_43_MCAN.h"


#define  MCAN_USER_FUNC
#define  MCAN_TEST_DEMO

#define  MCAN_0_CONTROLLER_ID	(CanController_5)
#define  MCAN_1_CONTROLLER_ID	(CanController_6)

#define  MCAN_0_TX_HWHANDLE_OBJ	(Can_43_MCAN_Can_Network_CANNODE_5_Tx_Std_MailBox_1)
#define  MCAN_1_TX_HWHANDLE_OBJ	(Can_43_MCAN_Can_Network_CANNODE_6_Tx_Std_MailBox_1)

/* The total size of MCAN Rx message buffer. */
#define  MCAN_RX_MSG_BUF_SIZE	(10)



typedef  uint8_t MCanHwObjId;

typedef enum
{
	InvalidCanFrame	= 0,
	ValidCanFrame	= 1
}MCANFrameStatus_Def;

typedef struct
{
	uint8_t dlc;
	uint8_t data[64];
	uint32_t Id;
	MCANFrameStatus_Def frameStat;
}MCANMessage_TypeDef;

typedef struct
{
	uint8_t writePtr;
	uint8_t readPtr;
	MCANMessage_TypeDef rxMsgBuf[MCAN_RX_MSG_BUF_SIZE];
}MCANRxMessageBuffer_t;


extern CONST(Can_43_MCAN_MBConfigObjectType, CAN_43_MCAN_CONST) Can_43_MCAN_MessageBufferConfigs0_PB[CAN_43_MCAN_MAXMBCOUNT_0];


void McanComm_Init(void);
void McanComm_RxBufferInit(void);
int McanComm_SendMessages(MCanHwObjId hwObj, MCANMessage_TypeDef* pTxMsg);
int McanComm_ReceiveMessages(uint8_t ControllerId, MCANMessage_TypeDef *pRxMessage);
int McanComm_WriteRxMsgBuffer(uint8_t ControllerId, Can_IdType Id, uint8_t Len, uint8_t* pData);

#ifdef MCAN_TEST_DEMO
void McanComm_TransmitProcess(void);
void McanComm_ReceiveProcess_0(void);
void McanComm_ReceiveProcess_1(void);
#endif


#ifdef __cplusplus
}
#endif
#endif /* CDD_MCANCOMM_MCANCOMM_H_ */
