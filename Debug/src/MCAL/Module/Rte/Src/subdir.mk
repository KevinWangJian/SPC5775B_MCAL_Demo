################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/Module/Rte/Src/SchM_Can.c \
../src/MCAL/Module/Rte/Src/SchM_Dio.c \
../src/MCAL/Module/Rte/Src/SchM_Eth.c \
../src/MCAL/Module/Rte/Src/SchM_Gpt.c \
../src/MCAL/Module/Rte/Src/SchM_MCan.c \
../src/MCAL/Module/Rte/Src/SchM_Mcl.c \
../src/MCAL/Module/Rte/Src/SchM_Mcu.c \
../src/MCAL/Module/Rte/Src/SchM_Port.c \
../src/MCAL/Module/Rte/Src/SchM_Spi.c 

OBJS += \
./src/MCAL/Module/Rte/Src/SchM_Can.o \
./src/MCAL/Module/Rte/Src/SchM_Dio.o \
./src/MCAL/Module/Rte/Src/SchM_Eth.o \
./src/MCAL/Module/Rte/Src/SchM_Gpt.o \
./src/MCAL/Module/Rte/Src/SchM_MCan.o \
./src/MCAL/Module/Rte/Src/SchM_Mcl.o \
./src/MCAL/Module/Rte/Src/SchM_Mcu.o \
./src/MCAL/Module/Rte/Src/SchM_Port.o \
./src/MCAL/Module/Rte/Src/SchM_Spi.o 

C_DEPS += \
./src/MCAL/Module/Rte/Src/SchM_Can.d \
./src/MCAL/Module/Rte/Src/SchM_Dio.d \
./src/MCAL/Module/Rte/Src/SchM_Eth.d \
./src/MCAL/Module/Rte/Src/SchM_Gpt.d \
./src/MCAL/Module/Rte/Src/SchM_MCan.d \
./src/MCAL/Module/Rte/Src/SchM_Mcl.d \
./src/MCAL/Module/Rte/Src/SchM_Mcu.d \
./src/MCAL/Module/Rte/Src/SchM_Port.d \
./src/MCAL/Module/Rte/Src/SchM_Spi.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/Module/Rte/Src/%.o: ../src/MCAL/Module/Rte/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Diab C Compiler'
	dcc -c -tPPCE200Z759N3VES -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Base" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Gen/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcu/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Rte/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Gpt/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcl/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dem/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Det/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dio/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Port/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Users" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/MCan/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/CanIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Eth/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/EthIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Spi/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Can/Inc" -DSTART_FROM_FLASH -DMPC5777C -DAUTOSAR_OS_NOT_USED -D__DCC__ -g3 -Xmake-dependency=0x5 -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '


