################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/touchPanel.c 

OBJS += \
./src/touchPanel.o 

C_DEPS += \
./src/touchPanel.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"E:\Boreas\LPCXpresso\MisProyectos\DecibelimetroNuevo\Diciembre07\Nuevo16\Lib_TouchPanel\inc" -I"E:\Boreas\LPCXpresso\MisProyectos\DecibelimetroNuevo\Diciembre07\Nuevo16\Lib_CMSISv1p30_LPC17xx\inc" -I"E:\Boreas\LPCXpresso\MisProyectos\DecibelimetroNuevo\Diciembre07\Nuevo16\Lib_MCU\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


