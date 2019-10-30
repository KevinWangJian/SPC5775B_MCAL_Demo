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

/*
@brief
@details
@para
@return
*/
int Ethernet_SendFrameData(Eth_DataType* txDataBuf, uint16_t txLength)
{
	int retResult = 0;
	uint16 i;
	uint8 bufIdx = 0;
	Std_ReturnType ret;
	BufReq_ReturnType ethRet;
	Eth_FrameType frameType;
	uint8 targetMacAddr[6];

	Eth_DataType *txBufPtr = NULL;
	Eth_DataType **txBufPtrPtr = NULL;
	uint16 lenByte;
	uint16 *lenBytePtr = NULL;

//	Eth_DataType *txBufPtr = &txDataBuf[0 + OFFSET_PAYLOAD];
//	Eth_DataType **txBufPtrPtr = &txBufPtr;
//
//	uint16 lenByte = txLength - OFFSET_PAYLOAD;
//	uint16 *lenBytePtr = &lenByte;

	if ((txDataBuf != NULL) && (txLength > OFFSET_PAYLOAD))
	{
		txBufPtr = &txDataBuf[0 + OFFSET_PAYLOAD];
		txBufPtrPtr = &txBufPtr;

		lenByte = txLength - OFFSET_PAYLOAD;
		lenBytePtr = &lenByte;

		memcpy((uint8*)targetMacAddr, (Eth_DataType*)txDataBuf, 6);

		ethRet = Eth_ProvideTxBuffer(CTRL_INDEX, &bufIdx, txBufPtrPtr, lenBytePtr);

		if (ethRet != BUFREQ_OK)
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

				/* Transmit Ethernet frame data. */
				ret = Eth_Transmit(CTRL_INDEX, bufIdx, frameType, TXCOMFIRMATION_OFF, lenByte, &targetMacAddr[0]);

				if (ret == E_OK)
				{
					retResult = 1;
				}
				else
				{
					retResult = 0;
				}
			}
			else
			{
				retResult = 0;
			}
		}
	}

	return (retResult);
}





