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
all: cr_dsplib_testbench_fft.axf

# Tool invocations
cr_dsplib_testbench_fft.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\cr_dsplibFFTbin_cm3" -Xlinker --gc-sections -Xlinker -Map=cr_dsplib_testbench_fft.map -mcpu=cortex-m3 -mthumb -T "cr_dsplib_testbench_fft_Debug.ld" -o "cr_dsplib_testbench_fft.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) cr_dsplib_testbench_fft.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size cr_dsplib_testbench_fft.axf; # arm-none-eabi-objdump -h -S cr_dsplib_testbench_fft.axf >cr_dsplib_testbench_fft.lss
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
