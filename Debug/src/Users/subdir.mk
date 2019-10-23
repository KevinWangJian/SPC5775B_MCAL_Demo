################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Users/CanIf_Usr.c \
../src/Users/EthComm.c \
../src/Users/IntCtrl.c \
../src/Users/McanComm.c \
../src/Users/NXP_TJA1100_Functions.c \
../src/Users/PhyDP83822I.c \
../src/Users/PhyTja110x.c \
../src/Users/tickTimer.c 

OBJS += \
./src/Users/CanIf_Usr.o \
./src/Users/EthComm.o \
./src/Users/IntCtrl.o \
./src/Users/McanComm.o \
./src/Users/NXP_TJA1100_Functions.o \
./src/Users/PhyDP83822I.o \
./src/Users/PhyTja110x.o \
./src/Users/tickTimer.o 

C_DEPS += \
./src/Users/CanIf_Usr.d \
./src/Users/EthComm.d \
./src/Users/IntCtrl.d \
./src/Users/McanComm.d \
./src/Users/NXP_TJA1100_Functions.d \
./src/Users/PhyDP83822I.d \
./src/Users/PhyTja110x.d \
./src/Users/tickTimer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Users/%.o: ../src/Users/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Diab C Compiler'
	dcc -c -tPPCE200Z759N3VES -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/include" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/include/Base" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Gen/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcu/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Rte/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Gpt/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcl/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dem/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Det/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dio/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Port/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/include/Users" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/MCan/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/CanIf/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Eth/Inc" -I"D:/DuPower/SRC/SPC5775B_Ethernet/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/EthIf/Inc" -DSTART_FROM_FLASH -DMPC5777C -DAUTOSAR_OS_NOT_USED -D__DCC__ -g3 -Xmake-dependency=0x5 -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '


