/*
 * tickTimer.h
 *
 *  Created on: 2019Äê10ÔÂ21ÈÕ
 *      Author: admin
 */

#ifndef USERS_TICKTIMER_H_
#define USERS_TICKTIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
#include "typedefs.h"
#include "Std_Types.h"
#include "Gpt.h"


#define  TICKTIMER_PERIOD_1MS	(40000U)


extern volatile uint32_t CommUpdateEvent;
extern volatile uint32_t systemGlobalTickCount;


void SystemTickTimer_Init(void);
void SystemDelay_Ms(uint32_t timeMs);

#ifdef __cplusplus
}
#endif
#endif /* USERS_TICKTIMER_H_ */
