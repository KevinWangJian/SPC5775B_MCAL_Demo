################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/Module/Mcu/Src/Mcu.c \
../src/MCAL/Module/Mcu/Src/Mcu_CMU.c \
../src/MCAL/Module/Mcu/Src/Mcu_CMU_Irq.c \
../src/MCAL/Module/Mcu/Src/Mcu_FLASH.c \
../src/MCAL/Module/Mcu/Src/Mcu_IPW.c \
../src/MCAL/Module/Mcu/Src/Mcu_PLLDIG.c \
../src/MCAL/Module/Mcu/Src/Mcu_PLLDIG_Irq.c \
../src/MCAL/Module/Mcu/Src/Mcu_PMC.c \
../src/MCAL/Module/Mcu/Src/Mcu_PMC_Irq.c \
../src/MCAL/Module/Mcu/Src/Mcu_PRAM.c \
../src/MCAL/Module/Mcu/Src/Mcu_SIU.c \
../src/MCAL/Module/Mcu/Src/Mcu_SSCM.c \
../src/MCAL/Module/Mcu/Src/Mcu_STCU.c \
../src/MCAL/Module/Mcu/Src/Mcu_eMios.c 

OBJS += \
./src/MCAL/Module/Mcu/Src/Mcu.o \
./src/MCAL/Module/Mcu/Src/Mcu_CMU.o \
./src/MCAL/Module/Mcu/Src/Mcu_CMU_Irq.o \
./src/MCAL/Module/Mcu/Src/Mcu_FLASH.o \
./src/MCAL/Module/Mcu/Src/Mcu_IPW.o \
./src/MCAL/Module/Mcu/Src/Mcu_PLLDIG.o \
./src/MCAL/Module/Mcu/Src/Mcu_PLLDIG_Irq.o \
./src/MCAL/Module/Mcu/Src/Mcu_PMC.o \
./src/MCAL/Module/Mcu/Src/Mcu_PMC_Irq.o \
./src/MCAL/Module/Mcu/Src/Mcu_PRAM.o \
./src/MCAL/Module/Mcu/Src/Mcu_SIU.o \
./src/MCAL/Module/Mcu/Src/Mcu_SSCM.o \
./src/MCAL/Module/Mcu/Src/Mcu_STCU.o \
./src/MCAL/Module/Mcu/Src/Mcu_eMios.o 

C_DEPS += \
./src/MCAL/Module/Mcu/Src/Mcu.d \
./src/MCAL/Module/Mcu/Src/Mcu_CMU.d \
./src/MCAL/Module/Mcu/Src/Mcu_CMU_Irq.d \
./src/MCAL/Module/Mcu/Src/Mcu_FLASH.d \
./src/MCAL/Module/Mcu/Src/Mcu_IPW.d \
./src/MCAL/Module/Mcu/Src/Mcu_PLLDIG.d \
./src/MCAL/Module/Mcu/Src/Mcu_PLLDIG_Irq.d \
./src/MCAL/Module/Mcu/Src/Mcu_PMC.d \
./src/MCAL/Module/Mcu/Src/Mcu_PMC_Irq.d \
./src/MCAL/Module/Mcu/Src/Mcu_PRAM.d \
./src/MCAL/Module/Mcu/Src/Mcu_SIU.d \
./src/MCAL/Module/Mcu/Src/Mcu_SSCM.d \
./src/MCAL/Module/Mcu/Src/Mcu_STCU.d \
./src/MCAL/Module/Mcu/Src/Mcu_eMios.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/Module/Mcu/Src/%.o: ../src/MCAL/Module/Mcu/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Diab C Compiler'
	dcc -c -tPPCE200Z759N3VES -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/include" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/include/Base" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Gen/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcu/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Rte/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Gpt/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcl/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dem/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Det/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dio/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Port/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/include/Users" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/MCan/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/CanIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Eth/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/EthIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191105/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Spi/Inc" -DSTART_FROM_FLASH -DMPC5777C -DAUTOSAR_OS_NOT_USED -D__DCC__ -g3 -Xmake-dependency=0x5 -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '


