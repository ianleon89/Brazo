################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc.c \
../src/cr_startup_lpc17.c \
../src/debug.c \
../src/freq.c \
../src/iap_driver.c \
../src/main.c \
../src/rtc.c \
../src/uart.c 

OBJS += \
./src/adc.o \
./src/cr_startup_lpc17.o \
./src/debug.o \
./src/freq.o \
./src/iap_driver.o \
./src/main.o \
./src/rtc.o \
./src/uart.o 

C_DEPS += \
./src/adc.d \
./src/cr_startup_lpc17.d \
./src/debug.d \
./src/freq.d \
./src/iap_driver.d \
./src/main.d \
./src/rtc.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC13xx -DNO_FLOAT_PRINTF -DDEBUG -D__CODE_RED -D__REDLIB__ -I"E:\Boreas\TDA\Vibrometro\Brazo\NBrazo_4\cr_dsplib_cm3" -I"E:\Boreas\TDA\Vibrometro\Brazo\NBrazo_4\cr_dsplib_testbench_fft" -I"E:\Boreas\TDA\Vibrometro\Brazo\NBrazo_4\cr_dsplibFFTbin_cm3" -I"E:\Boreas\TDA\Vibrometro\Brazo\NBrazo_4\CMSISv1p30_LPC17xx\inc" -I"E:\Boreas\TDA\Vibrometro\Brazo\NBrazo_4\lib_small_printf_m3\inc" -I"E:\Boreas\TDA\Vibrometro\Brazo\NBrazo_4\adc_buzzer\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


