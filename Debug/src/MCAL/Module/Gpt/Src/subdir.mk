################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/Module/Gpt/Src/Gpt.c \
../src/MCAL/Module/Gpt/Src/Gpt_Ipw.c \
../src/MCAL/Module/Gpt/Src/Gpt_Pit.c \
../src/MCAL/Module/Gpt/Src/Gpt_Stm.c \
../src/MCAL/Module/Gpt/Src/Gpt_eMios.c \
../src/MCAL/Module/Gpt/Src/Gpt_eMios_Irq.c 

OBJS += \
./src/MCAL/Module/Gpt/Src/Gpt.o \
./src/MCAL/Module/Gpt/Src/Gpt_Ipw.o \
./src/MCAL/Module/Gpt/Src/Gpt_Pit.o \
./src/MCAL/Module/Gpt/Src/Gpt_Stm.o \
./src/MCAL/Module/Gpt/Src/Gpt_eMios.o \
./src/MCAL/Module/Gpt/Src/Gpt_eMios_Irq.o 

C_DEPS += \
./src/MCAL/Module/Gpt/Src/Gpt.d \
./src/MCAL/Module/Gpt/Src/Gpt_Ipw.d \
./src/MCAL/Module/Gpt/Src/Gpt_Pit.d \
./src/MCAL/Module/Gpt/Src/Gpt_Stm.d \
./src/MCAL/Module/Gpt/Src/Gpt_eMios.d \
./src/MCAL/Module/Gpt/Src/Gpt_eMios_Irq.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/Module/Gpt/Src/%.o: ../src/MCAL/Module/Gpt/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Diab C Compiler'
	dcc -c -tPPCE200Z759N3VES -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Base" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Gen/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcu/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Rte/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Gpt/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcl/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dem/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Det/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dio/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Port/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Users" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/MCan/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/CanIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Eth/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/EthIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Spi/Inc" -DSTART_FROM_FLASH -DMPC5777C -DAUTOSAR_OS_NOT_USED -D__DCC__ -g3 -Xmake-dependency=0x5 -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '


