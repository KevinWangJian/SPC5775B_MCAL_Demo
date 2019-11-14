/*=================================================================================================*/
/**
*   @file    Startup_vle.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Sample_app - Startup file for PowerPC VLE.
*   @details Startup file for PowerPC VLE.
*
*   @addtogroup BUILD_ENV
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : 
*   Dependencies         : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC5777C_MCAL_1_0_0_RTM_ASR_REL_4_0_REV_0003_20160807
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/************************************************************************/
/* Autosar synopsis of startup code (See MCU Specification):            */
/*                                                                      */
/*   Before the MCU driver can be initialized, a basic initialization   */
/*   of the MCU has to be executed. This MCU specific initialization is */
/*   typically executed in a start-up code. The start-up code of the    */
/*   MCU shall be executed after power up and any kind of micro-        */
/*   controller reset. It shall perform very basic and microcontroller  */
/*   specific start-up initialization and shall be kept short, because  */
/*   the MCU clock and PLL is not yet initialized. The start-up code    */
/*   shall cover MCU specific initialization, which is not part of      */
/*   other MCU services or other MCAL drivers. The following steps      */
/*   summarizes basic functionality which shall be included in the      */
/*   start-up code. They are listed for guidance, because some          */
/*   functionality might not be supported. No code will be found in     */
/*   case.                                                              */
/************************************************************************/
#include "typedefs.h"
/*#include "sys_init.h"*/
#include "Mcal.h"


#define S_INTC_BASEADDR        0xFFF48000UL
#define S_INTC_MCR             (S_INTC_BASEADDR + ((unsigned long)0x0u))
#define S_INTC_MCR_VTES_4BYTES ((unsigned long)0x00000000)    /* Vector Table Entry Size - 4 bytes */
#define S_INTC_MCR_HVEN_ON     ((unsigned long)0x00000101)    /* Hardware Vector ENable - On */
#define S_INTC_CPR0           (S_INTC_BASEADDR + ((unsigned long)0x08)) /* Current Priority Register */
#define S_INTC_CPR1           (S_INTC_BASEADDR + ((unsigned long)0x0C)) /* Current Priority Register */

#define S_SIU_RSTVEC1         0xC3F909B0UL

#define S_REG_WRITE32(address, value)       (*(volatile unsigned long*)(address) = (value))

extern uint32 __RAM_NO_CACHEABLE_START; 
extern uint32 __RAM_NO_CACHEABLE_END;
extern uint32 __RAM_CACHEABLE_START;
extern uint32 __RAM_CACHEABLE_END;  

                   
/* Function Definitions */
extern int main(void);

#ifdef CCOV_ENABLE
/* code coverage is requested */
extern void ccov_main(void);
#endif

#ifdef ENABLE_RCHECK
/* initialization for the runtime checks memory space */
void init_runtime_check(void);
#endif /* ENABLE_RCHECK */

void StartupCode(void)
{
/*****************************************************/
/* Skip normal entry point as nothing is initialized */
/*****************************************************/
 
/* entry point for core2  - set by debugger to allow attaching to it*/  
    ASM_KEYWORD(".globl _start2");
    ASM_KEYWORD(".globl __start2");
    ASM_KEYWORD(".align 4");
    ASM_KEYWORD("_start2:");
    ASM_KEYWORD("__start2:");
    
    ASM_KEYWORD("while_2:");
    ASM_KEYWORD("se_b while_2");
    
/* Program start point */       
    ASM_KEYWORD(".globl _start");
    ASM_KEYWORD(".globl __start");
    ASM_KEYWORD(".align 4");
    ASM_KEYWORD("_start:");
    ASM_KEYWORD("__start:");

    ASM_KEYWORD(" xor  r0, r0, r0");
    ASM_KEYWORD(" xor  r1, r1, r1");
    ASM_KEYWORD(" xor  r2, r2, r2");
    ASM_KEYWORD(" xor  r3, r3, r3");
    ASM_KEYWORD(" xor  r4, r4, r4");
    ASM_KEYWORD(" xor  r5, r5, r5");
    ASM_KEYWORD(" xor  r6, r6, r6");
    ASM_KEYWORD(" xor  r7, r7, r7");
    ASM_KEYWORD(" xor  r8, r8, r8");
    ASM_KEYWORD(" xor  r9, r9, r9");
    ASM_KEYWORD(" xor  r10, r10, r10");
    ASM_KEYWORD(" xor  r11, r11, r11");
    ASM_KEYWORD(" xor  r12, r12, r12");
    ASM_KEYWORD(" xor  r13, r13, r13");
    ASM_KEYWORD(" xor  r14, r14, r14");
    ASM_KEYWORD(" xor  r15, r15, r15");
    ASM_KEYWORD(" xor  r16, r16, r16");
    ASM_KEYWORD(" xor  r17, r17, r17");
    ASM_KEYWORD(" xor  r18, r18, r18");
    ASM_KEYWORD(" xor  r19, r19, r19");
    ASM_KEYWORD(" xor  r20, r20, r20");
    ASM_KEYWORD(" xor  r21, r21, r21");
    ASM_KEYWORD(" xor  r22, r22, r22");
    ASM_KEYWORD(" xor  r23, r23, r23");
    ASM_KEYWORD(" xor  r24, r24, r24");
    ASM_KEYWORD(" xor  r25, r25, r25");
    ASM_KEYWORD(" xor  r26, r26, r26");
    ASM_KEYWORD(" xor  r27, r27, r27");
    ASM_KEYWORD(" xor  r28, r28, r28");
    ASM_KEYWORD(" xor  r29, r29, r29");
    ASM_KEYWORD(" xor  r30, r30, r30");
    ASM_KEYWORD(" xor  r31, r31, r31");
 

/*******************************************************************/
/* Freescale Guidance 1 - Init registers to avoid lock-step issues */
/* N/A                                                             */
/*******************************************************************/

/*******************************************************************/
/* Freescale Guidance 2 - MMU Initialization for CPU               */
/******************************************************************/
/* Note 1: Explicitly configure MMU here because MPC5676R BAM does not cover       */ 
/* all available SRAM or PBRIDGE spaces when it sets up the MMU. Also, when        */
/* core 1 is running this same code it may not have executed BAM at all.           */
/*                                                                                 */
/* Note 2: configure TLB1 and TLB3 first before TLB0 since core 1 may be running   */
/* from RAM or Flash with the default 4k TLB0 page out of reset.                   */
/*                                                                                 */
/* TLB1 = internal flash @ 0x0000_0000, VLE    Write-Through Cache                                    */
    ASM_KEYWORD(" e_lis r3,0x1001  ");   
    ASM_KEYWORD(" mtspr mas0,r3    ");
    ASM_KEYWORD(" e_lis r3,0xC000  ");
    ASM_KEYWORD(" e_or2i r3,0x0700 ");
    ASM_KEYWORD(" mtspr mas1,r3    ");
    ASM_KEYWORD(" e_lis r3,0x0000  ");
    ASM_KEYWORD(" e_or2i r3,0x0020 ");
    ASM_KEYWORD(" mtspr mas2,r3    ");
    ASM_KEYWORD(" e_lis r3,0x0000  ");
    ASM_KEYWORD(" e_or2i r3,0x003F ");
    ASM_KEYWORD(" mtspr mas3,r3    ");
    ASM_KEYWORD(" msync            ");     /* Synchronize in case running from flash */
    ASM_KEYWORD(" tlbwe            ");
    ASM_KEYWORD(" se_isync         ");     /* Synchronize in case running from flash  */

/* TLB3 = internal SRAM @ 0x4000_0000, VLE,  Write-Through Cache */
    ASM_KEYWORD(" e_lis r3,0x1003  ");
    ASM_KEYWORD(" mtspr mas0,r3    ");
    ASM_KEYWORD(" e_lis r3,0xC000  ");
    ASM_KEYWORD(" e_or2i 3,0x0400  ");
    ASM_KEYWORD(" mtspr mas1,r3    ");
    ASM_KEYWORD(" e_lis r3,0x4000  ");
    ASM_KEYWORD(" e_or2i r3,0x0020 ");
    ASM_KEYWORD(" mtspr mas2,r3    ");
    ASM_KEYWORD(" e_lis r3,0x4000  ");
    ASM_KEYWORD(" e_or2i r3,0x003F ");
    ASM_KEYWORD(" mtspr mas3,r3    ");
    ASM_KEYWORD(" msync            ");    /* Synchronize in case running from SRAM */
    ASM_KEYWORD(" tlbwe            ");
    ASM_KEYWORD(" se_isync         ");    /* Synchronize in case running from SRAM */
    
    /* TLB4 = internal SRAM @ 0x4000_4000, NO-VLE, Cache Inhibited  */
    ASM_KEYWORD(" e_lis r3,0x1004  ");
    ASM_KEYWORD(" mtspr mas0,r3    ");
    ASM_KEYWORD(" e_lis r3,0xC000  ");
    ASM_KEYWORD(" e_or2i 3,0x0400  ");
    ASM_KEYWORD(" mtspr mas1,r3    ");
    ASM_KEYWORD(" e_lis r3,0x4004  ");
    ASM_KEYWORD(" e_or2i r3,0x0028 ");
    ASM_KEYWORD(" mtspr mas2,r3    ");
    ASM_KEYWORD(" e_lis r3,0x4004  ");
    ASM_KEYWORD(" e_or2i r3,0x003F ");
    ASM_KEYWORD(" mtspr mas3,r3    ");
    ASM_KEYWORD(" msync            ");    /* Synchronize in case running from SRAM */
    ASM_KEYWORD(" tlbwe            ");
    ASM_KEYWORD(" se_isync         ");    /* Synchronize in case running from SRAM */
    

/* TLB0 = pbridgeB @ 0xFFE0_0000, Cache inhibited, Guarded */
    ASM_KEYWORD(" e_lis r3,0x1000 ");  
    ASM_KEYWORD(" mtspr mas0,r3   ");
    ASM_KEYWORD(" e_lis r3,0xC000 ");
    ASM_KEYWORD(" e_or2i r3,0x0580");
    ASM_KEYWORD(" mtspr mas1,r3   ");
    ASM_KEYWORD(" e_lis r3,0xFFE0 ");
    ASM_KEYWORD(" e_or2i r3,0x000A");
    ASM_KEYWORD(" mtspr mas2,r3   ");
    ASM_KEYWORD(" e_lis r3,0xFFE0 ");
    ASM_KEYWORD(" e_or2i r3,0x003F");
    ASM_KEYWORD(" mtspr mas3,r3   ");
    ASM_KEYWORD(" tlbwe           ");

/* TLB2 = external bus @ 0x2000_0000, VLE */
    ASM_KEYWORD(" e_lis r3,0x1002  ");
    ASM_KEYWORD(" mtspr mas0,r3    ");
    ASM_KEYWORD(" e_lis r3,0xC000  ");
    ASM_KEYWORD(" e_or2i r3,0x0700 ");
    ASM_KEYWORD(" mtspr mas1,r3    ");
    ASM_KEYWORD(" e_lis r3,0x2000  ");
    ASM_KEYWORD(" e_or2i r3,0x0020 ");
    ASM_KEYWORD(" mtspr mas2,r3    ");
    ASM_KEYWORD(" e_lis r3,0x0000  ");
    ASM_KEYWORD(" e_or2i r3,0x003F ");
    ASM_KEYWORD(" mtspr mas3,r3    ");
    ASM_KEYWORD(" tlbwe            ");

/* TLB5 = pbridgeA @ 0xC3E0_0000, Cache inhibited, Guarded */
    ASM_KEYWORD("e_lis r3,0x1005   ");
    ASM_KEYWORD("mtspr mas0,r3     ");
    ASM_KEYWORD("e_lis r3,0xC000   ");
    ASM_KEYWORD("e_or2i r3,0x0580  ");
    ASM_KEYWORD("mtspr mas1,r3     ");
    ASM_KEYWORD("e_lis r3,0xC3E0   ");
    ASM_KEYWORD("e_or2i r3,0x000A  ");
    ASM_KEYWORD("mtspr mas2,r3     ");
    ASM_KEYWORD("e_lis r3,0xC3E0   ");
    ASM_KEYWORD("e_or2i r3,0x003F  ");
    ASM_KEYWORD("mtspr mas3,r3     ");
    ASM_KEYWORD("tlbwe             ");    
/******************************************************************/
/* Autosar Guidance 1 - The start-up code shall initialize the    */
/* base addresses for interrupt and trap vector tables. These base*/
/* addresses are provided as configuration parameters or          */
/* linker/locator setting.                                        */
/******************************************************************/
    /* Initialize IVPR register to address of Interrupt Vector Table */
    ASM_KEYWORD (" e_lis r5, __IV_ADDR@h ");
    ASM_KEYWORD (" e_or2i  r5,__IV_ADDR@l ");
    ASM_KEYWORD (" mtIVPR r5");
    ASM_KEYWORD (" se_mr   r0, r31 ");

    ASM_KEYWORD(" e_lis r5,IVOR0_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5,IVOR0_Handler@l ");
    ASM_KEYWORD(" mtspr   400, r5    ");
    
    ASM_KEYWORD(" e_lis r5,IVOR1_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5,IVOR1_Handler@l ");
    ASM_KEYWORD(" mtspr   401, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR2_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR2_Handler@l ");
    ASM_KEYWORD(" mtspr   402, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR3_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR3_Handler@l ");
    ASM_KEYWORD(" mtspr   403, r5    ");
    
    ASM_KEYWORD(" e_lis r5, __IV_ADDR@h  ");
    ASM_KEYWORD(" e_or2i r5, __IV_ADDR@l ");
    ASM_KEYWORD(" mtspr   404, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR5_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR5_Handler@l ");
    ASM_KEYWORD(" mtspr   405, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR6_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR6_Handler@l ");
    ASM_KEYWORD(" mtspr   406, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR7_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR7_Handler@l ");
    ASM_KEYWORD(" mtspr   407, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR8_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR8_Handler@l ");
    ASM_KEYWORD(" mtspr   408, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR9_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR9_Handler@l ");
    ASM_KEYWORD(" mtspr   409, r5    ");
    
    ASM_KEYWORD(" e_lis r5, IVOR10_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR10_Handler@l ");
    ASM_KEYWORD(" mtspr   410, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR11_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR11_Handler@l ");
    ASM_KEYWORD(" mtspr   411, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR12_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR12_Handler@l ");
    ASM_KEYWORD(" mtspr   412, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR13_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR13_Handler@l ");
    ASM_KEYWORD(" mtspr   413, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR14_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR14_Handler@l ");
    ASM_KEYWORD(" mtspr   414, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR15_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR15_Handler@l ");
    ASM_KEYWORD(" mtspr   415, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR32_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR32_Handler@l ");
    ASM_KEYWORD(" mtspr   528, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR33_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR33_Handler@l ");
    ASM_KEYWORD(" mtspr   529, r5     ");
    
    ASM_KEYWORD(" e_lis r5, IVOR34_Handler@h  ");
    ASM_KEYWORD(" e_or2i r5, IVOR34_Handler@l ");
    ASM_KEYWORD(" mtspr   530, r5     ");
    
    /* define MSR mask to enable Machine Check and Exception / IRQ */
    ASM_KEYWORD(" .equ    MSR_Mask, 0x00009000 ");
    ASM_KEYWORD(" mfmsr   r5 ");
    ASM_KEYWORD(" e_lis   r6, MSR_Mask@h ");
    ASM_KEYWORD(" e_or2i  r6, MSR_Mask@l ");
    ASM_KEYWORD(" se_or   r5, r6 ");
    ASM_KEYWORD(" mtmsr   r5 ");
    ASM_KEYWORD(" se_isync"); 

/******************************************************************/
/* Autosar Guidance 2 - The start-up code shall initialize the    */
/* interrupt stack pointer, if an interrupt stack is              */
/* supported by the MCU. The interrupt stack pointer base address */
/* and the stack size are provided as configuration parameter or  */
/* linker/locator setting.                                        */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 3 - The start-up code shall initialize the    */
/* user stack pointer. The user stack pointer base address and    */
/* the stack size are provided as configuration parameter or      */
/* linker/locator setting.                                        */
/******************************************************************/
    ASM_KEYWORD(" e_lis   r1, __SP_INIT@h");
    ASM_KEYWORD(" e_or2i    r1, __SP_INIT@l");

/******************************************************************/
/* Autosar Guidance 4 - If the MCU supports context save          */
/* operation, the start-up code shall initialize the memory which */
/* is used for context save operation. The maximum amount of      */
/* consecutive context save operations is provided as             */
/* configuration parameter or linker/locator setting.             */
/*                                                                */
/******************************************************************/
/******************************************************************/
/* Autosar Guidance 11 - The start-up code shall enable           */
/* protection mechanisms for special function registers(SFR’s),   */
/* if supported by the MCU.                                       */
/* N/A - will be handled by Autosar OS                            */
/******************************************************************/
/* Setup the AIPS bus bridge and its protection features. Avoid that any access  */
/* to a peripheral fails due to protection settings  For this purpose remove any */
/* protection feature that might have been defined by default settings.          */
/* To do so, we write b'0111 (0x7) into every protection field MPROT of the      */

/* AIPS_A_MPROT register, which will setup all 8 master ports accordingly.         */
/*  The meaning of these four bits is as follows:                                */
/*   0 - Master Buffer Writes: no (Write accesses are not bufferable)            */
/*   1 - Master Trusted for Reads                                                */
/*   1 - Master Trusted for Writes                                               */
/*   1 - Master Priviledge Level: accesses are not forced to user-mode           */
/* NOTE: we do only setup the masters M0-M7, M8-M15 are not modified at all.     */
   
    ASM_KEYWORD(" .equ AIPS_A_MPRA, 0xFFF00000 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_MPRA@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_MPRA@l ");
    ASM_KEYWORD(" e_lis   r5, 0x77777777@ha ");
    ASM_KEYWORD(" e_or2i  r5, 0x77777777@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");
    ASM_KEYWORD(" e_li r5, 0 ");
    
    ASM_KEYWORD(" .equ AIPS_A_MPRB, 0xFFF00004 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_MPRB@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_MPRB@l ");
    ASM_KEYWORD(" e_lis   r5, 0x77777777@ha ");
    ASM_KEYWORD(" e_or2i  r5, 0x77777777@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");
    ASM_KEYWORD(" e_li r5, 0 ");
    
    
/* Allow non-priviledged access to all peripherals (on and off-platform). This is */
/* achieved by modifying the PACR and OPACR registers in the AIPS.                */
/* To do so, we write b'0000 (0x0) into every peripheral access control reg.      */
/* The meaning of these four bits is as follows:                                  */
/*   0 - Buffer Writes: no                                                        */
/*   0 - Supervisor Protect: periph. doesn't require supervisor priviledge level  */
/*   0 - Write Protect: no (peripheral allows write accesses)                     */
/*   0 - Trusted Protect: no (accesses from an untrusted master allowed)          */

    ASM_KEYWORD(" .equ AIPS_A_PACRA, 0xFFF00020 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_PACRA@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_PACRA@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");

    ASM_KEYWORD(" .equ AIPS_A_PACRB, 0xFFF00024 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_PACRB@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_PACRB@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");
     
    ASM_KEYWORD(" .equ AIPS_A_PACRC, 0xFFF00028 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_PACRC@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_PACRC@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) "); 
    
    ASM_KEYWORD(" .equ AIPS_A_PACRD, 0xFFF0002C ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_PACRD@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_PACRD@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");
    
    ASM_KEYWORD(" .equ AIPS_A_OPACRA, 0xFFF00040 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRA@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRA@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");  
  
    ASM_KEYWORD(" .equ AIPS_A_OPACRB, 0xFFF00044 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRB@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRB@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");  
    
    ASM_KEYWORD(" .equ AIPS_A_OPACRC, 0xFFF00048 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRC@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRC@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) "); 
    
    ASM_KEYWORD(" .equ AIPS_A_OPACRD, 0xFFF0004C ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRD@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRD@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");   
    
    ASM_KEYWORD(" .equ AIPS_A_OPACRE, 0xFFF00050 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRE@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRE@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");  
    
    ASM_KEYWORD(" .equ AIPS_A_OPACRF, 0xFFF00054 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRF@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRF@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");   
    
    ASM_KEYWORD(" .equ AIPS_A_OPACRG, 0xFFF00058 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRG@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRG@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");    
 
    ASM_KEYWORD(" .equ AIPS_A_OPACRH, 0xFFF0005C ");
    ASM_KEYWORD(" e_lis   r4, AIPS_A_OPACRH@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_A_OPACRH@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");    
    
 
/* AIPS_B_MPROT register, which will setup all 8 master ports accordingly.         */
/*  The meaning of these four bits is as follows:                                */
/*   0 - Master Buffer Writes: no (Write accesses are not bufferable)            */
/*   1 - Master Trusted for Reads                                                */
/*   1 - Master Trusted for Writes                                               */
/*   1 - Master Priviledge Level: accesses are not forced to user-mode           */
/* NOTE: we do only setup the masters M0-M7, M8-M15 are not modified at all.     */
   
    ASM_KEYWORD(" .equ AIPS_B_MPRA, 0xC3F00000 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_MPRA@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_MPRA@l ");
    ASM_KEYWORD(" e_lis   r5, 0x77777777@ha ");
    ASM_KEYWORD(" e_or2i  r5, 0x77777777@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4)");
    ASM_KEYWORD(" e_li r5, 0" );
    
    ASM_KEYWORD(" .equ AIPS_B_MPRB, 0xC3F00004 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_MPRB@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_MPRB@l ");
    ASM_KEYWORD(" e_lis   r5, 0x77777777@ha ");
    ASM_KEYWORD(" e_or2i  r5, 0x77777777@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4)");
    ASM_KEYWORD(" e_li r5, 0" );
    
/* Allow non-priviledged access to all peripherals (on and off-platform). This is */
/* achieved by modifying the PACR and OPACR registers in the AIPS.                */
/* To do so, we write b'0000 (0x0) into every peripheral access control reg.      */
/* The meaning of these four bits is as follows:                                  */
/*   0 - Buffer Writes: no                                                        */
/*   0 - Supervisor Protect: periph. doesn't require supervisor priviledge level  */
/*   0 - Write Protect: no (peripheral allows write accesses)                     */
/*   0 - Trusted Protect: no (accesses from an untrusted master allowed)          */

    ASM_KEYWORD(" .equ AIPS_B_PACRA, 0xC3F00020 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_PACRA@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_PACRA@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");

    ASM_KEYWORD(" .equ AIPS_B_PACRB, 0xC3F00024 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_PACRB@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_PACRB@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");
     
    ASM_KEYWORD(" .equ AIPS_B_PACRC, 0xC3F00028 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_PACRC@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_PACRC@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) "); 
    
    ASM_KEYWORD(" .equ AIPS_B_PACRD, 0xC3F0002C ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_PACRD@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_PACRD@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");
   
    ASM_KEYWORD(" .equ AIPS_B_OPACRA, 0xC3F00040 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRA@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRA@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");  
  
    ASM_KEYWORD(" .equ AIPS_B_OPACRB, 0xC3F00044 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRB@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRB@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");  
    
    ASM_KEYWORD(" .equ AIPS_B_OPACRC, 0xC3F00048 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRC@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRC@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) "); 
    
    ASM_KEYWORD(" .equ AIPS_B_OPACRD, 0xC3F0004C ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRD@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRD@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");   
    
    ASM_KEYWORD(" .equ AIPS_B_OPACRE, 0xC3F00050 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRE@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRE@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");  
    
    ASM_KEYWORD(" .equ AIPS_B_OPACRF,  0xC3F00054 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRF@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRF@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");   
    
    ASM_KEYWORD(" .equ AIPS_B_OPACRG,  0xC3F00058 ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRG@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRG@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");    
 
    ASM_KEYWORD(" .equ AIPS_B_OPACRH,  0xC3F0005C ");
    ASM_KEYWORD(" e_lis   r4, AIPS_B_OPACRH@ha ");
    ASM_KEYWORD(" e_or2i  r4, AIPS_B_OPACRH@l ");
    ASM_KEYWORD(" e_stw   r5, 0(r4) ");    



/******************************************************************/
/* Autosar Guidance 5 - The start-up code shall ensure that the   */
/* MCU internal watchdog shall not be serviced until the watchdog */
/* is initialized from the MCAL watchdog driver. This can be      */
/* done for example by increasing the watchdog service time.      */
/*                                                                */
/******************************************************************/
#ifdef CORE_SET
 #if (CORE_SET==0)
    ASM_KEYWORD(" e_lis     r6,0xFFF3 ");
    ASM_KEYWORD(" e_or2i    r6,0x4010 ");
    ASM_KEYWORD(" e_li      r7,0xC520 ");
    ASM_KEYWORD(" se_stw    r7,0x0(r6)");
    ASM_KEYWORD(" e_li      r7,0xD928 ");
    ASM_KEYWORD(" se_stw    r7,0x0(r6)"); /* # Disengage soft-lock */

    ASM_KEYWORD(" e_lis     r6,0xFFF3 ");
    ASM_KEYWORD(" e_or2i    r6,0x4000 ");
    ASM_KEYWORD(" e_lis     r7,0xFF00 ");
    ASM_KEYWORD(" e_or2i    r7,0x0106 ");
    ASM_KEYWORD(" se_stw    r7,0x0(r6) "); /* # WEN = 0 */

    ASM_KEYWORD(" e_lis     r6,0xFFF3 ");
    ASM_KEYWORD(" e_or2i    r6,0x8010 ");
    ASM_KEYWORD(" e_li      r7,0xC520 ");
    ASM_KEYWORD(" se_stw    r7,0x0(r6)");
    ASM_KEYWORD(" e_li      r7,0xD928 ");
    ASM_KEYWORD(" se_stw    r7,0x0(r6)"); /* # Disengage soft-lock */

    ASM_KEYWORD(" e_lis     r6,0xFFF3 ");
    ASM_KEYWORD(" e_or2i    r6,0x8000 ");
    ASM_KEYWORD(" e_lis     r7,0xFF00 ");
    ASM_KEYWORD(" e_or2i    r7,0x0106 ");
    ASM_KEYWORD(" se_stw    r7,0x0(r6) "); /* # WEN = 0 */
  #endif
#endif  
    

/******************************************************************/
/* Autosar Guidance 7 - The start-up code shall initialize MCU    */
/* specific features of internal memory like memory protection.   */
/*                                                                */
/******************************************************************/
  /* Configure SSCM module ERROR register to generate bus abort 
       on any access to a peripheral slot that is not used on the
       device(PAE bit). Configure SSCM to generate bus abort on 
       illegal accesses to off-platform peripherals. 
    REG_WRITE16(SSCM_ERROR, SSCM_ERROR_PAE | SSCM_ERROR_RAE);
    */
    ASM_KEYWORD(" e_lis     r7,0xFFFF ");
    ASM_KEYWORD(" se_li     r6,0x3 ");
    ASM_KEYWORD(" e_or2i    r7,0x8006 ");
    ASM_KEYWORD(" se_sth    r6,0x0(r7) ");
/******************************************************************/
/* Autosar Guidance 8 - If external memory is used, the memory    */
/* shall be initialized in the start-up code. The start-up code   */
/* shall be prepared to support different memory configurations   */
/* depending on code location. Different configuration options    */
/* shall be taken into account for code execution from            */
/* external/internal memory.                                      */
/* N/A - external memory is not used                              */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 9 - The settings of the different memories    */
/* shall be provided to the start-up code as configuration        */
/* parameters.                                                    */
/* N/A - all memories are already configured                      */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 10 - In the start-up code a default           */
/* initialization of the MCU clock system shall be performed      */
/* including global clock prescalers.                             */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 12 - The start-up code shall initialize all   */
/* necessary write once registers or registers common to several  */
/* drivers where one write, rather than repeated writes, to the   */
/* register is required or highly desirable.                      */
/******************************************************************/
/* enable BTB */
#ifdef BTB_ENABLE
    ASM_KEYWORD(" e_li r3, 0x0211 ");
    ASM_KEYWORD(" mtspr 1013, r3  ");
    ASM_KEYWORD(" se_isync ");
#endif
/******************************************************************/
/* Autosar Guidance 13 - The start-up code shall initialize a     */
/* minimum amount of RAM in order to allow proper execution of    */
/* the MCU driver services and the caller of these services.      */
/******************************************************************/
/* MPC574xP - internal ram must be initialized for error correction*/
/******************************************************************/
#ifndef SINTRAM  /* SINTRAM defined by compiler option -DSINTRAM only for INTRAM build */
     ASM_KEYWORD(" e_lis   r5, INT_SRAM_SIZE@h");       /* Number of 64 byte segments */
     ASM_KEYWORD(" e_or2i    r5, INT_SRAM_SIZE@l");     /* Number of 64 byte segments */
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* start address of the internal SRAM */
     ASM_KEYWORD(" e_lis   r5,INT_SRAM_START@h");
     ASM_KEYWORD(" e_or2i    r5, INT_SRAM_START@l");
     
/* Repeat */
     ASM_KEYWORD("sram_loop:");
     ASM_KEYWORD("e_stmw  r16,0(r5)");   /* write 0 to to L2RAM and update r5 address */
     ASM_KEYWORD("e_addi r5,r5,64 ");
     ASM_KEYWORD("e_bdnz   sram_loop"); /* loop for 64k of L2RAM */
#endif

/************************/
/* Erase ".sbss Section" */
/************************/
     ASM_KEYWORD(" xor   r0, r0, r0 ");

     ASM_KEYWORD(" e_lis  r5, SBSS_SRAM_SIZE@h");       /* Number of words */
     ASM_KEYWORD(" e_or2i   r5, SBSS_SRAM_SIZE@l");   /* Number of words */
     ASM_KEYWORD(" or.  r5, r5, r5");                 /* Number of words */
     ASM_KEYWORD(" e_beq    sram_erase1");
     ASM_KEYWORD(" se_mtctr r5");                        /* configure control register for use with e_bdnz */

/* start address of the sbss section */
     ASM_KEYWORD(" e_lis   r5,SBSS_SRAM_START@h");
     ASM_KEYWORD(" e_or2i    r5, SBSS_SRAM_START@l");
     ASM_KEYWORD(" xor   r0, r0, r0 ");
     ASM_KEYWORD(" e_subi  r5,r5,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("sram_loop1:");
     ASM_KEYWORD(" e_stwu   r0,4(r5)");                 /* write 0 to RAM and update r5 address */
     ASM_KEYWORD(" e_bdnz   sram_loop1");
     ASM_KEYWORD("sram_erase1:");

/************************/
/* Erase ".bss Section" */
/************************/
     ASM_KEYWORD(" e_lis   r5, BSS_SRAM_SIZE@h");      /* Number of words */
     ASM_KEYWORD(" e_or2i    r5, BSS_SRAM_SIZE@l");  /* Number of words */
     ASM_KEYWORD(" or.   r5, r5, r5");               /* Number of words */
     ASM_KEYWORD(" e_beq   sram_erase2");
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* start address of the bss section */
     ASM_KEYWORD(" e_lis   r5, BSS_SRAM_START@h");
     ASM_KEYWORD(" e_or2i    r5, BSS_SRAM_START@l");
     ASM_KEYWORD(" e_subi  r5,r5,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("sram_loop2:");
     ASM_KEYWORD(" e_stwu r0,4(r5)");                  /* write 0 to RAM and update r5 address, r0 must be zero */
     ASM_KEYWORD(" e_bdnz   sram_loop2");
     ASM_KEYWORD("sram_erase2:");

/************************/
/* Erase ".bss_no_cacheable Section" */
/************************/
     ASM_KEYWORD(" e_lis   r5, BSS_NO_CACHEABLE_SRAM_SIZE@h");      /* Number of words */
     ASM_KEYWORD(" e_or2i    r5, BSS_NO_CACHEABLE_SRAM_SIZE@l");  /* Number of words */
     ASM_KEYWORD(" or.   r5, r5, r5");               /* Number of words */
     ASM_KEYWORD(" e_beq   sram_erase3");
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* start address of the bss section */
     ASM_KEYWORD(" e_lis   r5, BSS_NO_CACHEABLE_SRAM_START@h");
     ASM_KEYWORD(" e_or2i    r5, BSS_NO_CACHEABLE_SRAM_START@l");
     ASM_KEYWORD(" e_subi  r5,r5,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("sram_loop3:");
     ASM_KEYWORD(" e_stwu r0,4(r5)");                  /* write 0 to RAM and update r5 address, r0 must be zero */
     ASM_KEYWORD(" e_bdnz   sram_loop3");
     ASM_KEYWORD("sram_erase3:");     
     
     
/******************************************************************/
/* Copy  initialized data from Flash to SRAM                      */
/******************************************************************/
/*******************/
/* .PPC.EMB.sdata0 */
/*******************/
     ASM_KEYWORD(" e_lis   r5, RC_PPC_SDATA2_SIZE@h");      /* Number of words */
     ASM_KEYWORD(" e_or2i    r5, RC_PPC_SDATA2_SIZE@l");  /* Number of words */
     ASM_KEYWORD(" or.   r5, r5, r5");                     /* Number of words */
     ASM_KEYWORD(" e_beq   data_copy1");
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* source address of the section */
     ASM_KEYWORD(" e_lis   r8, RC_PPC_SDATA2_SRC@h");
     ASM_KEYWORD(" e_or2i    r8, RC_PPC_SDATA2_SRC@l");
     ASM_KEYWORD(" e_subi  r8,r8,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Destination address of the section */
     ASM_KEYWORD(" e_lis   r9, RC_PPC_SDATA2_DEST@h");
     ASM_KEYWORD(" e_or2i    r9, RC_PPC_SDATA2_DEST@l");
     ASM_KEYWORD(" e_subi  r9,r9,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("data_copy_loop1:");
     ASM_KEYWORD(" e_lwzu  r10,4(r8)");
     ASM_KEYWORD(" e_stwu  r10,4(r9)");
     ASM_KEYWORD(" e_bdnz  data_copy_loop1");
    ASM_KEYWORD("data_copy1:");
/**********/
/* .sdata */
/**********/
     ASM_KEYWORD(" e_lis   r5, RC_SDATA_SIZE@h");      /* Number of words */
     ASM_KEYWORD(" e_or2i    r5, RC_SDATA_SIZE@l");      /* Number of words */
     ASM_KEYWORD(" or.   r5, r5, r5");                     /* Number of words */
     ASM_KEYWORD(" e_beq   data_copy2");
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* source address of the section */
     ASM_KEYWORD(" e_lis   r8, RC_SDATA_SRC@h");
     ASM_KEYWORD(" e_or2i    r8, RC_SDATA_SRC@l");
     ASM_KEYWORD(" e_subi  r8,r8,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Destination address of the section */
     ASM_KEYWORD(" e_lis   r9, RC_SDATA_DEST@h");
     ASM_KEYWORD(" e_or2i    r9, RC_SDATA_DEST@l");
     ASM_KEYWORD(" e_subi  r9,r9,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("data_copy_loop2:");
     ASM_KEYWORD(" e_lwzu  r10,4(r8)");
     ASM_KEYWORD(" e_stwu  r10,4(r9)");
     ASM_KEYWORD(" e_bdnz  data_copy_loop2");
     ASM_KEYWORD("data_copy2:");
/**********/
/* .data */
/**********/
     ASM_KEYWORD(" e_lis   r5, RC_DATA_SIZE@h");      /* Number of words */
     ASM_KEYWORD(" e_or2i    r5, RC_DATA_SIZE@l");      /* Number of words */
     ASM_KEYWORD(" or.   r5, r5, r5");                     /* Number of words */
     ASM_KEYWORD(" e_beq   data_copy3");
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* source address of the section */
     ASM_KEYWORD(" e_lis   r8, RC_DATA_SRC@h");
     ASM_KEYWORD(" e_or2i    r8, RC_DATA_SRC@l");
     ASM_KEYWORD(" e_subi  r8,r8,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Destination address of the section */
     ASM_KEYWORD(" e_lis   r9, RC_DATA_DEST@h");
     ASM_KEYWORD(" e_or2i    r9, RC_DATA_DEST@l");
     ASM_KEYWORD(" e_subi  r9,r9,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("data_copy_loop3:");
     ASM_KEYWORD(" e_lwzu  r10,4(r8)");
     ASM_KEYWORD(" e_stwu  r10,4(r9)");
     ASM_KEYWORD(" e_bdnz  data_copy_loop3");
     ASM_KEYWORD("data_copy3:");

/**********/
/* .data_no_cacheable */
/**********/
     ASM_KEYWORD(" e_lis   r5, RC_DATA_NO_CACHEABLE_SIZE@h");      /* Number of words */
     ASM_KEYWORD(" e_or2i    r5, RC_DATA_NO_CACHEABLE_SIZE@l");      /* Number of words */
     ASM_KEYWORD(" or.   r5, r5, r5");                     /* Number of words */
     ASM_KEYWORD(" e_beq   data_copy5");
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* source address of the section */
     ASM_KEYWORD(" e_lis   r8, RC_DATA_NO_CACHEABLE_SRC@h");
     ASM_KEYWORD(" e_or2i    r8, RC_DATA_NO_CACHEABLE_SRC@l");
     ASM_KEYWORD(" e_subi  r8,r8,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Destination address of the section */
     ASM_KEYWORD(" e_lis   r9, RC_DATA_NO_CACHEABLE_DEST@h");
     ASM_KEYWORD(" e_or2i    r9, RC_DATA_NO_CACHEABLE_DEST@l");
     ASM_KEYWORD(" e_subi  r9,r9,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("data_copy_loop5:");
     ASM_KEYWORD(" e_lwzu  r10,4(r8)");
     ASM_KEYWORD(" e_stwu  r10,4(r9)");
     ASM_KEYWORD(" e_bdnz  data_copy_loop5");
     ASM_KEYWORD("data_copy5:");        
    

/************/
/* .ramcode */
/************/
     ASM_KEYWORD(" e_lis   r5, RC_RAMCODE_SIZE@h");      /* Number of words */
     ASM_KEYWORD(" e_or2i    r5, RC_RAMCODE_SIZE@l");      /* Number of words */
     ASM_KEYWORD(" or.   r5, r5, r5");                     /* Number of words */
     ASM_KEYWORD(" e_beq   data_copy4");
     ASM_KEYWORD(" se_mtctr r5");                       /* configure control register for use with e_bdnz */

/* source address of the section */
     ASM_KEYWORD(" e_lis   r8, RC_RAMCODE_SRC@h");
     ASM_KEYWORD(" e_or2i    r8, RC_RAMCODE_SRC@l");
     ASM_KEYWORD(" e_subi  r8,r8,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Destination address of the section */
     ASM_KEYWORD(" e_lis   r9, RC_RAMCODE_DEST@h");
     ASM_KEYWORD(" e_or2i    r9, RC_RAMCODE_DEST@l");
     ASM_KEYWORD(" e_subi  r9,r9,4");                   /* decrement by 4 to prepare for e_stwu in loop */

/* Repeat */
     ASM_KEYWORD("data_copy_loop4:");
     ASM_KEYWORD(" e_lwzu  r10,4(r8)");
     ASM_KEYWORD(" e_stwu  r10,4(r9)");
     ASM_KEYWORD(" e_bdnz  data_copy_loop4");
     ASM_KEYWORD("data_copy4:");

/*********************************/
/* Set the small ro data pointer */
/*********************************/
     ASM_KEYWORD(" e_lis   r2, SDATA_RO_START@h");
     ASM_KEYWORD(" e_or2i    r2, SDATA_RO_START@l");

/*********************************/
/* Set the small rw data pointer */
/*********************************/
     ASM_KEYWORD(" e_lis   r13, SDATA_RW_START@h");
     ASM_KEYWORD(" e_or2i    r13, SDATA_RW_START@l");

     
/******************************************************************/
/* Autosar Guidance 6 - If the MCU supports cache memory for data */
/* and/or code, it shall be initialized and enabled in the        */
/* start-up code.                                                 */
/*                                                                */
/******************************************************************/
/* invalidate and enable the data and instruction caches          */
/* data cache */
#ifdef D_CACHE_ENABLE
    ASM_KEYWORD("DCACHE_CFG: ");
    ASM_KEYWORD(" e_li r5, 0x2 ");
    ASM_KEYWORD(" mtspr l1csr0,r5 ");
    
    ASM_KEYWORD(" e_li r7, 0x4 ");
    ASM_KEYWORD(" e_li r8, 0x2 ");
    ASM_KEYWORD(" e_lis   r11, 0xFFFF ");
    ASM_KEYWORD(" e_or2i  r11, 0xFFFB ");
    
    ASM_KEYWORD("DCACHE_INV: ");
    ASM_KEYWORD(" mfspr r9, l1csr0 ");
    ASM_KEYWORD(" and.  r10, r7, r9 ");
    ASM_KEYWORD(" e_beq   DCACHE_NO_ABORT ");
    ASM_KEYWORD(" and.  r10, r11, r9 ");
    ASM_KEYWORD(" mtspr l1csr0, r10 ");
    ASM_KEYWORD(" e_b  DCACHE_CFG ");
    
    ASM_KEYWORD("DCACHE_NO_ABORT: ");
    ASM_KEYWORD(" and.  r10, r8, r9 ");
    ASM_KEYWORD(" e_bne DCACHE_INV ");
    
    ASM_KEYWORD(" mfspr r5, l1csr0 ");
    ASM_KEYWORD(" e_ori   r5, r5, 0x0001 ");
    ASM_KEYWORD(" se_isync ");
    ASM_KEYWORD(" msync ");
    ASM_KEYWORD(" mtspr l1csr0, r5 ");
#endif   
 
/* inst cache */
#ifdef I_CACHE_ENABLE
    
    ASM_KEYWORD("ICACHE_CFG:");
    ASM_KEYWORD(" e_li r5, 0x2 ");
    ASM_KEYWORD(" mtspr l1csr1,r5 ");
    
    ASM_KEYWORD(" e_li r7, 0x4 ");
    ASM_KEYWORD(" e_li r8, 0x2 ");
    ASM_KEYWORD(" e_lis   r11, 0xFFFF ");
    ASM_KEYWORD(" e_or2i  r11, 0xFFFB ");
    
    ASM_KEYWORD("ICACHE_INV:");
    ASM_KEYWORD(" mfspr r9, l1csr1 ");
    ASM_KEYWORD(" and.  r10, r7, r9 ");
    ASM_KEYWORD(" e_beq   ICACHE_NO_ABORT ");
    ASM_KEYWORD(" and.  r10, r11, r9 ");
    ASM_KEYWORD(" mtspr l1csr1, r10 ");
    ASM_KEYWORD(" e_b  ICACHE_CFG");
    
    ASM_KEYWORD("ICACHE_NO_ABORT:");
    ASM_KEYWORD(" and.  r10, r8, r9 ");
    ASM_KEYWORD(" e_bne ICACHE_INV ");
    
    ASM_KEYWORD(" mfspr r5, l1csr1 ");
    ASM_KEYWORD(" e_ori   r5, r5, 0x0001 ");
    ASM_KEYWORD(" se_isync ");
    ASM_KEYWORD(" msync ");
    ASM_KEYWORD(" mtspr l1csr1, r5 ");
   
#endif      
    
/******************************************************************/
/* Freescale Guidance 4 - Set up INTC                             */
/******************************************************************/
    /* Configure INTC for hardware vector mode */
    /* S_REG_WRITE32(S_INTC_MCR,S_INTC_MCR_HVEN_ON|S_INTC_MCR_VTES_4BYTES); */

    /* Setup main code priority */
    /* S_REG_WRITE32(S_INTC_CPR0,0); */
    /* S_REG_WRITE32(S_INTC_CPR1,0); */

    ASM_KEYWORD(" e_lis     r6,0xFFF4 ");
    ASM_KEYWORD(" e_or2i    r6,0x8000 ");
    ASM_KEYWORD(" e_li      r7,0x0101 ");
    ASM_KEYWORD(" se_stw    r7,0x0(r6)");

    ASM_KEYWORD(" se_li     r7,0x0  ");
    ASM_KEYWORD(" se_stw    r7,0x8(r6)   ");
    ASM_KEYWORD(" se_stw    r7,0x0C(r6)  ");

   
  
/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
    /* Prepare a terminating stack record. */
    ASM_KEYWORD (" e_li r0, -1");
    ASM_KEYWORD (" e_stwu r1, -8(r1)"); /* Decrement stack by 8 bytes, (write word) */
    ASM_KEYWORD (" e_stw  r0, 4(r1)");  /* Make an illegal return address of 0xFFFFFFFF */
    ASM_KEYWORD (" e_stw  r0, 0(r1)");  /* Make an illegal back chain address of 0xFFFFFFFF */

/******************************************************************/
/* Init runtime check data space                                  */
/******************************************************************/
#ifdef ENABLE_RCHECK
    /* initialization for the runtime checks memory space */
    init_runtime_check();
#endif /* ENABLE_RCHECK */

    ASM_KEYWORD ("e_bl main");
    /* main(); */
    
    /* Define a symbol to Turn OFF (stop the tracing and save the data) the LTB PowerTracer */    
    ASM_KEYWORD(" .globl MCAL_LTB_TRACE_OFF");
    ASM_KEYWORD("MCAL_LTB_TRACE_OFF:");
    ASM_KEYWORD(" e_nop");
    
#ifdef CCOV_ENABLE
    /* code coverage is requested */
    ccov_main();
#endif
  
    ASM_KEYWORD ("se_illegal"); /* SW breakpoint to stop debugging */
     
    while (1)
    {
    }
}



/* This handler is the one that will be called after sc_se instruction. It is mapped to IVOR8 
The LR will be altered, at the end of the function. */

void SystemCall()
{
    ASM_KEYWORD(".globl SystemCall_Handler");  
    ASM_KEYWORD("SystemCall_Handler:");
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    /* push R3 on stack*/
    ASM_KEYWORD("se_subi   r1,0x4");
    ASM_KEYWORD("e_stw     r3,0x0(r1)");
    /* clear MSR[PR] bit by modifying SRR1 for keeping supervisor mode after exiting the Handler */
    ASM_KEYWORD("mfsrr1      r3");                          /* load SRR1 */
    ASM_KEYWORD("se_bclri    r3,17");                     /* clear PR bit */
    ASM_KEYWORD("mtsrr1      r3 ");                        /* save SRR1 */
    /* pop R3 from the stack */
    ASM_KEYWORD("e_lwz     r3,0x0(r1)");
    ASM_KEYWORD("se_addi   r1,0x4");
    /* return from interrupt */
   ASM_KEYWORD("se_rfi");
#else
    /* while(1) */
     ASM_KEYWORD("e_b .");
#endif
}


/* if RUNTIME Checks are enabled (GHS toolchain) */
#ifdef ENABLE_RCHECK
int __re_extra, __re_pid;

#define AUX_BUFFER_SIZE 800
#define RUNTIME_COUNT_OF_VIOLATIONS 24

/* The "_rnerr" function will be called whenever a run-time error has occurred
 * and runtime error checking is enabled.  It will, in turn, call the handler 
 */
typedef struct
{
    uint32_t violation;   /**< violation code */
    uint32_t line_no;     /**< line number for the violation */
    sint8 filename[AUX_BUFFER_SIZE-RUNTIME_COUNT_OF_VIOLATIONS*4-4]; /**< filename. Length will be the min between 
                                                 space left in the data buffer and the current file name */
} Runtime_violation_info_t;

 typedef struct
{
    uint32_t runtime_check_count[RUNTIME_COUNT_OF_VIOLATIONS];      /**< count of all violations */
    uint32_t position;                     /**< position in data buffer */
    sint8 data[AUX_BUFFER_SIZE-RUNTIME_COUNT_OF_VIOLATIONS*4-4];  /**< data formatting - list of Runtime_violation_info_t 
                                              structures (filename length is variable) */
} Runtime_violation_t;
 
Runtime_violation_t *violation_storage;


void MyRuntimeErrorHandler(int code, int line, const char *filename) {
/*
 * code:       error type  
 * line:       line in the source code which fails  
 * filename:   name of the source file which fails  
 *          
 * Valid error types:  
 * 0:  UNUSED  
 * 1:  array index OutOfBounds
 * 2:  variant  
 * 3:  nil pointer  
 * 4:  switch out of bounds  
 * 5:  uninitialized variable  
 * 6:  assignment out of bounds  
 * 7:  division by zero  
 * 8:  value out of bounds (pred,succ)  
 * 9:  free of something not malloced  
 * 10: free of something already free  
 * 11: free list corrupted  
 * 12: reference to bad data  
 * 13: unreferenced memory  
 * 14: overflow  
 * 15: Error limit exceeded  
 * 16: Watchpoint  
 * 17: Return of nothing from non-void procedure  
 * 18: Ambiguous virtual function called  
 * 19: Attempt to free NULL  
 * 20: Heap max exceeded  
 * 21: Stack max exceeded    
 */
    uint32_t counter;
    uint32_t max_length;
    Runtime_violation_info_t *violation_data;

    /* Raise global priority level - to disable all interrupts */
    (*((volatile uint32_t*) (0xFFF48008)))=0xF;

    /* save parameters to global variables for further processing */
    if( (0<=code) && (code <22))
    {
        violation_storage->runtime_check_count[code]++;
    }
    else
    {
        /* unknown violation - save it to the final location */
        violation_storage->runtime_check_count[22]++;
    }
    
    /* save data for as many violations as possible */
    if( violation_storage->position< sizeof( violation_storage->data))
    {
        /* if there is still some space in the buffer, try to save the violation data */
        
        /* position must be aligned at 4 bytes - assuming the violation_storage->data is already aligned */
        violation_storage->position= (violation_storage->position+3)&0xFFFFFFFC;

        /* set position for the new violation data */
        violation_data= (Runtime_violation_info_t*) &(violation_storage->data[violation_storage->position]);
        
        /* violation buffer must have space for at least the violation type, line no + 2 chars for the filename */
        if( ( violation_storage->position + sizeof( violation_data->violation) 
            + sizeof( violation_data->line_no) + 2) < sizeof( violation_storage->data))
        {
            violation_data->violation= code;            
            violation_storage->position+= sizeof( violation_data->violation);
            violation_data->line_no= line;
            violation_storage->position+= sizeof( violation_data->line_no);
            /* copy filename - make sure that it doesn't overflow the buffer */
            max_length= sizeof( violation_storage->data)-violation_storage->position-1;
            for( counter=0; (counter<max_length) && (filename[counter]!=0); counter++)
            {
                violation_data->filename[counter]= filename[counter];
            }
            /* add null terminator to the string */
            violation_data->filename[counter]=0;
            violation_storage->position+= counter+1;            
        }
        else
        {
            /* buffer filled - set position greater than the data size */
            violation_storage->position= sizeof( violation_storage->data)+10;
        }
    }

    /* Lower global priority level - to re-enable all interrupts */
    (*((volatile uint32_t*) (0xFFF48008)))=0x0;

#if 0
    switch(code)  {
        case 1:
        OutOfBounds:
            CONSOLE_MESSAGE("Runtime error: Array index out of bounds in file = %s, line = %d\n", filename, line);
            break;
        case 3:
        NullDereference:
            CONSOLE_MESSAGE("Runtime error: NULL pointer dereference in file = %s, line = %d\n", filename, line);
            break;
        case 4:
        SwitchFallThrough:
            CONSOLE_MESSAGE("Runtime error: Case/Switch has no match in file = %s, line = %d\n", filename, line);
            break;
        case 7:
        DivideByZero:
            CONSOLE_MESSAGE("Runtime error: Divide by zero!!! in file = %s, line = %d\n", filename, line);
            break;
        case 9:
        AttemptToFree:
            CONSOLE_MESSAGE("Runtime error: Attempt to free unallocated memory in file = %s, line = %d\n", filename, line);
            break;
        case 19:
        AttemptToFree2:
            CONSOLE_MESSAGE("Runtime error: Attempt to free memory not allocated in file = %s, line = %d\n", filename, line);
            break;
        default:
        Error:
            CONSOLE_MESSAGE("Error code = %d, file = %s, line = %d\n", code, filename, line);
    }
#endif
}

void _rnerr(int code, int line, const char *filename)
{
    if (filename == NULL_PTR)
        filename = "(null)";
    MyRuntimeErrorHandler(code, line, filename);
}


 
/* initialization for the runtime checks memory space */
void init_runtime_check(void)
{
    uint32_t counter;
    uint32_t max_length;

    /* save data to specific memory address, to be dumped by the debugger script */
    violation_storage= (Runtime_violation_t*)(AUX_BUFFER_ADDR+4);
    
    /* init fields */
    max_length= sizeof(violation_storage->runtime_check_count)/sizeof(violation_storage->runtime_check_count[0]);
    for( counter=0; counter< max_length; counter++)
    {
        violation_storage->runtime_check_count[counter]= 0;
    }
    violation_storage->position= 0;
    max_length= sizeof(violation_storage->data)/sizeof(violation_storage->data[0]);
    for( counter=0; counter< max_length; counter++)
    {
        violation_storage->data[counter]= 0;
    }
}
#endif /* ENABLE_RCHECK */
