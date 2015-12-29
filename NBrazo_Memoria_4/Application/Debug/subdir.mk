################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../cr_startup_lpc17.c \
../debug.c \
../freq.c \
../iap_driver.c \
../main.c \
../rtc.c \
../uart.c 

OBJS += \
./adc.o \
./cr_startup_lpc17.o \
./debug.o \
./freq.o \
./iap_driver.o \
./main.o \
./rtc.o \
./uart.o 

C_DEPS += \
./adc.d \
./cr_startup_lpc17.d \
./debug.d \
./freq.d \
./iap_driver.d \
./main.d \
./rtc.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DALIGN_STRUCT_END=__attribute\(\(aligned\(4\)\)\) -DPACK_STRUCT_END=__attribute\(\(packed\)\) -DPACK_STRUCT_END=__attribute\(\(packed\)\) -DDEBUG -D__USE_CMSIS=CMSISv1p30_LPC17xx -D__CODE_RED -D__REDLIB__ -I"C:\nxp\projects\NBrazo_Memoria_4\cr_dsplibFFTbin_cm3" -I"C:\nxp\projects\NBrazo_Memoria_4\cr_dsplib_cm3" -I"C:\nxp\projects\NBrazo_Memoria_4\cr_dsplib_testbench_fft" -I"C:\nxp\projects\NBrazo_Memoria_4\uart\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\CMSISv1p30_LPC17xx" -I"C:\nxp\projects\NBrazo_Memoria_4\lib_small_printf_m3\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\adc_buzzer\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\Application" -I"C:\nxp\projects\NBrazo_Memoria_4\Application\Lib_FreeRTOS\include" -I"C:\nxp\projects\NBrazo_Memoria_4\Application\Lib_FreeRTOS\portable\GCC\ARM_CM3" -I"C:\nxp\projects\NBrazo_Memoria_4\Application\Bitmaps" -I"C:\nxp\projects\NBrazo_Memoria_4\LIB_GLCDgui\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\LIB_GLCDPrimitives\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\LIB_GLCDPrimitives\fonts" -I"C:\nxp\projects\NBrazo_Memoria_4\Lib_GLCDLowLevel\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\Lib_TouchPanel\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\Lib_MCU\inc" -I"C:\nxp\projects\NBrazo_Memoria_4\Lib_CMSISv1p30_LPC17xx\inc" -O0 -g3 -fsigned-char -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


