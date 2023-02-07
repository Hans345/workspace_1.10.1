################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CPP_Core/Base1.cpp \
../CPP_Core/Base2.cpp 

OBJS += \
./CPP_Core/Base1.o \
./CPP_Core/Base2.o 

CPP_DEPS += \
./CPP_Core/Base1.d \
./CPP_Core/Base2.d 


# Each subdirectory must supply rules for building sources it contributes
CPP_Core/%.o CPP_Core/%.su: ../CPP_Core/%.cpp CPP_Core/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DSTD_MAP -DDEBUG -DCOUT -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/raphael.baumeler/STM32CubeIDE/workspace_1.10.1/Test/CPP_Core/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CPP_Core

clean-CPP_Core:
	-$(RM) ./CPP_Core/Base1.d ./CPP_Core/Base1.o ./CPP_Core/Base1.su ./CPP_Core/Base2.d ./CPP_Core/Base2.o ./CPP_Core/Base2.su

.PHONY: clean-CPP_Core

