################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CPP_Core/Src/InternalTemperature.cpp 

OBJS += \
./CPP_Core/Src/InternalTemperature.o 

CPP_DEPS += \
./CPP_Core/Src/InternalTemperature.d 


# Each subdirectory must supply rules for building sources it contributes
CPP_Core/Src/%.o CPP_Core/Src/%.su: ../CPP_Core/Src/%.cpp CPP_Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DSTD_MAP -DDEBUG -DCOUT -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/raphael.baumeler/STM32CubeIDE/workspace_1.10.1/EmbReal_Ex_Baumeler_Raphael/CPP_Core/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CPP_Core-2f-Src

clean-CPP_Core-2f-Src:
	-$(RM) ./CPP_Core/Src/InternalTemperature.d ./CPP_Core/Src/InternalTemperature.o ./CPP_Core/Src/InternalTemperature.su

.PHONY: clean-CPP_Core-2f-Src

