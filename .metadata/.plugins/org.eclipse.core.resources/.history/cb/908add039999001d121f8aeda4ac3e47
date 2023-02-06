################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CPP_Core/Src/AccGyroSensor.cpp \
../CPP_Core/Src/AccSensor.cpp \
../CPP_Core/Src/IKS01A3Motion.cpp \
../CPP_Core/Src/STM32H7Led.cpp \
../CPP_Core/Src/SpiritLevelSignelAxis3LED.cpp 

OBJS += \
./CPP_Core/Src/AccGyroSensor.o \
./CPP_Core/Src/AccSensor.o \
./CPP_Core/Src/IKS01A3Motion.o \
./CPP_Core/Src/STM32H7Led.o \
./CPP_Core/Src/SpiritLevelSignelAxis3LED.o 

CPP_DEPS += \
./CPP_Core/Src/AccGyroSensor.d \
./CPP_Core/Src/AccSensor.d \
./CPP_Core/Src/IKS01A3Motion.d \
./CPP_Core/Src/STM32H7Led.d \
./CPP_Core/Src/SpiritLevelSignelAxis3LED.d 


# Each subdirectory must supply rules for building sources it contributes
CPP_Core/Src/%.o CPP_Core/Src/%.su: ../CPP_Core/Src/%.cpp CPP_Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DCOUT -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../X-CUBE-MEMS1/Target -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dso -I../Drivers/BSP/Components/lis2dw12 -I../Drivers/BSP/Components/lis2mdl -I../Drivers/BSP/Components/hts221 -I../Drivers/BSP/Components/lps22hh -I../Drivers/BSP/Components/stts751 -I../Drivers/BSP/IKS01A3 -I../Drivers/BSP/Components/Common -I"C:/Users/raphael.baumeler/STM32CubeIDE/workspace_1.10.1/EP_CPP_IKS01A3_SpitirLevel/CPP_Core/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CPP_Core-2f-Src

clean-CPP_Core-2f-Src:
	-$(RM) ./CPP_Core/Src/AccGyroSensor.d ./CPP_Core/Src/AccGyroSensor.o ./CPP_Core/Src/AccGyroSensor.su ./CPP_Core/Src/AccSensor.d ./CPP_Core/Src/AccSensor.o ./CPP_Core/Src/AccSensor.su ./CPP_Core/Src/IKS01A3Motion.d ./CPP_Core/Src/IKS01A3Motion.o ./CPP_Core/Src/IKS01A3Motion.su ./CPP_Core/Src/STM32H7Led.d ./CPP_Core/Src/STM32H7Led.o ./CPP_Core/Src/STM32H7Led.su ./CPP_Core/Src/SpiritLevelSignelAxis3LED.d ./CPP_Core/Src/SpiritLevelSignelAxis3LED.o ./CPP_Core/Src/SpiritLevelSignelAxis3LED.su

.PHONY: clean-CPP_Core-2f-Src

