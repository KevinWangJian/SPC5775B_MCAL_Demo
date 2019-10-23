/**
*   @file    Dem_IntErrId.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dem -  module error codes
*   @details This file contains error IDs of the AUTOSAR Dem
*            This file contains sample code only. It is not part of the production code deliverables
*    
*   @addtogroup DEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : 
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
#ifndef DEM_INTERRID_H
#define DEM_INTERRID_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEM_INTERRID_VENDOR_ID 43
#define DEM_INTERRID_MODULE_ID 54

#define DEM_INTERRID_AR_RELEASE_MAJOR_VERSION       4
#define DEM_INTERRID_AR_RELEASE_MINOR_VERSION       0
#define DEM_INTERRID_AR_RELEASE_REVISION_VERSION    3
#define DEM_INTERRID_SW_MAJOR_VERSION               1
#define DEM_INTERRID_SW_MINOR_VERSION               0
#define DEM_INTERRID_SW_PATCH_VERSION               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#include "Dem_Types.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
  
 
/** @brief Identifier for DEM error ADC_E_TIMEOUT*/
#define DemConf_DemEventParameter_ADC_E_TIMEOUT   ((Dem_EventIdType) 0x1)

/** @brief Identifier for DEM error DEM_E_GENERAL_FAILURE*/
#define DemConf_DemEventParameter_DEM_E_GENERAL_FAILURE   ((Dem_EventIdType) 0x13)

/** @brief Identifier for DEM error ETH_E_ACCESS*/
#define DemConf_DemEventParameter_ETH_E_ACCESS   ((Dem_EventIdType) 0x2)

/** @brief Identifier for DEM error FLS_E_COMPARE_FAILED*/
#define DemConf_DemEventParameter_FLS_E_COMPARE_FAILED   ((Dem_EventIdType) 0x6)

/** @brief Identifier for DEM error FLS_E_ERASE_FAILED*/
#define DemConf_DemEventParameter_FLS_E_ERASE_FAILED   ((Dem_EventIdType) 0x4)

/** @brief Identifier for DEM error FLS_E_READ_FAILED*/
#define DemConf_DemEventParameter_FLS_E_READ_FAILED   ((Dem_EventIdType) 0x5)

/** @brief Identifier for DEM error FLS_E_UNEXPECTED_FLASH_ID*/
#define DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID   ((Dem_EventIdType) 0x7)

/** @brief Identifier for DEM error FLS_E_WRITE_FAILED*/
#define DemConf_DemEventParameter_FLS_E_WRITE_FAILED   ((Dem_EventIdType) 0x3)

/** @brief Identifier for DEM error FR_E_ACCESS*/
#define DemConf_DemEventParameter_FR_E_ACCESS   ((Dem_EventIdType) 0x8)

/** @brief Identifier for DEM error LIN_E_TIMEOUT*/
#define DemConf_DemEventParameter_LIN_E_TIMEOUT   ((Dem_EventIdType) 0x9)

/** @brief Identifier for DEM error MCU_E_CLOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE   ((Dem_EventIdType) 0xa)

/** @brief Identifier for DEM error MCU_E_LOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_LOCK_FAILURE   ((Dem_EventIdType) 0xb)

/** @brief Identifier for DEM error MCU_E_QUARTZ_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_QUARTZ_FAILURE   ((Dem_EventIdType) 0xc)

/** @brief Identifier for DEM error MCU_E_TIMEOUT_TRANSITION*/
#define DemConf_DemEventParameter_MCU_E_TIMEOUT_TRANSITION   ((Dem_EventIdType) 0xd)

/** @brief Identifier for DEM error PWM_E_UNEXPECTED_IRQ*/
#define DemConf_DemEventParameter_PWM_E_UNEXPECTED_IRQ   ((Dem_EventIdType) 0xe)

/** @brief Identifier for DEM error SPI_E_HARDWARE_ERROR*/
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR   ((Dem_EventIdType) 0xf)

/** @brief Identifier for DEM error WDG_E_DISABLE_REJECTED*/
#define DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED   ((Dem_EventIdType) 0x11)

/** @brief Identifier for DEM error WDG_E_MISS_TRIGGER*/
#define DemConf_DemEventParameter_WDG_E_MISS_TRIGGER   ((Dem_EventIdType) 0x12)

/** @brief Identifier for DEM error WDG_E_MODE_FAILED*/
#define DemConf_DemEventParameter_WDG_E_MODE_FAILED   ((Dem_EventIdType) 0x10)


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
#ifdef __cplusplus
}
#endif

#endif /* DEM_INTERRID_H */
