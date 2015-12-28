################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GLCDgui.c \
../src/button.c \
../src/list.c \
../src/object.c \
../src/picture.c \
../src/text.c \
../src/textSlider.c \
../src/windows.c 

OBJS += \
./src/GLCDgui.o \
./src/button.o \
./src/list.o \
./src/object.o \
./src/picture.o \
./src/text.o \
./src/textSlider.o \
./src/windows.o 

C_DEPS += \
./src/GLCDgui.d \
./src/button.d \
./src/list.d \
./src/object.d \
./src/picture.d \
./src/text.d \
./src/textSlider.d \
./src/windows.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDPrimitives\fonts" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_GLCDLowLevel\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDPrimitives\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDgui\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


