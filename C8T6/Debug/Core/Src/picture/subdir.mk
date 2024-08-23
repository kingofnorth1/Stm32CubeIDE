################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/picture/Fan1.c \
../Core/Src/picture/Fan2.c \
../Core/Src/picture/Fan3.c \
../Core/Src/picture/love.c 

OBJS += \
./Core/Src/picture/Fan1.o \
./Core/Src/picture/Fan2.o \
./Core/Src/picture/Fan3.o \
./Core/Src/picture/love.o 

C_DEPS += \
./Core/Src/picture/Fan1.d \
./Core/Src/picture/Fan2.d \
./Core/Src/picture/Fan3.d \
./Core/Src/picture/love.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/picture/%.o Core/Src/picture/%.su Core/Src/picture/%.cyclo: ../Core/Src/picture/%.c Core/Src/picture/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-picture

clean-Core-2f-Src-2f-picture:
	-$(RM) ./Core/Src/picture/Fan1.cyclo ./Core/Src/picture/Fan1.d ./Core/Src/picture/Fan1.o ./Core/Src/picture/Fan1.su ./Core/Src/picture/Fan2.cyclo ./Core/Src/picture/Fan2.d ./Core/Src/picture/Fan2.o ./Core/Src/picture/Fan2.su ./Core/Src/picture/Fan3.cyclo ./Core/Src/picture/Fan3.d ./Core/Src/picture/Fan3.o ./Core/Src/picture/Fan3.su ./Core/Src/picture/love.cyclo ./Core/Src/picture/love.d ./Core/Src/picture/love.o ./Core/Src/picture/love.su

.PHONY: clean-Core-2f-Src-2f-picture

