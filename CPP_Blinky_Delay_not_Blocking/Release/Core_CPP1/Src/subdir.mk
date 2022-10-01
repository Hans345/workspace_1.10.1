################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core_CPP1/Src/BlinkingLed.cpp \
../Core_CPP1/Src/NoneBlockSystemTickDelay.cpp \
../Core_CPP1/Src/STM32H7Led.cpp \
../Core_CPP1/Src/cpp_main.cpp 

OBJS += \
./Core_CPP1/Src/BlinkingLed.o \
./Core_CPP1/Src/NoneBlockSystemTickDelay.o \
./Core_CPP1/Src/STM32H7Led.o \
./Core_CPP1/Src/cpp_main.o 

CPP_DEPS += \
./Core_CPP1/Src/BlinkingLed.d \
./Core_CPP1/Src/NoneBlockSystemTickDelay.d \
./Core_CPP1/Src/STM32H7Led.d \
./Core_CPP1/Src/cpp_main.d 


# Each subdirectory must supply rules for building sources it contributes
Core_CPP1/Src/%.o Core_CPP1/Src/%.su: ../Core_CPP1/Src/%.cpp Core_CPP1/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/raphael.baumeler/STM32CubeIDE/workspace_1.10.1/CPP_Blinky_Delay_not_Blocking/Core_CPP1/Inc" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core_CPP1-2f-Src

clean-Core_CPP1-2f-Src:
	-$(RM) ./Core_CPP1/Src/BlinkingLed.d ./Core_CPP1/Src/BlinkingLed.o ./Core_CPP1/Src/BlinkingLed.su ./Core_CPP1/Src/NoneBlockSystemTickDelay.d ./Core_CPP1/Src/NoneBlockSystemTickDelay.o ./Core_CPP1/Src/NoneBlockSystemTickDelay.su ./Core_CPP1/Src/STM32H7Led.d ./Core_CPP1/Src/STM32H7Led.o ./Core_CPP1/Src/STM32H7Led.su ./Core_CPP1/Src/cpp_main.d ./Core_CPP1/Src/cpp_main.o ./Core_CPP1/Src/cpp_main.su

.PHONY: clean-Core_CPP1-2f-Src

