################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GLCDLowLevel.c \
../src/MicroInterface.c 

OBJS += \
./src/GLCDLowLevel.o \
./src/MicroInterface.o 

C_DEPS += \
./src/GLCDLowLevel.d \
./src/MicroInterface.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\Lib_GLCDLowLevel\inc" -I"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\Lib_CMSISv1p30_LPC17xx\inc" -I"E:\Boreas\TDA\Vibrometro\Unificado\NBrazo_Memoria_Iv\Lib_MCU\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


