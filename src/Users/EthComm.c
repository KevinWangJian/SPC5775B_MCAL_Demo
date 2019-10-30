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





