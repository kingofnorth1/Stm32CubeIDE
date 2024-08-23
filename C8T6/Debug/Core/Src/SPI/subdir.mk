################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SPI/lcd.c \
../Core/Src/SPI/lcd_Init.c 

OBJS += \
./Core/Src/SPI/lcd.o \
./Core/Src/SPI/lcd_Init.o 

C_DEPS += \
./Core/Src/SPI/lcd.d \
./Core/Src/SPI/lcd_Init.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SPI/%.o Core/Src/SPI/%.su Core/Src/SPI/%.cyclo: ../Core/Src/SPI/%.c Core/Src/SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SPI

clean-Core-2f-Src-2f-SPI:
	-$(RM) ./Core/Src/SPI/lcd.cyclo ./Core/Src/SPI/lcd.d ./Core/Src/SPI/lcd.o ./Core/Src/SPI/lcd.su ./Core/Src/SPI/lcd_Init.cyclo ./Core/Src/SPI/lcd_Init.d ./Core/Src/SPI/lcd_Init.o ./Core/Src/SPI/lcd_Init.su

.PHONY: clean-Core-2f-Src-2f-SPI

