/*
 * PhyDP83822I.c
 *
 *  Created on: 2019Äê10ÔÂ23ÈÕ
 *      Author: admin
 */

#include "PhyDP83822I.h"
#include "Eth.h"
#include "EthComm.h"
#include "Eth_GeneralTypes.h"
#include "Std_Types.h"


static PHY_DP83822_ProTypeDef PHY_DP83822HF_Prop[2];


/*
@brief
@details
@para
@return
*/
void CntDelay(uint32_t cnt)
{
	while (cnt--){;}
}


/*
@brief Write data to DP83822HF chip internal registers.
@para phyAddr, DP83822HF PHY address;
@para regAddr, internal register address;
@para WtData, the new write data;
@return 1,success; 0,failed;
*/
int PHY_DP83822_SMIWriteRegData(const uint8_t phyAddr, const uint16_t regAddr, const uint16_t WtData)
{
	const uint8_t TIMEOUT = 100;
	uint8_t MMD = 0, ExtendRegCmd = 0;
	uint16_t writeData, writeAddr;
	uint8_t dummyCount = 0;
	Eth_ReturnType ret;

	int retVal = -1;

	if (regAddr <= 0x001FU)
	{
		ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)regAddr, (uint16)WtData);
		dummyCount = 0;

		if (ret != ETH_OK)
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (1);
		}
	}
	else if ((regAddr > 0x001FU) && (regAddr <= 0x04D1U))
	{
		ExtendRegCmd = 0x00U;	/* Address command */
		MMD = 0x1FU;
		writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

		ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
		dummyCount = 0;

		if (ret == ETH_OK)
		{
			ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)regAddr);
			dummyCount = 0;

			if (ret == ETH_OK)
			{
				ExtendRegCmd = 0x01U;	/* Data command no post increment. */
				MMD = 0x1FU;
				writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

				ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
				dummyCount = 0;

				if (ret == ETH_OK)
				{
					ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)WtData);
					dummyCount = 0;

					if (ret == ETH_OK)
					{
						while (dummyCount < 3U)dummyCount++;
						return (1);
					}
					else
					{
						while (dummyCount < 3U)dummyCount++;
						return (0);
					}
				}
				else
				{
					while (dummyCount < 3U)dummyCount++;
					return (0);
				}
			}
			else
			{
				while (dummyCount < 3U)dummyCount++;
				return (0);
			}
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
	}
	else if ((regAddr >= 0x3000U) && (regAddr <= 0x3016U))
	{
		ExtendRegCmd = 0x00U;	/* Address command */
		MMD = 0x03U;
		writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

		ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
		dummyCount = 0;

		if (ret == ETH_OK)
		{
			writeAddr = regAddr;
			writeAddr &= 0x0FFFU;

			ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)writeAddr);
			dummyCount = 0;

			if (ret == ETH_OK)
			{
				ExtendRegCmd = 0x01U;	/* Data command no post increment. */
				MMD = 0x03U;
				writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

				ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
				dummyCount = 0;

				if (ret == ETH_OK)
				{
					ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)WtData);
					dummyCount = 0;

					if (ret == ETH_OK)
					{
						while (dummyCount < 3U)dummyCount++;
						return (1);
					}
					else
					{
						while (dummyCount < 3U)dummyCount++;
						return (0);
					}
				}
				else
				{
					while (dummyCount < 3U)dummyCount++;
					return (0);
				}
			}
			else
			{
				while (dummyCount < 3U)dummyCount++;
				return (0);
			}
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
	}
	else if ((regAddr >= 0x703CU) && (regAddr <= 0x703DU))
	{
		ExtendRegCmd = 0x00U;	/* Address command */
		MMD = 0x07U;
		writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

		ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
		dummyCount = 0;

		if (ret == ETH_OK)
		{
			writeAddr = regAddr;
			writeAddr &= 0x0FFFU;

			ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)writeAddr);
			dummyCount = 0;

			if (ret == ETH_OK)
			{
				ExtendRegCmd = 0x01U;	/* Data command no post increment. */
				MMD = 0x07U;
				writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

				ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
				dummyCount = 0;

				if (ret == ETH_OK)
				{
					ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)WtData);
					dummyCount = 0;

					if (ret == ETH_OK)
					{
						while (dummyCount < 3U)dummyCount++;
						return (1);
					}
					else
					{
						while (dummyCount < 3U)dummyCount++;
						return (0);
					}
				}
				else
				{
					while (dummyCount < 3U)dummyCount++;
					return (0);
				}
			}
			else
			{
				while (dummyCount < 3U)dummyCount++;
				return (0);
			}
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
	}
	else
	{
		while (dummyCount < 3U)dummyCount++;
		return (0);
	}
}


/*
@brief
@para
@para
@return
*/
int PHY_DP83822_SMIReadRegData(const uint8_t phyAddr, const uint16_t regAddr, uint16_t* pRdData)
{
	const uint8_t TIMEOUT = 100;
	uint8_t MMD = 0, ExtendRegCmd = 0;
	uint16_t writeData, writeAddr;
	uint8_t dummyCount = 0;
	Eth_ReturnType ret;
	int retVal = -1;

	if (regAddr <= 0x001FU)
	{
		ret = Eth_ReadMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)regAddr, (uint16 *)pRdData);
		dummyCount = 0;

		if (ret == ETH_OK)
		{
			while (dummyCount < 3U)dummyCount++;
			return (1);
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
	}
	else if ((regAddr > 0x001FU) && (regAddr <= 0x04D1U))
	{
		ExtendRegCmd = 0x00U;	/* Address command */
		MMD = 0x1FU;
		writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

		ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
		dummyCount = 0;

		if (ret == ETH_OK)
		{
			ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)regAddr);
			dummyCount = 0;

			if (ret == ETH_OK)
			{
				ExtendRegCmd = 0x01U;	/* Data command no post increment. */
				MMD = 0x1FU;
				writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

				ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
				dummyCount = 0;

				if (ret == ETH_OK)
				{
					ret = Eth_ReadMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16 *)pRdData);
					dummyCount = 0;

					if (ret == ETH_OK)
					{
						while (dummyCount < 3U)dummyCount++;
						return (1);
					}
					else
					{
						while (dummyCount < 3U)dummyCount++;
						return (0);
					}
				}
				else
				{
					while (dummyCount < 3U)dummyCount++;
					return (0);
				}
			}
			else
			{
				while (dummyCount < 3U)dummyCount++;
				return (0);
			}
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
	}
	else if ((regAddr >= 0x3000U) && (regAddr <= 0x3016U))
	{
		ExtendRegCmd = 0x00U;	/* Address command */
		MMD = 0x03U;
		writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

		ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
		dummyCount = 0;

		if (ret == ETH_OK)
		{
			writeAddr = regAddr;
			writeAddr &= 0x0FFFU;

			ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)writeAddr);
			dummyCount = 0;

			if (ret == ETH_OK)
			{
				ExtendRegCmd = 0x01;	/* Data command no post increment. */
				MMD = 0x03;
				writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

				ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
				dummyCount = 0;

				if (ret == ETH_OK)
				{
					ret = Eth_ReadMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16 *)pRdData);
					dummyCount = 0;

					if (ret == ETH_OK)
					{
						while (dummyCount < 3U)dummyCount++;
						return (1);
					}
					else
					{
						while (dummyCount < 3U)dummyCount++;
						return (0);
					}
				}
				else
				{
					while (dummyCount < 3U)dummyCount++;
					return (0);
				}
			}
			else
			{
				while (dummyCount < 3U)dummyCount++;
				return (0);
			}
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
	}
	else if ((regAddr >= 0x703CU) && (regAddr <= 0x703DU))
	{
		ExtendRegCmd = 0x00U;	/* Address command */
		MMD = 0x07U;
		writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

		ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
		dummyCount = 0;

		if (ret == ETH_OK)
		{
			writeAddr = regAddr;
			writeAddr &= 0x0FFFU;

			ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16)writeAddr);
			dummyCount = 0;

			if (ret == ETH_OK)
			{
				ExtendRegCmd = 0x01U;	/* Data command no post increment. */
				MMD = 0x07U;
				writeData = ((uint16_t)ExtendRegCmd << 14) + MMD;

				ret = Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_REGCR_REG, (uint16)writeData);
				dummyCount = 0;

				if (ret == ETH_OK)
				{
					ret = Eth_ReadMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)DP83822HF_ADDAR_REG, (uint16 *)pRdData);
					dummyCount = 0;

					if (ret == ETH_OK)
					{
						while (dummyCount < 3U)dummyCount++;
						return (1);
					}
					else
					{
						while (dummyCount < 3U)dummyCount++;
						return (0);
					}
				}
				else
				{
					while (dummyCount < 3U)dummyCount++;
					return (0);
				}
			}
			else
			{
				while (dummyCount < 3U)dummyCount++;
				return (0);
			}
		}
		else
		{
			while (dummyCount < 3U)dummyCount++;
			return (0);
		}
	}
	else
	{
		while (dummyCount < 3U)dummyCount++;
		return (0);
	}
}


void PHY_DP83848C_Init(void)
{
	uint16_t RegRdData = 0;
	uint32_t timeoutCnt = 0;

	PHY_DP83822_SMIWriteRegData(0x01, 0x00, 0x0100);

	PHY_DP83822_SMIReadRegData(0x01, 0x00, &RegRdData);

	timeoutCnt = 10;
}


/*
@brief
@para
@para
@return
*/
int PHY_DP83822_Init(void)
{
	uint16_t RegRdData;
	uint32_t timeoutCnt;

//	PHY_DP83822HF_RESET_1_LOW();
//	PHY_DP83822HF_RESET_2_LOW();
//	CntDelay(2000);
//	PHY_DP83822HF_RESET_1_HIGH();
//	PHY_DP83822HF_RESET_2_HIGH();
//
//	/* Reset PHY_1 chip. */
//	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_1_ADDRESS,
//			                 	DP83822HF_PHYRCR_REG,
//							   (DP83822HF_PHYRCR_REG_SoftwareReset_Mask | \
//								DP83822HF_PHYRCR_REG_DigitalRestart_Mask));
//	timeoutCnt = 0;
//
//	do
//	{
//		PHY_DP83822_SMIReadRegData(DP83822HF_PHY_1_ADDRESS, DP83822HF_BMCR_REG, &RegRdData);
//		timeoutCnt++;
//	}
//	while (((RegRdData & DP83822HF_BMCR_REG_Reset_Mask) != 0) && (timeoutCnt < 0x10000000U));
//	if (timeoutCnt >= 0x10000000U)return (-1);
//
//	RegRdData = 0;
//	/* Reset PHY_2 chip. */
//	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_2_ADDRESS,
//			                 	DP83822HF_PHYRCR_REG,
//							   (DP83822HF_PHYRCR_REG_SoftwareReset_Mask | \
//								DP83822HF_PHYRCR_REG_DigitalRestart_Mask));
//	timeoutCnt = 0;
//
//	do
//	{
//		PHY_DP83822_SMIReadRegData(DP83822HF_PHY_2_ADDRESS, DP83822HF_BMCR_REG, &RegRdData);
//		timeoutCnt++;
//	}
//	while (((RegRdData & DP83822HF_BMCR_REG_Reset_Mask) != 0) && (timeoutCnt < 0x10000000U));
//	if (timeoutCnt >= 0x10000000U)return (-1);

	/* Enable Link loss recovery mechanism. */
	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_1_ADDRESS,
							 	DP83822HF_CR1_REG,
							    DP83822HF_CR1_REG_LinkLossRecovery_Mask);

	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_2_ADDRESS,
							    DP83822HF_CR1_REG,
							    DP83822HF_CR1_REG_LinkLossRecovery_Mask);


	/* LEDCFG1 Control: LED_1 LINK OK / BLINK on TX/RX Activity. */
	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_1_ADDRESS,
							 	DP83822HF_LEDCFG1_REG,
								DP83822HF_LEDCFG1_REG_LED1Contrl(0x8));

	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_2_ADDRESS,
							 	DP83822HF_LEDCFG1_REG,
								DP83822HF_LEDCFG1_REG_LED1Contrl(0x8));

	/* IOCTRL1 Control: LED_1 config to GPIO output.  */
	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_1_ADDRESS,
							 	DP83822HF_IOCTRL1_REG,
								DP83822HF_IOCTRL1_REG_LED1GPIOCtrl(0x1));

	PHY_DP83822_SMIWriteRegData(DP83822HF_PHY_2_ADDRESS,
							 	DP83822HF_IOCTRL1_REG,
								DP83822HF_IOCTRL1_REG_LED1GPIOCtrl(0x1));

	return (1);
}


/*
@brief Get current DP83822HF property status.
@para None.
@return None.
*/
void PHY_DP83822_GetCurrentStatus(void)
{
	uint16_t RegRdData;
	uint8_t index;
	int result;

	for (index = 0; index < 2; index++)
	{
		result = PHY_DP83822_SMIReadRegData((DP83822HF_PHY_1_ADDRESS + index), DP83822HF_BMSR_REG, &RegRdData);

		if (result == 1)
		{
			PHY_DP83822HF_Prop[index].PhyLinkStatus = (PhyLinkState)((RegRdData & DP83822HF_BMSR_REG_LinkStatus_Mask) >> 2);
			PHY_DP83822HF_Prop[index].AutoNegotiationCompleteStatus = (PhyAutoNegotiationState)((RegRdData & DP83822HF_BMSR_REG_AutoNegoComplete_Mask) >> 5);
		}
		else
		{
			PHY_DP83822HF_Prop[index].PhyLinkStatus = 0;
			PHY_DP83822HF_Prop[index].AutoNegotiationCompleteStatus = 0;
		}

		result = PHY_DP83822_SMIReadRegData((DP83822HF_PHY_1_ADDRESS + index), DP83822HF_PHYSTS_REG, &RegRdData);

		if (result == 1)
		{
			PHY_DP83822HF_Prop[index].DuplexStatus = (PhyDuplexModeState)((RegRdData & DP83822HF_PHYSTS_REG_DuplexStatus_Mask) >> 2);
			PHY_DP83822HF_Prop[index].SpeedStatus = (PhySpeedModeState)((RegRdData & DP83822HF_PHYSTS_REG_SpeedStatus_Mask) >> 1);
		}
		else
		{
			PHY_DP83822HF_Prop[index].DuplexStatus = 0;
			PHY_DP83822HF_Prop[index].SpeedStatus = 0;
		}

		result = PHY_DP83822_SMIReadRegData((DP83822HF_PHY_1_ADDRESS + index), DP83822HF_PHYCR_REG, &RegRdData);

		if (result == 1)
		{
			PHY_DP83822HF_Prop[index].MiiLinkStatus = (PhyMIILinkState)((RegRdData & DP83822HF_PHYCR_REG_MIILinkStatus_Mask) >> 11);
			PHY_DP83822HF_Prop[index].PhyAddress = (uint8_t)((RegRdData & DP83822HF_PHYCR_REG_PHYADDRESS_Mask) >> 0);
		}
		else
		{
			PHY_DP83822HF_Prop[index].MiiLinkStatus = 0;
			PHY_DP83822HF_Prop[index].PhyAddress = 0;
		}
	}
}


/*
@brief
@para
@para
@return
*/
int PHY_DP83822_SendDataFrame(void)
{
	uint8_t i;
	Std_ReturnType ret;
	BufReq_ReturnType ethRet;
	Eth_FrameType frameTypeARP;

	uint8 bufIdx = 0;
	uint8_t dummyCnt;

	/*MAC frame is an ARP message saying "Who has 192.168.10.3? Tell 192.168.10.10"*/
	Eth_DataType txMacFrame[LENGTH_FRAME] = {
        										0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,			/*Destination Address*/
        										0x66,0x55,0x44,0x33,0x22,0x11,			/*Source Address(config in tresos)*/
        										0x08,0x06,					  			/*Frametype_ARP*/
        										0x00,0x01,0x08,0x00,0x06,0x04,0x00,0x01,/*Payload*/
												0x66,0x55,0x44,0x33,0x22,0x11,			/*Payload*/
												0xc0,0xa8,0x0a,0x0a,					/*Payload*/
												0x00,0x00,0x00,0x00,0x00,0x00,			/*Payload*/
        										0xc0,0xa8,0x0a,0x03						/*Payload*/
                                            };

	uint8 TargetMacAddr[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

	Eth_DataType *txBufPtr = &txMacFrame[OFFSET_PAYLOAD];
	Eth_DataType **txBufPtrPtr = &txBufPtr;

	uint16 lenByte = LENGTH_PAYLOAD;
	uint16 *lenBytePtr = &lenByte;

	if (((PHY_DP83822HF_Prop[0].PhyLinkStatus == Valid_Link_Established) && (PHY_DP83822HF_Prop[0].MiiLinkStatus == Active_100BaseTxFullDuplexLink)) ||
			((PHY_DP83822HF_Prop[1].PhyLinkStatus == Valid_Link_Established) && (PHY_DP83822HF_Prop[1].MiiLinkStatus == Active_100BaseTxFullDuplexLink)))
	{
		dummyCnt = 0;
		ethRet = Eth_ProvideTxBuffer(CTRL_INDEX, &bufIdx, txBufPtrPtr, lenBytePtr);

		if(ethRet != BUFREQ_OK)
		{
			while (dummyCnt < 3U)
			{
				dummyCnt++;
			}
			return (0);
		}
		else
		{
			while (dummyCnt < 3U)
			{
				dummyCnt++;
			}
		}

		/*If guaranteed memory is larger than requested memory, re-assign lenByte as requested value. Or return E_NOT_OK.*/
		if(*lenBytePtr >= (LENGTH_PAYLOAD))
			lenByte = LENGTH_PAYLOAD;
		else
			return (0);

		/*Assign value to memory pointed by txBufPtr, whose value is assigned by txBufPtrPtr in Eth_ProvideTxBuffer.*/
		for(i = 0; i < lenByte; i++)
		{
			*txBufPtr = txMacFrame[OFFSET_PAYLOAD + i];
			txBufPtr++;
		}

		frameTypeARP = ((uint16)txMacFrame[OFFSET_FRAMETYPE] << 8U) | txMacFrame[OFFSET_FRAMETYPE + 1];

		dummyCnt = 0;
		ret = Eth_Transmit(CTRL_INDEX, bufIdx, frameTypeARP, TXCOMFIRMATION_OFF, lenByte, &TargetMacAddr[0]);

		if(ret != E_OK)
		{
			while (dummyCnt < 3U)
			{
				dummyCnt++;
			}

			return (0);
		}

		while (dummyCnt < 3U)
		{
			dummyCnt++;
		}

		return (1);
	}
//	else
//	{
//		return (0);
//	}
}


