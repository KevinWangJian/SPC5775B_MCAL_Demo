/*
 * Switch_SJA1105.h
 *
 *  Created on: 2019Äê10ÔÂ23ÈÕ
 *      Author: admin
 */

#ifndef USERS_SWITCH_SJA1105_H_
#define USERS_SWITCH_SJA1105_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
#include "typedefs.h"
#include "Std_Types.h"
#include "Reg_eSys.h"
#include "StdRegMacros.h"
#include "Dio_Cfg.h"
#include "Dio.h"


#define  DRIVER_USE_MCAL	(1U)

#define  SWITCH_SJA1105_RESET_LOW()		Dio_WriteChannel(DioConf_DioChannel_SJA1105_RESET, STD_LOW)
#define  SWITCH_SJA1105_RESET_HIGH()	Dio_WriteChannel(DioConf_DioChannel_SJA1105_RESET, STD_HIGH)


void Switch_SJA1105_Init(void);


#ifdef __cplusplus
}
#endif
#endif /* USERS_SWITCH_SJA1105_H_ */
