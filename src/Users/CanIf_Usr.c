/*
 * CanIf_Usr.c
 *
 *  Created on: 2019Äê10ÔÂ21ÈÕ
 *      Author: admin
 */

#include "Mcal.h"
#include "typedefs.h"
#include "Std_Types.h"
#include "StdRegMacros.h"
#include "Reg_eSys.h"
#include "CanIf_Types.h"


FUNC (void, CANIF_CODE) CanIf_CancelTxConfirmation(PduIdType CanTxPduId, const PduInfoType * PduInfoPtr)
{
    return;
}


FUNC (void, CANIF_CODE) CanIf_ControllerBusOff(uint8 Controller)
{
    return;
}


FUNC (void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId)
{
	return;
}


FUNC (void, CANIF_CODE) CanIf_RxIndication( Can_HwHandleType Hrh, Can_IdType CanId, uint8 CanDlc, const uint8* CanSduPtr )
{
    return;
}


FUNC (void, CANIF_CODE) CanIf_ControllerModeIndication( uint8 Controller, CanIf_ControllerModeType ControllerMode )
{
	return;
}


