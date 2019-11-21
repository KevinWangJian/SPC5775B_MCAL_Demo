################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/Module/Mcl/Src/CDD_Mcl.c \
../src/MCAL/Module/Mcl/Src/Mcl_Axbs.c \
../src/MCAL/Module/Mcl/Src/Mcl_Dma.c \
../src/MCAL/Module/Mcl/Src/Mcl_Dma_Irq.c \
../src/MCAL/Module/Mcl/Src/Mcl_IPW.c \
../src/MCAL/Module/Mcl/Src/eMios_Common.c 

OBJS += \
./src/MCAL/Module/Mcl/Src/CDD_Mcl.o \
./src/MCAL/Module/Mcl/Src/Mcl_Axbs.o \
./src/MCAL/Module/Mcl/Src/Mcl_Dma.o \
./src/MCAL/Module/Mcl/Src/Mcl_Dma_Irq.o \
./src/MCAL/Module/Mcl/Src/Mcl_IPW.o \
./src/MCAL/Module/Mcl/Src/eMios_Common.o 

C_DEPS += \
./src/MCAL/Module/Mcl/Src/CDD_Mcl.d \
./src/MCAL/Module/Mcl/Src/Mcl_Axbs.d \
./src/MCAL/Module/Mcl/Src/Mcl_Dma.d \
./src/MCAL/Module/Mcl/Src/Mcl_Dma_Irq.d \
./src/MCAL/Module/Mcl/Src/Mcl_IPW.d \
./src/MCAL/Module/Mcl/Src/eMios_Common.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/Module/Mcl/Src/%.o: ../src/MCAL/Module/Mcl/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Diab C Compiler'
	dcc -c -Xdialect-c99 -tPPCE200Z759N3VES -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Base" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Gen/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcu/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Rte/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Gpt/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Mcl/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dem/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Det/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Dio/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Port/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/include/Users" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/MCan/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/CanIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Eth/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/EthIf/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Spi/Inc" -I"D:/DuPower/SRC/Ethernet/MCAL_Version/SPC5775B_Ethernet_20191113/SPC5775B_ETHERNET_Z7_0/src/MCAL/Module/Can/Inc" -DSTART_FROM_FLASH -DMPC5777C -DAUTOSAR_OS_NOT_USED -D__DCC__ -g3 -Xmake-dependency=0x5 -o $@ $<
	@echo 'Finished building: $<'
	@echo ' '


