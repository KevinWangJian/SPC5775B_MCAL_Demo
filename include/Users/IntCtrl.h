/*
 * IntCtrl.h
 *
 *  Created on: 2019Äê10ÔÂ21ÈÕ
 *      Author: admin
 */

#ifndef USERS_INTCTRL_H_
#define USERS_INTCTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
#include "typedefs.h"
#include "Std_Types.h"
#include "StdRegMacros.h"
#include "Reg_eSys.h"


#define  INTC_MCR_ADDR			(INTC_BASEADDR + 0x0)

#define  INTC_CPR_PRC0_ADDR		(INTC_BASEADDR + 0x8)
#define  INTC_CPR_PRC1_ADDR		(INTC_BASEADDR + 0xC)

#define  INTC_PSR_ADDR(n)       (INTC_BASEADDR + ((uint32)0x40u) + (1*n))



void InterruptController_Init(void);


#ifdef __cplusplus
}
#endif
#endif /* USERS_INTCTRL_H_ */
