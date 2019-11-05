/*
 * IntCtrl.c
 *
 *  Created on: 2019Äê10ÔÂ21ÈÕ
 *      Author: admin
 */

#include "IntCtrl.h"


/*
@brief
@details
@para
@return
*/
void InterruptController_Init(void)
{
	uint32_t temp;

	temp = REG_READ32(INTC_MCR_ADDR);
	temp |= ((uint32_t)1 << 8) | ((uint32_t)1 << 0);		/* HVEN set to 1, hardware vector mode. */
	REG_WRITE32(INTC_MCR_ADDR, temp);

	REG_WRITE32(INTC_CPR_PRC0_ADDR, 0);						/* Current priority configure to 0(Lowest). */
	REG_WRITE32(INTC_CPR_PRC1_ADDR, 0);

	REG_WRITE8(INTC_PSR_ADDR(301), 0x07);     				/* Gpt_PIT_0_TIMER_0_ISR */

	REG_WRITE8(INTC_PSR_ADDR(348), 0x07);					/* Can_IsrCombined_IL0 (M_CAN0/M_CAN1 Line0/Line1) */

	REG_WRITE8(INTC_PSR_ADDR(194), 0x07);					/* Eth_TxIrqHdlr_0 */
	REG_WRITE8(INTC_PSR_ADDR(195), 0x0A);					/* Eth_RxIrqHdlr_0 */

	ASM_KEYWORD("wrteei 1");
}



