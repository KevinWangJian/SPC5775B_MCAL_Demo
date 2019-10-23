/**
*   @file    Dio_Cfg.c
*   @implements    Dio_Cfg.c_artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio precompile configuration code.
*   @details This file is the Autosar DIO driver precompile configuration
*            code. This file is automatically generated, do not modify manually.
*
*   @addtogroup DIO_CFG
*   @{
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_Cfg_C_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
*          checked to ensure that 31 character significance and case sensitivity are supported
*          for external identifiers.  
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section Dio_Cfg_C_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
*          prevent the contents of a header file being included twice. This violation is not fixed 
*          since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Dio_Cfg_C_REF_3
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*          before '#include'. MemMap.h is included after each section define in order to set 
*          the current memory section as defined by AUTOSAR.
*
* @section Dio_Cfg_C_REF_4
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
*          functions at file scope shall have internal linkage unless external linkage is required.
*          This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Dio.h"


#if defined(DIO_PRECOMPILE_SUPPORT)
/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_VENDOR_ID_CFG_C                   43
/** @violates @ref Dio_Cfg_C_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */

#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_C    4
/** @violates @ref Dio_Cfg_C_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */

#define DIO_AR_RELEASE_MINOR_VERSION_CFG_C    0
/** @violates @ref Dio_Cfg_C_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */

#define DIO_AR_RELEASE_REVISION_VERSION_CFG_C 3
#define DIO_SW_MAJOR_VERSION_CFG_C            1
#define DIO_SW_MINOR_VERSION_CFG_C            0
#define DIO_SW_PATCH_VERSION_CFG_C            1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/


#if (((DIO_AR_RELEASE_MAJOR_VERSION_CFG_C != DIO_AR_RELEASE_MAJOR_VERSION)  ||  \
      (DIO_AR_RELEASE_MINOR_VERSION_CFG_C != DIO_AR_RELEASE_MINOR_VERSION)) ||  \
      (DIO_AR_RELEASE_REVISION_VERSION_CFG_C != DIO_AR_RELEASE_REVISION_VERSION)\
    )
      #error "AutoSar Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif
#if ((DIO_SW_MAJOR_VERSION_CFG_C != DIO_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_CFG_C != DIO_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_CFG_C != DIO_SW_PATCH_VERSION)    \
    )
      #error "Software Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif
#if ((DIO_VENDOR_ID_CFG_C != DIO_VENDOR_ID))
    #error "VENDOR ID for Dio_Cfg.c and Dio.h is different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED

/** @violates @ref Dio_Cfg_C_REF_2 MISRA 2004 Required Rule 19.15,
    Precautions to prevent the contents of a header file being included twice.*/
#include "MemMap.h"


/**
* @brief          Platform implemented port pins representation.
* @details        Array of bit maps reflecting the available pins in each port.
*                 The number of elements in the array corresponds to the number of
*                 ports implemented in the platform package. Leftmost bit of each
*                 array element corresponds to channel 0 of the associated port,
*                 while rightmost bit of each array element corresponds to channel 15
*                 of the associated port. A 0 bit means that the correspondent channel
*                 is not available in the platform package, while a bit of 1 means 
*                 that the correspondent channel is available in the platform package.
*
* @api
*/
/** @violates @ref Dio_Cfg_C_REF_4 All declarations and definitions of objects or functions
    at file scope shall have internal linkage unless external linkage is required. */
CONST(Dio_PortLevelType, DIO_CONST) Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16] = 
{
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x001F,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFE,
   (Dio_PortLevelType)0x7FFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFF8,
   (Dio_PortLevelType)0xEC0F,
   (Dio_PortLevelType)0x01FF,
   (Dio_PortLevelType)0xFFFC,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0xFC17,
   (Dio_PortLevelType)0xDFFF,
   (Dio_PortLevelType)0xFF80,
   (Dio_PortLevelType)0x0000
};

/** @violates @ref Dio_Cfg_C_REF_4 All declarations and definitions of objects or functions
    at file scope shall have internal linkage unless external linkage is required. */
CONST(Dio_PortLevelType, DIO_CONST) Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16] = 
{
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x001F,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFE,
   (Dio_PortLevelType)0x7FFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFF8,
   (Dio_PortLevelType)0xEC0F,
   (Dio_PortLevelType)0x01FF,
   (Dio_PortLevelType)0xFFFC,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0x0000,
   (Dio_PortLevelType)0xFCFF,
   (Dio_PortLevelType)0xFFFF,
   (Dio_PortLevelType)0xFFBF,
   (Dio_PortLevelType)0xFFF0
};


/* ========== DioConfig_0 ========== */

/**
* @brief          Data structure for configuration DioConfig_0.
*/
/** @violates @ref Dio_Cfg_C_REF_4 All declarations and definitions of objects or functions
    at file scope shall have internal linkage unless external linkage is required. */
CONST(Dio_ConfigType, DIO_CONST) DioConfig_0 = 
{
    (uint8)0x0,
    NULL_PTR    
};



#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED

/** @violates @ref Dio_Cfg_C_REF_2 MISRA 2004 Required Rule 19.15,
    Precautions to prevent the contents of a header file being included twice.*/
/** @violates @ref Dio_Cfg_C_REF_3 MISRA 2004 Advisory Rule 19.1,
    Only preprocessor statements and comments before '#include'.*/
#include "MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/


/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/


#endif /* defined(DIO_PRECOMPILE_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */
