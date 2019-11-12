################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Project_Settings/Startup_Code/Vector_vle_core.s \
../Project_Settings/Startup_Code/Vector_vle_mcal.s 

C_SRCS += \
../Project_Settings/Startup_Code/Startup_vle.c 

OBJS += \
./Project_Settings/Startup_Code/Startup_vle.o \
./Project_Settings/Startup_Code/Vector_vle_core.o \
./Project_Settings/Startup_Code/Vector_vle_mcal.o 

C_DEPS += \
./Project_Settings/Startup_Code/Startup_vle.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Diab C Compiler'
	dcc -c -tPPCE200Z759N3VES -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/include" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/include/Base" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Gen/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcu/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Rte/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Gpt/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcl/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dem/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Det/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dio/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Port/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/include/Users" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/MCan/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/CanIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Eth/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/EthIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191112/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Spi/Inc" -DSTART_FROM_FLASH -DMPC5777C -DAUTOSAR_OS_NOT_USED -D__DCC__ -g3 -Xmake-dependency=0x5 -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: Diab Assembler'
	dcc -c -tPPCE200Z759N3VES -Xpreprocess-assembly -DSTART_FROM_FLASH -DMPC5777C -DDISABLE_SWTA -g -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '


