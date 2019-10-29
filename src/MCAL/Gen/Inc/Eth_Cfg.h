/**
*   @file       Eth_Cfg.h
*   @implements Eth_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eth driver configuration header file
*   @details File containing the configuration for the Ethernet driver
*   @note    This file was generated on 2019-10-29.
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
#ifndef ETH_CFG_H
#define ETH_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_Cfg_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, functions should be used instead of
* function-like macros. Usage of function-like macros violates this advisory
* rule however the function-like macros are used only to wrap functions
* between driver layers so all advantages of function calls are used.
*
* @section Eth_Cfg_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macros is unfortunately longer than 31 characters required by the agreed 
* macros format.
*
* @section Eth_Cfg_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_Cfg_h_REF_7
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like
* macro each instance of a parameter shall be enclosed in parentheses unless
* it is used as the operand of # or ##.
* This violation is wrongly reported by PCLint because the CtrIdx is not used
* as parameter in macro expansion.
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

#include "Mcal.h"
#include "Reg_eSys.h"
#include "Soc_Ips.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_CFG                    43
#define ETH_MODULE_ID_CFG                    88
/** @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MAJOR_VERSION_CFG     4
/** @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MINOR_VERSION_CFG     0
/** @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_CFG  3
#define ETH_SW_MAJOR_VERSION_CFG             1
#define ETH_SW_MINOR_VERSION_CFG             0
#define ETH_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MCAL header file are of the same Autosar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Mcal.h are different"
    #endif
    /* Check if current file and Reg_eSys header file are of the same Autosar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Reg_eSys.h are different"
    #endif
    /* Check if current file and Soc_Ips header file are of the same Autosar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Soc_Ips.h are different"
    #endif
    /* Check if current file and DET header file are of the same Autosar version */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define VARIANT_PRE_COMPILE 0
#define VARIANT_LINK_TIME 1
#define VARIANT_POST_BUILD 2

/**
* @brief Configuration variant specification: VariantLinkTime
*/

#define ETH_CONFIG_VARIANT (VARIANT_LINK_TIME)
 /******************************************************************************
 * Diagnostic Event Manager (DEM)
 ******************************************************************************/
 #define ETH_DEM_EVENT_DETECT  (STD_OFF)  /*!< Enables Diagnostic Event Manager */
 #define ETH_BRIDGE_SUPPORT  (STD_OFF)  /*!< Disable the Ethernet Bridge feature with the dual channels shall be supported */
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief            Support for User mode.
*                   STD_ON: the Eth driver can be executed from both supervisor and user mode. 
*                   STD_OFF: the Eth driver can be executed only from supervisor mode. 
*/
#define ETH_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

/* Configuration access macros */
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TXBUFTOTAL(CtrlIdx)          ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthTxBufTotal)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_RXBUFTOTAL(CtrlIdx)          ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthRxBufTotal)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TXBDSTARTADDRESS(CtrlIdx)    ((uint32)((*(Eth_StaticConfigPtr.pController[CtrlIdx])).TxBufStartAddr))
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_RXBDSTARTADDRESS(CtrlIdx)    ((uint32)((*(Eth_StaticConfigPtr.pController[CtrlIdx])).RxBufStartAddr))
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_CTRLTXBUFLENBYTE(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthCtrlTxBufLenByte)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_CTRLRXBUFLENBYTE(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthCtrlRxBufLenByte)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_ENABLERXINTERRUPT(CtrlIdx)   ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).EnableRxInterrupt)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_ENABLETXINTERRUPT(CtrlIdx)   ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).EnableTxInterrupt)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MDIOSUPPORT(CtrlIdx)         ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).MDIOSupport)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MACADDRESSLOW(CtrlIdx)       ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthMACAddressLow)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MACADDRESSHIGH(CtrlIdx)      ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthMACAddressHigh)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MSCR(CtrlIdx)                ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthMSCR)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_RCR(CtrlIdx)                 ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthRCR)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TCR(CtrlIdx)                 ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthTCR)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_CTRLIDXINETHIF(CtrlIdx)      ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).EthCtrlIdxInEthIf)
#if STD_ON == ETH_DEM_EVENT_DETECT
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_ACCESS_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).ETH_DEM_E_ACCESS_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_ACCESS(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).ETH_DEM_E_ACCESS_Cfg.id)
#endif /* ETH_DEM_EVENT_DETECT */

/******************************************************************************
* Features enable/disable switches 
******************************************************************************/
/* ETH004_Conf */
#define ETH_VERSION_INFO_API (STD_ON) /*!< Enables Version info function */
/* ETH005_Conf */
#define ETH_VERSION_INFO_API_MACRO (STD_OFF) /*!< Enables Version info function implementation as macro */
/* ETH019_Conf */
#define ETH_UPDATE_PHYS_ADDR_FILTER (STD_OFF) /*!< Enables optional API Eth_UpdatePhysAddrFilter */

/* Multi-Buffer frames support */
#define ETH_USE_MULTIBUFFER_RX_FRAMES (STD_OFF) /*!< Enables multi-buffer frames reception */
#define ETH_USE_RX_FRAMES_WRAP (STD_OFF) /*!< Enables multi-buffer frames wrap */

/* TX Multi-Buffer frames support */
#define ETH_USE_MULTIBUFFER_TX_FRAMES (STD_OFF) /*!< Enables multi-buffer frames transmission */

    /* This macro can have STD_OFF value only if the controller in all multiple configurations
       does not use the MII API. The value STD_ON means that code is compiled but the MII
       might not be used (API is present because it is needed in another multiple configuration
       but it is not called). */
    /* @requirements SWS_Eth_00012_Conf */
    #define ETH_CTRLENABLE_MII (STD_ON)         /*!< MII handling functions compilation enabled */      



    /******************************************************************************
    * Development Error Detection 
    ******************************************************************************/
    /* ETH003_Conf */
    #define ETH_DEV_ERROR_DETECT  (STD_OFF)     /*!< Enables Development Error Detect feature */
    
    /******************************************************************************
    * Configuration constants
    ******************************************************************************/
    /* Required Eth buffers alignment, may be different for TX and RX depending on the used IP */
    #define ETH_TX_BUF_ALIGNMENT 64 /* 64 bytes */
    #define ETH_RX_BUF_ALIGNMENT 64 /* 64 bytes */
    /* ETH002_Conf */
    #define ETH_MAXCTRLS_SUPPORTED 1U  /* Number of supported controllers */
    #if ETH_CONFIG_VARIANT == VARIANT_POST_BUILD /* Only post-build variant can have multiple configurations */
      #define ETH_NUM_OF_CONFIGURATIONS 1U /* Number of configurations */
    #else /* VARIANT_POST_BUILD */
      #define ETH_NUM_OF_CONFIGURATIONS 1U /* Number of configurations */
    #endif /* VARIANT_POST_BUILD */
    #define ETH_DRIVER_INSTANCE 0U   /* Instance number assigned to the driver */
    /* FEC is running on half of core frequency at least 10 bus cycles are needed
       so the minimal value is 20 */
    #define ETH_RESET_WAIT_LOOP_COUNT 30U /* Reset waiting loop timeout */
    #define ETH_INFINITE_LOOP_PROTECTION 4096U /* Number of runs in the loop 
                  before it is claimed to be never-ending and broken */   
    #define DEBUG_VARIABLES (STD_OFF) /* Debug variables inclusion into the code -
     debug variables are normally excluded from the code to save memory space */
    
    #define ETH_MULTICAST_POOL_SIZE 15U /* Maximal count of MAC address inside multicast pool */

    #define ETHTXBUFNUM 255U /* Number of tranmit buffers supported by the driver 
         each buffer requires one byte in internal driver memory, decreasing this number
         allows reducing memory consumption */



    /* Sizes of memory blocks allocated for TX/RX data buffers and related descriptors */
    #define ETH_TX_BUF_MEM_SIZE (23680U)
    #define ETH_RX_BUF_MEM_SIZE (23680U)
    #define ETH_MAX_CONTROLLER_CFG  (1U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief         Type for Ethernet driver configuration values storage.
* @details       This type is used to collect and pass all configuration data
*                of one controller (except those which have only
*                precompile variant) to the Eth driver.
* @implements Eth_CtrlCfgType_structure
*/
typedef struct
{
    uint32 EthMACAddressLow;     /**< First 32 bits of MAC address */
    uint32 EthMACAddressHigh; /**< Last 16 bits of MAC address<<16|0x8808 */
    uint32 EthTCR;         /**< Value stored to TCR during initialization */
    uint32 EthRCR;         /**< Value stored to RCR during initialization */
    uint32 EthMSCR;        /**< Value stored to MSCR during initialization */
#if ETH_DEM_EVENT_DETECT
    Mcal_DemErrorType ETH_DEM_E_ACCESS_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_ACCESS and   */
#endif /* ETH_DEM_EVENT_DETECT */
    uint16 EthCtrlRxBufLenByte;  /**< Length of one Rx buffer*/
    uint16 EthCtrlTxBufLenByte;  /**< Length of one Tx buffer */
    uint8 EthRxBufTotal;         /**< Number of Rx buffers */
    uint8 EthTxBufTotal;         /**< Number of Tx buffers */
} Eth_CtrlCfgType;

/**
* @brief         Type for Ethernet driver Static configuration values storage.
* @details       This type is used to collect and pass all configuration data
*                of one controller (except those which have only
*                precompile variant) to the Eth driver.
*/
typedef struct
{
    boolean EnableRxInterrupt;   /**< Enable interrupt requests for frame
                                      reception event */
    boolean EnableTxInterrupt;   /**< Enable interrupt requests for
                                      frame transmission event */
    boolean MDIOSupport;         /**<Support MDIO for current controller */
    uint8 EthCtrlIdxInEthIf;     /**< Instance ID of the controller */
    uint8 *TxBufStartAddr;       /**< Start address for TX buffer of the controller */
    uint8 *RxBufStartAddr;       /**< Start address for TX buffer of the controller */
} Eth_StaticCtrlCfgType;

/* 
* @brief This type is used to group all multiple configurations.
*/   
typedef struct 
{
    P2CONST(Eth_CtrlCfgType, TYPEDEF, ETH_APPL_DATA) pController[ETH_MAXCTRLS_SUPPORTED];
} Eth_ConfigType;


/* 
* @brief This type is used to group Static configuration for all controllers.
*/   
typedef struct 
{
    P2CONST(Eth_StaticCtrlCfgType, TYPEDEF, ETH_APPL_DATA) pController[ETH_MAXCTRLS_SUPPORTED];
} Eth_StaticConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ETH_START_SEC_CONST_UNSPECIFIED
/** 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "MemMap.h"

/* Configuration for parameters which are not variant */
extern CONST(Eth_StaticConfigType, ETH_APPL_CONST) Eth_StaticConfigPtr;

#define ETH_STOP_SEC_CONST_UNSPECIFIED
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "MemMap.h"


/**
* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "MemMap.h"


/** @violates @ref Eth_Cfg_h_REF_8 MISRA rule 8.8 */
extern CONST(Eth_ConfigType, ETH_APPL_CONST) EthConfigSet_0;

/**
* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED

/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "MemMap.h"






/* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "MemMap.h"
extern VAR_ALIGN(VAR(uint8, ETH_VAR) Eth_RxBuffers[ETH_MAX_CONTROLLER_CFG][ETH_RX_BUF_MEM_SIZE],ETH_RX_BUF_ALIGNMENT)
extern VAR_ALIGN(VAR(uint8, ETH_VAR) Eth_TxBuffers[ETH_MAX_CONTROLLER_CFG][ETH_TX_BUF_MEM_SIZE],ETH_TX_BUF_ALIGNMENT)

/* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */   
#endif /* ETH_CFG_H */
/** @} */
