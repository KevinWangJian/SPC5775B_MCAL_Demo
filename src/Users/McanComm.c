/*
 * McanComm.c
 *
 *  Created on: 2019Äê9ÔÂ26ÈÕ
 *      Author: admin
 */

#include "McanComm.h"


static MCANRxMessageBuffer_t MCAN_0_RxMsgBuffer;
static MCANRxMessageBuffer_t MCAN_1_RxMsgBuffer;



/*
@brief
@details
@para
@return
*/
void McanComm_Init(void)
{
	Can_43_MCAN_Init(&Can_43_MCAN_CanConfigSet_0);

	Can_43_MCAN_EnableControllerInterrupts(MCAN_0_CONTROLLER_ID);
	Can_43_MCAN_EnableControllerInterrupts(MCAN_1_CONTROLLER_ID);

	Can_43_MCAN_SetControllerMode(MCAN_0_CONTROLLER_ID, CAN_T_START);
	Can_43_MCAN_SetControllerMode(MCAN_1_CONTROLLER_ID, CAN_T_START);
}

/*
@brief
@details
@para
@return
*/
void McanComm_RxBufferInit(void)
{
	MCAN_0_RxMsgBuffer.writePtr = 0;
	MCAN_0_RxMsgBuffer.readPtr  = 0;
	MCAN_0_RxMsgBuffer.rxMsgBuf[0].frameStat = InvalidCanFrame;
	MCAN_0_RxMsgBuffer.rxMsgBuf[1].frameStat = InvalidCanFrame;
	MCAN_0_RxMsgBuffer.rxMsgBuf[2].frameStat = InvalidCanFrame;
	MCAN_0_RxMsgBuffer.rxMsgBuf[3].frameStat = InvalidCanFrame;
	MCAN_0_RxMsgBuffer.rxMsgBuf[4].frameStat = InvalidCanFrame;

	MCAN_1_RxMsgBuffer.writePtr = 0;
	MCAN_1_RxMsgBuffer.readPtr  = 0;
	MCAN_1_RxMsgBuffer.rxMsgBuf[0].frameStat = InvalidCanFrame;
	MCAN_1_RxMsgBuffer.rxMsgBuf[1].frameStat = InvalidCanFrame;
	MCAN_1_RxMsgBuffer.rxMsgBuf[2].frameStat = InvalidCanFrame;
	MCAN_1_RxMsgBuffer.rxMsgBuf[3].frameStat = InvalidCanFrame;
	MCAN_1_RxMsgBuffer.rxMsgBuf[4].frameStat = InvalidCanFrame;
}

/*
@brief MCAN module send CAN message frames.
@details This function should be called by users to send a specified CAN message frame.
@para hwObj, the hardware object id which is used to send CAN messages.
@para *pTxMsg, the specified CAN message frame.
@return 0, failed; 1, success;
*/
int McanComm_SendMessages(MCanHwObjId hwObj, MCANMessage_TypeDef* pTxMsg)
{
	Can_PduType canPdu;
	Can_ReturnType ret;
	uint8_t i;
	uint8_t flag = 0;

	for (i = 0; i < CAN_43_MCAN_MAXMBCOUNT_0; i++)
	{
		if ((Can_43_MCAN_MessageBufferConfigs0_PB[i].u32HWObjID == hwObj) &&
			(Can_43_MCAN_MessageBufferConfigs0_PB[i].eMBType == CAN_43_MCAN_TRANSMIT))
		{
			flag = 0xff;
			break;
		}
	}

	if (flag == 0)return (0);
	if (pTxMsg == NULL)return (0);

	canPdu.id = (Can_IdType)pTxMsg->Id;
	canPdu.length = (uint8)pTxMsg->dlc;
	canPdu.sdu = (uint8*)&pTxMsg->data[0];
	/* use PduID of larger than 0x100 to indicate MCAN not FlexCAN. Details in CanIf_TxConfirmation.*/
	canPdu.swPduHandle = 0x200;

	ret = Can_43_MCAN_Write(hwObj, &canPdu);

	if (ret == CAN_OK)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
@brief  MCAN module receive CAN message frames.
@details This function should be called by users to get the received CAN message frames.
@para ControllerId, MCAN module controller ID.
@para *pRxMessage, the received CAN message frames stored buffer.
@return 0, get the received CAN message failed; 1, get the received CAN message success;
*/
int McanComm_ReceiveMessages(uint8_t ControllerId, MCANMessage_TypeDef *pRxMessage)
{
	uint8_t i;

	SuspendAllInterrupts();

	if (ControllerId == MCAN_0_CONTROLLER_ID)
	{
		if (MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].frameStat == (MCANFrameStatus_Def)InvalidCanFrame)
		{
			ResumeAllInterrupts();

			return (0);
		}
		else
		{
			pRxMessage->Id = MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].Id;
			MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].Id = 0;

			pRxMessage->dlc = MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].dlc;
			MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].dlc = 0;

			for (i = 0; i < (pRxMessage->dlc); i++)
			{
				pRxMessage->data[i] = MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].data[i];
				MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].data[i] = 0;
			}

			pRxMessage->frameStat = MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].frameStat;
			MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.readPtr].frameStat = (MCANFrameStatus_Def)InvalidCanFrame;

			ResumeAllInterrupts();

			MCAN_0_RxMsgBuffer.readPtr++;

			if (MCAN_0_RxMsgBuffer.readPtr >= MCAN_RX_MSG_BUF_SIZE)
			{
				MCAN_0_RxMsgBuffer.readPtr = 0;
			}

			return (1);
		}
	}
	else if (ControllerId == MCAN_1_CONTROLLER_ID)
	{
		if (MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].frameStat == (MCANFrameStatus_Def)InvalidCanFrame)
		{
			ResumeAllInterrupts();

			return (0);
		}
		else
		{
			pRxMessage->Id = MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].Id;
			MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].Id = 0;

			pRxMessage->dlc = MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].dlc;
			MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].dlc = 0;

			for (i = 0; i < (pRxMessage->dlc); i++)
			{
				pRxMessage->data[i] = MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].data[i];
				MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].data[i] = 0;
			}

			pRxMessage->frameStat = MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].frameStat;
			MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.readPtr].frameStat = (MCANFrameStatus_Def)InvalidCanFrame;

			ResumeAllInterrupts();

			MCAN_1_RxMsgBuffer.readPtr++;

			if (MCAN_1_RxMsgBuffer.readPtr >= MCAN_RX_MSG_BUF_SIZE)
			{
				MCAN_1_RxMsgBuffer.readPtr = 0;
			}

			return (1);
		}
	}
	else
	{
		return (0);
	}
}

/*
@brief MCAN module write CAN messages to receive buffers.
@details This function is called by CAN RX ISR routine,it should not be called by users.
@para ControllerId, MCAN controller id.
@para Id, CAN frame id.
@para Len, CAN frame data length.
@para *pData, the pointer of received CAN frame data.
@return 0, write CAN messages to receive buffer failed; 1, write CAN messages to receive buffer success;
*/
int McanComm_WriteRxMsgBuffer(uint8_t ControllerId, Can_IdType Id, uint8_t Len, uint8_t* pData)
{
	uint8_t i;
	uint32_t idVal;

	if (Id & 0x80000000)
	{
		idVal = (uint32_t)Id & 0x7FFFFFFFU;
	}
	else
	{
		idVal = (uint32_t)Id;
	}

	if (ControllerId == MCAN_0_CONTROLLER_ID)
	{
		if (MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.writePtr].frameStat != (MCANFrameStatus_Def)InvalidCanFrame)
		{
			return (0);
		}
		else
		{
			MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.writePtr].Id = idVal;
			MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.writePtr].dlc = Len;

			for (i = 0; i < Len; i++)
			{
				MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.writePtr].data[i] = pData[i];
			}

			MCAN_0_RxMsgBuffer.rxMsgBuf[MCAN_0_RxMsgBuffer.writePtr].frameStat = ValidCanFrame;

			MCAN_0_RxMsgBuffer.writePtr++;

			if (MCAN_0_RxMsgBuffer.writePtr >= MCAN_RX_MSG_BUF_SIZE)
			{
				MCAN_0_RxMsgBuffer.writePtr = 0;
			}

			return (1);
		}
	}
	else if (ControllerId == MCAN_1_CONTROLLER_ID)
	{
		if (MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.writePtr].frameStat != (MCANFrameStatus_Def)InvalidCanFrame)
		{
			return (0);
		}
		else
		{
			MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.writePtr].Id = idVal;
			MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.writePtr].dlc = Len;

			for (i = 0; i < Len; i++)
			{
				MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.writePtr].data[i] = pData[i];
			}

			MCAN_1_RxMsgBuffer.rxMsgBuf[MCAN_1_RxMsgBuffer.writePtr].frameStat = ValidCanFrame;

			MCAN_1_RxMsgBuffer.writePtr++;

			if (MCAN_1_RxMsgBuffer.writePtr >= MCAN_RX_MSG_BUF_SIZE)
			{
				MCAN_1_RxMsgBuffer.writePtr = 0;
			}

			return (1);
		}
	}
	else
	{
		return (0);
	}
}


#ifdef MCAN_TEST_DEMO
/*
@brief
@details
@para
@return
*/
void McanComm_TransmitProcess(void)
{
	MCANMessage_TypeDef txmessage;

	txmessage.frameStat = ValidCanFrame;
	txmessage.Id = 0x101;
	txmessage.dlc = 8;
	txmessage.data[0] = 0x5A;
	txmessage.data[1] = 0x22;
	txmessage.data[2] = 0x33;
	txmessage.data[3] = 0x44;
	txmessage.data[4] = 0x55;
	txmessage.data[5] = 0x66;
	txmessage.data[6] = 0x77;
	txmessage.data[7] = 0x88;

	McanComm_SendMessages(MCAN_0_TX_HWHANDLE_OBJ, &txmessage);
	McanComm_SendMessages(MCAN_1_TX_HWHANDLE_OBJ, &txmessage);
}


MCANMessage_TypeDef RxMessage_0;
MCANMessage_TypeDef RxMessage_1;


/*
@brief
@details
@para
@return
*/
void McanComm_ReceiveProcess_0(void)
{
	uint8_t controllerId = MCAN_0_CONTROLLER_ID;

	McanComm_ReceiveMessages(controllerId, &RxMessage_0);
}

/*
@brief
@details
@para
@return
*/
void McanComm_ReceiveProcess_1(void)
{
	uint8_t controllerId = MCAN_1_CONTROLLER_ID;

	McanComm_ReceiveMessages(controllerId, &RxMessage_1);
}
#endif







