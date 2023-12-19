################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/util/debounce.c \
../Core/Src/util/endian_conversions.c \
../Core/Src/util/messages.c \
../Core/Src/util/parser.c 

OBJS += \
./Core/Src/util/debounce.o \
./Core/Src/util/endian_conversions.o \
./Core/Src/util/messages.o \
./Core/Src/util/parser.o 

C_DEPS += \
./Core/Src/util/debounce.d \
./Core/Src/util/endian_conversions.d \
./Core/Src/util/messages.d \
./Core/Src/util/parser.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/util/%.o Core/Src/util/%.su Core/Src/util/%.cyclo: ../Core/Src/util/%.c Core/Src/util/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/ -I../Core/Inc/demos -I../Core/Inc/devices -I../Core/Inc/midi -I../Core/Inc/system -I../Core/Inc/test -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-util

clean-Core-2f-Src-2f-util:
	-$(RM) ./Core/Src/util/debounce.cyclo ./Core/Src/util/debounce.d ./Core/Src/util/debounce.o ./Core/Src/util/debounce.su ./Core/Src/util/endian_conversions.cyclo ./Core/Src/util/endian_conversions.d ./Core/Src/util/endian_conversions.o ./Core/Src/util/endian_conversions.su ./Core/Src/util/messages.cyclo ./Core/Src/util/messages.d ./Core/Src/util/messages.o ./Core/Src/util/messages.su ./Core/Src/util/parser.cyclo ./Core/Src/util/parser.d ./Core/Src/util/parser.o ./Core/Src/util/parser.su

.PHONY: clean-Core-2f-Src-2f-util

