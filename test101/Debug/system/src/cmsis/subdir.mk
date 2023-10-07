################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/cmsis/system_stm32f7xx.c \
../system/src/cmsis/vectors_stm32f767xx.c 

OBJS += \
./system/src/cmsis/system_stm32f7xx.o \
./system/src/cmsis/vectors_stm32f767xx.o 

C_DEPS += \
./system/src/cmsis/system_stm32f7xx.d \
./system/src/cmsis/vectors_stm32f767xx.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/cmsis/system_stm32f7xx.o: ../system/src/cmsis/system_stm32f7xx.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	echo -msmall-data-limit=8 -mno-save-restore -O2 -g -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/cmsis/%.o: ../system/src/cmsis/%.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	echo -msmall-data-limit=8 -mno-save-restore -O2 -g -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_SEMIHOSTING -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F767xx -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f7-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


