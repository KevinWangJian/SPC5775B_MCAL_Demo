/**
*   @file       Eth_Lcfg.c
*   @implements Eth_Lcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eth driver Link-Time configuration file
*   @details File containing the configuration for the Ethernet driver
*   @note    This file was generated on 2019-10-25.
*
*   @addtogroup ETH_DRIVER_CONFIGURATION
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FEC
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC5777C_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20170519
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
* @section Eth_Lcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Lcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Lcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macro is unfortunately longer than 31 characters required by the agreed file
* template and cannot be changed. Authors of the template have not taken the MISRA rules into
* account.
*
* @section Eth_Lcfg_c_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_Lcfg_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless
* external linkage is required. The APIs always require the external
* linkage. MISRA analysis tool does not see the linkage from other files
* therefore there is no violation.
*
* @section Eth_Lcfg_c_REF_6
* Violates MISRA 2004 Required Rule 9.2, Braces shall be used to indicate and match the structure in the 
* non-zero initialisation of arrays and structures. At here, we tend to initialized for whole structure, however, 
* when configure only 1 controller is configured, tool reported as non-zero initialisation. 
*
* @section Eth_Lcfg_c_REF_7
* Violates MISRA 2004 Required Rule 11.1, Pointer to a function shall not be converted to anything
* else than integral type. This rule is not violated however the tool used for checks reports it
* therefore it must be commented here.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* ETH001 */
#include "Eth.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       0
/** @violates @ref Eth_Lcfg_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Lcfg_c_REF_4 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_C    3
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               0
#define ETH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if (ETH_VENDOR_ID_C != ETH_VENDOR_ID)
    #error "Eth_Lcfg.c and Eth.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Eth_Lcfg.c and Eth.h are different"
#endif
/* Check if current file and ETH header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_Lcfg.c and Eth.h are different"
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
/** @violates @ref Eth_Lcfg_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Lcfg_c_REF_4 MISRA rule 5.1 */
#define ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Eth_Lcfg_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_Lcfg_c_REF_2 MISRA rule 19.15
*/
#include "MemMap.h"
/* Used configuration is EthConfigSet_0 */
#define ETH_USED_LT_CFG 0

/*******************************************************************************
* Configuration parameters
*******************************************************************************/
#if ETH_USED_LT_CFG == 0 /* TRUE */
/** The configuration for ConfigSet: EthConfigSet_0.
* @note This configuration is used
*/

/**
* @var Specified for EthCtrlConfig: EthCtrlConfig_0 CtrlId = 0U
* @par Memory usage:
* - RX buffers area: Occupied space: 16512 Bytes
* - TX buffers area: Occupied space: 16512 Bytes
*/
static CONST(Eth_CtrlCfgType, ETH_APPL_CONST) EthConfigSet_0_EthCtrlConfig_0 =
{
    /* Configured MAC Address is 66:55:44:33:22:11 */
    0x66554433U, /**< First 32 bits of MAC address */
    0x22118808U, /**< Last 16 bits of MAC address<<16 | 0x8808 */
    0x00000004U, /**< Value stored to TCR during initialization - full duplex mode selected */
    /* RCR value:
    - Maximal received frame length is 1000
    - MII mode is selected
    - Broadcast is accepted
    - Promiscuous mode is enabled
    - MII mode selected */
    (((VAR(uint32, AUTOMATIC))1024U)<<16U) | 0x0000000cU, /**< Value stored to RCR during initialization */
    (((VAR(uint32, AUTOMATIC))22U)<<1U) | ((VAR(uint32, AUTOMATIC))0U<<8U), /**< Value stored to MSCR during initialization, F_sys,max = 220 MHz */
#if STD_ON == ETH_DEM_EVENT_DETECT
    {(VAR(uint32, AUTOMATIC))STD_OFF, ((Dem_EventIdType)0) },
#endif /* ETH_DEM_EVENT_DETECT */
    1024U, /**< Maximum length of one Rx buffer (header, data, crc, 64-byte alignment) */
    1024U, /**< Maximum length of one Tx buffer (header, data, 64-byte alignment) */
    16U, /**< Number of Rx buffers */
    16U, /**< Number of Tx buffers */
};


#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief         Driver configuration to be passed to Eth_Init function
* @details       This array contains reference to the Link-Time configuration
*                to be used for the Eth driver configuration.
*/
/** @violates @ref Eth_Lcfg_c_REF_5 MISRA rule 8.10  */

CONST(Eth_ConfigType, ETH_APPL_CONST) EthConfigSet_0 = 
{
 {
      /** @violates @ref Eth_Lcfg_c_REF_6 MISRA rule 9.2 */
      &EthConfigSet_0_EthCtrlConfig_0
 }
}; 
/** @violates @ref Eth_Lcfg_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Lcfg_c_REF_4 MISRA rule 5.1 */
#define ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** 
* @violates @ref Eth_Lcfg_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_Lcfg_c_REF_2 MISRA rule 19.15
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
