/**
*   @file    Can_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PreCompile.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
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
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Can_Cfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_Cfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Cfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_Cfg_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_Cfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_IPW.h"

/**
* @file           Can_Cfg.c
*/



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID_PCCFG_C                   43
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C     4
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C     0
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C  3
#define CAN_SW_MAJOR_VERSION_PCCFG_C             1
#define CAN_SW_MINOR_VERSION_PCCFG_C             0
#define CAN_SW_PATCH_VERSION_PCCFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/



/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_VENDOR_ID_PCCFG_C != CAN_VENDOR_ID)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_Cfg.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_Cfg.c and Can.h are different"
#endif

/* Check if current file and Can_IPW configuration header file are of the same vendor */
#if (CAN_VENDOR_ID_PCCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_Cfg.c and Can.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_Cfg.c and Can.h are different"
#endif

#if (CAN_PRECOMPILE_SUPPORT == STD_ON)
/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_Cfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "MemMap.h"

/**
* @brief    Prototype of User Notifications
*/

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


/*==================================================================================================*/
/**
* @brief          Filter Masks
* @details        Filter Masks
*
*/
static CONST(Can_IdType, CAN_CONST) Can_FilterMasks_PC[CAN_MAXFILTERCOUNT_0] =
{
    /* FilterMasks_PC[0], "CanFilterMask_0" */
    (Can_IdType)0x7ffU,
    /* FilterMasks_PC[1], "CanFilterMask_1" */
    (Can_IdType)0x1fffffffU,
    /* FilterMasks_PC[2], "CanFilterMask_0" */
    (Can_IdType)0x7ffU,
    /* FilterMasks_PC[3], "CanFilterMask_0" */
    (Can_IdType)0x7ffU,
    /* FilterMasks_PC[4], "CanFilterMask_0" */
    (Can_IdType)0x7ffU
};

/*==================================================================================================*/
/**
* @brief          Configuration of FlexCan controller
* @details        Configuration of FlexCan controller
*
*/
static CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateConfigs_PC_0[CAN_CFGSET0_MAX_BAUDRATE_FC_A_0] = 
{
    /*
    =================================================
    Clock Size = 4.0E7 Hz - Clock from external OSC.Clock Prescaler = 5 (1..256)
    CanBitRate = 500 Kbps (1bps..1Mbps)
    Number CANTimeQuantas per bit = 16 (8..25)
    CTRL Register Fields:
    PSEG1 =5(0..7)
    PSEG2 =2(1..7)
    PROPSEG =8(0..7)
    RJW =1(0..3)
    =================================================
    */
    /* Configuration for CanController ID0 == FlexCAN_A */
    {
        /* ===== Control Register - CTRL ===== */
        /* CTRL[PRESDIV] - Clock Prescaler */
        (uint32)(
                  ((uint32)4 << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |
                  /* CTRL[RJW] - Resynchronization Jump Width */
                  ((uint32)0<< FLEXCAN_CTRL_RJW_SHIFT_U8) |
                  /* CTRL[PSEG1] - Segment 1 */
                  ((uint32)4U << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |
                  /* CTRL[PSEG2] - Segment 2 */
                  ((uint32)1U << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |
                  ((uint32)0<< FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                  /* CTRL[PROPSEG] - Propagation segment */
                  (uint32)7
                ),
        
        (uint8)12U, /* CTRL2[TASD] Tx Arbitration Start Delay */
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        0U,
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
        
        (uint16)500 ,  /* 500kbps baud rate */
        
        
        
        #if (CAN_SET_BAUDRATE_API == STD_ON)
        (uint16)1
        #endif
    }
};

static CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateConfigs_PC_1[CAN_CFGSET0_MAX_BAUDRATE_FC_B_1] = 
{
    /*
    =================================================
    Clock Size = 4.0E7 Hz - Clock from external OSC.Clock Prescaler = 20 (1..256)
    CanBitRate = 125 Kbps (1bps..1Mbps)
    Number CANTimeQuantas per bit = 16 (8..25)
    CTRL Register Fields:
    PSEG1 =5(0..7)
    PSEG2 =2(1..7)
    PROPSEG =8(0..7)
    RJW =1(0..3)
    =================================================
    */
    /* Configuration for CanController ID1 == FlexCAN_B */
    {
        /* ===== Control Register - CTRL ===== */
        /* CTRL[PRESDIV] - Clock Prescaler */
        (uint32)(
                  ((uint32)19 << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |
                  /* CTRL[RJW] - Resynchronization Jump Width */
                  ((uint32)0<< FLEXCAN_CTRL_RJW_SHIFT_U8) |
                  /* CTRL[PSEG1] - Segment 1 */
                  ((uint32)4U << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |
                  /* CTRL[PSEG2] - Segment 2 */
                  ((uint32)1U << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |
                  ((uint32)0<< FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                  /* CTRL[PROPSEG] - Propagation segment */
                  (uint32)7
                ),
        
        (uint8)12U, /* CTRL2[TASD] Tx Arbitration Start Delay */
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        0U,
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
        
        (uint16)125 ,  /* 125kbps baud rate */
        
        
        
        #if (CAN_SET_BAUDRATE_API == STD_ON)
        (uint16)1
        #endif
    }
};

static CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateConfigs_PC_2[CAN_CFGSET0_MAX_BAUDRATE_FC_C_2] = 
{
    /*
    =================================================
    Clock Size = 4.0E7 Hz - Clock from external OSC.Clock Prescaler = 5 (1..256)
    CanBitRate = 500 Kbps (1bps..1Mbps)
    Number CANTimeQuantas per bit = 16 (8..25)
    CTRL Register Fields:
    PSEG1 =5(0..7)
    PSEG2 =2(1..7)
    PROPSEG =8(0..7)
    RJW =1(0..3)
    =================================================
    */
    /* Configuration for CanController ID2 == FlexCAN_C */
    {
        /* ===== Control Register - CTRL ===== */
        /* CTRL[PRESDIV] - Clock Prescaler */
        (uint32)(
                  ((uint32)4 << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |
                  /* CTRL[RJW] - Resynchronization Jump Width */
                  ((uint32)0<< FLEXCAN_CTRL_RJW_SHIFT_U8) |
                  /* CTRL[PSEG1] - Segment 1 */
                  ((uint32)4U << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |
                  /* CTRL[PSEG2] - Segment 2 */
                  ((uint32)1U << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |
                  ((uint32)0<< FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                  /* CTRL[PROPSEG] - Propagation segment */
                  (uint32)7
                ),
        
        (uint8)12U, /* CTRL2[TASD] Tx Arbitration Start Delay */
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        0U,
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
        
        (uint16)500 ,  /* 500kbps baud rate */
        
        
        
        #if (CAN_SET_BAUDRATE_API == STD_ON)
        (uint16)1
        #endif
    }
};

static CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateConfigs_PC_3[CAN_CFGSET0_MAX_BAUDRATE_FC_D_3] = 
{
    /*
    =================================================
    Clock Size = 4.0E7 Hz - Clock from external OSC.Clock Prescaler = 20 (1..256)
    CanBitRate = 125 Kbps (1bps..1Mbps)
    Number CANTimeQuantas per bit = 16 (8..25)
    CTRL Register Fields:
    PSEG1 =5(0..7)
    PSEG2 =2(1..7)
    PROPSEG =8(0..7)
    RJW =1(0..3)
    =================================================
    */
    /* Configuration for CanController ID3 == FlexCAN_D */
    {
        /* ===== Control Register - CTRL ===== */
        /* CTRL[PRESDIV] - Clock Prescaler */
        (uint32)(
                  ((uint32)19 << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |
                  /* CTRL[RJW] - Resynchronization Jump Width */
                  ((uint32)0<< FLEXCAN_CTRL_RJW_SHIFT_U8) |
                  /* CTRL[PSEG1] - Segment 1 */
                  ((uint32)4U << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |
                  /* CTRL[PSEG2] - Segment 2 */
                  ((uint32)1U << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |
                  ((uint32)0<< FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                  /* CTRL[PROPSEG] - Propagation segment */
                  (uint32)7
                ),
        
        (uint8)12U, /* CTRL2[TASD] Tx Arbitration Start Delay */
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        0U,
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
        
        (uint16)125 ,  /* 125kbps baud rate */
        
        
        
        #if (CAN_SET_BAUDRATE_API == STD_ON)
        (uint16)1
        #endif
    }
};

/*==================================================================================================*/
/**
* @brief          Configuration of FlexCan controller
* @details        Configuration of FlexCan controller
*
*/
/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */ 
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
static CONST(CanStatic_ControllerBaudrateConfigType, CAN_CONST) StaticControllerBaudrateCfgSet_PC_0[CAN_CFGSET0_MAX_BAUDRATE_FC_A_0] = 
{
    /* Configuration for CanController ID0 == FlexCAN_A */
    {
        /* ===== Control Register - CTRL ===== */
        (uint32)(
                  ((uint32)0<< FLEXCAN_CTRL_LPB_SHIFT_U8) | /* CTRL[LPB] - Loop-back mode */
                  ((uint32)0<< FLEXCAN_CTRL_SMP_SHIFT_U8) | /* CTRL[SMP] - Sampling mode */
                  ((uint32)1<< FLEXCAN_CTRL_BOFFREC_SHIFT_U8) | /* CTRL[BOFF_REC] - Bus off recovery */
                  ((uint32)0<< FLEXCAN_CTRL_LBUF_SHIFT_U8) | /* CTRL[LBUF] - Lowest Buffer Transmitted First */
                  ((uint32)0<< FLEXCAN_CTRL_LOM_SHIFT_U8) /* CTRL[LOM] - Listen only mode */
                )
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        ,0U
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
    }
};

/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */ 
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
static CONST(CanStatic_ControllerBaudrateConfigType, CAN_CONST) StaticControllerBaudrateCfgSet_PC_1[CAN_CFGSET0_MAX_BAUDRATE_FC_B_1] = 
{
    /* Configuration for CanController ID1 == FlexCAN_B */
    {
        /* ===== Control Register - CTRL ===== */
        (uint32)(
                  ((uint32)0<< FLEXCAN_CTRL_LPB_SHIFT_U8) | /* CTRL[LPB] - Loop-back mode */
                  ((uint32)0<< FLEXCAN_CTRL_SMP_SHIFT_U8) | /* CTRL[SMP] - Sampling mode */
                  ((uint32)1<< FLEXCAN_CTRL_BOFFREC_SHIFT_U8) | /* CTRL[BOFF_REC] - Bus off recovery */
                  ((uint32)0<< FLEXCAN_CTRL_LBUF_SHIFT_U8) | /* CTRL[LBUF] - Lowest Buffer Transmitted First */
                  ((uint32)0<< FLEXCAN_CTRL_LOM_SHIFT_U8) /* CTRL[LOM] - Listen only mode */
                )
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        ,0U
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
    }
};

/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */ 
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
static CONST(CanStatic_ControllerBaudrateConfigType, CAN_CONST) StaticControllerBaudrateCfgSet_PC_2[CAN_CFGSET0_MAX_BAUDRATE_FC_C_2] = 
{
    /* Configuration for CanController ID2 == FlexCAN_C */
    {
        /* ===== Control Register - CTRL ===== */
        (uint32)(
                  ((uint32)0<< FLEXCAN_CTRL_LPB_SHIFT_U8) | /* CTRL[LPB] - Loop-back mode */
                  ((uint32)0<< FLEXCAN_CTRL_SMP_SHIFT_U8) | /* CTRL[SMP] - Sampling mode */
                  ((uint32)1<< FLEXCAN_CTRL_BOFFREC_SHIFT_U8) | /* CTRL[BOFF_REC] - Bus off recovery */
                  ((uint32)0<< FLEXCAN_CTRL_LBUF_SHIFT_U8) | /* CTRL[LBUF] - Lowest Buffer Transmitted First */
                  ((uint32)0<< FLEXCAN_CTRL_LOM_SHIFT_U8) /* CTRL[LOM] - Listen only mode */
                )
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        ,0U
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
    }
};

/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */ 
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
static CONST(CanStatic_ControllerBaudrateConfigType, CAN_CONST) StaticControllerBaudrateCfgSet_PC_3[CAN_CFGSET0_MAX_BAUDRATE_FC_D_3] = 
{
    /* Configuration for CanController ID3 == FlexCAN_D */
    {
        /* ===== Control Register - CTRL ===== */
        (uint32)(
                  ((uint32)0<< FLEXCAN_CTRL_LPB_SHIFT_U8) | /* CTRL[LPB] - Loop-back mode */
                  ((uint32)0<< FLEXCAN_CTRL_SMP_SHIFT_U8) | /* CTRL[SMP] - Sampling mode */
                  ((uint32)1<< FLEXCAN_CTRL_BOFFREC_SHIFT_U8) | /* CTRL[BOFF_REC] - Bus off recovery */
                  ((uint32)0<< FLEXCAN_CTRL_LBUF_SHIFT_U8) | /* CTRL[LBUF] - Lowest Buffer Transmitted First */
                  ((uint32)0<< FLEXCAN_CTRL_LOM_SHIFT_U8) /* CTRL[LOM] - Listen only mode */
                )
        
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
        ,0U
        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
    }
};


/*==================================================================================================*/
/**
* @brief          Information about message buffers
* @details        (CAN100)Several TX hardware objects with unique HTHs may be configured. The CanIf module provides the HTH as parameter of the TX request. See Figure 7-2 for a possible configuration.
*
*/
static CONST(Can_MBConfigObjectType, CAN_CONST) MessageBufferConfigs_PC[CAN_MAXMBCOUNT_0] =
{
    /* Can_Network_CANNODE_1_Rx_Std_MailBox_1 Message Buffer of Can Controller ID = 0U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)0U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_RECEIVE,
        /* MessageId */
        (Can_IdType)0x480U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x0U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0080U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)0U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_1_Rx_Std_MailBox_2 Message Buffer of Can Controller ID = 0U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)0U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_RECEIVE,
        /* MessageId */
        (Can_IdType)0x703U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x1U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0090U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)1U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_1_Rx_Ext_MailBox_3 Message Buffer of Can Controller ID = 0U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)1U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)0U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_EXTENDED,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_RECEIVE,
        /* MessageId */
        (Can_IdType)0x1801f1faU,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x2U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x00a0U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)2U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_2_Rx_Std_MailBox_1 Message Buffer of Can Controller ID = 1U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)2U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)1U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_RECEIVE,
        /* MessageId */
        (Can_IdType)0x490U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x3U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0080U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)0U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_3_Rx_Std_MailBox_1 Message Buffer of Can Controller ID = 2U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)3U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)2U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_RECEIVE,
        /* MessageId */
        (Can_IdType)0x420U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x4U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0080U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)0U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_4_Rx_Std_MailBox_1 Message Buffer of Can Controller ID = 3U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)4U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)3U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_RECEIVE,
        /* MessageId */
        (Can_IdType)0x430U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x5U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0080U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)0U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_1_Tx_Std_MailBox_1 Message Buffer of Can Controller ID = 0U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)0U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_TRANSMIT,
        /* MessageId */
        (Can_IdType)0x2U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x6U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x00b0U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)3U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_1_Tx_Std_MailBox_2 Message Buffer of Can Controller ID = 0U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)0U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_TRANSMIT,
        /* MessageId */
        (Can_IdType)0x3U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x7U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x00c0U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)4U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_1_Tx_Std_MailBox_3 Message Buffer of Can Controller ID = 0U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)0U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_EXTENDED,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_TRANSMIT,
        /* MessageId */
        (Can_IdType)0x4U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x8U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x00d0U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)5U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_2_Tx_Std_MailBox_1 Message Buffer of Can Controller ID = 1U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)1U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_TRANSMIT,
        /* MessageId */
        (Can_IdType)0x5U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0x9U,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0090U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)1U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_3_Tx_Std_MailBox_1 Message Buffer of Can Controller ID = 2U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)2U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_TRANSMIT,
        /* MessageId */
        (Can_IdType)0x7U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0xaU,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0090U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)1U    /* The index of MB in message buffer memory */
    },

    /* Can_Network_CANNODE_4_Tx_Std_MailBox_1 Message Buffer of Can Controller ID = 3U*/
    {
        /* uIdMaskIndex */
        (Can_HwHandleType)0U,
        /* ControllerId  - based on the order from CanController list */
        (uint8)3U,
        /* ID type: EXTENDED, STANDARD, MIXED */
        (CanIdType)CAN_STANDARD,
        /* Receive/Transmit MB configuration */
        (Can_ObjType)CAN_TRANSMIT,
        /* MessageId */
        (Can_IdType)0x9U,
        /* Local priority bits used for arbitration */
        (uint8)0x0U,
        /* Hardware Object ID */
        (Can_HwHandleType)0xbU,
        /* Read/Write period reference used when polling mode is selected for the controller */
        (uint8)0U, /* HOH configured for interrupt mode, reference not used */
        
        
        
        (uint16)0x0090U,       /* Address of Message Buffer  */
        (uint8)8U,    /* Payload lenth of Message Buffer */
        (uint8)1U    /* The index of MB in message buffer memory */
    }
};

/*==================================================================================================*/
/**
* @brief          Description of individual FlexCan controllers on chip
* @details        Description of individual FlexCan controllers on chip
*
*/
static CONST(Can_ControlerDescriptorType, CAN_CONST) ControlerDescriptors_PC[CAN_MAXCONTROLLERCOUNT_0] =
{
    /* ControlerDescriptor of CanController_0*/
    {
        (uint8)6U, /* No. of Message Buffers for current controller - u8MaxMBCount */
        (uint8)1U, /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)0U, /* Default BaudRate configured for current controller */
        ControllerBaudrateConfigs_PC_0, /* pControllerBaudrateConfigsPtr */
        #if (CAN_RXFIFO_ENABLE == STD_ON)
        (uint32)0U,/*Rx Fifo Global mask value*/
        (uint8)0U,/* Number of MBs used by Rx Fifo */
        NULL_PTR, /* Pointer to RxFifo Overflow notification function. */
        NULL_PTR, /* Pointer to RxFifo Warning notification function. */
        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        /* Message Buffer Data Size for three RAM regions */
        (uint32)(
                  0U
                ),
        #endif
        /* ===== Controller Options ===== */
        (uint32)(
                  /* Software BusOff Recovery */
                  CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32 | 
                  /* RX Fifo Disabled */ 
                  /* Error interrupt */ 
                  0U
                )
    },/* ControlerDescriptors CanController_0 end */

    /* ControlerDescriptor of CanController_1*/
    {
        (uint8)2U, /* No. of Message Buffers for current controller - u8MaxMBCount */
        (uint8)1U, /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)0U, /* Default BaudRate configured for current controller */
        ControllerBaudrateConfigs_PC_1, /* pControllerBaudrateConfigsPtr */
        #if (CAN_RXFIFO_ENABLE == STD_ON)
        (uint32)0U,/*Rx Fifo Global mask value*/
        (uint8)0U,/* Number of MBs used by Rx Fifo */
        NULL_PTR, /* Pointer to RxFifo Overflow notification function. */
        NULL_PTR, /* Pointer to RxFifo Warning notification function. */
        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        /* Message Buffer Data Size for three RAM regions */
        (uint32)(
                  0U
                ),
        #endif
        /* ===== Controller Options ===== */
        (uint32)(
                  /* Software BusOff Recovery */
                  CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32 | 
                  /* RX Fifo Disabled */ 
                  /* Error interrupt */ 
                  0U
                )
    },/* ControlerDescriptors CanController_1 end */

    /* ControlerDescriptor of CanController_2*/
    {
        (uint8)2U, /* No. of Message Buffers for current controller - u8MaxMBCount */
        (uint8)1U, /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)0U, /* Default BaudRate configured for current controller */
        ControllerBaudrateConfigs_PC_2, /* pControllerBaudrateConfigsPtr */
        #if (CAN_RXFIFO_ENABLE == STD_ON)
        (uint32)0U,/*Rx Fifo Global mask value*/
        (uint8)0U,/* Number of MBs used by Rx Fifo */
        NULL_PTR, /* Pointer to RxFifo Overflow notification function. */
        NULL_PTR, /* Pointer to RxFifo Warning notification function. */
        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        /* Message Buffer Data Size for three RAM regions */
        (uint32)(
                  0U
                ),
        #endif
        /* ===== Controller Options ===== */
        (uint32)(
                  /* Software BusOff Recovery */
                  CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32 | 
                  /* RX Fifo Disabled */ 
                  /* Error interrupt */ 
                  0U
                )
    },/* ControlerDescriptors CanController_2 end */

    /* ControlerDescriptor of CanController_3*/
    {
        (uint8)2U, /* No. of Message Buffers for current controller - u8MaxMBCount */
        (uint8)1U, /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
        (uint8)0U, /* Default BaudRate configured for current controller */
        ControllerBaudrateConfigs_PC_3, /* pControllerBaudrateConfigsPtr */
        #if (CAN_RXFIFO_ENABLE == STD_ON)
        (uint32)0U,/*Rx Fifo Global mask value*/
        (uint8)0U,/* Number of MBs used by Rx Fifo */
        NULL_PTR, /* Pointer to RxFifo Overflow notification function. */
        NULL_PTR, /* Pointer to RxFifo Warning notification function. */
        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        #if (CAN_FD_MODE_ENABLE == STD_ON)
        /* Message Buffer Data Size for three RAM regions */
        (uint32)(
                  0U
                ),
        #endif
        /* ===== Controller Options ===== */
        (uint32)(
                  /* Software BusOff Recovery */
                  CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32 | 
                  /* RX Fifo Disabled */ 
                  /* Error interrupt */ 
                  0U
                )
    }
};

/*==================================================================================================*/
/**
* @brief          Description of individual FlexCan controllers on chip
* @details        Description of individual FlexCan controllers on chip
*
*/
static CONST(CanStatic_ControlerDescriptorType, CAN_CONST) StaticControlerDescriptors_PC[CAN_MAXCONTROLLERCOUNT_0] =
{
    /* ControlerDescriptor of CanController_0 */
    {
        (uint8)FLEXCAN_A_OFFSET, /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        StaticControllerBaudrateCfgSet_PC_0, /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr */
        
        #if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). - Can_ErrorNotification */
        #elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). */
        #endif
        
        #if (CAN_MIX_MB_SUPPORT == STD_ON)
        /* Maximum MBs supported for this controller. - u8NumberOfMB */
        (uint8)32U,
        #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
        
        /* ===== Controller Options ===== */
        (uint32)(0U)
    },/* ControlerDescriptors CanController_0 end */

    /* ControlerDescriptor of CanController_1 */
    {
        (uint8)FLEXCAN_B_OFFSET, /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        StaticControllerBaudrateCfgSet_PC_1, /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr */
        
        #if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). - Can_ErrorNotification */
        #elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). */
        #endif
        
        #if (CAN_MIX_MB_SUPPORT == STD_ON)
        /* Maximum MBs supported for this controller. - u8NumberOfMB */
        (uint8)32U,
        #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
        
        /* ===== Controller Options ===== */
        (uint32)(0U)
    },/* ControlerDescriptors CanController_1 end */

    /* ControlerDescriptor of CanController_2 */
    {
        (uint8)FLEXCAN_C_OFFSET, /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        StaticControllerBaudrateCfgSet_PC_2, /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr */
        
        #if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). - Can_ErrorNotification */
        #elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). */
        #endif
        
        #if (CAN_MIX_MB_SUPPORT == STD_ON)
        /* Maximum MBs supported for this controller. - u8NumberOfMB */
        (uint8)32U,
        #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
        
        /* ===== Controller Options ===== */
        (uint32)(0U)
    },/* ControlerDescriptors CanController_2 end */

    /* ControlerDescriptor of CanController_3 */
    {
        (uint8)FLEXCAN_D_OFFSET, /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
        StaticControllerBaudrateCfgSet_PC_3, /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr */
        
        #if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). - Can_ErrorNotification */
        #elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
        NULL_PTR, /* Pointer to Error interrupt notification function (ESR[ERR_INT]). */
        #endif
        
        #if (CAN_MIX_MB_SUPPORT == STD_ON)
        /* Maximum MBs supported for this controller. - u8NumberOfMB */
        (uint8)32U,
        #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
        
        /* ===== Controller Options ===== */
        (uint32)(0U)
    }
};

/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
/* @violates @ref Can_Cfg_c_REF_4 Violates MISRA 2004 Required Rule 8.10*/
CONST(Can_ConfigType, CAN_CONST) Can_ConfigSet_PC =
{
    Can_FilterMasks_PC, /*  - pFilterMasks */
    /* MessageBufferConfigContainer - MBConfigContainer */
    {
        MessageBufferConfigs_PC, /* pMessageBufferConfigsPtr */
        (Can_HwHandleType)12U, /* uMessageBufferConfigCount */
    },
    
    ControlerDescriptors_PC, /* FlexCAN controller description */
    
    #if (CAN_RXFIFO_ENABLE == STD_ON)
    /* Can_RxFiFoTableIdConfigType */
    NULL_PTR, /* Rx fifo disabled */
    #endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */
    
    (uint32)12U, /*Maximum Object IDs configured - u32CanMaxObjectId*/
    /* The index of the first HTH configured */
    (Can_HwHandleType)6U,
    /*Controller ID mapping - u8ControllerIdMapping*/
    {0U, 0U, 0U, 1U, 2U, 3U, 0U, 0U, 0U, 1U, 2U, 3U },
    
    /*Can Object Type mapping - eObjectTypeMapping*/
    {
        (Can_ObjType)CAN_RECEIVE,
        (Can_ObjType)CAN_RECEIVE,
        (Can_ObjType)CAN_RECEIVE,
        (Can_ObjType)CAN_RECEIVE,
        (Can_ObjType)CAN_RECEIVE,
        (Can_ObjType)CAN_RECEIVE,
        (Can_ObjType)CAN_TRANSMIT,
        (Can_ObjType)CAN_TRANSMIT,
        (Can_ObjType)CAN_TRANSMIT,
        (Can_ObjType)CAN_TRANSMIT,
        (Can_ObjType)CAN_TRANSMIT,
        (Can_ObjType)CAN_TRANSMIT
    }
};

/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
/* @violates @ref Can_Cfg_c_REF_4 Violates MISRA 2004 Required Rule 8.10*/
CONST(CanStatic_ConfigType, CAN_CONST) CanStatic_ConfigSet =
{
    /* Number of CAN controllers configured -u8ControllersConfigured*/
    (uint8) 4U,
    /* FlexCAN controller description - ControlerDescriptors*/
    StaticControlerDescriptors_PC
};
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*
@file Can_Cfg.c
@note Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. - See @ref Can_Cfg_c_REF_1
@note Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h - See @ref Can_Cfg_c_REF_2
*/
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_Cfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
/* @violates @ref Can_Cfg_c_REF_1 MISRA 2004  Rule 19.1, #include preceded by non preproc directives.*/
#include "MemMap.h"

#endif /*CAN_PRECOMPILE_SUPPORT == STD_ON*/

#ifdef __cplusplus
}
#endif

/** @} */
