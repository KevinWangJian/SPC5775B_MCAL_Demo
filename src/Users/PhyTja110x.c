/*
 * PhyTja110x.c
 *
 *  Created on: 2019��10��22��
 *      Author: admin
 */

#include "PhyTja110x.h"
#include "tickTimer.h"
#include "NXP_TJA1100_Defines.h"
#include "NXP_TJA1100_Functions.h"
#include "Eth.h"
#include "EthComm.h"
#include "Eth_GeneralTypes.h"


static uint32_t  TJA1101_PHY_ID = 0;
static uint8_t   TJA1101_TYPE_NO = 0;
static uint8_t   TJA1101_REVISION_NO = 0;
static uint16_t  TJA1101_PHY_DEV_ADDR = 0;

static PHY_TJA1101_ATTRIBUTE_t TJA1101_AttributeInfo;


/*
@brief  NOP command delay.
@para   cnt, delay count value.
@return None.
*/
void nopDelay(uint32_t cnt)
{
	while (cnt--){;}
}

/*
@brief   
@details 
@para    
@return
*/
NXP_TJA1100_Error_Code_t SMI_Send(Byte* data, Byte phyAddr, Byte* mask, NXP_TJA1100_Access_t type)
{
	uint16_t regVal;
	uint16_t writeVal;
	uint8_t regAddr;
	uint8_t dummyCount;
	NXP_TJA1100_Error_Code_t result = NXP_TJA1100_ERROR_WRITE_FAIL;

	if (NXP_TJA1100_WRITE == type)
	{
		regAddr   = data[0];								/* PHY Register Address. */
		writeVal  = (((uint16_t)data[1] << 8) + data[2]);
		writeVal &= (((uint16_t)mask[1] << 8) + mask[2]);

		dummyCount = 0;

		if (Eth_WriteMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)regAddr, (uint16)writeVal) != ETH_OK)
		{
			while (dummyCount < 5U)dummyCount++;

			result = NXP_TJA1100_ERROR_WRITE_FAIL;
		}
		else
		{
			while (dummyCount < 5U)dummyCount++;

			result = NXP_TJA1100_SUCCESS;
		}
	}
	else if (NXP_TJA1100_READ == type)
	{
		regAddr = data[0];									/* PHY Register Address. */

		dummyCount = 0;

		if (Eth_ReadMii((uint8)CTRL_INDEX, (uint8)phyAddr, (uint8)regAddr, (uint16 *)&regVal) == ETH_OK)
		{
			data[1] = (uint8_t)((regVal >> 8) & 0x00FF);
			data[2] = (uint8_t)((regVal >> 0) & 0x00FF);

			result = NXP_TJA1100_SUCCESS;
		}
		else
		{
			while (dummyCount < 5U)dummyCount++;

			result = NXP_TJA1100_ERROR_WRITE_FAIL;
		}
	}
	else
	{
		dummyCount = 0;

		while (dummyCount < 5U)dummyCount++;

		result = NXP_TJA1100_ERROR_WRITE_FAIL;
	}

	return (result);
}

/*
@brief This function is initialize TJA1101 chip and configure TJA1101 working parameters.
@details This function should be called first by users before call other PHY functions.
@para None.
@return 0, initialization failed; 1, initialization success;
*/
int PHY_TJA1101_Init(void)
{
	uint32_t delayCount;
	TJA1100_Basic_Control_Reg_t    Tja110xBcr;
	TJA110x_PHY_Identifier_1_Reg_t Tja110xId1;
	TJA110x_PHY_Identifier_2_Reg_t Tja110xId2;
	TJA110x_Extended_Control_Reg_t Tja110xEcr;
	TJA110x_Configuration_1_Reg_t  Tja110xCfg1Reg;
	TJA110x_Configuration_2_Reg_t  Tja110xCfg2Reg;
	TJA110x_Common_Config_Reg_t    Tja110xCommonCfgReg;
	TJA110x_General_Status_Reg_t   Tja110xGenStatus;

	/* Note: TJA1101 chip should be enabled first. */
	PHY_TJA1101_ENABLE();

	PHY_TJA1101_RESET_LOW();
	nopDelay(2000);
	PHY_TJA1101_RESET_HIGH();

	TJA1101_AttributeInfo.PhySpeed = TJA1101_100Mbps;

	/* Software RESET command to TJA1101 chip. */
	Tja110xBcr.TJA1100_RST    = TJA1101_RST_PHY_RESET;
	Tja110xBcr.TJA1100_LB  	  = TJA1101_LB_NORMAL_OPERATION;
	Tja110xBcr.TJA1100_ANE    = TJA1101_ANE_DISABLE_AUTONEGOTIATION_PROCESS;
	Tja110xBcr.TJA1100_PWRD   = TJA1101_PWRD_NORMAL_OPERATION;
	Tja110xBcr.TJA1100_ISL    = TJA1101_ISL_NORMAL_OPERATION;
	Tja110xBcr.TJA1100_RAN    = TJA1101_RAN_NORMAL_OPERATION;
	Tja110xBcr.TJA1100_DM     = TJA1101_DM_FULL_DUPLEX;
	Tja110xBcr.TJA1100_CT     = TJA1101_CT_DISABLE_COL_SIGNAL_TEST;
	Tja110xBcr.TJA1100_UDE    = TJA1101_UDE_EN_MII_TRANSMIT_ONLY_WHEN_PHY_VALID_LINK;

	if (TJA1101_AttributeInfo.PhySpeed == TJA1101_10Mbps)
	{
		Tja110xBcr.TJA1100_SS_LSB = TJA1101_SS_LSB_0;
		Tja110xBcr.TJA1100_SS_MSB = TJA1101_SS_MSB_0;
	}
	else if (TJA1101_AttributeInfo.PhySpeed == TJA1101_100Mbps)
	{
		Tja110xBcr.TJA1100_SS_LSB = TJA1101_SS_LSB_1;
		Tja110xBcr.TJA1100_SS_MSB = TJA1101_SS_MSB_0;
	}
	else if (TJA1101_AttributeInfo.PhySpeed == TJA1101_1000Mbps)
	{
		Tja110xBcr.TJA1100_SS_LSB = TJA1101_SS_LSB_0;
		Tja110xBcr.TJA1100_SS_MSB = TJA1101_SS_MSB_1;
	}
	else
	{
		Tja110xBcr.TJA1100_SS_LSB = TJA1101_SS_LSB_1;
		Tja110xBcr.TJA1100_SS_MSB = TJA1101_SS_MSB_0;
	}

	if (TJA110x_setBasicControl(&Tja110xBcr, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	delayCount = 0;
	/* Wait reset complete. */
	while ((Tja110xBcr.TJA1100_RST == TJA1101_RST_PHY_RESET) && (delayCount < 100000000U))
	{
		if (TJA110x_getBasicControl(&Tja110xBcr, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
		{
			TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
			return (0);
		}

		delayCount++;
	}
	if (delayCount >= 100000000U)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	/* Get TJA1101 PHY id1 and id2 register value. */
	if (TJA110x_getPHYIdentifier1(&Tja110xId1, PHY_TJA1101_ADDRESS) == NXP_TJA1100_SUCCESS)
	{
		TJA1101_PHY_ID = ((uint32_t)Tja110xId1.TJA1100_PHY_ID1 << 3);

		if (TJA110x_getPHYIdentifier2(&Tja110xId2, PHY_TJA1101_ADDRESS) == NXP_TJA1100_SUCCESS)
		{
			TJA1101_PHY_ID |= ((uint32_t)Tja110xId2.TJA1100_PHY_ID2 << 19);

			TJA1101_TYPE_NO = Tja110xId2.TJA1100_TYPE;
			TJA1101_REVISION_NO = Tja110xId2.TJA1100_REV;
		}
		else
		{
			TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
			return (0);
		}
	}
	else
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	/* Configure Extended Control register to enable access CONFIG registers. */
	Tja110xEcr.TJA1101_LC   = TJA1101_LC_LINK_CONTROL_ENABLED;
	Tja110xEcr.TJA1101_PM   = TJA1101_PM_NORMAL_MODE;
	Tja110xEcr.TJA1101_SJT  = TJA1101_SJT_SLAVE_JITTER_TEST_DISABLED;
	Tja110xEcr.TJA1101_TRS  = TJA1101_TRS_STOPS_TRAINING_PHASE;
	Tja110xEcr.TJA1101_TM   = TJA1101_TM_NO_TEST_MODE;
	Tja110xEcr.TJA1101_CBT  = TJA1101_CBT_STOPS_TDR_BASED_CABLE_TEST;
	Tja110xEcr.TJA1101_LM   = TJA1101_LM_INTERNAL_LOOPBACK;							/* Attention:BCR register(0x00) LOOPBACK bit must be set to 1. */
	Tja110xEcr.TJA1101_CFEN = TJA1101_CFEN_CONFIGURATION_REGISTER_ACCESS_ENABLED;
	Tja110xEcr.TJA1101_WR   = TJA1101_WR_NO_WAKEUP_SIGNAL_TO_BE_SENT;
	if (TJA110x_setExtendedControl(&Tja110xEcr, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	/* Reading CONFIG_1 register. */
	if (TJA110x_getConfiguration1(&Tja110xCfg1Reg, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}
	Tja110xCfg1Reg.TJA1101_MS   		= TJA1101_MS_PHY_CONFIGURED_AS_MASTER;
	Tja110xCfg1Reg.TJA1101_REACT_RE_WU 	= TJA1101_REACT_REMOTE_WAKEUP;
	Tja110xCfg1Reg.TJA1101_REACT_LO_WU 	= TJA1101_REACT_LOCAL_WAKEUP;
	Tja110xCfg1Reg.TJA1101_MIIM 		= TJA1101_MIIM_MII_MODE_ENABLED;
	Tja110xCfg1Reg.TJA1101_APD  		= TJA1101_APD_AUTONOMOUS_POWER_DOWN_DISABLED;
	/* Re-write CONFIG_1 register. */
	if (TJA110x_setConfiguration1(&Tja110xCfg1Reg, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	/* Reading CONFIG_2 register to get PHY device address. */
	if (TJA110x_getConfiguration2(&Tja110xCfg2Reg, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}
	TJA1101_AttributeInfo.PhyAddress = (uint8_t)Tja110xCfg2Reg.TJA1101_PHYAD;

	/* Reading COMMON CONFIG register. */
	if (TJA110x_getCommonConfiguration(&Tja110xCommonCfgReg, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}
	Tja110xCommonCfgReg.TJA1101_AUTO_OP  = AUTONOMOUS_OPERATION;
	Tja110xCommonCfgReg.TJA1101_CLK_MODE = CLK_25MHZ_XTAL_NOCLK_AT_CLKINOUT;
	Tja110xCommonCfgReg.TJA1101_LDO_MODE = INTERNAL_1V8_LDO_ENABLED;
	/* Rewrite COMMON CONFIG register. */
	if (TJA110x_setCommonConfiguration(&Tja110xCommonCfgReg, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	/* Re-write ECR register CONFIG_EN bit to 0 and disable configuration register accessable. */
	Tja110xEcr.TJA1101_CFEN = TJA1101_CFEN_CONFIGURATION_REGISTER_ACCESS_DISABLED;
	if (TJA110x_setExtendedControl(&Tja110xEcr, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	delayCount = 0;

	/* Wait TJA1101 PLL locked and stable. */
	do
	{
		if (TJA110x_getGeneralStatus(&Tja110xGenStatus, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
		{
			TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
			return (0);
		}

		delayCount++;
	}
	while ((Tja110xGenStatus.TJA1101_PLLL != TJA1101_PLLL_PLL_STABLE_AND_LOCKED) && (delayCount < 100000000U));

	if (delayCount >= 100000000U)
	{
		TJA1101_AttributeInfo.InitStat = TJA1101_Init_Failed;
		return (0);
	}

	TJA1101_AttributeInfo.InitStat = TJA1101_Init_Success;
	return (1);
}

/*
@brief
@details
@para
@return
*/
int PHY_TJA1101_GetCurrentStatus(void)
{
	uint8_t dummyCnt = 0;
	TJA110x_Communication_Status_Reg_t CommStat;
	TJA110x_External_Status_Reg_t PhyExtStat;

	if (TJA1101_AttributeInfo.InitStat == TJA1101_Init_Success)
	{
		if (TJA110x_getCommunicationStatus(&CommStat, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
		{
			/* Execute several empty operation to enable system can set breakpoint here when in debug mode. */
			while (dummyCnt < 5U)dummyCnt++;

			return (0);
		}
		else
		{
			TJA1101_AttributeInfo.LinkStat    = (PHY_TJA1101_LinkupStatus_t)CommStat.TJA1101_LU;
			TJA1101_AttributeInfo.PhySQILevel = (PHY_TJA1101_SQI_Level_t)CommStat.TJA1101_SQI;
			TJA1101_AttributeInfo.PhyMode	  = (PHY_TJA1101_ModeState_t)CommStat.TJA1101_PHYS;
		}

		if (TJA110x_getExternalStatus(&PhyExtStat, PHY_TJA1101_ADDRESS) != NXP_TJA1100_SUCCESS)
		{
			/* Execute several empty operation to enable system can set breakpoint here when in debug mode. */
			while (dummyCnt < 5U)dummyCnt++;

			return (0);
		}
		else
		{
			/* Execute several empty operation to enable system can set breakpoint here when in debug mode. */
			while (dummyCnt < 5U)dummyCnt++;

			return (1);
		}
	}

	return (0);
}

/*
@brief
@details
@para
@return
*/
int PHY_TJA1101_SendEthernetFrame(void)
{
	int result = 0;

	/*MAC frame is an ARP message saying "Who has 192.168.10.3? Tell 192.168.10.10"*/
	const Eth_DataType txMacFrame[LENGTH_FRAME] = {
        											0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,			/*Destination Address*/
													0x66,0x55,0x44,0x33,0x22,0x11,			/*Source Address(config in tresos)*/
													0x08,0x06,					  			/*Frametype_ARP*/
													0x00,0x01,0x08,0x00,0x06,0x04,0x00,0x01,/*Payload*/
													0x66,0x55,0x44,0x33,0x22,0x11,			/*Payload*/
													0xc0,0xa8,0x0a,0x0a,					/*Payload*/
													0x00,0x00,0x00,0x00,0x00,0x00,			/*Payload*/
													0xc0,0xa8,0x0a,0x03						/*Payload*/
                                            	  };

	if (TJA1101_AttributeInfo.InitStat == TJA1101_Init_Success)
	{
		if ((TJA1101_AttributeInfo.LinkStat == TJA1101_Linkup_Success) && (TJA1101_AttributeInfo.PhySQILevel >= SQI_CLASS_E))
		{
			result = Ethernet_SendFrameData(txMacFrame, LENGTH_FRAME);
		}
	}

	return (result);
}


