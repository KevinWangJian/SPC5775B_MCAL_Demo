/**
*   @file    CanIf.h
*   @version 1.0.1
*
*   @brief   AUTOSAR CanIf - CanIf module interface
*   @details AUTOSAR CanIf module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : generic
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

#ifndef CANIF_H
#define CANIF_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanIf_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID                         43
#define CANIF_MODULE_ID                         60
#define CANIF_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_AR_RELEASE_MINOR_VERSION          0
#define CANIF_AR_RELEASE_REVISION_VERSION       3
#define CANIF_SW_MAJOR_VERSION                  1
#define CANIF_SW_MINOR_VERSION                  0
#define CANIF_SW_PATCH_VERSION                  1

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define CANIF_WAKEUP_SUPPORT  (STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
           
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
      FUNC (Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(VAR(EcuM_WakeupSourceType, CANIF_VAR) WakeupSource);
#endif

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_H */

/** @} */
