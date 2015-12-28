################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../cr_dsplib_biquad32.s \
../cr_dsplib_blockfir32.s \
../cr_dsplib_dotproduct.s \
../cr_dsplib_pid.s \
../cr_dsplib_random.s \
../cr_dsplib_resonator.s \
../cr_dsplib_vectoradd.s \
../cr_dsplib_vectoraddconst.s \
../cr_dsplib_vectormulconst.s \
../cr_dsplib_vectormulelement.s \
../cr_dsplib_vectorsub.s \
../cr_dsplib_vectsumofsquares.s 

OBJS += \
./cr_dsplib_biquad32.o \
./cr_dsplib_blockfir32.o \
./cr_dsplib_dotproduct.o \
./cr_dsplib_pid.o \
./cr_dsplib_random.o \
./cr_dsplib_resonator.o \
./cr_dsplib_vectoradd.o \
./cr_dsplib_vectoraddconst.o \
./cr_dsplib_vectormulconst.o \
./cr_dsplib_vectormulelement.o \
./cr_dsplib_vectorsub.o \
./cr_dsplib_vectsumofsquares.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -D__REDLIB__ -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


