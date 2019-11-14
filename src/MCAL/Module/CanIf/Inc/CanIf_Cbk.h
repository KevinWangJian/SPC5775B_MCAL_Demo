/**
*   @file    CanIf.h
*   @version 1.0.1
*
*   @brief   AUTOSAR CanIf - CanIf Cbk module interface
*   @details AUTOSAR CanIf Cbk module interface.- Stub Version
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
#ifndef CANIF_CBK_H
#define CANIF_CBK_H

#ifdef  __cplusplus
extern "C"
{
#endif
#include "CanIf_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CBK_VENDOR_ID                         43
#define CANIF_CBK_MODULE_ID                         60
#define CANIF_CBK_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_CBK_AR_RELEASE_MINOR_VERSION          0
#define CANIF_CBK_AR_RELEASE_REVISION_VERSION       3
#define CANIF_CBK_SW_MAJOR_VERSION                  1
#define CANIF_CBK_SW_MINOR_VERSION                  0
#define CANIF_CBK_SW_PATCH_VERSION                  1

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

FUNC (void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId);

FUNC (void, CANIF_CODE) CanIf_RxIndication( Can_HwHandleType Hrh, Can_IdType CanId, uint8 CanDlc, const uint8* CanSduPtr );
FUNC (void, CANIF_CODE) CanIf_CancelTxConfirmation(PduIdType CanTxPduId, const PduInfoType * PduInfoPtr);

FUNC (void, CANIF_CODE) CanIf_ControllerBusOff(uint8 Controller);

FUNC (void, CANIF_CODE) CanIf_ControllerModeIndication( uint8 Controller, CanIf_ControllerModeType ControllerMode );

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_CBK_H */

/** @} */
