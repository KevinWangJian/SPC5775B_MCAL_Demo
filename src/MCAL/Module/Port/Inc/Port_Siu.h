/**
* @file    Port_Siu.h
* @version 1.0.1
*
* @brief   AUTOSAR Port - SIU low level IP driver interface.
* @details API of the SIU low level IP driver.
*
* @addtogroup Siu
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIU
*   Dependencies         : none
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef PORT_SIU_H
#define PORT_SIU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_SIU_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file, 
* Precautions shall be taken in order to prevent the contents of a header file 
* being included twice. This violation is not fixed since the inclusion of MemMap.h 
* is as per Autosar requirement MEMMAP003.
*
* @section PORT_SIU_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "modules.h"
#include "Port_Cfg.h"
#include "Port_Siu_Types.h"
#include "Siu_IpVersion.h"

/*=================================================================================================
*                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define PORT_SIU_VENDOR_ID_H                     43
/* @violates @ref PORT_SIU_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIU_AR_RELEASE_MAJOR_VERSION_H      4
/* @violates @ref PORT_SIU_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIU_AR_RELEASE_MINOR_VERSION_H      0
/* @violates @ref PORT_SIU_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIU_AR_RELEASE_REVISION_VERSION_H   3
#define PORT_SIU_SW_MAJOR_VERSION_H              1
#define PORT_SIU_SW_MINOR_VERSION_H              0
#define PORT_SIU_SW_PATCH_VERSION_H              1


#if (STD_ON == USE_PORT_MODULE)
/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if the files Port_Siu.h and Port_Cfg.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_H != PORT_VENDOR_ID_CFG_H)
    #error "Port_Siu.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if the files Port_Siu.h and Port_Cfg.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_H    != PORT_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_H    != PORT_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
  #error "AutoSar Version Numbers of Port_Siu.h and Port_Cfg.h are different"
#endif
/* Check if the files Port_Siu.h and Port_Cfg.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_SIU_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_CFG_H) || \
     (PORT_SIU_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_CFG_H)    \
    )
  #error "Software Version Numbers of Port_Siu.h and Port_Cfg.h are different"
#endif

/* Check if the files Port_Siu.h and Port_Siu_Types.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_H != PORT_SIU_VENDOR_ID_TYPES_H)
    #error "Port_Siu.h and Port_Siu_Types.h have different vendor ids"
#endif
/* Check if the files Port_Siu.h and Port_Siu_Types.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_H    != PORT_SIU_AR_RELEASE_MAJOR_VERSION_TYPES_H) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_H    != PORT_SIU_AR_RELEASE_MINOR_VERSION_TYPES_H) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_H != PORT_SIU_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
   #error "AutoSar Version Numbers of Port_Siu.h and Port_PORT_SIU_Types.h are different"
#endif
/* Check if the files Port_Siu.h and Port_Siu_Types.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_H != PORT_SIU_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_SIU_SW_MINOR_VERSION_H != PORT_SIU_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_SIU_SW_PATCH_VERSION_H != PORT_SIU_SW_PATCH_VERSION_TYPES_H)    \
    )
  #error "Software Version Numbers of Port_Siu.h and Port_Siu_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port_Siu.h and modules.h are of the same version */
   #if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_H != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (PORT_SIU_AR_RELEASE_MINOR_VERSION_H != MODULES_AR_RELEASE_MINOR_VERSION_H)    \
       )
       #error "AutoSar Version Numbers of Port_Siu.h and modules.h are different"
   #endif
#endif

/* Check if the files Port_Siu.h and Siu_IpVersion.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_H != SIU_IPVERSION_VENDOR_ID_REG)
    #error "Port_Siu.h and Siu_IpVersion.h have different vendor ids"
#endif
/* Check if the files Port_Siu.h and Siu_IpVersion.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_H    != SIU_IPVERSION_AR_RELEASE_MAJOR_VERSION_REG) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_H    != SIU_IPVERSION_AR_RELEASE_MINOR_VERSION_REG) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_H != SIU_IPVERSION_AR_RELEASE_REVISION_VERSION_REG) \
    )
  #error "AutoSar Version Numbers of Port_Siu.h and Siu_IpVersion.h are different"
#endif
/* Check if the files Port_Siu.h and Siu_IpVersion.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_H != SIU_IPVERSION_SW_MAJOR_VERSION_REG) || \
     (PORT_SIU_SW_MINOR_VERSION_H != SIU_IPVERSION_SW_MINOR_VERSION_REG) || \
     (PORT_SIU_SW_PATCH_VERSION_H != SIU_IPVERSION_SW_PATCH_VERSION_REG)    \
    )
  #error "Software Version Numbers of Port_Siu.h and Siu_IpVersion.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                               DEFINES AND MACROS
=================================================================================================*/


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                     FUNCTION PROTOTYPES
=================================================================================================*/

/* @brief Allocate defined section for PORT code. */
#define PORT_START_SEC_CODE
/*
* @violates @ref PORT_SIU_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "MemMap.h"

/* @brief    Initializes the SIU IP Driver. */
FUNC (void, PORT_CODE) Port_Siu_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
/*
* @brief     Sets the port pin direction
*/
FUNC (Std_ReturnType, PORT_CODE) Port_Siu_SetPinDirection
(
    VAR    (Port_PinType,          AUTOMATIC                 ) PinIndex,
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) eDirection,
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief    Sets the port pin mode.
*/
#if (IPV_SIU_00_02_09_00 != IPV_SIU)
FUNC (void, PORT_CODE) Port_Siu_SetPinMode
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue,
    VAR(uint16,                 AUTOMATIC) u16InMuxRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) InMuxRegValue
);
#else
FUNC (void, PORT_CODE) Port_Siu_SetPinMode
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue
);
#endif /* (IPV_SIU_00_02_09_00 != IPV_SIU) */
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief    Sets or resets the direction changeability for pads in GPIO mode.
*/
FUNC (void, PORT_CODE) Port_Siu_SetGpioDirChangeability
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PadID,
    VAR(boolean,                AUTOMATIC) bStatus
);

/**
* @brief    Sets the desired output value for the pad  switched in GPIO mode.
*/
FUNC (void, PORT_CODE) Port_Siu_SetGpioPadOutput
(
    VAR    (Port_PinType,    AUTOMATIC                 ) PinIndex,
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */


/**
* @brief   Refreshes port direction.
*/
FUNC (void, PORT_CODE) Port_Siu_RefreshPortDirection
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);

#define PORT_STOP_SEC_CODE
/*
* @violates @ref PORT_SIU_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "MemMap.h"
/* USE_PORT_MODULE */
#endif


#ifdef __cplusplus
}
#endif
/* PORT_SIU_H */
#endif
/** @} */
