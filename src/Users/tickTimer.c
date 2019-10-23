/*
 * tickTimer.c
 *
 *  Created on: 2019Äê10ÔÂ21ÈÕ
 *      Author: admin
 */

#include "tickTimer.h"


volatile uint32_t tickTimerCount = 0;


/*
@brief
@details
@para
@return
*/
void SystemTickTimer_Init(void)
{
	Gpt_Init(&GptChannelConfigSet_0);

	Gpt_EnableNotification(0);

	Gpt_StartTimer(0, TICKTIMER_PERIOD_1MS);
}


/*
@brief
@details
@para
@return
*/
static void SystemTickTimerCount_Decrement(void)
{
	if (tickTimerCount != 0)
	{
		tickTimerCount--;
	}
}


/*
@brief
@details
@para
@return
*/
void Callback_func(void)
{
	SystemTickTimerCount_Decrement();
}

/*
@brief
@details
@para
@return
*/
void SystemDelay_Ms(uint32_t timeMs)
{
	SuspendAllInterrupts();

	tickTimerCount = timeMs;

	ResumeAllInterrupts();

	while (tickTimerCount != 0){;}
}



