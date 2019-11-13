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
#include "Eth_Fec.h"
#include "PhyDP83822I.h"
#include "PhyTja110x.h"
#include "tickTimer.h"


static EthernetRxFrameBuffer_t EthRxFrameBuffer = {0};


Eth_DataType txMacFrame[1014] = {
									0x20,0x3D,0x19,0x1C,0x29,0xCD,			/*Destination Address*/
									0x66,0x55,0x44,0x33,0x22,0x11,			/*Source Address(config in tresos)*/
									0x00,0x00,					  			/*Frametype / Payload length*/
									0										/*Payload*/
                                };

volatile uint32_t TIME1_START = 0;
volatile uint32_t TIME2_END   = 0;
volatile uint32_t DELTA_TIME  = 0;



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
void Ethernet_ClrRXBIrqFlag(uint8 u8CtrlIdx)
{
	uint32 ETH_BASE_ADDR;

	if (u8CtrlIdx == 0U)
	{
		ETH_BASE_ADDR = FEC_0_BASEADDR;
	}
#if ETH_MAXCTRLS_SUPPORTED > 1U
	else if (u8CtrlIdx == 1U)
	{
		ETH_BASE_ADDR = FEC_1_BASEADDR;
	}
#endif

	REG_WRITE32(ETH_BASE_ADDR + FEC_EIR_ADDR16, FEC_EIR_RXB_W1C);
}

/*
@brief
@details
@para
@return
*/
void Ethernet_ClrTXBIrqFlag(uint8 u8CtrlIdx)
{
	uint32 ETH_BASE_ADDR;

	if (u8CtrlIdx == 0U)
	{
		ETH_BASE_ADDR = FEC_0_BASEADDR;
	}
#if ETH_MAXCTRLS_SUPPORTED > 1U
	else if (u8CtrlIdx == 1U)
	{
		ETH_BASE_ADDR = FEC_1_BASEADDR;
	}
#endif

	REG_WRITE32(ETH_BASE_ADDR + FEC_EIR_ADDR16, FEC_EIR_TXB_W1C);
}

/*
@brief
@details
@para
@return
*/
boolean Ethernet_IsRXBIrqFlagSet(uint8 u8CtrlIdx)
{
	uint32 u32RegisterValue;
	boolean bReturnValue;

	uint32 ETH_BASE_ADDR;

	if (u8CtrlIdx == 0U)
	{
		ETH_BASE_ADDR = FEC_0_BASEADDR;
	}
#if ETH_MAXCTRLS_SUPPORTED > 1U
	else if (u8CtrlIdx == 1U)
	{
		ETH_BASE_ADDR = FEC_1_BASEADDR;
	}
#endif

    u32RegisterValue = REG_READ32(ETH_BASE_ADDR + FEC_EIR_ADDR16);
    /* Check whether the bit is set */
    if(FEC_EIR_RXB_U32 == (u32RegisterValue & FEC_EIR_RXB_U32))
    {
        bReturnValue = TRUE;
    }
    else
    {
        /** @violates @ref Eth_Fec_c_REF_19 MISRA rule 11.3 */
        bReturnValue = FALSE;
    }

    return bReturnValue;
}

/*
@brief
@details
@para
@return
*/
void Ethernet_ClrMIIIrqFlag(uint8 u8CtrlIdx)
{
	uint32 ETH_BASE_ADDR;

	if (u8CtrlIdx == 0U)
	{
		ETH_BASE_ADDR = FEC_0_BASEADDR;
	}
#if ETH_MAXCTRLS_SUPPORTED > 1U
	else if (u8CtrlIdx == 1U)
	{
		ETH_BASE_ADDR = FEC_1_BASEADDR;
	}
#endif

	REG_WRITE32(ETH_BASE_ADDR + FEC_EIR_ADDR16, FEC_EIR_MII_W1C);
}

/*
@brief
@details
@para
@return
*/
boolean Ethernet_IsMIIIrqFlagSet(uint8 u8CtrlIdx)
{
	uint32 u32RegisterValue;
	boolean bReturnValue;

	uint32 ETH_BASE_ADDR;

	if (u8CtrlIdx == 0U)
	{
		ETH_BASE_ADDR = FEC_0_BASEADDR;
	}
#if ETH_MAXCTRLS_SUPPORTED > 1U
	else if (u8CtrlIdx == 1U)
	{
		ETH_BASE_ADDR = FEC_1_BASEADDR;
	}
#endif

    u32RegisterValue = REG_READ32(ETH_BASE_ADDR + FEC_EIR_ADDR16);
    /* Check whether the bit is set */
    if(FEC_EIR_MII_U32 == (u32RegisterValue & FEC_EIR_MII_U32))
    {
        bReturnValue = TRUE;
    }
    else
    {
        /** @violates @ref Eth_Fec_c_REF_19 MISRA rule 11.3 */
        bReturnValue = FALSE;
    }

    return bReturnValue;
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
				ret = Eth_Transmit(CTRL_INDEX, bufIdx, frameType, TXCOMFIRMATION_ON, lenByte, &targetMacAddr[0]);

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

/*
@brief
@details
@para
@return
*/
int Ethernet_ReadRxFrameFromBuffer(EthernetPerFrameTypeDef_t* pRetFrameData)
{
	int result;

	if (EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].FrameValid == FALSE)
	{
		result = 0;
	}
	else
	{
		pRetFrameData->IsBroadcast = EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].IsBroadcast;
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].IsBroadcast = FALSE;

		pRetFrameData->FrameType = EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].FrameType;
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].FrameType = 0;

		pRetFrameData->DataLength = EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].DataLength;
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].DataLength = 0;

		memcpy((Eth_DataType*)pRetFrameData->FrameData,
			   (Eth_DataType*)EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].ptrDataBuffer,
			   pRetFrameData->DataLength);

		memcpy((uint8*)pRetFrameData->SrcMacAddr, (uint8*)EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].ptrSrcMacAddr, 6);

		pRetFrameData->FrameValid = EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].FrameValid;
		EthRxFrameBuffer.RxFrameBuf[EthRxFrameBuffer.ReadPtr].FrameValid = FALSE;

		EthRxFrameBuffer.ReadPtr++;

		if (EthRxFrameBuffer.ReadPtr >= ETH_RX_FRAME_BUF_SIZE)
		{
			EthRxFrameBuffer.ReadPtr = 0;
		}

		result = 1;
	}

	return (result);
}




/*
@brief
@details
@para
@return
*/
void Ethernet_FrameData_Init(void)
{
	uint8_t PayloadData[10] = {0x00,0x01,0x08,0x00,0x06,0x04,0x00,0x01,0x55,0xAA};
	uint16_t cnt;
	uint16_t payloadLength;

	for (cnt = 0; cnt < 100; cnt++)
	{
		memcpy((Eth_DataType*)&txMacFrame[10*cnt + 14], (uint8_t*)&PayloadData[0], (sizeof(PayloadData)/sizeof(uint8_t)));
	}

	payloadLength = sizeof(txMacFrame)/sizeof(Eth_DataType) - 14;

	memcpy((Eth_DataType*)&txMacFrame[12], (uint8_t*)&payloadLength, 2);
}

/*
@brief
@details
@para
@return
*/
void Ethernet_TransmitFramesTest(void)
{
	EthernetPerFrameTypeDef_t RxFrame;
	int retVal;
	uint8_t frameCount;
	uint32_t timeoutCnt;

	if (((TJA1101_AttributeInfo.LinkStatus == TJA1101_Linkup_Success)    && (TJA1101_AttributeInfo.PhySQILevel >= SQI_CLASS_E)) || \
		((PHY_DP83822HF_Prop[0].PhyLinkStatus == Valid_Link_Established) && (PHY_DP83822HF_Prop[0].MiiLinkStatus == Active_100BaseTxFullDuplexLink)) || \
		((PHY_DP83822HF_Prop[1].PhyLinkStatus == Valid_Link_Established) && (PHY_DP83822HF_Prop[1].MiiLinkStatus == Active_100BaseTxFullDuplexLink)))
	{
		/* Before read tick time value,user should disable interrupt firstly. */
		SuspendAllInterrupts();
		/* Read the start tick time before ETHERNET frame transmission. */
		TIME1_START = systemGlobalTickCount;
		/* After reading tick time value,user should enable interrupt immediately. */
		ResumeAllInterrupts();

		for (frameCount = 0; frameCount < 25; frameCount++)
		{
			Ethernet_SendFrameData(txMacFrame, (sizeof(txMacFrame)/sizeof(Eth_DataType)));

			retVal = 0;
			timeoutCnt = 0;
			/* Wait for receiving Ethernet frame data. */
//			while ((retVal == 0) || (EthRxFrameBuffer.ReadPtr != EthRxFrameBuffer.WritePtr))
			while ((retVal != 1) && (timeoutCnt < 0x10000U))
			{
				retVal = Ethernet_ReadRxFrameFromBuffer(&RxFrame);
				timeoutCnt++;
			}
			if (timeoutCnt >= 0x10000U)
			{
				break;
			}
		}

		/* Before read tick time value,user should disable interrupt firstly. */
		SuspendAllInterrupts();
		/* Read the start tick time before ETHERNET frame transmission. */
		TIME2_END = systemGlobalTickCount;
		/* After reading tick time value,user should enable interrupt immediately. */
		ResumeAllInterrupts();

		DELTA_TIME = TIME2_END - TIME1_START;

		frameCount = 0;
	}
}




