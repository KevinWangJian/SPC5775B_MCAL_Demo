/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "typedefs.h"
#include "Mcal.h"
#include "Mcu.h"
#include "Gpt.h"
#include "StdRegMacros.h"
#include "Reg_eSys.h"
#include "Port.h"
#include "IntCtrl.h"
#include "McanComm.h"
#include "EthComm.h"
#include "PhyTja110x.h"
#include "PhyDP83822I.h"
#include "Switch_SJA1105.h"
#include "tickTimer.h"


SJA1105TypeDef SJA1105_DEVICE_TYPE;
SJA1105ConfigStatus SJA1105_CONFIG_STA;



/*
@brief
@details
@para
@return
*/
int main(void)
{
	Std_ReturnType ret;

	Mcu_Init(&McuConfigPB_0);
	ret = Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig);
	while (Mcu_GetPllStatus() != MCU_PLL_LOCKED){;}
	Mcu_DistributePllClock();

	InterruptController_Init();

	Port_Init(&PortConfigSet_0);

	SystemTickTimer_Init();

	McanComm_Init();
	McanComm_RxBufferInit();

	Ethernet_Init();

	SJA1105_Init();
	SJA1105_ConfigStatusChecking(&SJA1105_DEVICE_TYPE, &SJA1105_CONFIG_STA);

	PHY_TJA1101_Init();
	PHY_DP83822_Init();

	Ethernet_FrameData_Init();

	/* Loop forever */
	for(;;)
	{
		PHY_TJA1101_GetCurrentStatus();
		PHY_DP83822_GetCurrentStatus();

		if (CommUpdateEvent)
		{
//			McanComm_TransmitProcess();

			Ethernet_TransmitFramesTest();

			CommUpdateEvent = 0;
		}
	}
}
