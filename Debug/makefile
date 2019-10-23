################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Users/subdir.mk
-include src/MCAL/Module/Rte/Src/subdir.mk
-include src/MCAL/Module/Port/Src/subdir.mk
-include src/MCAL/Module/Mcu/Src/subdir.mk
-include src/MCAL/Module/Mcl/Src/subdir.mk
-include src/MCAL/Module/MCan/Src/subdir.mk
-include src/MCAL/Module/Gpt/Src/subdir.mk
-include src/MCAL/Module/EthIf/Src/subdir.mk
-include src/MCAL/Module/Eth/Src/subdir.mk
-include src/MCAL/Module/Dio/Src/subdir.mk
-include src/MCAL/Module/Det/Src/subdir.mk
-include src/MCAL/Module/Dem/Src/subdir.mk
-include src/MCAL/Gen/Src/subdir.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
COM_WINDRIVER_CDT_DIAB_OUTPUTTYPE_LINKER_MAP_OUTPUTS += \
link.map \

WPODIR += \


# All Target
all: SPC5775B_ETHERNET_Z7_0.elf

# Tool invocations
SPC5775B_ETHERNET_Z7_0.elf: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Diab C Linker'
	dld -tPPCE200Z759N3VES -m6 > SPC5775B_ETHERNET_Z7_0.map ../Project_Settings/Linker_Files/57xx_flash.dld -o SPC5775B_ETHERNET_Z7_0.elf $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

link.map: SPC5775B_ETHERNET_Z7_0.elf $(OBJS)
: SPC5775B_ETHERNET_Z7_0.elf $(OBJS)

# Other Targets
clean:
	-$(RM) $(COM_WINDRIVER_CDT_DIAB_OUTPUTTYPE_LINKER_MAP_OUTPUTS)$(EXECUTABLES)$(WPODIR)$(OBJS)$(C_DEPS) SPC5775B_ETHERNET_Z7_0.elf
	-@echo ' '

post-build:
	-ddump -R -o SPC5775B_ETHERNET.s19 SPC5775B_ETHERNET_Z7_0.elf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
