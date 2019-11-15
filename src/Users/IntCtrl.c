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

	REG_WRITE8(INTC_PSR_ADDR(301), 0x0F);     				/* Gpt_PIT_0_TIMER_0_ISR */

	REG_WRITE8(INTC_PSR_ADDR(155), 0x07);					/* Can_IsrFCA_MB_00 (FlexCAN_A_MB0) */
	REG_WRITE8(INTC_PSR_ADDR(156), 0x07);					/* Can_IsrFCA_MB_01 (FlexCAN_A_MB1) */
	REG_WRITE8(INTC_PSR_ADDR(157), 0x07);					/* Can_IsrFCA_MB_02 (FlexCAN_A_MB2) */
	REG_WRITE8(INTC_PSR_ADDR(158), 0x07);					/* Can_IsrFCA_MB_03 (FlexCAN_A_MB3) */

	REG_WRITE8(INTC_PSR_ADDR(283), 0x06);					/* Can_IsrFCB_MB_00 (FlexCAN_B_MB0) */
	REG_WRITE8(INTC_PSR_ADDR(284), 0x06);					/* Can_IsrFCB_MB_01 (FlexCAN_B_MB1) */

	REG_WRITE8(INTC_PSR_ADDR(176), 0x05);					/* Can_IsrFCC_MB_00 (FlexCAN_C_MB0) */
	REG_WRITE8(INTC_PSR_ADDR(177), 0x05);					/* Can_IsrFCC_MB_01 (FlexCAN_C_MB1) */

	REG_WRITE8(INTC_PSR_ADDR(311), 0x04);					/* Can_IsrFCD_MB_00 (FlexCAN_D_MB0) */
	REG_WRITE8(INTC_PSR_ADDR(312), 0x04);					/* Can_IsrFCD_MB_01 (FlexCAN_D_MB1) */

	REG_WRITE8(INTC_PSR_ADDR(348), 0x0A);					/* Can_IsrCombined_IL0 (M_CAN0/M_CAN1 Line0/Line1) */

	REG_WRITE8(INTC_PSR_ADDR(194), 0x0D);					/* Eth_TxIrqHdlr_0 */
	REG_WRITE8(INTC_PSR_ADDR(195), 0x0E);					/* Eth_RxIrqHdlr_0 */

	ASM_KEYWORD("wrteei 1");
}



