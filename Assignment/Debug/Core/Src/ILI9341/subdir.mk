################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ILI9341/ILI9341_GFX.c \
../Core/Src/ILI9341/ILI9341_STM32_Driver.c \
../Core/Src/ILI9341/ILI9341_Sprite.c \
../Core/Src/ILI9341/ILI9341_Touchscreen.c 

OBJS += \
./Core/Src/ILI9341/ILI9341_GFX.o \
./Core/Src/ILI9341/ILI9341_STM32_Driver.o \
./Core/Src/ILI9341/ILI9341_Sprite.o \
./Core/Src/ILI9341/ILI9341_Touchscreen.o 

C_DEPS += \
./Core/Src/ILI9341/ILI9341_GFX.d \
./Core/Src/ILI9341/ILI9341_STM32_Driver.d \
./Core/Src/ILI9341/ILI9341_Sprite.d \
./Core/Src/ILI9341/ILI9341_Touchscreen.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ILI9341/%.o Core/Src/ILI9341/%.su Core/Src/ILI9341/%.cyclo: ../Core/Src/ILI9341/%.c Core/Src/ILI9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ILI9341

clean-Core-2f-Src-2f-ILI9341:
	-$(RM) ./Core/Src/ILI9341/ILI9341_GFX.cyclo ./Core/Src/ILI9341/ILI9341_GFX.d ./Core/Src/ILI9341/ILI9341_GFX.o ./Core/Src/ILI9341/ILI9341_GFX.su ./Core/Src/ILI9341/ILI9341_STM32_Driver.cyclo ./Core/Src/ILI9341/ILI9341_STM32_Driver.d ./Core/Src/ILI9341/ILI9341_STM32_Driver.o ./Core/Src/ILI9341/ILI9341_STM32_Driver.su ./Core/Src/ILI9341/ILI9341_Sprite.cyclo ./Core/Src/ILI9341/ILI9341_Sprite.d ./Core/Src/ILI9341/ILI9341_Sprite.o ./Core/Src/ILI9341/ILI9341_Sprite.su ./Core/Src/ILI9341/ILI9341_Touchscreen.cyclo ./Core/Src/ILI9341/ILI9341_Touchscreen.d ./Core/Src/ILI9341/ILI9341_Touchscreen.o ./Core/Src/ILI9341/ILI9341_Touchscreen.su

.PHONY: clean-Core-2f-Src-2f-ILI9341

