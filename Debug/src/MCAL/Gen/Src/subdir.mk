################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/Gen/Src/Can_43_MCAN_Cfg.c \
../src/MCAL/Gen/Src/Can_43_MCAN_PBcfg.c \
../src/MCAL/Gen/Src/Can_Cfg.c \
../src/MCAL/Gen/Src/Can_PBcfg.c \
../src/MCAL/Gen/Src/Dio_Cfg.c \
../src/MCAL/Gen/Src/Eth_Cfg.c \
../src/MCAL/Gen/Src/Eth_Lcfg.c \
../src/MCAL/Gen/Src/Eth_PBcfg.c \
../src/MCAL/Gen/Src/Gpt_Cfg.c \
../src/MCAL/Gen/Src/Gpt_PBcfg.c \
../src/MCAL/Gen/Src/Mcu_Cfg.c \
../src/MCAL/Gen/Src/Mcu_PBcfg.c \
../src/MCAL/Gen/Src/Port_Cfg.c \
../src/MCAL/Gen/Src/Port_PBcfg.c \
../src/MCAL/Gen/Src/Spi_Cfg.c \
../src/MCAL/Gen/Src/Spi_Lcfg.c \
../src/MCAL/Gen/Src/Spi_PBcfg.c 

OBJS += \
./src/MCAL/Gen/Src/Can_43_MCAN_Cfg.o \
./src/MCAL/Gen/Src/Can_43_MCAN_PBcfg.o \
./src/MCAL/Gen/Src/Can_Cfg.o \
./src/MCAL/Gen/Src/Can_PBcfg.o \
./src/MCAL/Gen/Src/Dio_Cfg.o \
./src/MCAL/Gen/Src/Eth_Cfg.o \
./src/MCAL/Gen/Src/Eth_Lcfg.o \
./src/MCAL/Gen/Src/Eth_PBcfg.o \
./src/MCAL/Gen/Src/Gpt_Cfg.o \
./src/MCAL/Gen/Src/Gpt_PBcfg.o \
./src/MCAL/Gen/Src/Mcu_Cfg.o \
./src/MCAL/Gen/Src/Mcu_PBcfg.o \
./src/MCAL/Gen/Src/Port_Cfg.o \
./src/MCAL/Gen/Src/Port_PBcfg.o \
./src/MCAL/Gen/Src/Spi_Cfg.o \
./src/MCAL/Gen/Src/Spi_Lcfg.o \
./src/MCAL/Gen/Src/Spi_PBcfg.o 

C_DEPS += \
./src/MCAL/Gen/Src/Can_43_MCAN_Cfg.d \
./src/MCAL/Gen/Src/Can_43_MCAN_PBcfg.d \
./src/MCAL/Gen/Src/Can_Cfg.d \
./src/MCAL/Gen/Src/Can_PBcfg.d \
./src/MCAL/Gen/Src/Dio_Cfg.d \
./src/MCAL/Gen/Src/Eth_Cfg.d \
./src/MCAL/Gen/Src/Eth_Lcfg.d \
./src/MCAL/Gen/Src/Eth_PBcfg.d \
./src/MCAL/Gen/Src/Gpt_Cfg.d \
./src/MCAL/Gen/Src/Gpt_PBcfg.d \
./src/MCAL/Gen/Src/Mcu_Cfg.d \
./src/MCAL/Gen/Src/Mcu_PBcfg.d \
./src/MCAL/Gen/Src/Port_Cfg.d \
./src/MCAL/Gen/Src/Port_PBcfg.d \
./src/MCAL/Gen/Src/Spi_Cfg.d \
./src/MCAL/Gen/Src/Spi_Lcfg.d \
./src/MCAL/Gen/Src/Spi_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/Gen/Src/%.o: ../src/MCAL/Gen/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Diab C Compiler'
	dcc -c -Xdialect-c99 -tPPCE200Z759N3VES -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Base" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Gen/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcu/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Rte/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Gpt/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcl/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dem/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Det/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dio/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Port/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Users" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/MCan/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/CanIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Eth/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/EthIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Spi/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Can/Inc" -DSTART_FROM_FLASH -DMPC5777C -DAUTOSAR_OS_NOT_USED -D__DCC__ -g3 -Xmake-dependency=0x5 -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '


