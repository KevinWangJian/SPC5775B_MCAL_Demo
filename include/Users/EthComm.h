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

#define  SIU_FECCR_REG_ADDR		(SIU_BASEADDR + 0x9E0)


void Ethernet_Init(void);



#ifdef __cplusplus
}
#endif
#endif /* USERS_ETHCOMM_H_ */
