################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/I2C/I2C_Init.c 

OBJS += \
./Core/Src/I2C/I2C_Init.o 

C_DEPS += \
./Core/Src/I2C/I2C_Init.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/I2C/%.o Core/Src/I2C/%.su Core/Src/I2C/%.cyclo: ../Core/Src/I2C/%.c Core/Src/I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-I2C

clean-Core-2f-Src-2f-I2C:
	-$(RM) ./Core/Src/I2C/I2C_Init.cyclo ./Core/Src/I2C/I2C_Init.d ./Core/Src/I2C/I2C_Init.o ./Core/Src/I2C/I2C_Init.su

.PHONY: clean-Core-2f-Src-2f-I2C

