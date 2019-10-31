/*
 * EthComm.h
 *
 *  Created on: 2019Äê10ÔÂ22ÈÕ
 *      Author: admin
 */

#ifndef USERS_ETHCOMM_H_
#define USERS_ETHCOMM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
#include "typedefs.h"
#include "Std_Types.h"
#include "Reg_eSys.h"
#include "Eth_GeneralTypes.h"
#include "Platform_Types.h"


#define  CTRL_INDEX				(0)
#define  CFG_INDEX				(0)

#define  TXCOMFIRMATION_OFF		(0)
#define  TXCOMFIRMATION_ON  	(1)
#define  LENGTH_MAC_ADD			(6)
#define  LENGTH_FRAME 			(42)
#define  LENGTH_PAYLOAD 		(28)
#define  OFFSET_PAYLOAD			(14)
#define  OFFSET_FRAMETYPE		(12)

#define  ETH_RX_FRAME_BUF_SIZE	(100U)
#define  ETH_MAX_PAYLOAD_SIZE	(1500U)

#define  SIU_FECCR_REG_ADDR		(SIU_BASEADDR + 0x9E0)



typedef struct
{
	boolean  		FrameValid;
	boolean 		IsBroadcast;
	Eth_FrameType 	FrameType;
	uint16			DataLength;
	Eth_DataType*   ptrDataBuffer;
	uint8*			ptrSrcMacAddr;
//	uint8*			ptrDestMacAddr;
}EthernetFrameData_Def_t;


typedef struct
{
	uint16  WritePtr;
	uint16  ReadPtr;
	EthernetFrameData_Def_t RxFrameBuf[ETH_RX_FRAME_BUF_SIZE];
}EthernetRxFrameBuffer_t;



void Ethernet_Init(void);

int Ethernet_SendFrameData(const Eth_DataType* txDataBuf, uint16 txLength);

int Ethernet_WriteRxFrameToBuffer(EthernetFrameData_Def_t* pRxframeData);


#ifdef __cplusplus
}
#endif
#endif /* USERS_ETHCOMM_H_ */
