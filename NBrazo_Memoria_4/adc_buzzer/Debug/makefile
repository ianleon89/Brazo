################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: adc_buzzer.axf

# Tool invocations
adc_buzzer.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\Lib_TouchPanel\Debug" -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\cr_dsplibFFTbin_cm3" -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\LIB_GLCDPrimitives\Debug" -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\Lib_GLCDLowLevel\Debug" -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\LIB_GLCDgui\Debug" -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\CMSISv1p30_LPC17xx\Debug" -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\lib_small_printf_m3\Lib" -Xlinker -Map=adc_buzzer.map -Xlinker --gc-sections -Xlinker --cref -mcpu=cortex-m3 -mthumb -T "adc_buzzer_Debug.ld" -o "adc_buzzer.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) adc_buzzer.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-cat ../Docs/Abstract.txt; arm-none-eabi-size adc_buzzer.axf; # arm-none-eabi-objcopy -O binary adc_buzzer.axf adc_buzzer.bin ; checksum -d adc_buzzer.bin;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
