/*
 * PhyTja110x.h
 *
 *  Created on: 2019Äê10ÔÂ22ÈÕ
 *      Author: admin
 */

#ifndef USERS_PHYTJA110X_H_
#define USERS_PHYTJA110X_H_

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


#define  PHY_TJA1101_ADDRESS	 	(0x06U)


#define  PHY_TJA1101_ENABLE()		Dio_WriteChannel(DioConf_DioChannel_TJA1101_EN, STD_HIGH)
#define  PHY_TJA1101_DISABLE()		Dio_WriteChannel(DioConf_DioChannel_TJA1101_EN, STD_LOW)

#define  PHY_TJA1101_RESET_LOW()	Dio_WriteChannel(DioConf_DioChannel_TJA1101_RESET, STD_LOW)
#define  PHY_TJA1101_RESET_HIGH()	Dio_WriteChannel(DioConf_DioChannel_TJA1101_RESET, STD_HIGH)


int PHY_TJA1101_Init(void);
int PHY_TJA1101_GetCurrentStatus(void);


#ifdef __cplusplus
}
#endif
#endif /* USERS_PHYTJA110X_H_ */
