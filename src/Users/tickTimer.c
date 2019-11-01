/*
 * tickTimer.c
 *
 *  Created on: 2019Äê10ÔÂ21ÈÕ
 *      Author: admin
 */

#include "tickTimer.h"
#include "Dio.h"


volatile uint32_t tickTimerCount = 0;

volatile uint32_t CommUpdateEvent = 0;

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
static void User_Func(void)
{
	static uint16_t delayCnt = 0;

	delayCnt++;

	if (delayCnt >= 100U)
	{
		delayCnt = 0;

		Dio_FlipChannel(DioConf_DioChannel_LED1_DRIVE_EN);
		Dio_FlipChannel(DioConf_DioChannel_LED2_DRIVE_EN);

		CommUpdateEvent = 1;
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

	User_Func();
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



