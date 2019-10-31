/*
 * EthComm.c
 *
 *  Created on: 2019Äê10ÔÂ22ÈÕ
 *      Author: admin
 */

#include <string.h>
#include "EthComm.h"
#include "StdRegMacros.h"
#include "Eth_Cfg.h"
#include "Eth_GeneralTypes.h"


static EthernetRxFrameBuffer_t EthRxFrameBuffer;



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

	/* Initializes the Ethernet Driver. */
	Eth_Init(&EthConfigSet_0);

	dummyCnt = 0;
	/* Initializes the Ethernet Driver. */
	retVal = Eth_ControllerInit(CTRL_INDEX, CFG_INDEX);

	if (retVal == E_OK)
	{
		retVal = E_NOT_OK;

		/* Enables the given controller. */
		retVal = Eth_SetControllerMode(CTRL_INDEX, ETH_MODE_ACTIVE);

		if (retVal == E_OK)
		{
			/* Execute several empty operation to enable system can set breakpoint here when in debug mode. */
			while (dummyCnt < 5U) dummyCnt++;

			/* Obtains the physical source address used by the indexed controller. */
			Eth_GetPhysAddr(CTRL_INDEX, &MAC_Addr[0]);
		}
		else
		{
			/* Execute several empty operation to enable system can set breakpoint here when in debug mode. */
			while (dummyCnt < 5U) dummyCnt++;
		}
	}
	else
	{
		/* Execute several empty operation to enable system can set breakpoint here when in debug mode. */
		while (dummyCnt < 5U) dummyCnt++;
	}
}

/*
@brief
@details
@para
@return
*/
int Ethernet_SendFrameData(const Eth_DataType* txDataBuf, uint16 txLength)
{
	int retResult = 0;
	uint16 i;
	uint8 targetMacAddr[6], bufIdx = 0;
	Std_ReturnType ret;
	BufReq_ReturnType ethRet;
	Eth_FrameType frameType;

	if ((txDataBuf != NULL) && (txLength > OFFSET_PAYLOAD))
	{
		Eth_DataType *txBufPtr = (Eth_DataType*)&txDataBuf[OFFSET_PAYLOAD];
		Eth_DataType **txBufPtrPtr = &txBufPtr;

		uint16 lenByte = txLength - OFFSET_PAYLOAD;		/* Payload data length. */
		uint16 *lenBytePtr = &lenByte;

		if (Eth_ProvideTxBuffer(CTRL_INDEX, &bufIdx, txBufPtrPtr, lenBytePtr) != BUFREQ_OK)
		{
			retResult = 0;
		}
		else
		{
			/*If guaranteed memory is larger than requested memory, re-assign lenByte as requested value. Or return E_NOT_OK.*/
			if (*lenBytePtr >= (txLength - OFFSET_PAYLOAD))
			{
				lenByte = txLength - OFFSET_PAYLOAD;

				/*Assign value to memory pointed by txBufPtr, whose value is assigned by txBufPtrPtr in Eth_ProvideTxBuffer.*/
				for(i = 0; i < lenByte; i++)
				{
					*txBufPtr = txDataBuf[OFFSET_PAYLOAD + i];
					txBufPtr++;
				}

				/* Assign frame type value. */
				frameType = ((uint16)txDataBuf[OFFSET_FRAMETYPE] << 8U) | txDataBuf[OFFSET_FRAMETYPE + 1];

				memcpy((uint8*)targetMacAddr, (Eth_DataType*)txDataBuf, 6);

				/* Transmit Ethernet frame data. */
				ret = Eth_Transmit(CTRL_INDEX, bufIdx, frameType, TXCOMFIRMATION_OFF, lenByte, &targetMacAddr[0]);

				if (ret == E_OK)
				{
					retResult = 1;
				}
			}
		}
	}

	return (retResult);
}

/*
@brief
@details
@para
@return
*/
int Ethernet_WriteRxFrameToBuffer(EthernetFrameData_Def_t* pRxframeData)
{
	int result;

	if (EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.WritePtr].FrameValid != FALSE)
	{
		result = 0;
	}
	else
	{
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.WritePtr].IsBroadcast   = pRxframeData->IsBroadcast;
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.WritePtr].FrameType     = pRxframeData->FrameType;
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.WritePtr].DataLength    = pRxframeData->DataLength;

		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.WritePtr].ptrDataBuffer = pRxframeData->ptrDataBuffer;
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.WritePtr].ptrSrcMacAddr = pRxframeData->ptrSrcMacAddr;

		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.WritePtr].FrameValid    = pRxframeData->FrameValid;

		EthRxFrameBuffer.WritePtr++;

		if (EthRxFrameBuffer.WritePtr >= ETH_RX_FRAME_BUF_SIZE)
		{
			EthRxFrameBuffer.WritePtr = 0;
		}

		result = 1;
	}

	return (result);
}






