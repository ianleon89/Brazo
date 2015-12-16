################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib_FreeRTOS/portable/MemMang/heap_2.c 

OBJS += \
./Lib_FreeRTOS/portable/MemMang/heap_2.o 

C_DEPS += \
./Lib_FreeRTOS/portable/MemMang/heap_2.d 


# Each subdirectory must supply rules for building sources it contributes
Lib_FreeRTOS/portable/MemMang/%.o: ../Lib_FreeRTOS/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DALIGN_STRUCT_END=__attribute\(\(aligned\(4\)\)\) -DPACK_STRUCT_END=__attribute\(\(packed\)\) -DPACK_STRUCT_END=__attribute\(\(packed\)\) -DDEBUG -D__USE_CMSIS=CMSISv1p30_LPC17xx -D__CODE_RED -D__REDLIB__ -I"C:\nxp\projects\Workspace_NBrazo_V1.2\cr_dsplibFFTbin_cm3" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\cr_dsplib_cm3" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\cr_dsplib_testbench_fft" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\uart\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\CMSISv1p30_LPC17xx" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\lib_small_printf_m3\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\adc_buzzer\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Application" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Application\Lib_FreeRTOS\include" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Application\Lib_FreeRTOS\portable\GCC\ARM_CM3" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Application\Bitmaps" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDgui\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDPrimitives\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\LIB_GLCDPrimitives\fonts" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_GLCDLowLevel\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_TouchPanel\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_MCU\inc" -I"C:\nxp\projects\Workspace_NBrazo_V1.2\Lib_CMSISv1p30_LPC17xx\inc" -O0 -g3 -fsigned-char -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


