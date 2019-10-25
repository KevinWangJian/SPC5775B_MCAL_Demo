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



#define  CTRL_INDEX		(0)
#define  CFG_INDEX		(0)

#define TXCOMFIRMATION_OFF	0
#define TXCOMFIRMATION_ON  	1
#define LENGTH_FRAME 		42
#define LENGTH_PAYLOAD 		28
#define OFFSET_PAYLOAD		14
#define OFFSET_FRAMETYPE	12
#define NUM_PHY_REG 		30
#define RX_NUM_MAX			1500
#define LENGTH_MAC_ADD		6
#define PHY_REG_ECR			17
#define PHY_RGE_CR1			18



#define  SIU_FECCR_REG_ADDR		(SIU_BASEADDR + 0x9E0)


void Ethernet_Init(void);



#ifdef __cplusplus
}
#endif
#endif /* USERS_ETHCOMM_H_ */
