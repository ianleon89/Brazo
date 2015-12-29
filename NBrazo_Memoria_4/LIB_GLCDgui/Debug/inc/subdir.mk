################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../inc/GLCDgui.c \
../inc/button.c \
../inc/windows.c 

OBJS += \
./inc/GLCDgui.o \
./inc/button.o \
./inc/windows.o 

C_DEPS += \
./inc/GLCDgui.d \
./inc/button.d \
./inc/windows.d 


# Each subdirectory must supply rules for building sources it contributes
inc/%.o: ../inc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"/home/eze/Documentos/Sistemas Embebidos/Control Automatico de Espacios/Eze/Software/LCD/4_GUI (Implementation)/Lib_GLCDLowLevel/inc" -I"/home/eze/Documentos/Sistemas Embebidos/Control Automatico de Espacios/Eze/Software/LCD/4_GUI (Implementation)/LIB_GLCDPrimitives/inc" -I"/home/eze/Documentos/Sistemas Embebidos/Control Automatico de Espacios/Eze/Software/LCD/4_GUI (Implementation)/LIB_GLCDgui/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


