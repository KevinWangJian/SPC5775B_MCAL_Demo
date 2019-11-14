/**
*   @file    Can_Mcan.c
*   @implements MCan.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR MCan - IPW module implementation.
*   @details Low Level Driver implementation.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : MCAN
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC5777C_MCAL_1_0_1_RTM_HF1_ASR_REL_4_0_REV_0003_20170606
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Can_MCan_c_REF_1
* Violates MISRA 2004 Required Rule 8.7, Global variables containing the generated configuration
* shall be defined in a separate source file and can't be defined inside a function although it is accessed
* by a single function.
*
* @section Can_MCan_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_MCan_c_REF_3
* Violates MISRA 2004 Required Rule 12.4, The right-hand operand of a logical and or operator shall not contain side effects.
*
* @section Can_MCan_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_MCan_c_REF_5
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_MCan_c_REF_6
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The code is not dynamically linked. An absolute stack address is obtained when taking the address of the near auto variable.
* A source of error in writing dynamic code is that the stack segment may be different from the data segment.
*
* @section Can_MCan_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section Can_MCan_c_REF_9
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type.
*
* @section Can_MCan_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_MCAN.h"
#include "Can_43_MCAN_IPW.h"
#include "CanIf_Cbk.h"

#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

#include "SchM_MCan.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Can_Mcan.c
*/

#define CAN_VENDOR_ID_MCAN_C                    43
#define CAN_MODULE_ID_MCAN_C                    80
#define CAN_AR_RELEASE_MAJOR_VERSION_MCAN_C     4
#define CAN_AR_RELEASE_MINOR_VERSION_MCAN_C     0
#define CAN_AR_RELEASE_REVISION_VERSION_MCAN_C  3
#define CAN_SW_MAJOR_VERSION_MCAN_C             1
#define CAN_SW_MINOR_VERSION_MCAN_C             0
#define CAN_SW_PATCH_VERSION_MCAN_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check if current file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_MCAN_C != CAN_VENDOR_ID_MCAN_H)
    #error "Can_Mcan.c and Can_Mcan.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_MCAN_C    != CAN_AR_RELEASE_MAJOR_VERSION_MCAN_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_MCAN_C    != CAN_AR_RELEASE_MINOR_VERSION_MCAN_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_MCAN_C != CAN_AR_RELEASE_REVISION_VERSION_MCAN_H))
    #error "AutoSar Version Numbers of Can_Mcan.c and Can_Mcan.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_MCAN_C != CAN_SW_MAJOR_VERSION_MCAN_H) || \
     (CAN_SW_MINOR_VERSION_MCAN_C != CAN_SW_MINOR_VERSION_MCAN_H) || \
     (CAN_SW_PATCH_VERSION_MCAN_C != CAN_SW_PATCH_VERSION_MCAN_H))
    #error "Software Version Numbers of Can_Mcan.c and Can_Mcan.h are different"
#endif


/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_MCAN_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_MCAN_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Mcan.c and Det.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


#define CAN_43_MCAN_START_SEC_VAR_NO_INIT_32
/* @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
/* @violates @ref Can_MCan_c_REF_1 Violates MISRA 2004 Required Rule 8.7, Required */    
VAR(uint32, AUTOMATIC)u32RxBufferDataSize[CAN_43_MCAN_MAXCTRL_SUPPORTED];
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(uint32, AUTOMATIC)u32RxFIFO1DataSize[CAN_43_MCAN_MAXCTRL_SUPPORTED];
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(uint32, AUTOMATIC)u32RxFIFO0DataSize[CAN_43_MCAN_MAXCTRL_SUPPORTED];

/* 
* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* @violates @ref Can_MCan_c_REF_1 Violates MISRA 2004 Required Rule 8.7, Required
*/
VAR(uint32, AUTOMATIC)u32TxDataSize[CAN_43_MCAN_MAXCTRL_SUPPORTED];
#endif
/**
* @brief          Array for HOH status flag
* @details        Mutex to prevent calling Can_Write with the same HOH
*/
static VAR(uint32, CAN_43_MCAN_VAR) Can_u32HOHStatus[((CAN_43_MCAN_MAX_OBJECT_ID/32U) + 1U)];

#define CAN_43_MCAN_STOP_SEC_VAR_NO_INIT_32
/* 
* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
*  @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h 
*/
#include "MemMap.h"

#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
    #define CAN_43_MCAN_START_SEC_VAR_NO_INIT_8
    /* 
    * @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
    *  @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h 
    */
    #include "MemMap.h"
    /* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    VAR(uint8, AUTOMATIC)u8MbSize[CAN_43_MCAN_MAXCTRL_SUPPORTED];

    /* 
    * @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
    *  @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h 
    */
    #define CAN_43_MCAN_STOP_SEC_VAR_NO_INIT_8
    #include "MemMap.h"
#else
    #define CAN_43_MCAN_START_SEC_VAR_NO_INIT_8
    /* 
    * @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
    *  @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h 
    */
    #include "MemMap.h"
    /* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    VAR(uint8, AUTOMATIC)u8MbSize[CAN_43_MCAN_MAXCTRL_SUPPORTED];

    /* 
    * @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
    *  @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h 
    */
    #define CAN_43_MCAN_STOP_SEC_VAR_NO_INIT_8
#endif

#define CAN_43_MCAN_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
*  @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h 
*/
#include "MemMap.h"

/**
* @brief          CAN Share Ram initialized state.
* @details        CAN Share Ram initialized state.
*
*/
/* @violates @ref Can_MCan_c_REF_1 Violates MISRA 2004 Required Rule 8.7, Required */
static VAR(Can_SramStateType, CAN_43_MCAN_VAR) Can_SramStatus = MCAN_SRAM_UNINITIALIZED;

#define CAN_43_MCAN_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
*  @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h 
*/
#include "MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CAN_43_MCAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @file  Can_Mcan.c
* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/**
* @brief          Array holding current status/run-time configuration of individual MCAN controllers
* @details        Array holding current status/run-time configuration of individual MCAN controllers
*                 - information like Guard bits, Pre-calculated MB INT masks, Storage space for id, INT nesting level,
*                 Index of MB buffer being cancelled, Index of the first MB used for Tx , Controller Options.
*
*
*/
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(Can_43_MCAN_ControllerStatusType, CAN_43_MCAN_VAR) Can_43_MCAN_ControllerStatuses[CAN_43_MCAN_MAXCTRL_SUPPORTED];

#define CAN_43_MCAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#define CAN_43_MCAN_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(uint8, CAN_43_MCAN_CONST) Can_Mcan_u8RealPayloadData[8U]= { 0x08U, 0x0CU, 0x10U, 0x14U, 0x18U, 0x20U, 0x30U, 0x40U};
/* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(uint32, CAN_43_MCAN_CONST) MCAN_BASE_ADDRS[MCAN_CONTROLLERS_NO] = {
#ifdef  MCAN1_BASEADDR
        MCAN1_BASEADDR,
#endif /* MCAN1_BASEADDR */
#ifdef  MCAN2_BASEADDR
        MCAN2_BASEADDR,
#endif /* MCAN2_BASEADDR */
#ifdef  MCAN3_BASEADDR
        MCAN3_BASEADDR,
#endif /* MCAN3_BASEADDR */
#ifdef  MCAN4_BASEADDR
        MCAN4_BASEADDR,
#endif /* MCAN4_BASEADDR */
#ifdef  TTCAN0_BASEADDR
        TTCAN0_BASEADDR,
#endif /* TTCAN0_BASEADDR */
    };

#define CAN_43_MCAN_STOP_SEC_CONST_UNSPECIFIED

/*
* @file  Can_Mcan.c
* @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef ERR_IPV_MCAN_0001 
    #if (ERR_IPV_MCAN_0001 == STD_ON)
        static FUNC(void,CAN_43_MCAN_CODE) Can_Mcan_Implement_EARATA_8655(VAR(uint8, AUTOMATIC) u8HwOffset);
    #endif
#endif


static FUNC(uint8, CAN_43_MCAN_CODE) Can_Mcan_DecodeLenghtData(VAR(uint8, AUTOMATIC) u8MbDataLength);
static FUNC(uint32, CAN_43_MCAN_CODE) Can_Mcan_CalcDataLenghtCode(VAR(uint8, AUTOMATIC) u8MbDataLength);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define CAN_43_MCAN_START_SEC_CODE
/* * @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.*/
/* @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*================================================================================================*/
/**
* @brief          Decode the length of the data bytes which are transmitted
* @details        Decode the length of the data bytes which are transmitted
*                 This routine is called by:
*                 - Can_MCan_ProcessTx() from Can_MCan.c file.
*
* @param[in]      The data length code of the MB
*
*
*/
static FUNC(uint8, CAN_43_MCAN_CODE) Can_Mcan_DecodeLenghtData(VAR(uint8, AUTOMATIC) u8MbDataLength)
{
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
    /* Initialize this variable as the maximum data length of the CAN FD module(64 bytes) */
    VAR(uint8, AUTOMATIC) u8ReturnValue = (uint8)MCAN_64_BYTES_U8;
#else
    /* Initialize this variable as the maximum data length of the CAN module(8 bytes) */
    VAR(uint8, AUTOMATIC) u8ReturnValue = (uint8)MCAN_8_BYTES_U8;
#endif
    
    if (u8MbDataLength <= 8U)
    {
        u8ReturnValue = u8MbDataLength;
    }
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
    else
    {
        switch (u8MbDataLength)
        {
            case (9U):
                u8ReturnValue = (uint8)MCAN_12_BYTES_U8;
                break;
            case (10U):
                u8ReturnValue = (uint8)MCAN_16_BYTES_U8;
                break;
            case (11U):
                u8ReturnValue = (uint8)MCAN_20_BYTES_U8;
                break;
            case (12U):
                u8ReturnValue = (uint8)MCAN_24_BYTES_U8;
                break;
            case (13U):
                u8ReturnValue = (uint8)MCAN_32_BYTES_U8;
                break;
            case (14U):
                u8ReturnValue = (uint8)MCAN_48_BYTES_U8;
                break;
            default:
                break;
        }    
    }
#endif

    return (u8ReturnValue);
}

/*================================================================================================*/
/**
* @brief          Calculate the data length code of MB
* @details        Calculate the data length code of MB
*                 This routine is called by:
*                 - Can_MCan_Write() from Can_MCan.c file.
*
* @param[in]      The length of the data bytes which are transmitted   
*
*
*/
static FUNC(uint32, CAN_43_MCAN_CODE) Can_Mcan_CalcDataLenghtCode(VAR(uint8, AUTOMATIC) u8MbDataLength)
{
    VAR(uint32, AUTOMATIC) u32ReturnValue = (uint32)0U;   
    
    if (u8MbDataLength <= (uint8)MCAN_8_BYTES_U8)   
    {
        u32ReturnValue = (uint32)u8MbDataLength << MCAN_MB_DLC_SHIFT_U32;
    }
    else if (u8MbDataLength <= (uint8)MCAN_12_BYTES_U8)
    {
        u32ReturnValue = ((uint32)9U << MCAN_MB_DLC_SHIFT_U32);
    }
    else if (u8MbDataLength <= (uint8)MCAN_16_BYTES_U8)
    {
        u32ReturnValue = ((uint32)10U << MCAN_MB_DLC_SHIFT_U32);
    }
    else if (u8MbDataLength <= (uint8)MCAN_20_BYTES_U8)
    {
        u32ReturnValue = ((uint32)11U << MCAN_MB_DLC_SHIFT_U32);
    }
    else if (u8MbDataLength <= (uint8)MCAN_24_BYTES_U8)
    {
        u32ReturnValue = ((uint32)12U << MCAN_MB_DLC_SHIFT_U32);
    }
    else if (u8MbDataLength <= (uint8)MCAN_32_BYTES_U8)
    {
        u32ReturnValue = ((uint32)13U << MCAN_MB_DLC_SHIFT_U32);
    }
    else if (u8MbDataLength <= (uint8)MCAN_48_BYTES_U8)
    {
        u32ReturnValue = ((uint32)14U << MCAN_MB_DLC_SHIFT_U32);   
    }
    else
    {
        u32ReturnValue = ((uint32)15U << MCAN_MB_DLC_SHIFT_U32);
    }
    
    return (u32ReturnValue);
}

/*================================================================================================*/
#ifdef ERR_IPV_MCAN_0001 
    #if (ERR_IPV_MCAN_0001 == STD_ON)
        /**
        * @brief          Setting the Configuration Change Enable (CCE) bit during a transmission scan can halt CAN transmissions
        * @details        Setting the Configuration Change Enable (CCE) bit during a transmission scan can halt CAN transmissions
        *                 This routine is called by:
        *                 - Can_MCan_Init() from Can_MCan.c file.
        *                 - Can_MCan_SetControllerMode() from Can_MCan.c file.
        *
        * @param[in]      Hardware Can controller offset.  
        *
        *
        */
        static FUNC(void,CAN_43_MCAN_CODE) Can_Mcan_Implement_EARATA_8655(VAR(uint8, AUTOMATIC) u8HwOffset)
        {
            VAR( uint32, AUTOMATIC) u32TimeoutCount;
            
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_TXBCR(u8HwOffset), (uint32)(MCAN_MASK_32BITS_U32));
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            while (( 0U != ((uint32)(REG_READ32( MCAN_TXBRP(u8HwOffset))))) && (u32TimeoutCount > (uint32)0x00U))
            {
                u32TimeoutCount--;
            }
            /*Can enters into Initializaton mode & access to write protected registers is enabled */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CSR_U32);
            /* load local time-out variable with configured time-out value */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
            
            /* wait until CCCR.INIT = '1'(Initialization is started) */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            while ((((REG_READ32( MCAN_CCCR(u8HwOffset))) & (MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32)) != (MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32))&&(u32TimeoutCount>(uint32)0x0U))
            {
                u32TimeoutCount--;
                
                /*Wait until INIT bit is set, as there is delay in synchronisation between two clock domains */
            }
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CSR_U32);
            
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_INIT_U32);
            /* load local time-out variable with configured time-out value */
            u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            while ((((REG_READ32(MCAN_CCCR(u8HwOffset)))&(MCAN_CCCR_INIT_U32)) == (MCAN_CCCR_INIT_U32)) && (u32TimeoutCount>(uint32)0x0U))
            {
                u32TimeoutCount--;
            }
            
            /*Can enters into Initializaton mode & access to write protected registers is enabled */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CSR_U32);
            
            /* load local time-out variable with configured time-out value */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
            
            /* wait until CCCR.INIT = 1(Initialization is started) */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */           
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */            
            while ((((REG_READ32( MCAN_CCCR(u8HwOffset))) &(MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32)) != (MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32))&&(u32TimeoutCount>(uint32)0x0U))
            {
                u32TimeoutCount--;
                /*Wait until INIT bit is set, as there is delay in synchronisation between two clock domains */
            }
            /* Set CCE bit and clear CSR bit in CCCR */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_RMW32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CCE_U32|MCAN_CCCR_CSR_U32,MCAN_CCCR_CCE_U32); 
        }
    #endif
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
extern FUNC(boolean, COM_APPL_CODE) Can_43_MCAN_LPduReceiveCalloutFunction(VAR(uint8, AUTOMATIC) Hrh,Can_IdType CanId,VAR(uint8, AUTOMATIC) CanDlc,const uint8 *CanSduPtr);
/*================================================================================================*/
/**
* @brief          Initialisation of indicator, statuses, etc.
* @details        Initialisation of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_Init() from Can.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
*
*/
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_InitVariables( void )
{
    /* Index CAN controllers from configuration. */
    VAR(uint8, AUTOMATIC) u8CtrlIndex = 0U;
    /* Index CAN Message Buffers from configuration. */
    VAR(uint8, AUTOMATIC) u8MbIndex = 0U;
    /* Temp word index for initialize Can_u32HOHStatus */
    VAR(uint8, AUTOMATIC) u8TempWordIndex = 0U;

    /* Init all global varibales/statuses for all controllers. */
    for ( u8CtrlIndex = 0U; u8CtrlIndex < (uint8)Can_43_MCANStatic_pCurrentConfig->u8ControllersConfigured; u8CtrlIndex++)
    {
        Can_43_MCAN_ControllerStatuses[u8CtrlIndex].u32MBInterruptMask =0U;
        /* Init INT Disable nesting indicator. It is incremented after every call of Can_DisableControllerInterrupts().
           The function Can_EnableControllerInterrupts() shall perform no action when Can_DisableControllerInterrupts() has not been called before. */
        Can_43_MCAN_ControllerStatuses[u8CtrlIndex].s8IntDisableLevel = (sint8)0;
        /* Set  interrupt mode status to interrupt disabled mode. */
        Can_43_MCAN_ControllerStatuses[u8CtrlIndex].eInterruptMode = CAN_43_MCAN_INTERRUPT_ENABLED;

        /* Set the controller state to STOP after power-up */
        Can_43_MCAN_ControllerStatuses[u8CtrlIndex].ControllerState = CAN_43_MCAN_STOPPED;

        /* Set the controller current baudrate index as default */
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        Can_43_MCAN_ControllerStatuses[u8CtrlIndex].u8CurrentBaudRateIndex = (uint8)(Can_43_MCAN_pControlerDescriptors[u8CtrlIndex].u8DefaultBaudRateIndex);

        for (u8MbIndex = 0U; u8MbIndex < (uint8)CAN_43_MCAN_MAX_TX_MB_CONFIG; u8MbIndex++)
        {
            Can_43_MCAN_ControllerStatuses[u8CtrlIndex].u32MbTxMapping[u8MbIndex] = (uint32)0U;
        }
    }
#if 32U < CAN_43_MCAN_MAX_OBJECT_ID
    do 
    {
#endif
        Can_u32HOHStatus[u8TempWordIndex] = (uint32)0U;
        u8TempWordIndex++;
#if 32U < CAN_43_MCAN_MAX_OBJECT_ID
    } while(u8TempWordIndex <= (uint8)(CAN_43_MCAN_MAX_OBJECT_ID / 32U));
#endif
}

/*================================================================================================*/
/**
* @brief          Service for initializing the Can driver module according to a configuration set referenced by Config.
* @details        Driver Module Initialization - MCan Driver Module Initialization
*                 This routine is called by:
*                  - Can_Init() from Can.c file.
*
* @param[in]      Controller Can controller to be initialized
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Controller is enabled and set into Stop mode.
*
*
*/

FUNC (void, CAN_43_MCAN_CODE) Can_MCan_Init( VAR(uint8, AUTOMATIC) controller )
{
    /* Hardware Can controller offset. */
    VAR(uint8, AUTOMATIC)  u8HwOffset = 0U;
    VAR(uint32, AUTOMATIC) u32TimeoutCount;
    VAR(uint32, AUTOMATIC) u32OffsetShareRam;
    
    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;
#ifdef ERR_IPV_MCAN_0001 
    #if (ERR_IPV_MCAN_0001 == STD_ON)
        Can_Mcan_Implement_EARATA_8655(u8HwOffset);
    #endif
#endif

#if((!defined(ERR_IPV_MCAN_0001)) && (defined (ERR_IPV_MCAN_0003))) 
    #if (ERR_IPV_MCAN_0003 == STD_ON)
        /*Can enters into Initializaton mode & access to write protected registers is enabled */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CSR_U32);
        /* load local time-out variable with configured time-out value */           
        u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        while ((((REG_READ32( MCAN_CCCR(u8HwOffset))) & (MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32)) != (MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32))&&(u32TimeoutCount>(uint32)0x0U))
        {
            u32TimeoutCount--;
        }
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CSR_U32);
    #else
        #error: The define ERR_IPV_MCAN_0003 should not be STD_OFF
    #endif
#else
    /* Set INIT bit to change controller mode to initialization state */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_INIT_U32);
#endif

    
    /* load local time-out variable with configured time-out value */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
     
    /* wait until CCCR.INIT = '1'(Initialization is started) */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    while ((((REG_READ32( MCAN_CCCR(u8HwOffset))) & MCAN_CCCR_INIT_U32) != MCAN_CCCR_INIT_U32)&&(u32TimeoutCount>(uint32)0x0U))
    {
        u32TimeoutCount--;
        /*Wait until INIT bit is set, as there is delay in synchronisation between two clock domains */
    }
    /* Set CCCR.CCE bit (The CPU has write access to the protected configuration registers (while CCCR.INIT = 1))*/
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CCE_U32);
    /* Initializ Share Ram only once for all controllers */
    if(Can_SramStatus == MCAN_SRAM_UNINITIALIZED)
    {       
        /* clear Share RAM: 0xFFED4000 - 0xFFED9000 */
        u32OffsetShareRam = (uint32)( IPV_MCAN_START_ADDRESS_OFFSET_SHARE_RAM_U32 + SCM_RAM_BASEADDR);
        do
        {
            if ((u32OffsetShareRam < (IPV_MCAN_START_ADDRESS_OFFSET_TTCAN_U32 + SCM_RAM_BASEADDR)) || (u32OffsetShareRam > (IPV_MCAN_END_ADDRESS_OFFSET_TTCAN_U32 + SCM_RAM_BASEADDR)))
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32(u32OffsetShareRam, MCAN_NOT_MASK_32BITS_U32);
            }
            u32OffsetShareRam = ((uint32)(u32OffsetShareRam + 4U));
        } while(u32OffsetShareRam <= (uint32)(IPV_MCAN_END_ADDRESS_OFFSET_USEABLE_SHARE_RAM_U32 + SCM_RAM_BASEADDR));
        Can_SramStatus = MCAN_SRAM_INITIALIZED;
    }
}

/*================================================================================================*/
/**
* @brief          Service for reset the controller.
* @details        Re-initialization must start with a reset (soft).
*                 This routine is called by:
*                  - Can_MCan_ChangeBaudrate() from Can_Mcan.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done (CAN_FCA_INDEX / CAN_FCB_INDEX).
*                 This ID depends by the order of the controller's definition in the Tresos 'CanController' list.
*                 If CanController_0 is assigned to CANB then CAN_FCB_INDEX is 0.
*                 These indexes are used for access inside 'Can_ControlerDescriptorType' structure.
*
* @post           Controller is enabled and reset.
*
*/
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Can_ReturnType, CAN_43_MCAN_CODE) Can_MCan_ResetController( VAR(uint8, AUTOMATIC) controller)
{
    /* Variable store return status. */
    VAR(Can_ReturnType, AUTOMATIC) eReturnValue = CAN_OK;
    VAR(uint32, AUTOMATIC)         u32TimeoutCount = 0U;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)          u8HwOffset = 0U;

    /* Get the hardware offset for this controller. */
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
    u8HwOffset =  Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* The re-initialization of controller start with a Soft-Reset. Test if Can is not ready -> can be in any of disable, Doze/Stop/Freeze modes. */
    /* Set the INIT & CCE bits of CCCR register,to enter CAN into reset mode. */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_INIT_U32);
    
    /* load local time-out variable with configured time-out value*/
    u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
    
    /* Wait until INIT bit is set (Initialization is started), as there is delay in synchronisation between two clock domains */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    while ( (((REG_READ32( MCAN_CCCR(u8HwOffset))) & (MCAN_CCCR_INIT_U32 ) )!= MCAN_CCCR_INIT_U32 ) && (u32TimeoutCount > (uint32)0x0U) )
    {
        u32TimeoutCount--;
    }
    if(u32TimeoutCount == 0U)
    {
        eReturnValue = CAN_NOT_OK;
    }
    else
    {
        Can_43_MCAN_ControllerStatuses[controller].ControllerState = CAN_43_MCAN_STOPPED;
        /* Disable all interrupt flags by writing '0' in the all of bits */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_IE(u8HwOffset), MCAN_NOT_MASK_32BITS_U32);
        /* Clear all interrupt flags by writing '1' in the all of bits */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_MASK_32BITS_U32);
        /* Clear all New Data 1 flags by writing '1' in the all of bits */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_NDAT1(u8HwOffset), MCAN_MASK_32BITS_U32);
        /* Clear all New Data 2 flags by writing '1' in the all of bits*/
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_NDAT2(u8HwOffset), MCAN_MASK_32BITS_U32);
        
        eReturnValue = CAN_OK;
    }

    return (eReturnValue);
}
/*================================================================================================*/
/**
* @brief          Service for (re)initializing only CAN controller specific settings.
* @details        CAN controller (re-)initialization.
*                 This routine is called by:
*                  - Can_Init() from Can.c file.
*                  - Can_ChangeBaudrate() from Can.c file.
*                  - Can_SetBaudrate() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set the MBs and interrupts into predefinite state for Can bus communication.
*
*
*/

FUNC (void, CAN_43_MCAN_CODE) Can_MCan_ChangeBaudrate( VAR(uint8, AUTOMATIC) controller)
{
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_43_MCAN_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
    /* Local copy of pointer to the section address offset descriptor. */
    P2CONST(Can_43_MCAN_ControllerSectionOffsetType, AUTOMATIC, CAN_APPL_CONST) pCanControllerSectionOffset = NULL_PTR;
    /* Local copy of pointer to the static controller descriptor. */
    P2CONST(Can_43_MCANStatic_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanStaticControlerDescriptor = NULL_PTR;
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)        
    /* Local copy of pointer to the Fifo configuration structure */        
    P2CONST(Can_43_MCAN_ControllerRxFifoConfigType, AUTOMATIC, CAN_APPL_CONST) pCanControllerRxFifoConfig = NULL_PTR;
    /*Variable stores Shared RAM address offset of Rx FIFO 0 section */
    VAR(uint16, AUTOMATIC)            u32RxFifo0AddOffset = 0U;
    /*Variable stores Shared RAM address offset of Rx FIFO 1 section */
    VAR(uint16, AUTOMATIC)            u32RxFifo1AddOffset = 0U;
#endif
    /* Pointer to the MB container structure. */
    VAR(Can_43_MCAN_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    /* Variable for indexing all the MBs fron hardware unit chain (all controllers). */
    VAR(uint16, AUTOMATIC)            u16MbGlobalIndex = 0U;
    /* Variable for indexing the MBs inside a single controller. */
    VAR(uint8, AUTOMATIC)             u8MbCtrlIndex = 0U;
    /*Number of Standrad filter elements configured */
    VAR(uint8, AUTOMATIC)             u8NumberStdRxFilterCount = 0U;
    /*Number of Extended filter elements configured */
    VAR(uint8, AUTOMATIC)             u8NumberExtdRxFilterCount = 0U;
    /* Hardware Can controller offset. */
    volatile VAR(uint8, AUTOMATIC)             u8HwOffset = 0U;
    /*Stores the reset controller function status */
    VAR(Can_ReturnType, AUTOMATIC)    eResetReturn = CAN_OK;
    /* Variable to hold the index of the current baudrate */
    VAR(uint8, AUTOMATIC) u8BaudrateIndex = 0U;
    /* Used to access configured table id and filtermask. */
    VAR(uint8, AUTOMATIC)             u8TempIndex = 0U;
    /*Variable for offset Filter*/
    VAR(uint8, AUTOMATIC)             u8RxFilterOffset = 0U;
    /*Variable configuration Filter */
    VAR(uint8, AUTOMATIC)             u8RxFilterConfig = 0U;
    /*Variable for type Filer */
    VAR(uint8, AUTOMATIC)             u8RxFilterType = 0U;
    /*Variable stores value Filter ID1*/
    VAR(uint32, AUTOMATIC)            u32RxFilterId1Value = 0U;
    /*Variable stores value Filter ID2*/
    VAR(uint32, AUTOMATIC)            u32RxFilterId2Value = 0U;
    /*Variable stores Shared RAM address offset of standard filter section */
    VAR(uint32, AUTOMATIC)            u32StdRxFilterAddOffset = 0U;
    /*Variable stores Shared RAM address offset of standard filter section */
    VAR(uint32, AUTOMATIC)            u32ExtdRxFilterAddOffset = 0U;
    /*Variable stores Shared RAM address offset of Rx Buffer section */
    VAR(uint32, AUTOMATIC)            u32RxBufferAddOffset = 0U;
    /*Variable stores Shared RAM address offset of Tx Buffer section */
    VAR(uint32, AUTOMATIC)            u32TxBufferAddOffset = 0U;        
    VAR(uint8, AUTOMATIC)             u8NumTxBuffer = 0U;        
    VAR(uint8, AUTOMATIC)             u8NumRxBuffer = 0U;        
    VAR(uint32, AUTOMATIC)            u32TempReg = 0U;

    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &(Can_43_MCAN_pCurrentConfig->ControlerDescriptors[controller]);
    
    /* Get pointer to Section Address offset of this controller */
    pCanControllerSectionOffset = pCanControlerDescriptor->pControllerSectionOffsetPtr;
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanStaticControlerDescriptor = &(Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller]);
    
    pCanMbConfigContainer   = &(Can_43_MCAN_pCurrentConfig->MBConfigContainer);
            
    /* Get the hardware offset for this controller. */
    u8HwOffset = pCanStaticControlerDescriptor->u8ControllerOffset;
    
    /* Get the shared RAM offset address of standard filter of this controller */
    u32StdRxFilterAddOffset = pCanControllerSectionOffset->StandardFilterOffset;
    
    /* Get the shared RAM offset address of extended filter of this controller */
    u32ExtdRxFilterAddOffset = pCanControllerSectionOffset->ExtendedFilterOffset;
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)          
    /* Get the shared RAM offset address of Rx FIFO 0 of this controller */
    u32RxFifo0AddOffset = pCanControllerSectionOffset->RxFifo0Offset;
    
    /* Get the shared RAM offset address of Rx FIFO 1 of this controller */
    u32RxFifo1AddOffset = pCanControllerSectionOffset->RxFifo1Offset;
#endif        
    /* Get the shared RAM offset address of Rx Buffer of this controller */
    u32RxBufferAddOffset = pCanControllerSectionOffset->RxBufferOffset;
    
    /* Get the shared RAM offset address of Tx Buffer of this controller */
    u32TxBufferAddOffset = pCanControllerSectionOffset->TxBufferOffset;
    
    u8NumTxBuffer = pCanControlerDescriptor->u8MaxMbTxCount;
    
    u8NumRxBuffer = pCanControlerDescriptor->u8MaxMbRxCount;

    eResetReturn = Can_MCan_ResetController( controller);

    /* Get the index of the current baudrate */
    u8BaudrateIndex = Can_43_MCAN_ControllerStatuses[controller].u8CurrentBaudRateIndex;

    if (CAN_OK == eResetReturn )
    {
        /* Init the Cancelled MB index with a precalculated value - out of range for every controller. */
        Can_43_MCAN_ControllerStatuses[controller].u32CancelMBIndex = pCanMbConfigContainer->uMessageBufferConfigCount;
        /*set the can controller to initialisation mode */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_CCCR(u8HwOffset), (uint32)(MCAN_CCCR_INIT_U32 | MCAN_CCCR_CCE_U32));
        /*Set to ASM mode */
        if ( CAN_43_MCAN_CONTROLLERCONFIG_CCCR_ASM_EN_U32 == (pCanStaticControlerDescriptor->u32Options & CAN_43_MCAN_CONTROLLERCONFIG_CCCR_ASM_EN_U32) )
        {
            /*Set the can controler restricted operation mode active */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_ASM_U32);
        }
        else
        {
            /*Set the can controler normal operation mode active */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_ASM_U32);
        }
        /* Set to Bus Monitoring Mode */
        if ( CAN_43_MCAN_CONTROLLERCONFIG_CCCR_MON_EN_U32 == (pCanStaticControlerDescriptor->u32Options & CAN_43_MCAN_CONTROLLERCONFIG_CCCR_MON_EN_U32) )
        {
            /* Bus Monitoring Mode is enabled */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_MON_U32);
        }
        else
        {
            /* Bus Monitoring Mode is disabled */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_MON_U32);
        }
        
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
        /* Configure the FD feature */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if( ((uint32)(MCAN_CCCR_INIT_U32 | MCAN_CCCR_CCE_U32)) == (((uint32)(REG_READ32(MCAN_CCCR(u8HwOffset)))) & ((uint32)(MCAN_CCCR_INIT_U32 | MCAN_CCCR_CCE_U32))))
        {
            /* Check the FD feature is enabled */
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
#ifdef IPV_MCAN
#if ((IPV_MCAN == IPV_MCAN_00_01_00_03) || (IPV_MCAN == IPV_MCAN_01_00_01_61))
            if ( MCAN_CCCR_CME_FDN_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable) )
#endif
#if (IPV_MCAN == IPV_MCAN_00_00_00_21) 
            if ( MCAN_CCCR_FDOE_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable) )
#endif 
#endif 
            {
                /* Check the switch rate feature */
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
#ifdef IPV_MCAN
#if ((IPV_MCAN == IPV_MCAN_00_01_00_03) || (IPV_MCAN == IPV_MCAN_01_00_01_61))
                if ( MCAN_CCCR_CME_BRS_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTxBitRateSwitch) )
#endif
#if (IPV_MCAN == IPV_MCAN_00_00_00_21) 
                if ( MCAN_CCCR_BRSE_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTxBitRateSwitch) )
#endif
#endif
                {
                    /* write data configuration into CCCR register */
                    /* Enable FD feature */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    REG_BIT_SET32(MCAN_CCCR(u8HwOffset),((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable)));
                    /* In this case, CAN operate with the switch rate feature */
                    /* Write in the CME field */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    REG_BIT_SET32(MCAN_CCCR(u8HwOffset),((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTxBitRateSwitch)));
                }
                else
                {
                    /* In this case, CAN don't operate with the switch rate feature */
                    /* Write in the CME field */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    REG_BIT_SET32(MCAN_CCCR(u8HwOffset),((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable)));
                }
                /* Write baudrate in FBTP register */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                REG_WRITE32(MCAN_FBTP(u8HwOffset), (uint32)(((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdCbtRegister)) & MCAN_FBTP_MASK_U32));
                
               /*Write Transceiver enable to DBTP[TDC] and TDCR[TDCO] - MCAN FD high baudrate*/
                if(((pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.CanControllerTrcvDelayEnabled) == TRUE) &&((uint32)((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTrcvDelayCompensation))!=0U))
                {
                    REG_BIT_SET32(MCAN_DBTP(u8HwOffset), CAN_43_MCAN_DBTP_TDC_MASK_U32);
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    REG_WRITE32(MCAN_TDCR(u8HwOffset) ,(uint32)(((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTrcvDelayCompensation)) & MCAN_TDCR_TDCO_MASK_U32));
                }
                else
                {
                    /*do nothing with MCAN classic*/
                }
            }
        }
        
        /* Calculate the MB size and the data lenght code for MB */
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */   
#ifdef IPV_MCAN
#if ((IPV_MCAN == IPV_MCAN_00_01_00_03) || (IPV_MCAN == IPV_MCAN_01_00_01_61))
        if ( MCAN_CCCR_CME_FDN_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable) )
#endif
#if (IPV_MCAN == IPV_MCAN_00_00_00_21)
        if ( MCAN_CCCR_FDOE_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanFdEnable) )
#endif 
#endif 
        {                 
            switch ((uint8)CAN_43_MCAN_REAL_PAYLOAD_U8)
            {
            case (MCAN_8_BYTES_U8):
                u8MbSize[controller] = 16U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_8_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_8_BYTES_DATA_SIZE_U32;
                break;
            case (MCAN_12_BYTES_U8):
                u8MbSize[controller] = 20U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_12_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_12_BYTES_DATA_SIZE_U32;
                break;
            case (MCAN_16_BYTES_U8):
                u8MbSize[controller] = 24U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_16_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_16_BYTES_DATA_SIZE_U32;
                break;
            case (MCAN_20_BYTES_U8):
                u8MbSize[controller] = 28U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_20_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_20_BYTES_DATA_SIZE_U32;
                break;
            case (MCAN_24_BYTES_U8):
                u8MbSize[controller] = 32U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_24_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_24_BYTES_DATA_SIZE_U32;
                break;
            case (MCAN_32_BYTES_U8):
                u8MbSize[controller] = 40U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_32_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_32_BYTES_DATA_SIZE_U32;
                break;
            case (MCAN_48_BYTES_U8):
                u8MbSize[controller] = 56U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_48_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_48_BYTES_DATA_SIZE_U32;
                break;
            case (MCAN_64_BYTES_U8):
                u8MbSize[controller] = 72U;
                u32RxBufferDataSize[controller] = MCAN_RXESC_64_BYTES_DATA_SIZE_U32;
                u32TxDataSize[controller]       = MCAN_TXESC_64_BYTES_DATA_SIZE_U32;
                break; 
            default :
                break;
            }
        }
        else
        {
            u8MbSize[controller] = 16U;   
        }
#else
u8MbSize[controller] = 16U;
#endif
        /*Configure the Baud Rate settings for the CAN controller */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        REG_WRITE32( MCAN_BTP(u8HwOffset), \
                     ((uint32)(pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegister) & MCAN_BTP_MASK_U32) \
                   );
        /*configure the CAN controller into internal loop back mode */
        if ( CAN_43_MCAN_CONTROLLERCONFIG_CCCR_TEST_EN_U32 == (pCanStaticControlerDescriptor->u32Options & CAN_43_MCAN_CONTROLLERCONFIG_CCCR_TEST_EN_U32) )
        {
            /* Test Mode, write access to register TEST enabled */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_TEST_U32);
            
            /* Bus Monitoring Mode is enabled */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_MON_U32);
            
            /* Loop Back mode is enabled */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_TEST(u8HwOffset), MCAN_TEST_LBCK_U32);
        }
        else
        {
            /* Normal operation, register TEST holds reset values */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_TEST_U32);
        }

        /* Init the Rx filter table. */                                   
        for ( u8TempIndex = 0U; u8TempIndex < (Can_43_MCAN_pCurrentConfig->u8NumberRxFilterTable); u8TempIndex++)
        {
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
            if (u8HwOffset == (Can_43_MCAN_pCurrentConfig->pRxFilterTableConfig)[u8TempIndex].u8ControllerOffset)
            {
                /* Calculate the physical address for each table to write the Table ID and FilterMask. */
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                u8RxFilterOffset = (Can_43_MCAN_pCurrentConfig->pRxFilterTableConfig)[u8TempIndex].u8RxFilterOffset;
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                u8RxFilterConfig = (Can_43_MCAN_pCurrentConfig->pRxFilterTableConfig)[u8TempIndex].u8RxFilterConfig;
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                u8RxFilterType = (Can_43_MCAN_pCurrentConfig->pRxFilterTableConfig)[u8TempIndex].u8RxFilterType;
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                u32RxFilterId1Value = (Can_43_MCAN_pCurrentConfig->pRxFilterTableConfig)[u8TempIndex].u32RxFilterId1Value;
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                u32RxFilterId2Value = (Can_43_MCAN_pCurrentConfig->pRxFilterTableConfig)[u8TempIndex].u32RxFilterId2Value;

                #if (CAN_43_MCAN_EXTENDEDID == STD_ON)
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                if ( CAN_43_MCAN_STANDARD == (Can_43_MCAN_pCurrentConfig->pRxFilterTableConfig)[u8TempIndex].eRxFilterMbType)
                {
                #endif /* (CAN_43_MCAN_EXTENDEDID == STD_ON) */
                    /* Clear the Standard Message ID Filter elements */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_WRITE32( (SCM_RAM_BASEADDR + ((uint32)u32StdRxFilterAddOffset << 2) + ((u8RxFilterOffset) * MCAN_SRAM_STD_FTR_LENGTH_U32)),0U);
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32( (SCM_RAM_BASEADDR + ((uint32)u32StdRxFilterAddOffset << 2) + ((u8RxFilterOffset) * MCAN_SRAM_STD_FTR_LENGTH_U32)), \
                                    (uint32)MCAN_SRAM_SMIDFE_SFID2_MASK_U32,u32RxFilterId2Value); 
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32( (SCM_RAM_BASEADDR + ((uint32)u32StdRxFilterAddOffset  << 2) + ((u8RxFilterOffset) * MCAN_SRAM_STD_FTR_LENGTH_U32)), \
                                    MCAN_SRAM_SMIDFE_SFID1_MASK_U32,u32RxFilterId1Value << MCAN_SRAM_SMIDFE_SFID1_SHIFT_U32);
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32( (SCM_RAM_BASEADDR + ((uint32)u32StdRxFilterAddOffset  << 2) + ((u8RxFilterOffset) * MCAN_SRAM_STD_FTR_LENGTH_U32)), \
                                   MCAN_SRAM_SMIDFE_SFEC_MASK_U32,(uint32)u8RxFilterConfig << MCAN_SRAM_SMIDFE_SFEC_SHIFT_U32) ;
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32( (SCM_RAM_BASEADDR + ((uint32)u32StdRxFilterAddOffset << 2) + ((u8RxFilterOffset) * MCAN_SRAM_STD_FTR_LENGTH_U32)), \
                                   MCAN_SRAM_SMIDFE_SFT_MASK_U32,(uint32)u8RxFilterType<< MCAN_SRAM_SMIDFE_SFT_SHIFT_U32);
                                   
                    u8NumberStdRxFilterCount++;
                #if (CAN_43_MCAN_EXTENDEDID == STD_ON)
                }
                else
                {
                    /* Clear the Extended Message ID Filter elements */                
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_WRITE32((SCM_RAM_BASEADDR+ ((uint32)u32ExtdRxFilterAddOffset << 2) + ((u8RxFilterOffset) * MCAN_SRAM_EXD_FTR_LENGTH_U32)), 0U);
                    /* Clear the Extended Message ID Filter elements */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_WRITE32((SCM_RAM_BASEADDR+ ((uint32)u32ExtdRxFilterAddOffset  << 2) + ((u8RxFilterOffset) * MCAN_SRAM_EXD_FTR_LENGTH_U32) + 4U), 0U);
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32((SCM_RAM_BASEADDR+ ((uint32)u32ExtdRxFilterAddOffset  << 2) + (((u8RxFilterOffset) * MCAN_SRAM_EXD_FTR_LENGTH_U32)+4U)), \
                                  MCAN_SRAM_EMIDFE_EFID_MASK_U32,u32RxFilterId2Value );
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32((SCM_RAM_BASEADDR+ ((uint32)u32ExtdRxFilterAddOffset << 2) + ((u8RxFilterOffset) * MCAN_SRAM_EXD_FTR_LENGTH_U32)), \
                                   MCAN_SRAM_EMIDFE_EFID_MASK_U32,u32RxFilterId1Value);
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32((SCM_RAM_BASEADDR+ ((uint32)u32ExtdRxFilterAddOffset << 2) + ((u8RxFilterOffset) * MCAN_SRAM_EXD_FTR_LENGTH_U32)), \
                                  MCAN_SRAM_EMIDFE_EFEC_MASK_U32,(uint32)u8RxFilterConfig << MCAN_SRAM_EMIDFE_EFEC_SHIFT_U32);
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_RMW32((SCM_RAM_BASEADDR+ ((uint32)u32ExtdRxFilterAddOffset << 2)  + (((u8RxFilterOffset) * MCAN_SRAM_EXD_FTR_LENGTH_U32)+4U)), \
                                   MCAN_SRAM_EMIDFE_EFEC_MASK_U32,(uint32)u8RxFilterType << MCAN_SRAM_EMIDFE_EFT_SHIFT_U32);
                    u8NumberExtdRxFilterCount++;
                }
                #endif /* (CAN_43_MCAN_EXTENDEDID == STD_ON) */
            }
        }
        
        /* Initialization of Standard ID filter section by writing value to SIDFC register */
        u32TempReg = (uint32)u32StdRxFilterAddOffset << MCAN_SIDFC_FLSSA_SHIFT_U32;
        
        u32TempReg |= (uint32)u8NumberStdRxFilterCount << MCAN_SIDFC_LSS_SHIFT_U32;
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */        
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */        
        REG_WRITE32( MCAN_SIDFC(u8HwOffset), u32TempReg);
        
        /* Initialization of Extended ID filter section by writing value to XIDFC register */
        
        u32TempReg = (uint32)u32ExtdRxFilterAddOffset << MCAN_XIDFC_FLESA_SHIFT_U32;
        
        u32TempReg |= (uint32)u8NumberExtdRxFilterCount << MCAN_XIDFC_LSE_SHIFT_U32;
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */        
        REG_WRITE32( MCAN_XIDFC(u8HwOffset), u32TempReg);
                    
        u16MbGlobalIndex  = 0U;
        u8MbCtrlIndex = 0U;
       
        while ( (u8MbCtrlIndex < pCanControlerDescriptor->u8MaxMbTxCount) &&
                (u16MbGlobalIndex < pCanMbConfigContainer->uMessageBufferConfigCount) 
              )
        {   /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
            if ( controller == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MbGlobalIndex)->u8ControllerId))
            {
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                if (CAN_43_MCAN_TRANSMIT == ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MbGlobalIndex)->eMBType )
                {
                    /* Transmission select by interrupt */
                    if ( CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 & pCanStaticControlerDescriptor->u32Options) )
                    {
                        Can_43_MCAN_ControllerStatuses[controller].u32MBInterruptMask |= ((uint32)1U << u8MbCtrlIndex);
                    }

                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    Can_43_MCAN_ControllerStatuses[controller].u32MbTxMapping[u8MbCtrlIndex] = \
                    ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u16MbGlobalIndex)->u32HWObjID;

                    u8MbCtrlIndex++;
                }
            }

            u16MbGlobalIndex++;
        }
                        
        /* Initialization of RxBuffer section */
        if(u8NumRxBuffer > 0U)
        {
            /*Initialization address offset section by writing value to RXBC register */
            u32TempReg = (uint32)u32RxBufferAddOffset << MCAN_RXBC_RBSA_SHIFT_U32;
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_RXBC(u8HwOffset), u32TempReg);
            
            /* Initialization of RxBuffer data payload size by writting value to RXESC */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32TempReg = REG_READ32(MCAN_RXESC(u8HwOffset));
            u32TempReg &= (~MCAN_RXESC_RBDS_MASK_U32);
          #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
            u32TempReg |= u32RxBufferDataSize[controller] << MCAN_RXESC_RBDS_SHIFT_U32;
          #else
            u32TempReg |= ((uint32)0U << MCAN_RXESC_RBDS_SHIFT_U32);
          #endif  
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_RXESC(u8HwOffset), u32TempReg & (MCAN_RXESC_MASK_U32) );
        }
        
        /* Initialization of TxBuffer section */
        if(u8NumTxBuffer > 0U)
        {
            /*Initialization address offset section by writing value to TXBC register */
            u32TempReg = (uint32)u32TxBufferAddOffset << MCAN_TXBC_TBSA_SHIFT_U32;
            
            /*Initialization number of Tx Buffer by writing value to TXBC register */
            u32TempReg |= (uint32)u8NumTxBuffer << MCAN_TXBC_NDTB_SHIFT_U32;
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_TXBC(u8HwOffset), u32TempReg & (MCAN_TXBC_MASK_U32) );
            
            /* Initialization of TxBuffer element size by writting value to TXESC */
          #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
            u32TempReg = u32TxDataSize[controller] << MCAN_TXESC_TBDS_SHIFT_U32;
          #else
            u32TempReg = ((uint32)0U << MCAN_TXESC_TBDS_SHIFT_U32);
          #endif
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_TXESC(u8HwOffset), u32TempReg & (MCAN_TXESC_MASK_U32));
        }
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)
        /* Initialization of Rx FIFO 0 section */
        if( NULL_PTR != pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)
        {   
            /* Get the pointer to the FIFO 0 configuration structure */
            pCanControllerRxFifoConfig = pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr;
            /* Initialized FIFO address offset section */
            u32TempReg = (uint32)u32RxFifo0AddOffset << MCAN_RXF0C_F0SA_SHIFT_U32;
            /* Initialized FIFO Depth */
            u32TempReg |= (uint32)(pCanControllerRxFifoConfig->FIFODepth) << MCAN_RXF0C_F0S_SHIFT_U32;
#if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)                
            /* Initialized FIFO Watermask Warning Level */
            u32TempReg |= (uint32)(pCanControllerRxFifoConfig->FIFOWaterMaskLevel) << MCAN_RXF0C_F0WM_SHIFT_U32;
#else
            /* Disabled RX FIFO 0 Watermark interrupt  */
            u32TempReg &= ~(MCAN_RXF0C_F0WM_MASK_U32);
#endif
            /* Write value to RXF0C register */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_RXF0C(u8HwOffset), u32TempReg & (MCAN_RXF0C_MASK_U32) );
            
            /* Initialized Rx FIFO 0 data payload size */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32TempReg = REG_READ32(MCAN_RXESC(u8HwOffset));
            u32TempReg &= (~MCAN_RXESC_F0DS_MASK_U32);
          #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
            u32TempReg |= u32RxBufferDataSize[controller] << MCAN_RXESC_F0DS_SHIFT_U32;
          #else
            u32TempReg |= ((uint32)0U << MCAN_RXESC_F0DS_SHIFT_U32);
          #endif
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_RXESC(u8HwOffset), u32TempReg & (MCAN_RXESC_MASK_U32) );
        }
        
        /* Initialization of Rx FIFO 1 section */
        if( NULL_PTR != pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr)
        {
            /* Get the pointer to the FIFO 1 configuration structure */
            pCanControllerRxFifoConfig = pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr;
            /* Initialized FIFO address offset section */
            u32TempReg = (uint32)u32RxFifo1AddOffset << MCAN_RXF1C_F1SA_SHIFT_U32;
            /* Initialized FIFO Depth */
            u32TempReg |= (uint32)(pCanControllerRxFifoConfig->FIFODepth) << MCAN_RXF1C_F1S_SHIFT_U32;
#if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)
            /* Initialized FIFO Watermask Warning Level */
            u32TempReg |= (uint32)(pCanControllerRxFifoConfig->FIFOWaterMaskLevel) << MCAN_RXF1C_F1WM_SHIFT_U32;
#else
            /* Disabled RX FIFO 1 Watermark interrupt  */
            u32TempReg &= ~(MCAN_RXF1C_F1WM_MASK_U32);
#endif                
            /* Write value to RXF1C register */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_RXF1C(u8HwOffset), u32TempReg & (MCAN_RXF1C_MASK_U32) );
            
            /* Initialized Rx FIFO 1 data payload size */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32TempReg = REG_READ32(MCAN_RXESC(u8HwOffset));
            u32TempReg &= (~MCAN_RXESC_F1DS_MASK_U32);
          #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
            u32TempReg |= u32RxBufferDataSize[controller] << MCAN_RXESC_F1DS_SHIFT_U32;
          #else
            u32TempReg |= ((uint32)0U << MCAN_RXESC_F1DS_SHIFT_U32);
          #endif
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_RXESC(u8HwOffset), u32TempReg & (MCAN_RXESC_MASK_U32) );
        }
#endif
            
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_GFC(u8HwOffset), MCAN_GFC_MASK_U32);

        /*Configure the Interrupt line source */
#if (CAN_43_MCAN_INTERRUPT_SUPPORTED == STD_ON)
        if( CAN_43_MCAN_CTLR_CONFIG_ILE_INTL0_EN_U32 == (CAN_43_MCAN_CTLR_CONFIG_ILE_INTL0_EN_U32 & pCanControlerDescriptor->u32Options) )
        {
            /* Interrupt assigned to interrupt line M_CAN INT0 */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_ILS(u8HwOffset), (uint32)(MCAN_NOT_MASK_32BITS_U32));
            /* Enable Interrupt Line 0 */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_ILE(u8HwOffset), (uint32)(MCAN_ILE_EINT0_U32));
        }

        if( CAN_43_MCAN_CTLR_CONFIG_ILE_INTL1_EN_U32 == (CAN_43_MCAN_CTLR_CONFIG_ILE_INTL1_EN_U32 & pCanControlerDescriptor -> u32Options) )
        {
            /* Interrupt assigned to interrupt line M_CAN INT1 */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_ILS(u8HwOffset),(uint32)MCAN_MASK_32BITS_U32);
            /* Enable Interrupt Line 1 */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_ILE(u8HwOffset),(uint32)(MCAN_ILE_EINT1_U32));
        }
#else
            /* Disable interrupt line when it is not used */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_ILE(u8HwOffset), MCAN_NOT_MASK_32BITS_U32);
#endif

        /*clear the contents of IR register */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_IR(u8HwOffset),(uint32)(MCAN_MASK_32BITS_U32));
    }
}
/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to another state/mode.
*                 This routine is called by:
*                  - Can_SetControllerMode() from Can.c file.
*                  - Can_MainFunction_BusOff() from Can.c file.
*                  - Can_MCan_SetControllerMode() from Can_MCan.c file.
*
* @param[in]      CAN controller for which mode has to be changed
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
* @param[in]      Transition Possible transitions
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
* @pre            Controller is configured and must be into a state that permit the valid transition to another different state.
* @post           Shall enable interrupts that are needed in the new state. Shall disable interrupts that are not allowed in the new state.
*
* @requirements   CAN283
*
*/


FUNC (Can_ReturnType, CAN_43_MCAN_CODE) Can_MCan_SetControllerMode( VAR(uint8, AUTOMATIC) controller, \
                                                            P2CONST(Can_43_MCAN_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor, \
                                                            VAR(Can_StateTransitionType, AUTOMATIC) Transition, \
                                                            VAR(boolean, AUTOMATIC) canif_notification_required
                                                          )
{
  /* Variable store return status. */
    VAR(Can_ReturnType, AUTOMATIC)  eReturnValue = CAN_NOT_OK;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC)           u8HwOffset = 0U;
    /* Timeout counter. */
    VAR(uint32, AUTOMATIC)          u32TimeoutCount = 0U;
    /* Template Variable */
    VAR(uint32, AUTOMATIC)          u32TempVar = 0U;
    
    P2CONST(Can_43_MCANStatic_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanStaticControlerDescriptor = NULL_PTR;
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)        
    P2CONST(Can_43_MCAN_ControllerRxFifoConfigType, AUTOMATIC, CAN_APPL_CONST) pCanControllerRxFifoConfig = NULL_PTR;
#endif   
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanStaticControlerDescriptor = &(Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller]);
    
    /* Get the hardware offset for this controller. */
    u8HwOffset = pCanStaticControlerDescriptor->u8ControllerOffset;

    switch (Transition)
    {
        /* CANIF_CS_STARTED -> CANIF_CS_STOPPED. */
        case (CAN_T_STOP):

            if ( CAN_43_MCAN_STOPPED == Can_43_MCAN_ControllerStatuses[controller].ControllerState)
            {
                eReturnValue = CAN_OK;
            }
            else
            {
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
                if ( CAN_43_MCAN_STARTED != Can_43_MCAN_ControllerStatuses[controller].ControllerState)
                {
                        
                        (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_MCAN_E_TRANSITION);
                }
                else
                {
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */

                    /* Cancel the MB (just in case it is scheduled for Tx). This is a HARD ABORT, confirmation of whether the MB was transmitted or not is not required. */
                    /*
                        (CAN282) The function Can_SetControllerMode(CAN_T_STOP) shall cancel pending messages.
                        (CAN273)After bus-off detection, the Can module shall cancel still pending messages without raising a cancellation notification.
                    */
                    /* Clear Tx_complete_guard flags, in this state driver does not allow transmit, but guard for sure. */
                    SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_03();
                    Can_43_MCAN_ControllerStatuses[controller].Tx_complete_guard = (uint32)0x0UL;
                    SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_03();
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_WRITE32( MCAN_TXBCR(u8HwOffset), (uint32)(MCAN_MASK_32BITS_U32)); 
                    
                #if((!defined (ERR_IPV_MCAN_0001 ))&& (defined (ERR_IPV_MCAN_0003)))
                    #if (ERR_IPV_MCAN_0003 == STD_ON)
                        /*Can enters into Initializaton mode & access to write protected registers is enabled */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CSR_U32);
                        /* load local time-out variable with configured time-out value */                            
                        u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        while ((((REG_READ32( MCAN_CCCR(u8HwOffset))) & (MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32)) != (MCAN_CCCR_INIT_U32|MCAN_CCCR_CSA_U32))&&(u32TimeoutCount>(uint32)0x0U))
                        {
                            u32TimeoutCount--;
                        }
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_CSR_U32);
                    #else
                        #error: The define ERR_IPV_MCAN_0003 should not be STD_OFF
                    #endif
                #else
                        /* Set INIT bit to change controller mode to initialization state */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_BIT_SET32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_INIT_U32);
                #endif

                    /* if interrupt enable then reset interrupt */
                    if (CAN_43_MCAN_INTERRUPT_ENABLED == Can_43_MCAN_ControllerStatuses[controller].eInterruptMode )
                    {
                        
                        /* Disable all interrupt flags - reset interrupt */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_WRITE32( MCAN_IE(u8HwOffset), (uint32)(MCAN_NOT_MASK_32BITS_U32));

                        /* Transmission interrupt disabled */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_WRITE32( MCAN_TXBTIE(u8HwOffset), (uint32)(MCAN_NOT_MASK_32BITS_U32));

                        /* Cancellation finished interrupt disabled */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_WRITE32( MCAN_TXBCIE(u8HwOffset), (uint32)(MCAN_NOT_MASK_32BITS_U32));
                    }

                    u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
                    u32TempVar = (uint32)0U;
                    do 
                    {
                        u32TimeoutCount--;
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u32TempVar |= ( (uint32)((REG_READ32( MCAN_CCCR(u8HwOffset))) & ( MCAN_CCCR_INIT_U32)));
                    } while ((u32TimeoutCount > (uint32)0x0U) && ( u32TempVar != (MCAN_CCCR_INIT_U32)));
                    
                    if(MCAN_CCCR_INIT_U32== u32TempVar)
                    {
                        Can_43_MCAN_ControllerStatuses[controller].ControllerState = CAN_43_MCAN_STOPPED;

                        eReturnValue = CAN_OK;

                    }/* what about NOT_OK status  */
                    else
                    /* software timeout */
                    {
                        
                        eReturnValue = CAN_NOT_OK;
                    }
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
                }
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */
            }
            if (CAN_OK == eReturnValue)
            {
                if ((boolean)TRUE == canif_notification_required)
                {
                    CanIf_ControllerModeIndication(controller, CANIF_CS_STOPPED);
                }
            }
            break;

        /* CANIF_CS_STOPPED -> CANIF_CS_STARTED. */
        case (CAN_T_START):

#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
                if ( CAN_43_MCAN_STOPPED != Can_43_MCAN_ControllerStatuses[controller].ControllerState)
                {
                        
                        (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_MCAN_E_TRANSITION);
                }
                else
                {
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */

#ifdef ERR_IPV_MCAN_0001 
#if (ERR_IPV_MCAN_0001 == STD_ON)
                    Can_Mcan_Implement_EARATA_8655(u8HwOffset);
#endif
#endif 

#if (CAN_43_MCAN_DUAL_CLOCK_MODE == STD_OFF)
                    Can_MCan_ChangeBaudrate(controller);
#endif
                    /* Clear Tx_complete_guard flags, in this state driver does not allow transmit, but guard for sure. */
                    SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_03();
                    Can_43_MCAN_ControllerStatuses[controller].Tx_complete_guard = (uint32)0x0UL;
                    SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_03();

                    /* Normal Operation */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_BIT_CLEAR32( MCAN_CCCR(u8HwOffset), MCAN_CCCR_INIT_U32);

                    u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
                    
                    /*Wait until INIT bit is cleared, as there is delay in synchronisation between two clock domains */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    while ((((REG_READ32(MCAN_CCCR(u8HwOffset)))&(MCAN_CCCR_INIT_U32)) == (MCAN_CCCR_INIT_U32))&&(u32TimeoutCount>(uint32)0x0U))
                    {
                        u32TimeoutCount--;
                    }
                    if(u32TimeoutCount == 0U)
                    {
                        eReturnValue = CAN_NOT_OK;
                    }
                    else
                    {               
                        /* Check interrupt enable */
                        if (CAN_43_MCAN_INTERRUPT_ENABLED == Can_43_MCAN_ControllerStatuses[controller].eInterruptMode )
                        {
                            /* Transmission select by interrupt */
                            if (CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 & pCanStaticControlerDescriptor->u32Options))
                            {
                                /* Transmission Completed Interrupt Enable */
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_TC_U32);
                                
                                /* Enable transmission interrupts respective with masks*/
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_WRITE32( MCAN_TXBTIE(u8HwOffset), (uint32)(Can_43_MCAN_ControllerStatuses[controller].u32MBInterruptMask));
                                
                                /* Enable cancellation finished interrupts respective with masks */
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_WRITE32( MCAN_TXBCIE(u8HwOffset), (uint32)(Can_43_MCAN_ControllerStatuses[controller].u32MBInterruptMask));
                            }
                        
                            /* Receive select by interrupt */
                            if(CAN_43_MCAN_CONTROLLERCONFIG_RXPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_RXPOL_EN_U32 & pCanStaticControlerDescriptor->u32Options))
                            { 
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)                            
                                /* Rx FIFO 1 New Message Interrupt Enable */
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1N_U32);
                                /* Rx FIFO 0 New Message Interrupt Enable */
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0N_U32);
#endif                                    
                                /* Message stored to Dedicated Rx Buffer Interrupt Enable */
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_DRX_U32);
                            }
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)                                 
                            /* Setup interrupt for Rx Fifo 0 */
                            if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)
                            {
                                pCanControllerRxFifoConfig = pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr;
                                if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOOverflowPolling)
                                {
                                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                    REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0F_U32);
                                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                    REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0L_U32);
                                }
#if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)                                        
                                if(pCanControllerRxFifoConfig->FIFOWaterMaskLevel > 0U)
                                {
                                    if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOWaterMaskPolling)
                                    {
                                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                        REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0W_U32);
                                    }
                                }
#endif                                    
                            }
                            /* Setup interrupt for Rx Fifo 1 */
                            if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr)
                            {                                
                                pCanControllerRxFifoConfig = pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr;
                                if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOOverflowPolling)
                                {
                                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                    REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1F_U32);
                                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                    REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1L_U32);
                                }
#if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)                                        
                                if(pCanControllerRxFifoConfig->FIFOWaterMaskLevel > 0U)
                                {
                                    if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOWaterMaskPolling)
                                    {
                                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                        REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1W_U32);
                                    }
                                }
#endif                                    
                            }
#endif                                
                            /* BusOff select by interrupt */
                            if ( CAN_43_MCAN_CONTROLLERCONFIG_BOPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_BOPOL_EN_U32 & pCanStaticControlerDescriptor->u32Options))
                            {
                                /* Bus_Off Status Interrupt Enable */
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_BO_U32);
                            }
                          #if (CAN_43_MCAN_SUPPORT_MRAF_EVENT == STD_ON)
                            if ( CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32 != (pCanStaticControlerDescriptor->u32Options & CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32) )
                            {
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_MRAF_U32);
                            }
                           #endif
                            /* Error Notification enabled */
                            if ( CAN_43_MCAN_CONTROLLERCONFIG_ERR_EN_U32 == (pCanStaticControlerDescriptor->u32Options & CAN_43_MCAN_CONTROLLERCONFIG_ERR_EN_U32) )
                            {
                                /* Stuff Error Interrupt Enable, Format Error Interrupt Enable, Acknowledge Error Interrupt Enable, Bit Error Interrupt Enable */
                                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                                REG_RMW32(MCAN_IE(u8HwOffset), MCAN_ERR_INTERRUPT_U32, MCAN_ERR_INTERRUPT_U32);
                            }
                        }
                        /* Set the Start State. */
                        Can_43_MCAN_ControllerStatuses[controller].ControllerState = CAN_43_MCAN_STARTED;
                        eReturnValue = CAN_OK;
                    }
                    
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
                }
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */
            if (CAN_OK == eReturnValue)
            {
                CanIf_ControllerModeIndication(controller, CANIF_CS_STARTED);
            }
            break;

        /* CANIF_CS_STOPPED -> CANIF_CS_SLEEP. */
        case (CAN_T_SLEEP):
            if ( CAN_43_MCAN_SLEEPED == Can_43_MCAN_ControllerStatuses[controller].ControllerState )
            {
                /* If the controller is already in SLEEP state, return CAN_OK. */
                eReturnValue = CAN_OK;
            }
            else
            {
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
                /* Valid transitions to Sleep state are only from Stop state. */
                if ( CAN_43_MCAN_STOPPED != Can_43_MCAN_ControllerStatuses[controller].ControllerState)
                {
                        
                        (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_MCAN_E_TRANSITION);
                }
                else
                {
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */
                    eReturnValue = CAN_OK;
                    Can_43_MCAN_ControllerStatuses[controller].ControllerState = CAN_43_MCAN_SLEEPED;
                    CanIf_ControllerModeIndication(controller, CANIF_CS_SLEEP);

#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
                }
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */
            }
            break;

        /* CANIF_CS_SLEEP -> CANIF_CS_STOPPED */
        case (CAN_T_WAKEUP):
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
            /* Valid transitions to Wakeup state are only from Sleep state. */
            if( (CAN_43_MCAN_SLEEPED != Can_43_MCAN_ControllerStatuses[controller].ControllerState) && \
                (CAN_43_MCAN_STOPPED != Can_43_MCAN_ControllerStatuses[controller].ControllerState) \
              )
            {
                    
                    (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_MCAN_E_TRANSITION);
            }
            else
            {
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */
                /* When Wakeup is not supported the driver should only change state and return CAN_OK. (implement of logical sleep) */
                eReturnValue = CAN_OK;
                Can_43_MCAN_ControllerStatuses[controller].ControllerState = CAN_43_MCAN_STOPPED;
                CanIf_ControllerModeIndication(controller, CANIF_CS_STOPPED);                        
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
            }
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */                                                            
            break;

        default:
#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
                
                (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_43_MCAN_E_TRANSITION);
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */
            break;
    }

    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief          Service disables all interrupts for the given CAN controller.
* @details        This routine is called by:
*                 - Can_DisableControllerInterrupts() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
*
* @pre            Disable interrupts must be called prior to enable interrupts.
* @post           Clear all flags/bits that are needed for disabling the interrupts.
*
*
*/
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) controller )
{
    /* Hardware Can controller offset. */
    VAR(uint8, AUTOMATIC)   u8HwOffset = 0U;
    /* Allow CAN to enter the specific critical region */
    
    P2CONST(Can_43_MCANStatic_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanStaticControlerDescriptor = NULL_PTR;
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanStaticControlerDescriptor = &(Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller]);
    
    SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_00();

    Can_43_MCAN_ControllerStatuses[controller].s8IntDisableLevel++;

    if ( (sint8)1 == Can_43_MCAN_ControllerStatuses[controller].s8IntDisableLevel )
    {
        /* Allow CAN to exit the specific critical region */
        SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_00();

        Can_43_MCAN_ControllerStatuses[controller].eInterruptMode = CAN_43_MCAN_INTERRUPT_DISABLED;

        u8HwOffset = pCanStaticControlerDescriptor->u8ControllerOffset;

        /* Disable all interrupt flags - reset interrupt */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_IE(u8HwOffset), (uint32)(MCAN_NOT_MASK_32BITS_U32));

        /* Transmission interrupt disabled */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_TXBTIE(u8HwOffset), (uint32)(MCAN_NOT_MASK_32BITS_U32));
        
        /* Cancellation finished interrupt disabled */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_TXBCIE(u8HwOffset), (uint32)(MCAN_NOT_MASK_32BITS_U32));
    }
    else
    {
        /* Allow CAN to exit the specific critical region */
        SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_00();
    }
}

/*================================================================================================*/
/**
* @brief          Service enables all interrupts that shall be enabled according the current software status.
* @details        This routine is called by:
*                  - Can_EnableControllerInterrupts() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      pCanControlerDescriptor Pointer to controller descriptor configuration
*
* @pre            Can be executed only if disable interrupts was called before.
* @post           Enable all interrupts that must be enabled according the current sw status.
*
*
*/
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) controller,
                                                           P2CONST(Can_43_MCAN_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanControlerDescriptor
                                                         )                                                                                                                   
{
    /* Hardware Can controller offset. */
    VAR(uint8, AUTOMATIC)   u8HwOffset = 0U;

    VAR(uint8, AUTOMATIC)   u8DisCalledBefore = 0U;
    
    P2CONST(Can_43_MCANStatic_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanStaticControlerDescriptor = NULL_PTR;
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON) 
    /* Local copy of pointer to the Fifo configuration structure */
    P2CONST(Can_43_MCAN_ControllerRxFifoConfigType, AUTOMATIC, CAN_APPL_CONST) pCanControllerRxFifoConfig = NULL_PTR;
#endif    
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanStaticControlerDescriptor = &(Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller]);

    if ( Can_43_MCAN_ControllerStatuses[controller].s8IntDisableLevel > (sint8)0 )
    {
        /* Allow CAN to enter the specific critical region */
        SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_01();

        Can_43_MCAN_ControllerStatuses[controller].s8IntDisableLevel--;

        u8DisCalledBefore = (uint8)0x1U;
    }

    if ( ((sint8)0 == Can_43_MCAN_ControllerStatuses[controller].s8IntDisableLevel) && ((uint8)0x1U == u8DisCalledBefore) )
    {
        /* Allow CAN to exit the specific critical region */
        SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_01();
        /* Check interrupt enable */
        Can_43_MCAN_ControllerStatuses[controller].eInterruptMode = CAN_43_MCAN_INTERRUPT_ENABLED;
        /* read CAN hardware offset  */
        u8HwOffset = pCanStaticControlerDescriptor->u8ControllerOffset;
        /* Transmission select by interrupt */
        if (CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 & pCanStaticControlerDescriptor->u32Options))
        {
            /* Transmission Completed Interrupt Enable */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_TC_U32);
            /* Enable transmission interrupts respective with masks*/
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_TXBTIE(u8HwOffset), (uint32)(Can_43_MCAN_ControllerStatuses[controller].u32MBInterruptMask));
            /* Enable cancellation finished interrupts respective with masks */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_TXBCIE(u8HwOffset), (uint32)(Can_43_MCAN_ControllerStatuses[controller].u32MBInterruptMask));
            
        }
        /* Receive select by interrupt */
        if(CAN_43_MCAN_CONTROLLERCONFIG_RXPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_RXPOL_EN_U32 & pCanStaticControlerDescriptor->u32Options))
        {
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)                 
            /* Rx FIFO 1 New Message Interrupt Enable */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1N_U32);
            /* Rx FIFO 0 New Message Interrupt Enable */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0N_U32);
#endif                
            /* Message stored to Dedicated Rx Buffer Interrupt Enable */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_DRX_U32);
        }
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)             
        /* Setup interrupt for Rx Fifo 0 */
        if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)
        {
            pCanControllerRxFifoConfig = pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr;
            if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOOverflowPolling)
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0F_U32);
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0L_U32);
            }
#if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)
            if(pCanControllerRxFifoConfig->FIFOWaterMaskLevel > 0U)
            {
                if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOWaterMaskPolling)
                {
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF0W_U32);
                }
            }
#endif
        }
        /* Setup interrupt for Rx Fifo 1 */
        if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr)
        {                                
            pCanControllerRxFifoConfig = pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr;
            if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOOverflowPolling)
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1F_U32);
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1L_U32);
            }
#if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)                    
            if(pCanControllerRxFifoConfig->FIFOWaterMaskLevel > 0U)
            {
                if((boolean)FALSE == pCanControllerRxFifoConfig->FIFOWaterMaskPolling)
                {
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_RF1W_U32);
                }
            }
#endif
        }
#endif
        /* BusOff select by interrupt */
        if ( CAN_43_MCAN_CONTROLLERCONFIG_BOPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_BOPOL_EN_U32 & pCanStaticControlerDescriptor->u32Options))
        {
                /* Bus_Off Status Interrupt Enable */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_BO_U32);
            
        }
        /* Error Notification enabled */
        if ( CAN_43_MCAN_CONTROLLERCONFIG_ERR_EN_U32 == (pCanStaticControlerDescriptor->u32Options & CAN_43_MCAN_CONTROLLERCONFIG_ERR_EN_U32) )
        {
            /* Stuff Error Interrupt Enable, Format Error Interrupt Enable, Acknowledge Error Interrupt Enable, Bit Error Interrupt Enable */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_RMW32(MCAN_IE(u8HwOffset), MCAN_ERR_INTERRUPT_U32, MCAN_ERR_INTERRUPT_U32);

        }
      #if (CAN_43_MCAN_SUPPORT_MRAF_EVENT == STD_ON)
        if ( CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32 != (pCanStaticControlerDescriptor->u32Options & CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32) )
        {
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_BIT_SET32( MCAN_IE(u8HwOffset), MCAN_INTERRUPT_MRAF_U32);
        }
      #endif
    }
    else
    {
        if ( Can_43_MCAN_ControllerStatuses[controller].s8IntDisableLevel > (sint8)0 )
        {
            /* Allow CAN to exit the specific critical region */
            SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_01();
        }
    }
}

/*================================================================================================*/
/**
* @brief          Local function for canceling low priority msg during Can Write operation.
* @details        This routine is called by:
*                  - Can_MCan_Write() from Can_Mcan.c file.
*                  - Can_MCan_AbortMb() from Can_Mcan.c file.
*
* @param[in]      controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex index of the message buffer to be canceled
*
* @pre            A Tx message with a higher priority was requested for a MB.
* @post           Inform CanIf about cancellation in case of success.
*
*
*/

#if (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON)
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_Cancel( VAR(uint8, AUTOMATIC) controller, VAR(uint8, AUTOMATIC) mbindex)
{
    /* Hardware Can controller offset. */
    VAR(uint8, AUTOMATIC)    u8HwOffset = 0U;

    /* Read CAN controller offset */
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    if ( ((uint32)(REG_READ32( MCAN_TXBRP(u8HwOffset)) & (uint32)((uint32)(1U) << mbindex))) == (uint32)((uint32)1U << mbindex ) )
    {
        /* Check transmission request pending of each Tx Buffer if have a request pending then cancellation pending */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_TXBCR(u8HwOffset), ((uint32)(1U) << (uint32)(mbindex)));
    }
}

#endif /* (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

#if ((CAN_43_MCAN_API_ENABLE_ABORT_MB == STD_ON) && (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON))


/*================================================================================================*/
/**
* @brief          Process a message buffer abort
* @details        This function write a abort code (b'1001) to MBCS[CODE] field of the MB.
*                This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth - HW-transmit handler
*
* @pre            Driver must be initialized and the current MB transmission should be ready for transmit.
*
*
*/

FUNC(void, CAN_43_MCAN_CODE) Can_MCan_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth )
{
    VAR(uint8, AUTOMATIC) u8Controller;
    VAR(uint8, AUTOMATIC) u8MbTxIndex = 0U;

    u8Controller = (Can_43_MCAN_pCurrentConfig->u8ControllerIdMapping)[Hth];

    while( (Can_43_MCAN_ControllerStatuses[u8Controller].u32MbTxMapping[u8MbTxIndex] != Hth) && \
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
           (u8MbTxIndex < Can_43_MCAN_pCurrentConfig->ControlerDescriptors[u8Controller].u8MaxMbTxCount) 
         )
    {
        u8MbTxIndex++;
    }

#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
    /* Test if controller is in valid range. */
    if ( (u8Controller >= (uint8)Can_43_MCANStatic_pCurrentConfig->u8ControllersConfigured) || \
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
         (MCAN_NULL_OFFSET_U8 == (Can_43_MCANStatic_pControlerDescriptors[u8Controller].u8ControllerOffset)) 
       )
    {
                
                (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_ABORT_MB, (uint8)CAN_43_MCAN_E_PARAM_CONTROLLER);
    }
    else
    {
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */

    #if(CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON)
    /*Now we must search the MessageBuffer that has the code specific to a TX Activated MB(sending message in progress), in the range of the Hth.*/
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    while( (Can_43_MCAN_ControllerStatuses[u8Controller].u32MbTxMapping[u8MbTxIndex] == Hth) && (u8MbTxIndex < (Can_43_MCAN_pControlerDescriptors[u8Controller].u8MaxMbTxCount)) )
    {
        Can_MCan_Cancel( u8Controller, u8MbTxIndex);
        u8MbTxIndex++;
    }
    #else
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    if( (u8MbTxIndex < (Can_43_MCAN_pControlerDescriptors[u8Controller].u8MaxMbTxCount)) && \
        (Can_43_MCAN_ControllerStatuses[u8Controller].u32MbTxMapping[u8MbTxIndex] == Hth) 
      )
    {
        Can_MCan_Cancel( u8Controller, u8MbTxIndex);
    }
    #endif

#if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (CAN_43_MCAN_API_ENABLE_ABORT_MB == STD_ON) && (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

/*================================================================================================*/
/**
* @brief          Can_MCan_Write checks if hardware transmit object that is identified by the HTH is free.
* @details        Can_MCan_Write checks if hardware transmit object that is identified by the HTH is free.
*                     Can_Write checks if another Can_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers/buffers.
*                         All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with CAN_OK.
*                     b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                         The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                         The transmission of the previous L-PDU is cancelled (asynchronously).
*                         The function returns with CAN_BUSY.
*                         This routine is called by:
*                         - Can_Write() from Can.c file.
*                     Algorithm Description:
*                     Case1: TxMUX supported = ON
*                           Can_Write receive the Hth handle and the PduInfo for transmission. It starts to check from the first MBs of the
*                           current controller to search for a free MB. On the first free MB it stops and place the PduInfo and activate the transmission.
*                           In this case function set CAN_OK for return value and all other functionality is skipped.
*                           If no MB is finded as free then the lowest priority MB is selected for comparing with the priority of the current PduInfo.
*                           If the current PduInfo has a higher priority than the current lower priority (from all MBs) then this lower priority MB is canceled.
*                    Case2: TxMUX supported = OFF
*                          CanWrite() receive the Hth handle and the PduInfo for transmission. It checks if MB with the same index as Hth is free and if yes prepare
*                          and sends the current PduInfo data. If that MB is bussy with another data then it checks the priority between these 2 structures.
*                          Depending by the last evaluation it decides what MB data to cancel.
*
* @param[in]      Hth information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use
*                 because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier
*
* @return          Can_ReturnType
* @retval          CAN_OK write command has been accepted
* @retval          CAN_NOT_OK development error occured
* @retval          CAN_BUSY no TX hardware buffer available or preemtive call of Can_Write() that can't be implemented reentrant
*
* @pre            The MB must be configured for Tx.
* @post           Transmit the data or ignore it in case of MB is full with another task.
*
*
*/

FUNC (Can_ReturnType, CAN_43_MCAN_CODE) Can_MCan_Write( Can_HwHandleType Hth, P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo )
{
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_43_MCAN_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
    /* Local copy of pointer to the section address offset descriptor. */
    P2CONST(Can_43_MCAN_ControllerSectionOffsetType, AUTOMATIC, CAN_APPL_CONST) pCanControllerSectionOffset = NULL_PTR;
    VAR(Can_ReturnType, AUTOMATIC) eReturnValue = CAN_BUSY; /* Variable store return status. */
    VAR(uint8, AUTOMATIC)          u8MbIndex = 0U;  /* Index CAN Message Buffers from configuration. */
    VAR(uint32, AUTOMATIC)          u32TxBufferAddOffset = 0U;
    VAR(uint32, AUTOMATIC) u32WordIndex;
    VAR(uint32, AUTOMATIC) u32BitIndex;
#if ((CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON))
    VAR(uint8, AUTOMATIC)          u8MbLprioIndex = 0U;
    VAR(uint32, AUTOMATIC)         u32MbLprioId = 0U;
#endif /* ((CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON)) */
    VAR(uint8, AUTOMATIC)          u8HwOffset = 0U;  /* Hardware Can controller offset. */
    VAR(uint32, AUTOMATIC)         u32TempFlag = 0U;
    VAR(uint32, AUTOMATIC)         u32MbMessageId = 0U;
    VAR(uint8, AUTOMATIC)          u8MbDataByte = 0U;
    VAR(uint8, AUTOMATIC)          u8ByteIndex = 0U;
    VAR(uint32, AUTOMATIC)         u32ByteShiftArray[4U]={0U,8U,16U,24U};
    VAR(uint32, AUTOMATIC)         u32BaseAddress = 0U;
    VAR(uint8, AUTOMATIC)          u8CtrlId = (Can_43_MCAN_pCurrentConfig->u8ControllerIdMapping)[Hth];
    VAR(uint8, AUTOMATIC)          u8NumberWord = 0U;
    VAR(uint8, AUTOMATIC)          u8IndexWord = 0U;    
    VAR(uint32, AUTOMATIC)         u32DataWord = 0U;
    /*Variable stores value of data lenght code*/
    VAR(uint32, AUTOMATIC)         u32DataLengthCode = 0U;
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
    VAR(uint8, AUTOMATIC)          u8BaudrateIndex  = 0U;
    VAR(uint8, AUTOMATIC)          u8PaddingValue;
    VAR(uint32, AUTOMATIC)         u32TimeoutCount = 0U;
#endif

    u32WordIndex = Hth / (uint32)32U;
    u32BitIndex = Hth % (uint32)32U;
    SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_04();
    if (0U == (Can_u32HOHStatus[u32WordIndex] & ((uint32) 1U << u32BitIndex)))
    {
        Can_u32HOHStatus[u32WordIndex] |=  (uint32) 1U << u32BitIndex;
        SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_04();
#if ((CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON))
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        u8MbLprioIndex = Can_43_MCAN_pCurrentConfig->ControlerDescriptors[u8CtrlId].u8MaxMbTxCount - (uint8)0x1U;
#endif /* ((CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON)) */

        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset;
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        pCanControlerDescriptor = &(Can_43_MCAN_pCurrentConfig->ControlerDescriptors[u8CtrlId]);
    
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
        u8BaudrateIndex = Can_43_MCAN_ControllerStatuses[u8CtrlId].u8CurrentBaudRateIndex;
#endif

        pCanControllerSectionOffset = pCanControlerDescriptor->pControllerSectionOffsetPtr;
        /* Get the shared RAM offset address of Tx Buffer of this controller */
        u32TxBufferAddOffset = pCanControllerSectionOffset->TxBufferOffset;
    
/* Check the current mode: correct */
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
        u32TimeoutCount = (uint32)CAN_43_MCAN_TIMEOUT_DURATION;
        u32MbMessageId = (uint32)PduInfo->id;
        /* Check type of frame */
        if( ((uint32)CAN_43_MCAN_FD_ID_DESCRIPTOR) == (((uint32)u32MbMessageId) & ((uint32)CAN_43_MCAN_FD_ID_DESCRIPTOR)) )
        {
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
#if ((IPV_MCAN == IPV_MCAN_00_01_00_03) || (IPV_MCAN == IPV_MCAN_01_00_01_61))
            if(((uint32)MCAN_CCCR_FDO_CONFIGURATION) == (REG_READ32(MCAN_CCCR(u8HwOffset)) & ((uint32)MCAN_CCCR_FDO_CONFIGURATION)))
#else
            if(((uint32)MCAN_CCCR_FDOE_U32) == (REG_READ32(MCAN_CCCR(u8HwOffset)) & ((uint32)MCAN_CCCR_FDOE_U32)))
#endif
            {
                eReturnValue = CAN_OK;
            }
            else
            {
                /* Wait all transmition finished in order to change mode for transmition */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                while (( 0U != (uint32)((uint32)(REG_READ32( MCAN_TXBRP(u8HwOffset))))) && (u32TimeoutCount > (uint32)0x00U))
                {
                    u32TimeoutCount--;
                }
                if (0U == u32TimeoutCount)
                {
                    /* Have pedding in the CAN bus */
                    eReturnValue = CAN_BUSY;
                }
                else
                {
#ifdef IPV_MCAN
#if ((IPV_MCAN == IPV_MCAN_00_01_00_03) || (IPV_MCAN == IPV_MCAN_01_00_01_61))
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    if (MCAN_CCCR_CME_BRS_U32 == (pCanControlerDescriptor->pControllerBaudrateConfigsPtr[u8BaudrateIndex].ControllerFD.u32CanControllerTxBitRateSwitch))
                    {
                        /* Write in the CMR field */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_BIT_SET32(MCAN_CCCR(u8HwOffset), MCAN_CCCR_CMR_BRS_U32);
                    }
                    else
                    {
                        /* Write in the CMR field */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_BIT_SET32(MCAN_CCCR(u8HwOffset), MCAN_CCCR_CMR_NOT_BRS_U32);
                    }
#endif
#endif
                    eReturnValue = CAN_OK;
                }
            }
        }
        else /* Not FD frame */
        {
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
#ifdef IPV_MCAN
#if ((IPV_MCAN == IPV_MCAN_00_01_00_03) || (IPV_MCAN == IPV_MCAN_01_00_01_61))
            if((uint32)0U == (REG_READ32(MCAN_CCCR(u8HwOffset)) & ((uint32)MCAN_CCCR_FDO_CONFIGURATION)))
#else
            if((uint32)0U == (REG_READ32(MCAN_CCCR(u8HwOffset)) & ((uint32)MCAN_CCCR_FDOE_U32)))
#endif
            {
                eReturnValue = CAN_OK;
            }
            else
#endif
            {
                /* Wait all transmition finished in order to change mode for transmition */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                while (( 0U != (uint32)((uint32)(REG_READ32( MCAN_TXBRP(u8HwOffset))))) && (u32TimeoutCount > (uint32)0x00U))
                {
                    u32TimeoutCount--;
                }
                if (0U == u32TimeoutCount)
                {
                    /* Have pedding in the CAN bus */
                    eReturnValue = CAN_BUSY;
                }
                else
                {
                    /* Write in the CMR field */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
#ifdef IPV_MCAN
#if ((IPV_MCAN == IPV_MCAN_00_01_00_03) || (IPV_MCAN == IPV_MCAN_01_00_01_61))
                    REG_RMW32(MCAN_CCCR(u8HwOffset), MCAN_CCCR_CMR_FSTD_U32, MCAN_CCCR_CMR_FSTD_U32);
#endif
#endif
                    eReturnValue = CAN_OK;
                }
            }
        }
#endif
    
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
        if (eReturnValue == CAN_OK)
        {
#endif    
            while( (Can_43_MCAN_ControllerStatuses[u8CtrlId].u32MbTxMapping[u8MbIndex] != Hth) &&
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    (u8MbIndex < Can_43_MCAN_pControlerDescriptors[u8CtrlId].u8MaxMbTxCount) )
            {
                u8MbIndex ++;
            }
#if (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON)
            do
            {
#endif /* (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON) */
                /* Calculate the real MBsize and DataLenghtCode for each MB */
                u32DataLengthCode = Can_Mcan_CalcDataLenghtCode(PduInfo->length);
                /* Calculate the base address for MB */
                u32BaseAddress = SCM_RAM_BASEADDR + (u32TxBufferAddOffset << 2) + ((uint32)(u8MbIndex) * (uint32)u8MbSize[u8CtrlId]); 
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */              
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */                
                u32TempFlag = ((uint32)(((uint32)0x01U) << u8MbIndex));
                /* Allow CAN to enter the specific critical region */
                SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_02();
        
                if ( (uint32)0x0U == (Can_43_MCAN_ControllerStatuses[u8CtrlId].Tx_complete_guard & u32TempFlag) )
                {
                    /* No need to set the flag right now because there is mutex to prevent call with same HTH. 
                    Tx_complete_guard will be set after trigger transmit to synchronize with ProcessTx or Cancel */               
                    /* Allow CAN to exit the specific critical region */
                    SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_02();
                    u32MbMessageId = (uint32)PduInfo->id;

                    /* Set-up the MB content for Tx. Remember the PduId for reporting when the frame is transmitted. */
                    Can_43_MCAN_ControllerStatuses[u8CtrlId].u32TxPduId[u8MbIndex] = PduInfo->swPduHandle;

                #if (CAN_43_MCAN_EXTENDEDID == STD_ON)
                    if ( (u32MbMessageId & MCAN_MBC_ID_IDE_U32) != (uint32)0U)
                    {
                        /* Extended ID - need to shift left 18 bits. */

                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_WRITE32( u32BaseAddress , (((u32MbMessageId & MCAN_TX_MB_ID_MASK_U32)| MCAN_MB_TYPE_XTD_U32)) );
                    }
                    else
                    {
                #endif /*(CAN_43_MCAN_EXTENDEDID == STD_ON) */
                        /* Standard ID - need to shift left 18 bits. */

                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_WRITE32( u32BaseAddress , ((u32MbMessageId << MCAN_STANDARD_ID_SHIFT_U32) & MCAN_MB_TYPE_STD_U32));
                #if (CAN_43_MCAN_EXTENDEDID == STD_ON)
                    }
                #endif /*(CAN_43_MCAN_EXTENDEDID == STD_ON) */

                    #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                #if (IPV_MCAN == IPV_MCAN_00_00_00_21)
                    if((uint32)0UL != (REG_READ32( MCAN_CCCR(u8HwOffset)) & MCAN_CCCR_FDOE_U32))
                    {
                        if((uint32)0UL != (REG_READ32( MCAN_CCCR(u8HwOffset)) & MCAN_CCCR_BRSE_U32))
                        {
                            u32DataLengthCode |= MCAN_FD_WITH_BITRATE_SWITCHING_U32;
                        }
                        else
                        {
                            u32DataLengthCode |= MCAN_FD_WITHOUT_BITRATE_SWITCHING_U32;
                        }
                    }
                    else
                    {
                        u32DataLengthCode |= MCAN_CLASSIC_U32;
                    }
                #endif
                #endif
                
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                #if (IPV_MCAN == IPV_MCAN_00_00_00_21)
                    REG_WRITE32( (u32BaseAddress + 4U ), (((uint32)(u32DataLengthCode)) & MCAN_TX_MB_DLC_FD_MASK_U32));
                #else
                    REG_WRITE32( (u32BaseAddress + 4U ), (((uint32)(u32DataLengthCode)) & MCAN_TX_MB_DLC_MASK_U32));
                #endif
                    
                #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                    /* Copy the padding data into the variable */
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */    
                    u8PaddingValue = ((uint8)(Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIndex].u8FdPaddingValue));
                #endif
                    /* Calculate the number the word which uses to store the data of frame */
                    u8NumberWord = (uint8)((uint32)u8MbSize[u8CtrlId] - (uint32)8U) >> 2U;
                    /* Increase the u32BaseAddress to the beginning of data section */
                    u32BaseAddress = u32BaseAddress + 8U;
                    /* Access to each word anh each byte to arrange again the order layout of data */  
                    for(u8IndexWord = 0U; u8IndexWord < u8NumberWord; u8IndexWord ++)
                    {
                        u32DataWord = 0U;
                        for(u8MbDataByte = (uint8)0U; u8MbDataByte < 4U; u8MbDataByte++)
                        {
                          #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                            if(u8ByteIndex >= PduInfo->length)
                            {
                                u32DataWord |= (uint32)((uint32)((uint32)u8PaddingValue) << (u32ByteShiftArray[u8MbDataByte]));
                            }
                            else
                            {
                          #endif
                                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                u32DataWord |= (uint32)((uint32)((PduInfo->sdu)[u8ByteIndex]) << (u32ByteShiftArray[u8MbDataByte]));
                          #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                            }
                          #endif
                            u8ByteIndex++;
                        }
                        /* Write the data to data field of buffer */
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        REG_WRITE32(( u32BaseAddress ), u32DataWord);
                        u32BaseAddress = u32BaseAddress + 4U;
                    }

                    SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_02();
                    /* Trigger transmission by set correspond bit in TXBAR */
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    REG_WRITE32( MCAN_TXBAR(u8HwOffset), (uint32)((uint32)(1U) << (u8MbIndex)));
                    /* Set Tx_complete_guard bit */
                    Can_43_MCAN_ControllerStatuses[u8CtrlId].Tx_complete_guard |= (uint32)u32TempFlag;
                    SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_02();
                    eReturnValue = CAN_OK;
                }
                else /* else of "if ( (uint32)0x0U == (Can_43_MCAN_ControllerStatuses[u8CtrlId].Tx_complete_guard & u32TempFlag) )" */
                {
                    /* Allow CAN to exit the specific critical region */
                    SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_02();
    #if (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON)
                    /* Keep track of the lowest prio message (highest ID). */
            
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    if((uint32)MCAN_MB_TYPE_XTD_U32==(uint32)(REG_BIT_GET32( u32BaseAddress , MCAN_MB_TYPE_XTD_U32)))
                    {
                
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u32MbMessageId = (uint32)(REG_BIT_GET32( u32BaseAddress , MCAN_TX_MB_ID_MASK_U32));
                    }
                    else
                    {
                
                        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        u32MbMessageId = (uint32)((REG_BIT_GET32( u32BaseAddress , MCAN_TX_MB_ID_MASK_U32))>>MCAN_STANDARD_ID_SHIFT_U32 );
                    }
            
        #if (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON)
                    if  ( ((uint32)u32MbLprioId < (uint32)u32MbMessageId)
            #if (CAN_43_MCAN_IDENTICAL_ID_CANCELLATION == STD_ON)
                        || ((uint32)u32MbLprioId == (uint32)u32MbMessageId)
            #endif /* (CAN_43_MCAN_IDENTICAL_ID_CANCELLATION == STD_ON) */
                        )
                    {
                        u32MbLprioId = u32MbMessageId;
                        u8MbLprioIndex = u8MbIndex;
                    }

        #else /* (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_OFF) */
                    if  ( 
            #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                        ((uint32)u32MbMessageId > (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32)&(~CAN_43_MCAN_FD_ID_DESCRIPTOR)))
            #else
                        ((uint32)u32MbMessageId > (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32)))
            #endif
            #if (CAN_43_MCAN_IDENTICAL_ID_CANCELLATION == STD_ON)
                #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                        || ((uint32)u32MbMessageId == (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32)&(~CAN_43_MCAN_FD_ID_DESCRIPTOR)))
                #else
                        || ((uint32)u32MbMessageId == (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32)))
                #endif
            #endif
                        )
                    {
                        Can_MCan_Cancel( u8CtrlId, u8MbIndex);
                    }
        #endif /* (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_OFF) */
    #endif /* (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

                    /* MB is not empty. */
                    eReturnValue = CAN_BUSY;
                }

    #if (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON)
                /* Increment the MB index. */
                u8MbIndex++;
            } while ( (Can_43_MCAN_ControllerStatuses[u8CtrlId].u32MbTxMapping[u8MbIndex] == Hth) && (CAN_BUSY == eReturnValue));
    #endif /* (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON) */

    #if ((CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON) && (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON))
            /* Was the message scheduled for transmission? */
            if ( CAN_OK != eReturnValue )
            {
                /* Did the search find a lower priority message? */
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                if ( u8MbLprioIndex < Can_43_MCAN_pControlerDescriptors[u8CtrlId].u8MaxMbTxCount)
                {
                    u32TempFlag = ((uint32)0x01U) << ((uint32)u8MbLprioIndex & MCAN_MASK_32BITS_U32);
                
                    if  ((
                    #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                        u32MbLprioId > (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32)&(~CAN_43_MCAN_FD_ID_DESCRIPTOR)))
                    #else
                        (u32MbLprioId > (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32)))
                    #endif
                    #if (CAN_43_MCAN_IDENTICAL_ID_CANCELLATION == STD_ON)
                      #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                        || (u32MbLprioId == (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32)&(~CAN_43_MCAN_FD_ID_DESCRIPTOR)))
                      #else
                        || (u32MbLprioId == (uint32)((PduInfo->id)&((uint32)MCAN_TX_MB_ID_MASK_U32))))
                      #endif
                    #endif
                        )
                    {
                        Can_MCan_Cancel( u8CtrlId, u8MbLprioIndex);
                    }
                
                }
            }
    #endif /* ((CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON) && (CAN_43_MCAN_MULTIPLEXED_TRANSMISSION == STD_ON)) */
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)    
        }
#endif
        SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_04();
        Can_u32HOHStatus[u32WordIndex] &=  ~((uint32) 1U << u32BitIndex);
        SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_04();
    }
    else
    {
        SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_04();
        eReturnValue = CAN_BUSY;
    }    
    return (eReturnValue);
}

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_Write if polling is selected or from ISR when Interrupt mode selected.
* @details        Processes Tx interrupt flags.
*               This routine is called by:
*                - Can_MCan_MainFunctionWrite() from Can_Mcan.c file.
*                - Can_MCan_MainFunctionMultipleWritePoll() from Can_Mcan.c file.
*                - Can_MCan_Isr_common_process_interrupt() from Can_Mcan.c file.
*                - Can_IsrFC##FC##_UNI() / Can_IsrFC##FC##_##Name() from Can_Irq.c file.
*
* @param[in]      controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex_start first MB to process.
* @param[in]      mbindex_end last MB to process.
*
* @pre            MB is configured for Tx.
* @post           CanIf is informed with cancellation or transmit success.
*
*
*/

/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_ProcessTx( CONST(uint8, AUTOMATIC) controller,
                                          CONST(uint8, AUTOMATIC) mbindex_start,
                                          CONST(uint8, AUTOMATIC) mbindex_end 
                                        )
{
    VAR(uint8, AUTOMATIC)           u8MbIndex = 0U;
    /* Hardware Can controller offset. */
    VAR(uint8, AUTOMATIC)           u8HwOffset = 0U;
    VAR(uint32, AUTOMATIC)          u32TempFlag = 0U;
    VAR(PduIdType, AUTOMATIC) u32PduId;
#if (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON)
    VAR(uint32, AUTOMATIC)          u32BaseAddress = 0U;
    VAR(uint32, AUTOMATIC)          u32TxBufferAddOffset = 0U;
    /* Local copy of pointer to the section address offset descriptor. */
    P2CONST(Can_43_MCAN_ControllerSectionOffsetType, AUTOMATIC, CAN_APPL_CONST) pCanControllerSectionOffset = NULL_PTR;    
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_43_MCAN_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;    
    /* Unique identifier of a PDU within a software module */
    /* Store the basic information about a PDU */
    VAR(PduInfoType, AUTOMATIC) CbkPduInfo;
    /* Pointer to the MB container structure. */
    VAR(Can_43_MCAN_PtrMBConfigContainerType, AUTOMATIC) pCanMbConfigContainer = NULL_PTR;
    
    VAR(uint32, AUTOMATIC)    u32TempVar = 0U;
    VAR(uint32, AUTOMATIC)    u32TempVar1 = 0U;
    
    VAR(uint8, AUTOMATIC)     u8TempVar = 0U;
#if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
    VAR(uint8, AUTOMATIC)      u8CanMbData[64]={0U};
#else
    VAR(uint8, AUTOMATIC)      u8CanMbData[8]={0U};
#endif
    VAR(uint8, AUTOMATIC)            u8DatabyteIndex = 0U;

    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &(Can_43_MCAN_pCurrentConfig->ControlerDescriptors[controller]);
    pCanControllerSectionOffset = pCanControlerDescriptor->pControllerSectionOffsetPtr;
    u32TxBufferAddOffset = pCanControllerSectionOffset->TxBufferOffset;
    pCanMbConfigContainer = &(Can_43_MCAN_pCurrentConfig->MBConfigContainer);
#endif /* (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;
        
    
    for ( u8MbIndex = 0U; u8MbIndex <= (mbindex_end - mbindex_start); u8MbIndex++)
    {
        u32TempFlag = ((uint32)0x01U) << ((uint32)u8MbIndex & MCAN_MASK_32BITS_U32);
        u32PduId = Can_43_MCAN_ControllerStatuses[controller].u32TxPduId[u8MbIndex];

#if (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON)
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        u32TempVar = REG_READ32( MCAN_TXBTO(u8HwOffset));
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        u32TempVar1 = REG_READ32( MCAN_TXBCF(u8HwOffset));
        
        if(((((u32TempVar & (uint32)((uint32)1U << (uint32)(u8MbIndex)))) & u32TempFlag) == 0U) && (((u32TempVar1 & (uint32)((uint32)1U << (uint32)(u8MbIndex)))& u32TempFlag) == u32TempFlag))
        {
            if ( (Can_HwHandleType)u8MbIndex == Can_43_MCAN_ControllerStatuses[controller].u32CancelMBIndex)
            {
                Can_43_MCAN_ControllerStatuses[controller].u32CancelMBIndex = pCanMbConfigContainer->uMessageBufferConfigCount;
            }
            
            /* Calculate the base address for MB */
            u32BaseAddress = SCM_RAM_BASEADDR + (u32TxBufferAddOffset << 2) + ((uint32)u8MbIndex * u8MbSize[controller]);
            
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            CbkPduInfo.SduLength =  ( ( REG_BIT_GET32( ( u32BaseAddress + 4U ), MCAN_TX_MB_DLC_MASK_U32)) >> MCAN_TX_MB_DLC_SHIFT_U32);
            /* decode SduLength */
            CbkPduInfo.SduLength = Can_Mcan_DecodeLenghtData((uint8)CbkPduInfo.SduLength);
            
            for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < CbkPduInfo.SduLength; u8DatabyteIndex++)
            {               
                u8TempVar = (uint8)((u8DatabyteIndex & (uint8)0xFCU) + 3U) - (uint8)(u8DatabyteIndex & 3U);
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u8CanMbData[u8DatabyteIndex] =  ( REG_READ8( u32BaseAddress +8U + (uint32)u8TempVar));
            }
            /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */           
            CbkPduInfo.SduDataPtr = u8CanMbData;
            SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_05();
            if((Can_43_MCAN_ControllerStatuses[controller].Tx_complete_guard & u32TempFlag) != 0U )
            {
                Can_43_MCAN_ControllerStatuses[controller].Tx_complete_guard &= (uint32)(~u32TempFlag);
                SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_05();
                /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */    
                CanIf_CancelTxConfirmation(u32PduId , &CbkPduInfo);
            }
            else
            {
                SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_05();
            }
        }

#endif /* (CAN_43_MCAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

        
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if (((((uint32)(REG_READ32( MCAN_TXBTO(u8HwOffset)) & (uint32)((uint32)(1U) << (uint32)(u8MbIndex))) ) & u32TempFlag) == u32TempFlag))
        {
            SchM_Enter_Can_43_MCAN_CAN_EXCLUSIVE_AREA_05();
            if((Can_43_MCAN_ControllerStatuses[controller].Tx_complete_guard & u32TempFlag) != 0U )
            {
                Can_43_MCAN_ControllerStatuses[controller].Tx_complete_guard &= (uint32)(~u32TempFlag);
                SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_05();
                CanIf_TxConfirmation(u32PduId);
            }
            else
            {
                SchM_Exit_Can_43_MCAN_CAN_EXCLUSIVE_AREA_05();
            }
        }
    }
}

/*================================================================================================*/
/**
* @brief          Service to perform the polling of TX confirmation and TX cancellation confirmation
* @details        This routine is called by:
*               - Can_MainFunction_Write() from Can.c file.
*
* @pre            The controller must be configured for transmit in polling mode and at least one MB is configured for Tx.
* @post           Process the transmission data in case of availability.
*
*
*/
#if (CAN_43_MCAN_TXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_43_MCAN_CODE) Can_MCan_MainFunctionWrite(void)
{
    /* Index CAN controllers from configuration. */
    VAR(uint8, AUTOMATIC)   u8CtrlIndex = 0U;
    /* Last MB to process. */
    VAR(uint8, AUTOMATIC)   u8MbLast = 0U;

    for ( u8CtrlIndex = 0U; u8CtrlIndex < (uint8)Can_43_MCANStatic_pCurrentConfig->u8ControllersConfigured; u8CtrlIndex++)
    {   /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        if ( (MCAN_NULL_OFFSET_U8 != Can_43_MCANStatic_pControlerDescriptors[u8CtrlIndex].u8ControllerOffset) &&
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
             ((uint32)0U != (CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 & (Can_43_MCANStatic_pControlerDescriptors[u8CtrlIndex].u32Options))) &&
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
             ((uint8)0U != (Can_43_MCAN_pControlerDescriptors[u8CtrlIndex].u8MaxMbTxCount)) 
           )
        {

            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            u8MbLast = (uint8)Can_43_MCAN_pControlerDescriptors[u8CtrlIndex].u8MaxMbTxCount - (uint8)1U;

            Can_MCan_ProcessTx( (uint8)u8CtrlIndex, 0U, (uint8)u8MbLast );
        }
    }
}

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to writepoll
* @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Send the data from that MB that is configured for Tx.
*/
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_MainFunctionMultipleWritePoll( VAR(uint8, AUTOMATIC) writepoll)
{
    /* Id CAN controllers from configuration. */
    VAR(uint8, AUTOMATIC)  u8CtrlId = 0U;
    /* Index MB from configuration. */
    VAR(uint8, AUTOMATIC)  u8MbIndex = 0U;

    VAR(uint32, AUTOMATIC)  u32ObjectId = 0U;

    VAR(uint8, AUTOMATIC)  u8TxProcessIndex[CAN_43_MCAN_MAXCTRL_SUPPORTED];
    
    VAR(uint8, AUTOMATIC)  u8TempIndex = 0U;
    
    if ( NULL_PTR != Can_43_MCAN_pCurrentConfig )
    {
        #if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
            if ( CAN_43_MCAN_UNINIT == Can_43_MCAN_eDriverStatus )
            {
                    
                    (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_MAIN_FUNCTION_WRITE, (uint8)CAN_43_MCAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON) */

                for ( u8CtrlId = (uint8)0U; u8CtrlId < CAN_43_MCAN_MAXCTRL_SUPPORTED; u8CtrlId++)
                {
                    u8TxProcessIndex[u8CtrlId] = 0U;
                }

                for ( u8MbIndex = (uint8)0U; u8MbIndex < (uint8)Can_43_MCAN_pCurrentConfig->MBConfigContainer.uMessageBufferConfigCount; u8MbIndex++)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    u8CtrlId = Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIndex].u8ControllerId;

                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    if ( (writepoll == Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIndex].u32CanMainFuncRWPeriodRef) &&
                         /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                         (MCAN_NULL_OFFSET_U8 != Can_43_MCANStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset) &&

                         /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                         ((uint32)0U != (CAN_43_MCAN_CONTROLLERCONFIG_TXPOL_EN_U32 & (Can_43_MCANStatic_pControlerDescriptors[u8CtrlId].u32Options))) &&

                         /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                         (CAN_43_MCAN_TRANSMIT == (Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIndex].eMBType ))
                       )
                    {
                        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                        u32ObjectId = (Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIndex].u32HWObjID );

                        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                        u8TempIndex = u8TxProcessIndex[u8CtrlId];
                        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                        while ((u32ObjectId != (Can_43_MCAN_ControllerStatuses[u8CtrlId].u32MbTxMapping[u8TempIndex])) && (u8TempIndex < (Can_43_MCAN_pControlerDescriptors[u8CtrlId].u8MaxMbTxCount)))
                        {
                            u8TempIndex++;
                        }
                        if (u32ObjectId == Can_43_MCAN_ControllerStatuses[u8CtrlId].u32MbTxMapping[u8TempIndex])
                        {
                            Can_MCan_ProcessTx( (uint8)u8CtrlId, (uint8)u8TempIndex, (uint8)u8TempIndex );
                            u8TempIndex++;
                        } 
                        u8TxProcessIndex[u8CtrlId] = u8TempIndex;
                    }
                }
        #if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif
    }
}
#endif /* (CAN_43_MCAN_TXPOLL_SUPPORTED == STD_ON) */

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_Read if polling is selected or from ISR when Interrupt mode selected.
* @details        Processes Rx interrupt flags.
                  This routine is called by:
                    - Can_MCan_MainFunctionRead() from Can_Mcan.c file
                    - Can_MCan_MainFunctionMultipleReadPoll() from Can_Mcan.c file.
                    - Can_MCan_Isr_common_process_interrupt() from Can_Mcan.c file.
                    - Can_IsrFC##MC##_##ILS() from Can_Irq.c file
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex_start first MB to process
* @param[in]      mbindex_end last MB to process
*
* @pre            MB is configured for Rx.
* @post           Inform CanIf in case a data frame was received.
*
*
*/

/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_ProcessRx( CONST(uint8, AUTOMATIC) controller, CONST(uint8, AUTOMATIC) u8BufferID)
{
    VAR(uint8, AUTOMATIC)       u8MbDataLength = 0U;
    #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
        VAR(uint8, AUTOMATIC)   u8CanMbData[64]={0U};
    #else
        VAR(uint8, AUTOMATIC)   u8CanMbData[8]={0U};
    #endif

    VAR(uint8, AUTOMATIC)       u8DatabyteIndex = 0U;  
    VAR(uint32, AUTOMATIC)      u32BaseAddress = 0U;
    
    VAR(Can_HwHandleType, AUTOMATIC)      u32MbHrh = 0U;
    VAR(Can_IdType, AUTOMATIC) u32MbMessageId = 0U;
    VAR(uint8, AUTOMATIC)      u8HwOffset = 0U;
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)     
    VAR(uint8, AUTOMATIC)      u8FifoIndex = 0U;
    VAR(uint32, AUTOMATIC)     u32RxFifo0AddOffset = 0U;
    VAR(uint32, AUTOMATIC)     u32RxFifo1AddOffset = 0U;
#endif
    VAR(uint8, AUTOMATIC)      u8MbCtrlIndex = 0U;
    VAR(uint32, AUTOMATIC)     u32FlagRxBuffer = 0U; /* value 0 is don't has new message in Rx buffer */
    /* Pointer to the MB container structure. */
    VAR(Can_43_MCAN_PtrMBConfigContainerType, AUTOMATIC)   pCanMbConfigContainer = NULL_PTR;
    VAR(Can_43_MCAN_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
    /* Local copy of pointer to the section address offset descriptor. */
    P2CONST(Can_43_MCAN_ControllerSectionOffsetType, AUTOMATIC, CAN_APPL_CONST) pCanControllerSectionOffset = NULL_PTR;
    VAR(uint32, AUTOMATIC)     u32RxBufferAddOffset = 0U;
    VAR(uint8, AUTOMATIC)      u8TempVar = 0U;

    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanControlerDescriptor = &Can_43_MCAN_pCurrentConfig->ControlerDescriptors[controller];
    pCanControllerSectionOffset = pCanControlerDescriptor->pControllerSectionOffsetPtr;
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    pCanMbConfigContainer   = &(Can_43_MCAN_pCurrentConfig->MBConfigContainer);
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON) 
    MCAL_FAULT_INJECTION_POINT(CAN_FIP_3_CHANGE_LENGTH_FIELD);
    if ((uint8)MCAN_STORE_RX_FIFO0_U8 == u8BufferID)
    {
        u32RxFifo0AddOffset = pCanControllerSectionOffset->RxFifo0Offset;
        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if(MCAN_RXFIFO0_OVFL_MASK_U32 == ((REG_READ32( MCAN_IR(u8HwOffset)))&( MCAN_INTERRUPT_RF0F_U32|MCAN_INTERRUPT_RF0L_U32)))
        {
            if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)
            {
                if ( NULL_PTR != (pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)->Can_RxFifoOverflowNotification)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    (pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)->Can_RxFifoOverflowNotification();
                }
            }
        #if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
            
            (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_43_MCAN_E_DATALOST);
        #endif
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0F_U32);
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0L_U32);
        }
    
    #if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if ( MCAN_INTERRUPT_RF0W_U32 == ((REG_READ32(MCAN_IR(u8HwOffset)))& MCAN_INTERRUPT_RF0W_U32) )
        {
            if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)
            {
                if ( NULL_PTR != (pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)->Can_RxFifoWarningNotification)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    (pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)->Can_RxFifoWarningNotification();
                }
            }
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0W_U32) ;    
        }
    #endif

        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if ( MCAN_INTERRUPT_RF0N_U32 == ((REG_READ32( MCAN_IR(u8HwOffset))) & MCAN_INTERRUPT_RF0N_U32) )
        {
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0N_U32);
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            while ( ((REG_READ32( MCAN_RXF0S(u8HwOffset))) & MCAN_RXF0S_F0FL_U32)> 0U)
            {
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u8FifoIndex = (uint8)(((REG_READ32( MCAN_RXF0S(u8HwOffset))) & MCAN_RXF0S_F0GI_U32) >> MCAN_RXF0S_F0GI_SHIFT_U32 );
                /* Calculate the base address for MB */
                u32BaseAddress = SCM_RAM_BASEADDR + (u32RxFifo0AddOffset << 2U) +((uint32)(u8FifoIndex) * u8MbSize[controller]);
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u8MbDataLength = (uint8)(( REG_BIT_GET32( ( u32BaseAddress + 4U), MCAN_RX_MB_DLC_MASK_U32)) >> MCAN_RX_MB_DLC_SHIFT_U32);
                /* decode the length of the data buffer */
                u8MbDataLength = Can_Mcan_DecodeLenghtData(u8MbDataLength);
                /*Prevents that a buffer overflow to be generated by a CAN bus error affecting length field*/
            #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                if (u8MbDataLength > CAN_43_MCAN_REAL_PAYLOAD_U8)
                {
                    u8MbDataLength = CAN_43_MCAN_REAL_PAYLOAD_U8;
                }
            #else
                if (u8MbDataLength > (uint8)8U)
                {
                    u8MbDataLength = (uint8)8U;
                }
            #endif
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                if ((uint32)MCAN_RX_MB_XTD_MASK_U32 == ((( REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_XTD_MASK_U32 ))) & (uint32)MCAN_RX_MB_XTD_MASK_U32))
                {
                    
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    u32MbMessageId = (Can_IdType)((( REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_ID_MASK_U32) )) | MCAN_MBC_ID_IDE_U32);
                }
                else
                {
                    
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    u32MbMessageId = (Can_IdType)(((( REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_ID_MASK_U32) )) & MCAN_MB_TYPE_STD_U32) >> MCAN_STANDARD_ID_SHIFT_U32);
                }
            #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                /* Check the frame, if frame is a FD frame */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                if (MCAN_EDL_MASK_U32 == (REG_BIT_GET32( u32BaseAddress + 4U , MCAN_EDL_MASK_U32)))
                {
                    u32MbMessageId |= CAN_43_MCAN_FD_ID_DESCRIPTOR;
                }
 
            #endif
                /* Read data to aray */
                for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < u8MbDataLength; u8DatabyteIndex++)
                {
                    u8TempVar = (uint8)((u8DatabyteIndex & (uint8)0xFCU) + 3U) - (uint8)(u8DatabyteIndex & 3U);
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    u8CanMbData[u8DatabyteIndex] =  ( REG_READ8( u32BaseAddress +8U + (uint32)u8TempVar));
                }
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_RXF0A(u8HwOffset), (uint32)(u8FifoIndex & MCAN_RXF0A_F0AI_U32));
                
                
                for (u8MbCtrlIndex = 0U; u8MbCtrlIndex < pCanMbConfigContainer->uMessageBufferConfigCount; u8MbCtrlIndex++)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    if (((uint8)MCAN_STORE_RX_FIFO0_U8 == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u8StoredRxMb)) && \
                        (controller == ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u8ControllerId))
                    {
                        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */

                        u32MbHrh = (Can_HwHandleType)((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u32HWObjID;
                                                
                        #if (CAN_43_MCAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                        /*[CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
                        /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                        if ((boolean)TRUE ==    Can_43_MCAN_LPduReceiveCalloutFunction(u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
                        {
                        #endif
                            /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                            CanIf_RxIndication( u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData);
                        #if (CAN_43_MCAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                        }
                        #endif
                        break;
                    }
                }
                    
            }
        }
    
    }
    else if((uint8)MCAN_STORE_RX_FIFO1_U8 == u8BufferID)
    {        
        u32RxFifo1AddOffset = pCanControllerSectionOffset->RxFifo1Offset;
        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if (MCAN_RXFIFO1_OVFL_MASK_U32 == ((REG_READ32( MCAN_IR(u8HwOffset)))&( MCAN_INTERRUPT_RF1F_U32|MCAN_INTERRUPT_RF1L_U32)))
        {
            if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)
            {
                if ( NULL_PTR != (pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)->Can_RxFifoOverflowNotification)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    (pCanControlerDescriptor->pControllerRxFifo0ConfigsPtr)->Can_RxFifoOverflowNotification();
                }
            }
          #if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
            
            (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_43_MCAN_E_DATALOST);
          #endif
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1F_U32);
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1L_U32);
        }
    
    #if (CAN_43_MCAN_FIFO_WARNING_NOTIFICATION == STD_ON)
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if ( MCAN_INTERRUPT_RF1W_U32 == ((REG_READ32( MCAN_IR(u8HwOffset)))& MCAN_INTERRUPT_RF1W_U32) )
        {
            if(NULL_PTR != pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr)
            {
                if ( NULL_PTR != (pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr)->Can_RxFifoWarningNotification)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    (pCanControlerDescriptor->pControllerRxFifo1ConfigsPtr)->Can_RxFifoWarningNotification();
                }
            }
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1W_U32);        
        }
    #endif

        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        if ( MCAN_INTERRUPT_RF1N_U32 == ((REG_READ32( MCAN_IR(u8HwOffset))) & MCAN_INTERRUPT_RF1N_U32) )
        {
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1N_U32);
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            while ( ((REG_READ32( MCAN_RXF1S(u8HwOffset))) & MCAN_RXF1S_F1FL_U32)> 0U)
            {
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u8FifoIndex = (uint8)(((REG_READ32( MCAN_RXF1S(u8HwOffset))) & MCAN_RXF1S_F1GI_U32) >> MCAN_RXF1S_F1GI_SHIFT_U32 );
                /* Calculate the base address for MB */
                u32BaseAddress = SCM_RAM_BASEADDR + (u32RxFifo1AddOffset << 2) +((uint32)(u8FifoIndex) * u8MbSize[controller]);
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u8MbDataLength = (uint8)(( REG_BIT_GET32( ( u32BaseAddress + 4U), MCAN_RX_MB_DLC_MASK_U32)) >> MCAN_RX_MB_DLC_SHIFT_U32);
                /* decode the length of the data buffer */
                u8MbDataLength = Can_Mcan_DecodeLenghtData(u8MbDataLength);
                /*Prevents that a buffer overflow to be generated by a CAN bus error affecting length field*/
            #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                if (u8MbDataLength > CAN_43_MCAN_REAL_PAYLOAD_U8)
                {
                    u8MbDataLength = CAN_43_MCAN_REAL_PAYLOAD_U8;
                }
            #else
                if (u8MbDataLength > (uint8)8U)
                {
                    u8MbDataLength = (uint8)8U;
                }
            #endif
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                if ((uint32)MCAN_RX_MB_XTD_MASK_U32 == ((( REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_XTD_MASK_U32 ))) & (uint32)MCAN_RX_MB_XTD_MASK_U32))
                {
                    
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    u32MbMessageId = (Can_IdType)((( REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_ID_MASK_U32 ) )) | MCAN_MBC_ID_IDE_U32);
                }
                else
                {
                    
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    u32MbMessageId = (Can_IdType)(((( REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_ID_MASK_U32 ) )) & MCAN_MB_TYPE_STD_U32) >> MCAN_STANDARD_ID_SHIFT_U32);
                }
                
            #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
                /* Check the frame, if frame is a FD frame */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                if (MCAN_EDL_MASK_U32 == (REG_BIT_GET32( u32BaseAddress + 4U , MCAN_EDL_MASK_U32)))
                {
                    u32MbMessageId |= CAN_43_MCAN_FD_ID_DESCRIPTOR;
                }
            #endif
                
                /* Read data to the aray */
                for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < u8MbDataLength; u8DatabyteIndex++)
                {
                    u8TempVar = (uint8)((u8DatabyteIndex & (uint8)0xFCU) + 3U) - (uint8)(u8DatabyteIndex & 3U); 
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    u8CanMbData[u8DatabyteIndex] = ( REG_READ8( u32BaseAddress + 8U + (uint32)u8TempVar));
                }
    
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                (REG_WRITE32( MCAN_RXF1A(u8HwOffset), (uint32)(u8FifoIndex & MCAN_RXF1A_F1AI_U32)));
                
                
                for (u8MbCtrlIndex = 0U; u8MbCtrlIndex < pCanMbConfigContainer->uMessageBufferConfigCount; u8MbCtrlIndex++)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    if (((uint8)MCAN_STORE_RX_FIFO1_U8 == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u8StoredRxMb)) && \
                        (controller == ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u8ControllerId) \
                       )   
                    {
                        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */

                        u32MbHrh = (Can_HwHandleType)((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u32HWObjID;
                        #if (CAN_43_MCAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                        /*[CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
                        /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                        if ((boolean)TRUE ==    Can_43_MCAN_LPduReceiveCalloutFunction(u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
                        {
                        #endif
                            /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                            CanIf_RxIndication( u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData);
                        #if (CAN_43_MCAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                        }
                        #endif
                        break;
                    }
                }
            }
        }
    }
    else       
    {
#endif
        u32RxBufferAddOffset = pCanControllerSectionOffset->RxBufferOffset;
        
       /*Clear DRX flag in interrupt mode */
       /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
       /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
       REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_DRX_U32);
     
        if (u8BufferID < 32U)
        {
            /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                    Non-constant argument to function, Implicit conversion of integer to smaller type */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32FlagRxBuffer = (uint32)(((uint32)((uint32)1U << (uint32)u8BufferID)) & (REG_READ32( MCAN_NDAT1(u8HwOffset))));
        }
        else
        {
            /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                    Non-constant argument to function, Implicit conversion of integer to smaller type */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u32FlagRxBuffer = (uint32)(((uint32)((uint32)1U << (uint32)((uint32)u8BufferID - (uint32)32U))) & (REG_READ32( MCAN_NDAT2(u8HwOffset))));
        }
        if (0U != u32FlagRxBuffer)
        {
            u32BaseAddress = SCM_RAM_BASEADDR + (u32RxBufferAddOffset << 2) + ((uint32)(u8BufferID) * u8MbSize[controller]);
            /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                 Non-constant argument to function, Implicit conversion of integer to smaller type */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            u8MbDataLength = (uint8)((uint32)(REG_BIT_GET32(( u32BaseAddress + 4U), MCAN_RX_MB_DLC_MASK_U32)) >> MCAN_RX_MB_DLC_SHIFT_U32 );
            /* decode the length of the data buffer */
            u8MbDataLength = Can_Mcan_DecodeLenghtData(u8MbDataLength);
            /*Prevents that a buffer overflow to be generated by a CAN bus error affecting length field*/
        #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
            if (u8MbDataLength > CAN_43_MCAN_REAL_PAYLOAD_U8)
            {
                u8MbDataLength = CAN_43_MCAN_REAL_PAYLOAD_U8;
            }
        #else
            if (u8MbDataLength > (uint8)8U)
            {
                u8MbDataLength = (uint8)8U;
            }
        #endif
            /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                    Non-constant argument to function, Implicit conversion of integer to smaller type */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            if ((uint32)MCAN_RX_MB_XTD_MASK_U32 == ((( REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_XTD_MASK_U32 ))) & (uint32)MCAN_RX_MB_XTD_MASK_U32) )
            {
                /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                        Non-constant argument to function, Implicit conversion of integer to smaller type */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u32MbMessageId = (Can_IdType)(((REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_ID_MASK_U32))) | MCAN_MBC_ID_IDE_U32 );
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                        Non-constant argument to function, Implicit conversion of integer to smaller type */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u32MbMessageId = (Can_IdType)((((REG_BIT_GET32( u32BaseAddress , MCAN_RX_MB_ID_MASK_U32))) & MCAN_MB_TYPE_STD_U32) >> MCAN_STANDARD_ID_SHIFT_U32 );
            }
            
        #if (CAN_43_MCAN_FD_MODE_ENABLE == STD_ON)
            /* Check the frame, if frame is a FD frame */
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            if (MCAN_EDL_MASK_U32 == (REG_BIT_GET32( u32BaseAddress + 4U , MCAN_EDL_MASK_U32)))
            {
                u32MbMessageId |= CAN_43_MCAN_FD_ID_DESCRIPTOR;
            }
        #endif
            /* Read data to the aray */
            for ( u8DatabyteIndex = (uint8)0U; u8DatabyteIndex < u8MbDataLength; u8DatabyteIndex++)
            {
                u8TempVar = (uint8)((u8DatabyteIndex & (uint8)0xFCU) + 3U) - (uint8)(u8DatabyteIndex & 3U);
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u8CanMbData[u8DatabyteIndex] = ( REG_READ8( u32BaseAddress + 8U + (uint32)u8TempVar ));
            }

            /* A flag is cleared by writing a 1 to the corresponding bit position */
            if (u8BufferID < 32U)
            {
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_NDAT1(u8HwOffset), (uint32)((uint32)1U << (uint32)u8BufferID));
        
            }
            else
            {
                
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_NDAT2(u8HwOffset), (uint32)((uint32)1U << ((uint32)u8BufferID - (uint32)32U)));
            }
            
            
            for (u8MbCtrlIndex = 0U; u8MbCtrlIndex < pCanMbConfigContainer->uMessageBufferConfigCount; u8MbCtrlIndex++)
            {
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                if ( ((uint8)u8BufferID == (((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u8StoredRxMb)) && \
                     (controller == ((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u8ControllerId)\
                   )
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    
                    u32MbHrh = (Can_HwHandleType)((pCanMbConfigContainer->pMessageBufferConfigsPtr) + u8MbCtrlIndex)->u32HWObjID;
                     
                    #if (CAN_43_MCAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                    /*[CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
                    /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */                  
                    if ((boolean)TRUE ==    Can_43_MCAN_LPduReceiveCalloutFunction(u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
                    {
                    #endif
                        /* @violates @ref Can_MCan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                        CanIf_RxIndication( u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData);
                    #if (CAN_43_MCAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                    }
                    #endif
                    break;
                }
            }
        }  
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)         
    }
#endif
}

/*================================================================================================*/
/**
* @brief          Service to perform the polling of RX indications.
* @details        Processes Rx interrupt flags.
*                 This routine is called by:
*                    - Can_MainFunction_Read() from Can.c file.
*
* @pre            The controller must be configured for receive in polling mode and at least one MB is configured for Rx.
* @post           Process the reception data in case of availability.
*
*
*/

#if (CAN_43_MCAN_RXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_43_MCAN_CODE) Can_MCan_MainFunctionRead( void)
{
    /* Index CAN controllers from configuration. */
    VAR(uint8, AUTOMATIC)       u8CtrlIndex = 0U;
    VAR(uint8, AUTOMATIC)       u8MBIndex = 0U;
    VAR(uint8, AUTOMATIC)       u8HwOffset = 0U;
    /* Local copy of pointer to the controller descriptor. */
    VAR(Can_43_MCAN_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;

    for ( u8CtrlIndex = (uint8)0U; u8CtrlIndex < (uint8)Can_43_MCANStatic_pCurrentConfig->u8ControllersConfigured; u8CtrlIndex++)
    {
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        pCanControlerDescriptor = &(Can_43_MCAN_pCurrentConfig->ControlerDescriptors[u8CtrlIndex]);
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[u8CtrlIndex].u8ControllerOffset;
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        if ( (MCAN_NULL_OFFSET_U8 != Can_43_MCANStatic_pControlerDescriptors[u8CtrlIndex].u8ControllerOffset) )
        {
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)                 
            Can_MCan_ProcessRx( (uint8)u8CtrlIndex, MCAN_STORE_RX_FIFO0_U8);
            Can_MCan_ProcessRx( (uint8)u8CtrlIndex, MCAN_STORE_RX_FIFO1_U8);
#endif           
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            if ( MCAN_INTERRUPT_DRX_U32 == ((REG_READ32( MCAN_IR(u8HwOffset))) & MCAN_INTERRUPT_DRX_U32) )
            {
                /* clean flag rx buffer */
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_DRX_U32);
                for (u8MBIndex = 0U; u8MBIndex < pCanControlerDescriptor->u8MaxMbRxCount; u8MBIndex++)
                {
                    Can_MCan_ProcessRx( (uint8)u8CtrlIndex, u8MBIndex);
                }
            }
        }
    }
}

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to .readpoll
* @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
* @pre            Driver must be initialized.
* @post           Receive the data from that MB that is configured for Rx.
*/

/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_MainFunctionMultipleReadPoll( VAR(uint8, AUTOMATIC) readpoll)
{
    VAR(uint8, AUTOMATIC)  u8CtrlId = 0U;
    VAR(uint8, AUTOMATIC)  u8MbIdx = 0U;
    
    if ( NULL_PTR != Can_43_MCAN_pCurrentConfig )
    {
      #if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)
        if ( CAN_43_MCAN_UNINIT == Can_43_MCAN_eDriverStatus )
        {
            
            (void)Det_ReportError( (uint16)CAN_43_MCAN_MODULE_ID, (uint8)CAN_43_MCAN_INSTANCE, (uint8)CAN_43_MCAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_43_MCAN_E_UNINIT);
        }
        else
        {
      #endif
            for ( u8MbIdx = (uint8)0U; u8MbIdx < (uint8)Can_43_MCAN_pCurrentConfig->MBConfigContainer.uMessageBufferConfigCount; u8MbIdx++)
            {
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                u8CtrlId = Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIdx].u8ControllerId;
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                if  ( (readpoll == Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIdx].u32CanMainFuncRWPeriodRef) && \
                      (MCAN_NULL_OFFSET_U8 != Can_43_MCANStatic_pControlerDescriptors[u8CtrlId].u8ControllerOffset) && \
                      ((uint32)0U != (CAN_43_MCAN_CONTROLLERCONFIG_RXPOL_EN_U32 & (Can_43_MCANStatic_pControlerDescriptors[u8CtrlId].u32Options))) && \
                      (CAN_43_MCAN_RECEIVE == Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIdx].eMBType ) \
                    ) 
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                    Can_MCan_ProcessRx( (uint8)u8CtrlId,(Can_43_MCAN_pCurrentConfig->MBConfigContainer.pMessageBufferConfigsPtr[u8MbIdx].u8StoredRxMb));
                }
            }
      #if (CAN_43_MCAN_DEV_ERROR_DETECT == STD_ON)                
        }
      #endif
    }
}
#endif

/*================================================================================================*/
/**
* @brief          Service to perform the polling of CAN status register flags to detect transition of CAN Controller state
* @details        The function Can_MainFunction_Mode shall implement the polling of CAN status register flags to detect transition of CAN Controller state
*                 This routine is called by:
*                   - Can_MainFunction_Mode() from Can.c file.
*
* @pre
* @post
*
*/

FUNC (void, CAN_43_MCAN_CODE) Can_MCan_MainFunctionMode( void)
{
    VAR(uint8, AUTOMATIC)  u8CtrlIndex = 0U;    /* Index CAN controllers from configuration. */
    VAR(uint8, AUTOMATIC)  u8HwOffset = 0U;     /* Controller hardware offset on chip. */
    VAR(uint32, AUTOMATIC)  u32NewMcr = 0U;
    P2CONST(Can_43_MCANStatic_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) pCanStaticControlerDescriptor = NULL_PTR;

    for ( u8CtrlIndex = (uint8)0U; u8CtrlIndex < (uint8)Can_43_MCANStatic_pCurrentConfig->u8ControllersConfigured; u8CtrlIndex++)
    {
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        if ( (MCAN_NULL_OFFSET_U8 != Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[u8CtrlIndex].u8ControllerOffset) )
        {
            if(CAN_43_MCAN_SLEEPED != Can_43_MCAN_ControllerStatuses[u8CtrlIndex].ControllerState)
            { 
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                pCanStaticControlerDescriptor = &Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[u8CtrlIndex];
                u8HwOffset = pCanStaticControlerDescriptor->u8ControllerOffset;
    
                /* from CAN_43_MCAN_STARTED to CAN_43_MCAN_STOPPED (in CAN_43_MCAN_STOPPED,  CCCR[INIT] = 1)*/
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                u32NewMcr = (uint32)(REG_READ32( MCAN_CCCR(u8HwOffset))) ;
                
                if( ((u32NewMcr & MCAN_CCCR_INIT_U32) == MCAN_CCCR_INIT_U32)&& (CAN_43_MCAN_STARTED == Can_43_MCAN_ControllerStatuses[u8CtrlIndex].ControllerState) )                 
                {
                    Can_43_MCAN_ControllerStatuses[u8CtrlIndex].ControllerState = CAN_43_MCAN_STOPPED;
                    CanIf_ControllerModeIndication(u8CtrlIndex, CANIF_CS_STOPPED);
                }
    
                /* from CAN_43_MCAN_STOPPED to CAN_43_MCAN_STARTED (in CAN_43_MCAN_STARTED,  CCCR[INIT] = 0 and CCCR[CCE] = 0)*/
                
                if( ((u32NewMcr & MCAN_CCCR_INIT_U32) == 0U) &&(CAN_43_MCAN_STOPPED == Can_43_MCAN_ControllerStatuses[u8CtrlIndex].ControllerState))                 
                {
                    Can_43_MCAN_ControllerStatuses[u8CtrlIndex].ControllerState = CAN_43_MCAN_STARTED;
                    CanIf_ControllerModeIndication(u8CtrlIndex, CANIF_CS_STARTED);
                }
            }
        }
    }
}

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_BusOff if polling is selected or from ISR when Interrupt mode selected.
* @details        Local function for calling notification function to notify upper layer during
*                 Can_MainFunction_BusOff if polling is selected or from ISR when Interrupt mode selected.
*                 This routine is called by:
*                  - Can_MainFunction_BusOff() from Can.c file.
*                  - Can_MCan_Isr_common_process_interrupt() from Can_MCan.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @pre            A busoff condition must to be fulfilled.
* @post           Status flag is cleared.
*
*/

/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_ProcessBusOff( CONST(uint8, AUTOMATIC) controller)
{
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC) u8HwOffset = 0U;
    
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* Clear Bus_Off Status flag */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_BO_U32);

}




/*================================================================================================*/
/**
* @brief          This function checks if a BusOff has occurred for the given controller.
* @details        This routine is called by:
*                  - Can_MainFunction_BusOff() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return        Std_ReturnType
* @retval        E_OK wakeup detected
* @retval        E_NOT_OK wakeup not detected
*
* @pre            A request for busoff checking is required.
* @post           Report the occurence or not for an busoff event.
*
*/
/* @violates @ref Can_MCan_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Std_ReturnType, CAN_43_MCAN_CODE) Can_MCan_CheckBusOff( VAR(uint8, AUTOMATIC) controller )
{
    /* Variable store return value */
    VAR(uint8, AUTOMATIC) eReturnValue = (uint8)E_NOT_OK;
    /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC) u8HwOffset = 0U;
    /* Temporary variable */
    VAR(uint32, AUTOMATIC) u32TempVar = 0U;
    VAR(uint32, AUTOMATIC) u32TempVar1 = 0U;
    VAR(uint32, AUTOMATIC) u32TempVar2 = 0U;

    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    u32TempVar = REG_BIT_GET32( MCAN_PSR(u8HwOffset), MCAN_PSR_BO_U32 );
     /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
     /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    u32TempVar1 = (uint32)(REG_READ32(MCAN_CCCR(u8HwOffset)) & MCAN_CCCR_INIT_U32);
     /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
     /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    u32TempVar2 = REG_BIT_GET32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_BO_U32 );
    
    if ( ( MCAN_PSR_BO_U32 == u32TempVar) && ( MCAN_CCCR_INIT_U32 == u32TempVar1) && ( MCAN_INTERRUPT_BO_U32 == u32TempVar2))
    {
        eReturnValue = (uint8)E_OK;
    }
    return (eReturnValue);
}
/*================================================================================================*/
/*
* @brief          Process a transition from one clock source to another.
* @details        This function is configuring Can controllers to run on the same baudrate, but having a different MCU source clock.
*                 This routine is called by:
*                  - Can_SetClockMode() from Can.c file.
*
* @param[in]      u8CanController    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      can_clk_mode clock mode selection
*
* @return        Std_ReturnType Result of the clock switch operation.
* @retval        E_OK  Switch clock operation was ok.
* @retval        E_NOT_OK  Switch clock operation was not ok.
*
* @pre            Driver must be initialized and all the controllers must be in Stop state.
*
* @note           Not AUTOSAR required. This is user implementation.
*/

#if (CAN_43_MCAN_DUAL_CLOCK_MODE == STD_ON)

FUNC(Std_ReturnType, CAN_43_MCAN_CODE) Can_MCan_SetClockMode( VAR(uint8, AUTOMATIC) u8Controller, VAR(Can_43_MCAN_ClockModeType, AUTOMATIC) can_clk_mode)
{
    VAR(Std_ReturnType, AUTOMATIC) eReturnValue = (uint8)E_OK;
    VAR(uint8, AUTOMATIC)  u8HwOffset = 0U;     /* Controller hardware offset on chip. */
    VAR(uint8, AUTOMATIC) u8BaudrateIndex = 0U;     /* Variable to hold the index of the current baudrate */

    u8BaudrateIndex = Can_43_MCAN_ControllerStatuses[u8Controller].u8CurrentBaudRateIndex;
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[u8Controller].u8ControllerOffset;

    switch (can_clk_mode)
    {
        case (CAN_43_MCAN_NORMAL):
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_BTP(u8HwOffset), ((uint32)(Can_43_MCAN_pControlerDescriptors[u8Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegister)) & (MCAN_BTP_MASK_U32) );
            break;

        case (CAN_43_MCAN_ALTERNATE):
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_BTP(u8HwOffset), ((uint32)(Can_43_MCAN_pControlerDescriptors[u8Controller].pControllerBaudrateConfigsPtr[u8BaudrateIndex].u32ControlRegisterAlternate)) & (MCAN_BTP_MASK_U32) );
            break;

        default:
            eReturnValue = (uint8)E_NOT_OK;
            break;
    }
/* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
    return (eReturnValue);
}

#endif
#ifdef ERR_IPV_MCAN_0002 
  #if (ERR_IPV_MCAN_0002 == STD_ON)
FUNC (void, CAN_43_MCAN_CODE) Can_MCan_DummyRead(VAR(uint8, AUTOMATIC) u8Controller)
{
    VAR(uint8, AUTOMATIC)      u8HwOffset = 0U;
    VAR(uint8, AUTOMATIC)      u8MbIndex = 0U;

    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[u8Controller].u8ControllerOffset;

    /* Clear all IRQs because they are invalid now */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_MASK_32BITS_U32);

    /* Read out all message in FIFO0, actually just read the index and set acknowledgement for coresponde index */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    while ( (REG_READ32( MCAN_RXF0S(u8HwOffset)) & MCAN_RXF0S_F0FL_U32)> 0U)
    {
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        u8MbIndex = (uint8)(((REG_READ32( MCAN_RXF0S(u8HwOffset))) & MCAN_RXF0S_F0GI_U32) >> 8U );
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        REG_WRITE32( MCAN_RXF0A(u8HwOffset), (uint32)(u8MbIndex & MCAN_RXF0A_F0AI_U32));
    }
    
    /* Read out all message in FIFO1, actually just read the index and set acknowledgement for coresponde index */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    while ((REG_READ32( MCAN_RXF1S(u8HwOffset)) & MCAN_RXF1S_F1FL_U32)> 0U)
    {
        
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        u8MbIndex = (uint8)(((REG_READ32( MCAN_RXF1S(u8HwOffset))) & MCAN_RXF1S_F1GI_U32) >> 8U );

        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        REG_WRITE32( MCAN_RXF1A(u8HwOffset), (uint32)(u8MbIndex & MCAN_RXF1A_F1AI_U32));
    }

    /* Do not care about the data, just clear all the new message reported by NDATx */
    
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    REG_WRITE32( MCAN_NDAT1(u8HwOffset), MCAN_MASK_32BITS_U32);

    
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    REG_WRITE32( MCAN_NDAT2(u8HwOffset), MCAN_MASK_32BITS_U32);
}
  #endif
#endif
#if (CAN_43_MCAN_SUPPORT_MRAF_EVENT == STD_ON)
    #if (CAN_43_MCAN_MRAFPOLL_SUPPORTED == STD_ON)
        FUNC (void, CAN_43_MCAN_CODE) Can_MCan_MainFunction_CheckMRAF( void)
        {
            /* Variable for indexing the controllers. */
            VAR(uint8, AUTOMATIC) u8CanController = 0U;
            VAR(uint8, AUTOMATIC) u8HwOffset = 0U;
            
            for ( u8CanController = 0U; u8CanController < (uint8)Can_43_MCANStatic_pCurrentConfig->u8ControllersConfigured; u8CanController++)
            {
                if ( MCAN_NULL_OFFSET_U8 != (Can_43_MCANStatic_pControlerDescriptors[u8CanController].u8ControllerOffset))
                {
                    if ( CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32 == (CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32 & Can_43_MCANStatic_pControlerDescriptors[u8CanController].u32Options))
                    {
                        u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[u8CanController].u8ControllerOffset;
                        
                        /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                                            Non-constant argument to function, Implicit conversion of integer to smaller type */
                        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
                        if (MCAN_INTERRUPT_MRAF_U32 == (REG_READ32( MCAN_IR(u8HwOffset)) & MCAN_INTERRUPT_MRAF_U32))
                        {
                            if ( NULL_PTR != Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[u8CanController].Can_SupportMRAFNotification)
                            {
                                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[u8CanController].Can_SupportMRAFNotification();
                            }
                                /* Clear flag any way */
                            REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_MRAF_U32);
                        }
                    }
                }
            }
            
        }
    #endif
#endif /* (CAN_43_MCAN_SUPPORT_MRAF_EVENT == STD_OFF) */ 

#if (STD_ON == CAN_43_MCAN_INTERRUPT_SUPPORTED)
/*================================================================================================*/
/**
* @brief          This function is called from ISR service routine
* @details        This function is used to handle the Interrupts
* @param[in]u8CanController    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return void
* @retval void
* @retval void
* @implements     Can_MCan_Isr_common_process_interrupt_Activity
*
*/
FUNC(void, CAN_43_MCAN_CODE) Can_MCan_Isr_common_process_interrupt( CONST(uint8, AUTOMATIC) controller)
{
    volatile VAR(uint32, AUTOMATIC)  u32TempInterruptStatus = 0U;
    volatile VAR(uint32, AUTOMATIC)  u32TempInterruptEnable = 0U;
    VAR(uint8, AUTOMATIC)  u8HwOffset = 0U;
    VAR(uint8, AUTOMATIC)  u8MBIndex = 0U;
    /* Pointer to the MB container structure. */
    VAR(Can_43_MCAN_PtrControlerDescriptorType, AUTOMATIC) pCanControlerDescriptor = NULL_PTR;
    /* Temporary variable */
    VAR(uint32, AUTOMATIC) u32TempVar = 0U;
    VAR(uint32, AUTOMATIC) u32TempVar1 = 0U;
    /* Hardware Can controller offset. */
    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
    u8HwOffset = Can_43_MCANStatic_pControlerDescriptors[controller].u8ControllerOffset;

    /* To store the CAN Interrupt Status Register */
    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    u32TempInterruptStatus = REG_READ32( MCAN_IR(u8HwOffset));

    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    u32TempInterruptEnable = REG_READ32( MCAN_IE(u8HwOffset));

    /* check any error bits are set & call error notification */

    if (NULL_PTR != Can_43_MCAN_pCurrentConfig)
    {
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            pCanControlerDescriptor = &Can_43_MCAN_pCurrentConfig->ControlerDescriptors[controller];
        /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */

        #if (CAN_43_MCAN_ERROR_NOTIFICATION_ENABLE == STD_ON)
            
        if((u32TempInterruptStatus & MCAN_ERR_INTERRUPT_U32) != 0U)
        {
            /*Clear the Error Flags*/
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
            REG_WRITE32( MCAN_IR(u8HwOffset), (uint32) MCAN_ERR_INTERRUPT_U32);
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            if ( NULL_PTR != Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller].Can_ErrorNotification)
            {
                /*call error notification */
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller].Can_ErrorNotification();
            }
        }
        #endif
        #if (CAN_43_MCAN_MRAFINT_SUPPORTED == STD_ON)
        if(MCAN_INTERRUPT_MRAF_U32 == (u32TempInterruptStatus & MCAN_INTERRUPT_MRAF_U32))
        {
            if ( CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_MRAFPOL_EN_U32 & Can_43_MCANStatic_pControlerDescriptors[controller].u32Options))
            {
                if ( NULL_PTR != Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller].Can_SupportMRAFNotification)
                {
                    /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    Can_43_MCANStatic_pCurrentConfig->StaticControlerDescriptors[controller].Can_SupportMRAFNotification();
                }
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_MRAF_U32);
            }
        }
        #endif
        
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        u32TempVar = REG_READ32(MCAN_CCCR(u8HwOffset))& MCAN_CCCR_INIT_U32;
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        u32TempVar1 = (uint32)(REG_BIT_GET32( MCAN_PSR(u8HwOffset), MCAN_PSR_BO_U32));     
        
        if ( (u32TempInterruptStatus & MCAN_INTERRUPT_BO_U32) != 0U )
        {
            /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            if ( ((u32TempInterruptEnable & MCAN_INTERRUPT_BO_U32) != 0U) \
                  && ( MCAN_CCCR_INIT_U32 == u32TempVar) \
                  && ( MCAN_PSR_BO_U32 ==  u32TempVar1) \
               )
            {
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                if ( CAN_OK == Can_MCan_SetControllerMode( controller, &(Can_43_MCAN_pCurrentConfig->ControlerDescriptors[controller]), \
                     CAN_T_STOP,(boolean)FALSE) \
                   )
                {
                    /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    Can_MCan_ProcessBusOff(controller);
                    CanIf_ControllerBusOff(controller);
                }
            }
         #if (CAN_43_MCAN_BUSOFFPOLL_SUPPORTED == STD_OFF)
            /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */ 
            else if(CAN_43_MCAN_CONTROLLERCONFIG_BOPOL_EN_U32 != (CAN_43_MCAN_CONTROLLERCONFIG_BOPOL_EN_U32 & Can_43_MCANStatic_pControlerDescriptors[controller].u32Options))
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_BO_U32);
            }         
            else
            {
                /* Just for prevent misra */
            }
          #endif
        }

        /* @violates @ref Can_MCan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion:
                                     Non-constant argument to function, Implicit conversion of integer to smaller type */
        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(0U != (u32TempInterruptStatus & MCAN_INTERRUPT_TC_U32))
        {
            if(0U != (u32TempInterruptEnable & MCAN_INTERRUPT_TC_U32))
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_TC_U32);
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                Can_MCan_ProcessTx( controller, 0U, (Can_43_MCAN_pCurrentConfig->ControlerDescriptors[controller].u8MaxMbTxCount - 1U));
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_TC_U32);
            }
        }

        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(0U != (u32TempInterruptStatus & MCAN_INTERRUPT_TCF_U32))
        {
            if(0U != (u32TempInterruptEnable & MCAN_INTERRUPT_TCF_U32))
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_TCF_U32);
                /* @violates @ref Can_MCan_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                Can_MCan_ProcessTx( controller, 0U, (Can_43_MCAN_pCurrentConfig->ControlerDescriptors[controller].u8MaxMbTxCount - 1U));
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_TCF_U32);
            }
        }
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON)         
        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(MCAN_INTERRUPT_RF0N_U32 == (u32TempInterruptStatus & MCAN_INTERRUPT_RF0N_U32))
        {
            if (MCAN_INTERRUPT_RF0N_U32 == (u32TempInterruptEnable & MCAN_INTERRUPT_RF0N_U32 ))
            {
                Can_MCan_ProcessRx(controller, (uint8)MCAN_STORE_RX_FIFO0_U8);
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0N_U32);
            }
        }
        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(MCAN_INTERRUPT_RF1N_U32 == (u32TempInterruptStatus & MCAN_INTERRUPT_RF1N_U32))
        {
            if (MCAN_INTERRUPT_RF1N_U32 == (u32TempInterruptEnable & MCAN_INTERRUPT_RF1N_U32 ))
            {
                Can_MCan_ProcessRx(controller, (uint8)MCAN_STORE_RX_FIFO1_U8);
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1N_U32);
            }
        }
#endif        
        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(MCAN_INTERRUPT_DRX_U32 == (u32TempInterruptStatus & MCAN_INTERRUPT_DRX_U32))
        {
            if (MCAN_INTERRUPT_DRX_U32 == (u32TempInterruptEnable & MCAN_INTERRUPT_DRX_U32))
            {
                for (u8MBIndex = 0U; u8MBIndex < pCanControlerDescriptor->u8MaxMbRxCount; u8MBIndex++)
                {
                    Can_MCan_ProcessRx(controller, u8MBIndex);
                }
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_DRX_U32);
            }
        }        
#if (CAN_43_MCAN_RXFIFO_ENABLE == STD_ON) 
        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(0U != (u32TempInterruptStatus & (MCAN_INTERRUPT_RF0F_U32 | MCAN_INTERRUPT_RF0L_U32)))
        {
            if(0U != (u32TempInterruptEnable & (MCAN_INTERRUPT_RF0F_U32 | MCAN_INTERRUPT_RF0L_U32)))
            {
                Can_MCan_ProcessRx( controller,(uint8)MCAN_STORE_RX_FIFO0_U8);
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0L_U32);
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0F_U32);
            }
        }

        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(0U != (u32TempInterruptStatus & (MCAN_INTERRUPT_RF1F_U32 | MCAN_INTERRUPT_RF1L_U32)))
        {
            if(0U != (u32TempInterruptEnable & (MCAN_INTERRUPT_RF1F_U32 | MCAN_INTERRUPT_RF1L_U32)))
            {
                Can_MCan_ProcessRx(controller,(uint8)MCAN_STORE_RX_FIFO1_U8);
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1F_U32);
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1L_U32);
            }
        }

        /* @violates @ref Can_MCan_c_REF_3 Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator. */
        if(0U != (u32TempInterruptStatus & (MCAN_INTERRUPT_RF0W_U32 | MCAN_INTERRUPT_RF1W_U32)))
        {
            if(0U != (u32TempInterruptEnable & (MCAN_INTERRUPT_RF0W_U32 | MCAN_INTERRUPT_RF1W_U32)))
            {
                if ((uint8)MCAN_INTERRUPT_RF0W_U32 == (u32TempInterruptStatus & MCAN_INTERRUPT_RF0W_U32))
                {            
                    Can_MCan_ProcessRx( controller,(uint8)MCAN_STORE_RX_FIFO0_U8);
                }
                if ((uint8)MCAN_INTERRUPT_RF1W_U32 == (u32TempInterruptStatus & MCAN_INTERRUPT_RF1W_U32))
                {
                    Can_MCan_ProcessRx(controller,(uint8)MCAN_STORE_RX_FIFO1_U8);
                }
            }
            else
            {
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF1W_U32);
                /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                REG_WRITE32( MCAN_IR(u8HwOffset), MCAN_INTERRUPT_RF0W_U32);
            }
        }
#endif        
    }
    else
    {
        /* @violates @ref Can_MCan_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_MCan_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        REG_WRITE32( MCAN_IR(u8HwOffset), u32TempInterruptStatus);
    }
}

#endif

#define CAN_43_MCAN_STOP_SEC_CODE
/* @violates @ref Can_MCan_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_MCan_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
