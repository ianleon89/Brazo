################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Lib_FreeRTOS/portable/MemMang/subdir.mk
-include Lib_FreeRTOS/portable/GCC/ARM_CM3/subdir.mk
-include Lib_FreeRTOS/subdir.mk
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
all: Application.axf

# Tool invocations
Application.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\nxp\projects\Workspace_NBrazo_V1.2\cr_dsplibFFTbin_cm3" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\uart\inc" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\CMSISv1p30_LPC17xx\Debug" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\lib_small_printf_m3\Lib" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDgui\Debug" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDPrimitives\Debug" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_GLCDLowLevel\Debug" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_TouchPanel\Debug" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_MCU\Debug" -L"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_CMSISv1p30_LPC17xx\Debug" -Xlinker --gc-sections -Xlinker -Map=Application.map -mcpu=cortex-m3 -mthumb -T "example01_Debug.ld" -o "Application.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Application.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size Application.axf; # arm-none-eabi-objcopy -O ihex Application.axf Application.hex ;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
