################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/test/activityfour.c \
../Core/Src/test/activitythree.c \
../Core/Src/test/bounceexample.c \
../Core/Src/test/buttontest.c \
../Core/Src/test/clock.c \
../Core/Src/test/echo.c \
../Core/Src/test/hello.c \
../Core/Src/test/hw4.c \
../Core/Src/test/hw8.c \
../Core/Src/test/sqr_wave.c \
../Core/Src/test/structs.c \
../Core/Src/test/timer.c 

OBJS += \
./Core/Src/test/activityfour.o \
./Core/Src/test/activitythree.o \
./Core/Src/test/bounceexample.o \
./Core/Src/test/buttontest.o \
./Core/Src/test/clock.o \
./Core/Src/test/echo.o \
./Core/Src/test/hello.o \
./Core/Src/test/hw4.o \
./Core/Src/test/hw8.o \
./Core/Src/test/sqr_wave.o \
./Core/Src/test/structs.o \
./Core/Src/test/timer.o 

C_DEPS += \
./Core/Src/test/activityfour.d \
./Core/Src/test/activitythree.d \
./Core/Src/test/bounceexample.d \
./Core/Src/test/buttontest.d \
./Core/Src/test/clock.d \
./Core/Src/test/echo.d \
./Core/Src/test/hello.d \
./Core/Src/test/hw4.d \
./Core/Src/test/hw8.d \
./Core/Src/test/sqr_wave.d \
./Core/Src/test/structs.d \
./Core/Src/test/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/test/%.o Core/Src/test/%.su Core/Src/test/%.cyclo: ../Core/Src/test/%.c Core/Src/test/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Inc/ -I../Core/Inc/demos -I../Core/Inc/devices -I../Core/Inc/midi -I../Core/Inc/system -I../Core/Inc/test -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-test

clean-Core-2f-Src-2f-test:
	-$(RM) ./Core/Src/test/activityfour.cyclo ./Core/Src/test/activityfour.d ./Core/Src/test/activityfour.o ./Core/Src/test/activityfour.su ./Core/Src/test/activitythree.cyclo ./Core/Src/test/activitythree.d ./Core/Src/test/activitythree.o ./Core/Src/test/activitythree.su ./Core/Src/test/bounceexample.cyclo ./Core/Src/test/bounceexample.d ./Core/Src/test/bounceexample.o ./Core/Src/test/bounceexample.su ./Core/Src/test/buttontest.cyclo ./Core/Src/test/buttontest.d ./Core/Src/test/buttontest.o ./Core/Src/test/buttontest.su ./Core/Src/test/clock.cyclo ./Core/Src/test/clock.d ./Core/Src/test/clock.o ./Core/Src/test/clock.su ./Core/Src/test/echo.cyclo ./Core/Src/test/echo.d ./Core/Src/test/echo.o ./Core/Src/test/echo.su ./Core/Src/test/hello.cyclo ./Core/Src/test/hello.d ./Core/Src/test/hello.o ./Core/Src/test/hello.su ./Core/Src/test/hw4.cyclo ./Core/Src/test/hw4.d ./Core/Src/test/hw4.o ./Core/Src/test/hw4.su ./Core/Src/test/hw8.cyclo ./Core/Src/test/hw8.d ./Core/Src/test/hw8.o ./Core/Src/test/hw8.su ./Core/Src/test/sqr_wave.cyclo ./Core/Src/test/sqr_wave.d ./Core/Src/test/sqr_wave.o ./Core/Src/test/sqr_wave.su ./Core/Src/test/structs.cyclo ./Core/Src/test/structs.d ./Core/Src/test/structs.o ./Core/Src/test/structs.su ./Core/Src/test/timer.cyclo ./Core/Src/test/timer.d ./Core/Src/test/timer.o ./Core/Src/test/timer.su

.PHONY: clean-Core-2f-Src-2f-test

