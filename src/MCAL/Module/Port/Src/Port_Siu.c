/**
*   @file    Port_Siu.c
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - SIU Low level driver implementation.
*   @details Implementation of the SIU low level driver.
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
#ifdef __cplusplus
extern "C" {
#endif

/**
*  @page misra_violations MISRA-C:2004 violations
*
*  @section Port_Siu_C_REF_1
*  Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*  '#include'. MemMap.h is included after each section define in order to set the current memory section 
*  as defined by AUTOSAR.
*
*  @section Port_Siu_C_REF_2
*  Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*  This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
*  @section Port_Siu_C_REF_3
*  Violates MISRA 2004 Required Rule 1.4, Identifier clash. 
*  The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
*  @section Port_Siu_C_REF_4
*  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*  This macro compute the address of any register by using the hardware offset of the controller.
*  The address calculated as an unsigned int is passed to  a macro for initializing the pointer
*  with that address. (ex: see REG_WRITE32 macro).
*
*  @section Port_Siu_C_REF_5
*  Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used.
*  This violation is due to the use of pointer arithmetic, to access the channel parameters,
*  the indexing of the pointer is taken care and hence the unintended memory location will not
*  be accessed.
*
*  @section Port_Siu_C_REF_6
*  Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
*  an integral type. The cast is used to access memory mapped registers.
*
*  @section [global]
*  Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely
*  on the significance of more than 31 characters. The used compilers use more than 31 chars
*  for identifiers.
*
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "modules.h"
#include "Port.h"
#include "Port_Reg_eSys_Siu.h"
#include "Port_Siu.h"
#include "SchM_Port.h"
#include "Siu_IpVersion.h"

#define USER_MODE_REG_PROT_ENABLED (PORT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

/*=================================================================================================
                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define PORT_SIU_VENDOR_ID_C                     43
/* @violates @ref Port_Siu_C_REF_3 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIU_AR_RELEASE_MAJOR_VERSION_C      4
/* @violates @ref Port_Siu_C_REF_3 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIU_AR_RELEASE_MINOR_VERSION_C      0
/* @violates @ref Port_Siu_C_REF_3 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIU_AR_RELEASE_REVISION_VERSION_C   3
#define PORT_SIU_SW_MAJOR_VERSION_C              1
#define PORT_SIU_SW_MINOR_VERSION_C              0
#define PORT_SIU_SW_PATCH_VERSION_C              1

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_Siu.c and Port.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_C != PORT_VENDOR_ID)
    #error "Port_Siu.c and Port.h have different vendor ids"
#endif
/* Check if Port_Siu.c and Port.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
   #error "AutoSar Version Numbers of Port_Siu.c and Port.h are different"
#endif
/* Check if Port_Siu.c and Port.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SIU_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SIU_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION)    \
    )
  #error "Software Version Numbers of Port_Siu.c and Port.h are different"
#endif
/* Check if Port_Siu.c and Port_Siu.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_C != PORT_SIU_VENDOR_ID_H)
    #error "Port_Siu.c and Port_Siu.h have different vendor ids"
#endif
/* Check if Port_Siu.c and Port_Siu.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_C    != PORT_SIU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_C    != PORT_SIU_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_C != PORT_SIU_AR_RELEASE_REVISION_VERSION_H) \
    )
  #error "AutoSar Version Numbers of Port_Siu.c and Port_Siu.h are different"
#endif
/* Check if Port_Siu.c and Port_Siu.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_C != PORT_SIU_SW_MAJOR_VERSION_H) || \
     (PORT_SIU_SW_MINOR_VERSION_C != PORT_SIU_SW_MINOR_VERSION_H) || \
     (PORT_SIU_SW_PATCH_VERSION_C != PORT_SIU_SW_PATCH_VERSION_H)    \
    )
  #error "Software Version Numbers of Port_Siu.c and Port_Siu.h are different"
#endif

/* Check if Port_Siu.c and Port_Reg_eSys_Siu.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_C != PORT_REGESYS_SIU_VENDOR_ID)
    #error "Port_Siu.c and Port_Reg_eSys_Siu.h have different vendor ids"
#endif
/* Check if Port_Siu.c and Port_Reg_eSys_Siu.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_C    != PORT_REGESYS_SIU_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_C    != PORT_REGESYS_SIU_AR_RELEASE_MINOR_VERSION) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_C != PORT_REGESYS_SIU_AR_RELEASE_REVISION_VERSION) \
    )
   #error "AutoSar Version Numbers of Port_Siu.c and Port_Reg_eSys_Siu.h are different"
#endif
/* Check if Port_Siu.c and Port_Reg_eSys_Siu.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_C != PORT_REGESYS_SIU_SW_MAJOR_VERSION) || \
     (PORT_SIU_SW_MINOR_VERSION_C != PORT_REGESYS_SIU_SW_MINOR_VERSION) || \
     (PORT_SIU_SW_PATCH_VERSION_C != PORT_REGESYS_SIU_SW_PATCH_VERSION)    \
    )
  #error "Software Version Numbers of Port_Siu.c and Port_Reg_eSys_Siu.h are different"
#endif
/* Check if Port_Siu.c and Port_Siu.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_C != PORT_SIU_VENDOR_ID_H)
    #error "Port_Siu.c and Port_Siu.h have different vendor ids"
#endif
/* Check if Port_Siu.c and Port_Siu.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_C    != PORT_SIU_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_C    != PORT_SIU_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_C != PORT_SIU_AR_RELEASE_REVISION_VERSION_H) \
    )
   #error "AutoSar Version Numbers of Port_Siu.c and Port_Siu.h are different"
#endif
/* Check if Port_Siu.c and Port_Siu.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_C != PORT_SIU_SW_MAJOR_VERSION_H) || \
     (PORT_SIU_SW_MINOR_VERSION_C != PORT_SIU_SW_MINOR_VERSION_H) || \
     (PORT_SIU_SW_PATCH_VERSION_C != PORT_SIU_SW_PATCH_VERSION_H)    \
    )
  #error "Software Version Numbers of Port_Siu.c and Port_Siu.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port_Siu.c and SilRegMacros.h are of the same version */
    #if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_SIU_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Port_Siu.c and SilRegMacros.h are different"
    #endif
    /* Check if the files Port_Siu.c and modules.h are of the same version */
   #if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_C != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (PORT_SIU_AR_RELEASE_MINOR_VERSION_C != MODULES_AR_RELEASE_MINOR_VERSION_H)    \
       )
       #error "AutoSar Version Numbers of Port_Siu.c and modules.h are different"
   #endif
#endif

/* Check if the files Port_Siu.c and Siu_IpVersion.h are of the same vendor */
#if (PORT_SIU_VENDOR_ID_C != SIU_IPVERSION_VENDOR_ID_REG)
    #error "Port_Siu.c and Siu_IpVersion.h have different vendor ids"
#endif
/* Check if the files Port_Siu.c and Siu_IpVersion.h are of the same Autosar version */
#if ((PORT_SIU_AR_RELEASE_MAJOR_VERSION_C    != SIU_IPVERSION_AR_RELEASE_MAJOR_VERSION_REG) || \
     (PORT_SIU_AR_RELEASE_MINOR_VERSION_C    != SIU_IPVERSION_AR_RELEASE_MINOR_VERSION_REG) || \
     (PORT_SIU_AR_RELEASE_REVISION_VERSION_C != SIU_IPVERSION_AR_RELEASE_REVISION_VERSION_REG) \
    )
  #error "AutoSar Version Numbers of Port_Siu.c and Siu_IpVersion.h are different"
#endif
/* Check if the files Port_Siu.c and Siu_IpVersion.h are of the same software version */
#if ((PORT_SIU_SW_MAJOR_VERSION_C != SIU_IPVERSION_SW_MAJOR_VERSION_REG) || \
     (PORT_SIU_SW_MINOR_VERSION_C != SIU_IPVERSION_SW_MINOR_VERSION_REG) || \
     (PORT_SIU_SW_PATCH_VERSION_C != SIU_IPVERSION_SW_PATCH_VERSION_REG)    \
    )
  #error "Software Version Numbers of Port_Siu.c and Siu_IpVersion.h are different"
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


/*=================================================================================================
                                       GLOBAL VARIABLES
=================================================================================================*/

#define PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
*  @violates @ref Port_Siu_C_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#include "MemMap.h"

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief    Segment descriptor for data arranged in array
* @detail   Port_Siu_au16GPIODirChangeability variable is only used by PORT_Siu_SetPinDirection
*           and PORT_Siu_SetPinMode functions
*/
static VAR(uint16, PORT_VAR) Port_Siu_au16GPIODirChangeability[PAD_16BLOCK_NO_U8];
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

#define PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/**
* @violates @ref Port_Siu_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1
* @violates @ref Port_Siu_C_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#include "MemMap.h"

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
                                       LOCAL FUNCTIONS
=================================================================================================*/
#define PORT_START_SEC_CODE
/**
* @violates @ref Port_Siu_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1
* @violates @ref Port_Siu_C_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#include "MemMap.h"

/*=================================================================================================
                                       GLOBAL FUNCTIONS
=================================================================================================*/

/**
* @brief        Initializes the SIU IP Driver
* @details      The function Port_Siu_Init will initialize ALL ports and port pins with the
*               configuration set pointed to by the parameter pConfigPtr.
*
* @param[in]    pConfigPtr  A pointer to the structure which contains initialization parameters
*
* @return none
*
* @pre    none
* @post   No function of the driver is executed without the initialisation of the module.
*
*
*/
FUNC(void, PORT_CODE) Port_Siu_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    /* Initialize all variables */
    VAR(uint16, AUTOMATIC) u16PinIndex;
    VAR(uint16, AUTOMATIC) u16NumUnusedPins = (uint16)(pConfigPtr->u16NumUnusedPins);
    VAR(uint16, AUTOMATIC) u16NumPins       = (uint16)(pConfigPtr->u16NumPins);
    
    VAR(uint16, AUTOMATIC) u16LocalPCR = pConfigPtr->pUnusedPadConfig->u16PCR;
    VAR(uint8,  AUTOMATIC) u8LocalPDO = pConfigPtr->pUnusedPadConfig->u8PDO;
#if (IPV_SIU_00_02_09_00 != IPV_SIU)
    VAR(uint16, AUTOMATIC) u16InmuxIndex;
    VAR(uint16, AUTOMATIC) u16NumInmuxRegs  = PORT_NMBR_INMUX_REGS_U16;
    VAR(uint8,  AUTOMATIC) u8MuxselValue;
    VAR(uint32, AUTOMATIC) u32LocalVar;
    VAR(uint8,  AUTOMATIC) u8Inmux;
    VAR(uint8,  AUTOMATIC) u8Muxsel;
#endif
    VAR(uint16, AUTOMATIC) u16PcrPin;
    VAR(Port_InternalPinIdType, AUTOMATIC) PinPad;

    /* Initialize All UnUsed Port Pins */
    for (u16PinIndex = (uint16)0U; u16PinIndex < u16NumUnusedPins; u16PinIndex++)
    {
        /**
        * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
        */
        u16PcrPin = pConfigPtr->au16UnusedPads[u16PinIndex];

        /**
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE8(SIU_GPDO_ADDR32((uint32)u16PcrPin), u8LocalPDO);
        /* Write MSCR configuration from Configuration tool */
        /**
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE16(SIU_PCR_ADDR32((uint32)u16PcrPin), u16LocalPCR);
    }

    /* Initialize All Configured Port Pins */
    for (u16PinIndex = (uint16)0U; u16PinIndex < u16NumPins; u16PinIndex++)
    {
        /**
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
        */
        PinPad = (uint16)(pConfigPtr->pUsedPadConfig[u16PinIndex].u16SIUPin);

        /**
        * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
        */
        u8LocalPDO = pConfigPtr->pUsedPadConfig[u16PinIndex].u8PDO;

        /**
        * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
        */
        if (pConfigPtr->pUsedPadConfig[u16PinIndex].bGPIO)
        {
            /* Set pin to High value */
            if (PORT_PIN_LEVEL_HIGH_U8 == u8LocalPDO)
            {
                /**
                * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE8(SIU_GPDO_ADDR32((uint32)PinPad), (uint8)STD_HIGH );
            }
            /* Set pin to Low value */
            else if (PORT_PIN_LEVEL_LOW_U8 == u8LocalPDO)
            {
                /**
                * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE8(SIU_GPDO_ADDR32((uint32)PinPad), (uint8)STD_LOW );
            }
            else
            {
                /* No action to be done */
            }
        }
        else
        {
            /* No action to be done */
        }
        /**
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE16(SIU_PCR_ADDR32((uint32)PinPad), (uint16)(pConfigPtr->pUsedPadConfig[u16PinIndex].u16PCR));
    }

#if (IPV_SIU_00_02_09_00 != IPV_SIU)
    /* Write Multiplexed Pad configuration registers from Configuration tool */
    for (u16InmuxIndex = (uint16)0U; u16InmuxIndex < u16NumInmuxRegs; u16InmuxIndex++)
    {
        /**
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
        */
        u8MuxselValue = ((uint8)(pConfigPtr->pPadSelConfig[u16InmuxIndex]));
        /* Write the coresponding Muxsel in the right Inmux register, only if the Muxsel is not reserved */
        if (MUXSEL_RESERVED_U8 != u8MuxselValue)
        {
            /* Get the number of the Inmux that needs to be set. There are 16 MUXSELs in one Inmux register
            so we need to divide by 16 to get to the Inmux we need */
            u8Inmux  = (uint8)(u16InmuxIndex >> 4);
            /* Get the number of the Muxsel by performing a modulo 16 operation */
            u8Muxsel = (uint8)((uint8)u16InmuxIndex & (uint8)0x0F);
            /** 
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.            
            */
            u32LocalVar  = REG_READ32(SIU_INMUX_ADDR32((uint32)u8Inmux));
            /* Clear first the Muxsel in the corresponding Inmux register */
            u32LocalVar &= ~(uint32)((uint32)SIU_INMUX_MUXSEL_MASK_U32 << ((uint32)u8Muxsel << 1));
            /* Set the Muxsel in the corresponding Inmux register */
            u32LocalVar |= (uint32)((uint32)u8MuxselValue << ((uint32)u8Muxsel << 1));
            /* Write the new value of the Inmux back in the register */
            /** 
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.            
            */
            REG_WRITE32(SIU_INMUX_ADDR32((uint32)u8Inmux),u32LocalVar);
        }
    }
#endif /* (IPV_SIU_00_02_09_00 != IPV_SIU) */

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
    /* Port_Siu_au16GPIODirChangeability is only used by PORT_Siu_SetPinDirection and PORT_Siu_SetPinMode functions */
    /* Initialize the Array with Change Direction Flags for GPIO */
    for (u16PinIndex=(uint16)0U; u16PinIndex < PAD_16BLOCK_NO_U8; u16PinIndex++)
    {
        Port_Siu_au16GPIODirChangeability[u16PinIndex] = (uint16)0UL;
    }
#endif
}


#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Sets the port pin direction
* @details Sets the pin direction at runtime, changing it only if the pin is configurated as
*          changeable.
*
* @param[in]     PinIndex      Pin ID number
* @param[in]     eDirection      Port Pin direction
* @param[in]     pConfigPtr      A pointer to the structure which contains initialization parameters
*
* @return Error code after execution
* @retval 0   No error occured
* @retval 1   Pin direction cannot be changed
*
* @pre Port_Init must have been called
* @post none
*
*
*/
FUNC (Std_ReturnType, PORT_CODE) Port_Siu_SetPinDirection
(
    VAR    (Port_PinType,          AUTOMATIC                 ) PinIndex,
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) eDirection,
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    /* Point to the Port Pin MSCR register address */
    /**
    * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
    * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
    */
    VAR(uint16, AUTOMATIC) u16PinPad = (uint16)pConfigPtr->pUsedPadConfig[PinIndex].u16SIUPin;

    /* Return value */
    VAR(Std_ReturnType, AUTOMATIC) PinDirError = (Std_ReturnType)E_OK;

    /* Bit Offset and Table value for change direction flag word */
    VAR(uint8,  AUTOMATIC) u8PinDescBitOffset = (uint8)((uint8)u16PinPad & (uint8)0x0F);
    VAR(uint16, AUTOMATIC) u16PinChangeDirFlagWord = Port_Siu_au16GPIODirChangeability[(uint8)(u16PinPad >> 4)];

    /* Check the Direction changeability option */
    /**
    * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
    */
    if (((boolean)TRUE == pConfigPtr->pUsedPadConfig[PinIndex].bDC) || ((uint16)0 != (u16PinChangeDirFlagWord & (uint16)(1UL << u8PinDescBitOffset))))
    {
        /* Enter critical region */
        SchM_Enter_Port_PORT_EXCLUSIVE_AREA_03();
        /* Configures Port Pin as Output */
        if (PORT_PIN_OUT == eDirection)
        {
            /**
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_CLEAR16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_IBE_ON_U16);

            /**
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_OBE_ON_U16 );
        }
        /* Configures Port Pin as Input */
        else if (PORT_PIN_IN == eDirection)
        {
            /** 
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_CLEAR16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_OBE_ON_U16);
            /** 
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_IBE_ON_U16);
        }
        else
        {
            /** 
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_IBE_ON_U16);
            /** 
            * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
            * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_OBE_ON_U16);
        }
        /* Exit critical region */
        SchM_Exit_Port_PORT_EXCLUSIVE_AREA_03();
    }
    /* Direction changeability is NOT supported */
    else
    {
        PinDirError = (Std_ReturnType)E_NOT_OK;
    }

    return PinDirError;
}
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */


#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Sets the port pin mode.
* @details The function will set the port pin mode of the referenced pin during runtime
*
* @param[in]     PinCfgRegIndex         Index of Register MSCR
* @param[in]     PinCfgRegValue         Value of Register MSCR
* @param[in]     u16InMuxRegIndex       Index of Register IMCR
* @param[in]     InMuxRegValue          Value of Register IMCR
*
* @return Error code after execution
* @retval 0   No error occured
* @retval PORT_E_MODE_UNCHANGEABLE   Pin mode cannot be changed
* @retval PORT_E_PARAM_INVALID_MODE  Invalid mode
*
* @pre Port_Init must have been called
* @post none
*
*
*/
#if (IPV_SIU_00_02_09_00 != IPV_SIU)
FUNC (void, PORT_CODE) Port_Siu_SetPinMode
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue,
    VAR(uint16,                 AUTOMATIC) u16InMuxRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) InMuxRegValue
)
#else
FUNC (void, PORT_CODE) Port_Siu_SetPinMode
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue
)
#endif
{
#if (IPV_SIU_00_02_09_00 != IPV_SIU)
    VAR(uint32, AUTOMATIC) u32LocalVar = (uint32)0U;
    VAR(uint8,  AUTOMATIC) u8Inmux = (uint8)0U;
    VAR(uint8,  AUTOMATIC) u8Muxsel = (uint8)0U;
#endif
    /* Variable used to clear and updated PCR register*/
    VAR(uint16, AUTOMATIC) u16LocalVar = (uint16)0U;
    
    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
    
    /** 
    * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
    * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
    */
    u16LocalVar = REG_READ16(SIU_PCR_ADDR32((uint32)PinCfgRegIndex));

#ifndef PORT_NO_ANALOG_MODE   
    if (PORT_ANALOG_INPUT_MODE == PinCfgRegValue)
    {
        /* Clear the previous mode and the IBE bit */
        u16LocalVar &= ~(SIU_PCR_PA_U16 | SIU_PCR_IBE_U16);
        /** 
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE16(SIU_PCR_ADDR32((uint32)PinCfgRegIndex), u16LocalVar);
    }
    else
#endif
    {
        /* Clear the previous mode. Do not alter the other settings */
        /** @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        u16LocalVar &= ~(SIU_PCR_PA_U16);

        /* Set the proper mode in MSCR */
        u16LocalVar |= ((uint16)PinCfgRegValue << SIU_PCR_PA_OFFSET_U16);
        /** 
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE16(SIU_PCR_ADDR32((uint32)PinCfgRegIndex), u16LocalVar);
    }

#if (IPV_SIU_00_02_09_00 != IPV_SIU)
    if (NO_INPUTMUX_U16 != u16InMuxRegIndex)
    {
        /* Set the proper values in Muxsel in the right Inmux register */
        /* Get the number of the Inmux that needs to be set. There are 16 Muxsels in one Inmux register
        so we need to divide by 16 to get to the Inmux we need */
        u8Inmux  = (uint8)(u16InMuxRegIndex >> 4);
        /* Get the number of the Muxsel by performing a modulo 16 operation */
        u8Muxsel = (uint8)((uint8)u16InMuxRegIndex & (uint8)0x0F);
        /** 
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        u32LocalVar  = REG_READ32(SIU_INMUX_ADDR32((uint32)u8Inmux));
        /* Clear first the Muxsel in the corresponding Inmux register */
        u32LocalVar &= ~(uint32)((uint32)SIU_INMUX_MUXSEL_MASK_U32 << ((uint32)u8Muxsel << 1));
        /* Set the Muxsel in the corresponding Inmux register */
        u32LocalVar |= (uint32)((uint32)InMuxRegValue << ((uint32)u8Muxsel << 1));
        /* Write the new value of the Inmux back in the register */
        /** 
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. 
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(SIU_INMUX_ADDR32((uint32)u8Inmux), u32LocalVar );
    }
#endif /* (IPV_SIU_00_02_09_00 != IPV_SIU) */

    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
}
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */


#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief    Sets or resets the direction changeability for pads in GPIO mode.
* @details  The function will update the direction changeabilty for the pads whose mode is changed
*
* @param[in] PadID          Pin ID number.
* @param[in] bStatus        The new value true or falsr for directuion changeability.
*
* @return    None
*
* @pre  none
* @post none
*
*
*/
FUNC (void, PORT_CODE) Port_Siu_SetGpioDirChangeability
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PadID,
    VAR(boolean,                AUTOMATIC) bStatus
)
{
    /* Pin description variables */
    VAR(uint16, AUTOMATIC) u16PinDirFlagWord;
    VAR(uint8, AUTOMATIC) u8PinBitOffset;

    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02();
    /* Bit offset of Pin index inside the pin description matrix */
    u8PinBitOffset    = (uint8)((uint8)PadID & (uint8)0x0F);
    u16PinDirFlagWord = Port_Siu_au16GPIODirChangeability[(uint8)(PadID >> 4)];

    if ((boolean)TRUE == bStatus)
    {
        /* Set the change direction flag */
        u16PinDirFlagWord |= (uint16)(1UL << u8PinBitOffset);
    }
    else
    {   /* Reset the change direction flag */
        u16PinDirFlagWord &= (uint16)(~((uint16)(1UL << u8PinBitOffset)));
    }
    Port_Siu_au16GPIODirChangeability[(uint8)(PadID >> 4)] = u16PinDirFlagWord;
    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02();
}

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
/**
* @brief    Sets the output status of the pads in GPIO mode.
* @details  The function will update the output for the pads whose mode is changed
*
* @param[in] PinIndex     Pin ID number.
* @param[in] pConfigPtr     A pointer to the structure which contains initialization parameters
*
*
* @return    None
*
* @pre  none
* @post none
*
*
*/

FUNC (void, PORT_CODE) Port_Siu_SetGpioPadOutput
(
    VAR    (Port_PinType,    AUTOMATIC                 ) PinIndex,
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    /**
    * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
    */
    VAR(uint16, AUTOMATIC) u16PinPad = (uint16)(pConfigPtr->pUsedPadConfig[PinIndex].u16SIUPin);
    /**
    * @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4
    */
    VAR(uint8, AUTOMATIC) u8LocalPDO = pConfigPtr->pUsedPadConfig[PinIndex].u8PDO;

    /* Set pin to High value */
    if (PORT_PIN_LEVEL_HIGH_U8 == u8LocalPDO)
    {
        /**
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE8( SIU_GPDO_ADDR32(u16PinPad), (uint8)STD_HIGH );
    }
    /* Set pin to Low value */
    else if (PORT_PIN_LEVEL_LOW_U8 == u8LocalPDO)
    {
        /**
        * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
        * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE8( SIU_GPDO_ADDR32(u16PinPad), (uint8)STD_LOW );
    }
    else
    {
        /* No action to be done */
    }
}
#endif /* (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL) */
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */


/**
* @brief   Refreshes port direction.
* @details This service shall refresh the direction of all configured ports to the configured
*          direction. The PORT driver shall exclude from refreshing those port pins that are
*          configured as pin direction changeable during runtime.
*
* @param[in]     numPins    Number of pins to be refreshed
* @return none
*
* @pre Port_Init must have been called
* @post none
*
*/
FUNC (void, PORT_CODE) Port_Siu_RefreshPortDirection
(
    P2CONST(Port_ConfigType, AUTOMATIC,PORT_APPL_CONST) pConfigPtr
)
{
    VAR(uint16, AUTOMATIC) u16NumPins = pConfigPtr->u16NumPins;
    /* Index of the port table */
    VAR(uint16, AUTOMATIC) u16PinIndex;
    VAR(uint16, AUTOMATIC) u16PinPad;

    /* Initialize All Configured Port Pins that aren't direction changable */
    for (u16PinIndex = (uint16)0U; u16PinIndex < u16NumPins; u16PinIndex++)
    {
        /** @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4 */
        /** @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ((boolean)FALSE == pConfigPtr->pUsedPadConfig[u16PinIndex].bDC)
        {
            /* Point to the Port Pin MSCR register address*/
            /** @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4 */
            /** @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            u16PinPad = (uint16)pConfigPtr->pUsedPadConfig[u16PinIndex].u16SIUPin;

            /* Enter critical region KK*/
            SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();

            /* Configures Port Pin as Output */
            /** @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4 */
            /** @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            if (pConfigPtr->pUsedPadConfig[u16PinIndex].u16PCR & SIU_PCR_OBE_U16)
            {
                /**
                * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_SET16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_OBE_ON_U16 );
            }
            else
            {
                /**
                * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_CLEAR16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_OBE_ON_U16);
            }
            /* Configures Port Pin as Input */
            /** @violates @ref Port_Siu_C_REF_5 Violates MISRA 2004 Required Rule 17.4 */
            /** @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            if (pConfigPtr->pUsedPadConfig[u16PinIndex].u16PCR & SIU_PCR_IBE_U16)
            {
                /**
                * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_SET16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_IBE_U16);
            }
            else
            {
                /**
                * @violates @ref Port_Siu_C_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                * @violates @ref Port_Siu_C_REF_6 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_CLEAR16(SIU_PCR_ADDR32((uint32)u16PinPad), SIU_PCR_IBE_U16);
           }
           /* Exit critical region */
           SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
        }
    }
}


#define PORT_STOP_SEC_CODE
/**
* @violates @ref Port_Siu_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
* @violates @ref Port_Siu_C_REF_2 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
