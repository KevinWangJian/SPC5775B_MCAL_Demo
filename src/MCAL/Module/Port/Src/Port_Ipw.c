/**
*   @file    Port_Ipw.c
*
*   @version 1.0.1
*   @brief   AUTOSAR Port - PORT driver midle level driver.
*   @details Implementation of the AutoSar midle level PORT driver.
*
*   @addtogroup Port
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIU
*   Dependencies         : none
*
*   Autosar Version      : 4.0.
*                          3
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_IPW_C_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*          '#include'. MemMap.h is included after each section define in order to set the current 
*          memory section as defined by AUTOSAR.
*
* @section PORT_IPW_C_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_IPW_C_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external
*          identifiers. The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_IPW_C_REF_4
*          Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
*          of pointer. The violation is FALSE: the quantity is unsigned.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
*          rely on the significance of more than 31 characters. The used compilers use more than
*          31 chars for identifiers.
*
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port_Ipw.h"
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
*
*/
#define PORT_VENDOR_ID_IPW_C                    43

/**
* @violates @ref PORT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_IPW_C     4

/**
* @violates @ref PORT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_IPW_C     0

/**
* @violates @ref PORT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_IPW_C  3

#define PORT_SW_MAJOR_VERSION_IPW_C             1
#define PORT_SW_MINOR_VERSION_IPW_C             0
#define PORT_SW_PATCH_VERSION_IPW_C             1


/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if source file and Port_Ipw.h file are of the same vendor */
#if (PORT_VENDOR_ID_IPW_C != PORT_VENDOR_ID_IPW_H)
    #error "Port_Ipw.c and Port_Ipw.h have different vendor ids"
#endif

/* Check if the source file and Port_Ipw.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_IPW_C    != PORT_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_IPW_C    != PORT_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_IPW_C != PORT_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
   #error "AutoSar Version Numbers of Port_Ipw.c and Port_Ipw.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_IPW_C != PORT_SW_MAJOR_VERSION_IPW_H) || \
     (PORT_SW_MINOR_VERSION_IPW_C != PORT_SW_MINOR_VERSION_IPW_H) || \
     (PORT_SW_PATCH_VERSION_IPW_C != PORT_SW_PATCH_VERSION_IPW_H)    \
    )
  #error "Software Version Numbers of Port_Ipw.c and Port_Ipw.h are different"
#endif

/* Check if source file and Port header file are of the same vendor */
#if (PORT_VENDOR_ID_IPW_C != PORT_VENDOR_ID)
    #error "Port_Ipw.c and Port.h have different vendor ids"
#endif

/* Check if source file and Port header file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_IPW_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_IPW_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_IPW_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
   #error "AutoSar Version Numbers of Port_Ipw.c and Port.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_IPW_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_IPW_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_IPW_C != PORT_SW_PATCH_VERSION)    \
    )
  #error "Software Version Numbers of Port_Ipw.c and Port.h are different"
#endif

/*=================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
#define PORT_START_SEC_CODE
/**
* @violates @ref PORT_IPW_C_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
static FUNC(uint16, PORT_CODE) Port_Ipw_GetIndexForEntry
(
    VAR    (Port_InternalPinIdType, AUTOMATIC) PinPad,
    VAR    (Port_PinModeType,       AUTOMATIC) PinMode
);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/*=================================================================================================
*                                      LOCAL FUNCTIONS
=================================================================================================*/

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Searches index in Port_aPadFunctIndex[] table.
* @details Searches index of an entry having a given Pad number and a given PadMode in 
*          Port_aPadFunctIndex[] table
* @pre     None

* @param[in] PinPad       Number of the pad for which index in Port_aPadFunctIndex is requested.
* @param[in] PinMode      Mode of the pad for which index in Port_aPadFunctIndex is requested
*
* @api
*/
static FUNC(uint16, PORT_CODE) Port_Ipw_GetIndexForEntry
(
    VAR    (Port_InternalPinIdType, AUTOMATIC) PinPad,
    VAR    (Port_PinModeType,       AUTOMATIC) PinMode
)
{
    VAR(uint16,         AUTOMATIC) u16ReturnIndex = (uint16)0;
    VAR(uint16,         AUTOMATIC) u16Counter;

    for(u16Counter = (uint16)0U; u16Counter < PORT_INDEX_TABLE_NUM_ENTRIES_U16; u16Counter++)
    {
        if((Port_aPadFunctIndex[u16Counter].u16PCR == (uint16)PinPad) && (Port_aPadFunctIndex[u16Counter].u8Mode == (uint8)PinMode))
        {
            u16ReturnIndex = u16Counter;
            break;
        }
    }
    return u16ReturnIndex;
}
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/*=================================================================================================
*                                      GLOBAL FUNCTIONS
=================================================================================================*/
/**
* @brief        Initializes the Port Driver
* @details      The function Port_Ipw_Init will initialize ALL ports and port pins along with all
*               IGF channels with the configuration set pointed to by the parameter pConfigPtr.
*
* @param[in]    pConfigPtr  A pointer to the structure which contains initialization parameters
*
* @return none
*
* @pre    none
*
*/
FUNC(void, PORT_CODE) Port_Ipw_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    /* Initialize all port pins */
    Port_Siu_Init(pConfigPtr);
    
    /* Initialize all IGF channels, in case a configuration for IGF is present */
    if(NULL_PTR != pConfigPtr->IgfConfig.pChannelConfig)
    {
        Port_Igf_Init(&pConfigPtr->IgfConfig);
    }
}

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Sets the port pin mode.
* @details The function @p Port_Ipw_SetPinMode will set the port pin mode of the
*          referenced pin during runtime.
* @pre     @p Port_Init() must have been called first.

* @param[in] PinIndex       Pin ID number.
* @param[in] PinMode        New Port Pin mode to be set on port pin.
* @param[in] pConfigPtr     Pointer to the initialization data structure
*
* @implements PORT_IPW_SetPinMode_Activity
* @api
*/
FUNC(Std_ReturnType, PORT_CODE) Port_Ipw_SetPinMode
(
    VAR    (Port_PinType,       AUTOMATIC                 ) PinIndex,
    VAR    (Port_PinModeType,   AUTOMATIC                 ) PinMode,
    P2CONST(Port_ConfigType,    AUTOMATIC, PORT_APPL_CONST) pConfigPtr
)
{
    VAR(Std_ReturnType,         AUTOMATIC) PinModeError = (Std_ReturnType)0UL;
    /** @violates @ref PORT_IPW_C_REF_4 MISRA 2004 Required Rule 17.4 */
    VAR(Port_InternalPinIdType, AUTOMATIC) PinPad = pConfigPtr->pUsedPadConfig[PinIndex].u16SIUPin;

    VAR(uint16,                 AUTOMATIC) u16PinDescWord;
    VAR(uint8,                  AUTOMATIC) u8PinDescBitOffset;

    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex   = (Port_InternalPinIdType)PinPad;
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue   = (Port_RegValueType)PinMode;
    VAR(uint16,                 AUTOMATIC) u16InMuxRegIndex = NO_INPUTMUX_U16;
    VAR(Port_RegValueType,      AUTOMATIC) InMuxRegValue    = (Port_RegValueType)0UL;
    VAR(uint16,                 AUTOMATIC) u16Index;
    VAR(Port_PinDirectionType,  AUTOMATIC) ePadDirection = PORT_PIN_IN;

    if (PAD_MODE_OPTIONS_U8 <= PinMode)
    {
        PinModeError = PORT_E_PARAM_INVALID_MODE;
    }
    else
    {
        /* Bit offset of Pin index inside the pin description matrix */
        u8PinDescBitOffset = (uint8)(PinPad & SIU_MODE_BIT_OFFSET_MASK_U8);
        /* Selected word inside the pin description matrix */
        u16PinDescWord = (uint16)Port_au16PinDescription[(uint8)PinMode][(uint8)(PinPad>>4)];

        /* Check if desired mode is valid for selected pin */
        if (u16PinDescWord & (uint16)(1UL<<u8PinDescBitOffset))
        {
            /* Do not treat the ADC mode case. This will be fully treated in Port_Siu.c */
            if(PORT_ANALOG_INPUT_MODE != PinMode)
            {
                if(PORT_GPIO_MODE == PinMode)
                {
                    Port_Siu_SetGpioDirChangeability(PinPad,(boolean)TRUE);
                    /** @violates @ref PORT_IPW_C_REF_4 MISRA 2004 Required Rule 17.4 */
                    ePadDirection = (Port_PinDirectionType)(pConfigPtr->pUsedPadConfig[PinIndex].u8PDDir);
#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
                    if(PORT_PIN_IN != ePadDirection)
                    {
                        Port_Siu_SetGpioPadOutput(PinIndex, pConfigPtr);
                    }
#endif /* (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL) */
                }                
                else
                {
                    /* This is the case of all non Adc functionalities having either only Mux settings or both
                       Mux (PCR) and Inmux settings 
                       Get the index of the corresponding entry in the Port_aPadFunctIndex table, based on PCR number and mode */
                    u16Index = Port_Ipw_GetIndexForEntry(PinPad, PinMode);
                    /* Use the same u16Index variable to get the index in the Mux table where we should jump */
                    u16Index = Port_aPadFunctIndex[u16Index].u16IdxMuxOrInmuxTable;
                    /* Check if the entry is for a Mux (PCR) only functionality, or one requiring a Inmux setting too */
                    if(PinMode < PORT_INPUT1_MODE)
                    {
                        /* Only PCR needs to be set */
                        ePadDirection = Port_aPadFunctMuxSettings[u16Index];
                    }
                    else
                    {
                        /* Both PCR and Inmux need to be set */
                        u16InMuxRegIndex = Port_aPadFunctInMuxSettings[u16Index].u16InMuxId;
                        InMuxRegValue    = Port_aPadFunctInMuxSettings[u16Index].u8InMuxCode;
                        ePadDirection    = Port_aPadFunctInMuxSettings[u16Index].eDirection;
                        PinCfgRegValue   = (Port_RegValueType)((Port_RegValueType)PinMode - ((Port_RegValueType)PORT_INPUT1_MODE - (Port_RegValueType)PORT_ALT1_FUNC_MODE));
                    }
                    /* Mark pin as not having the direction changeable */
                    Port_Siu_SetGpioDirChangeability(PinPad,(boolean)FALSE);
                }
                
                (void)Port_Siu_SetPinDirection(PinIndex, ePadDirection, pConfigPtr);
            }
            /* Sets the port pin mode */
            Port_Siu_SetPinMode(PinCfgRegIndex, PinCfgRegValue, u16InMuxRegIndex, InMuxRegValue);
        }
        else
        {
            
                PinModeError = PORT_E_PARAM_INVALID_MODE;
        }
    }
    return (PinModeError);
}
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#define PORT_STOP_SEC_CODE
/**
* @violates @ref PORT_IPW_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor
* statements and comments before '#include'
* @violates @ref PORT_IPW_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
