################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lsm6dso/lsm6dso.c \
../Drivers/BSP/Components/lsm6dso/lsm6dso_reg.c 

C_DEPS += \
./Drivers/BSP/Components/lsm6dso/lsm6dso.d \
./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.d 

OBJS += \
./Drivers/BSP/Components/lsm6dso/lsm6dso.o \
./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lsm6dso/%.o Drivers/BSP/Components/lsm6dso/%.su: ../Drivers/BSP/Components/lsm6dso/%.c Drivers/BSP/Components/lsm6dso/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../MEMS/Target -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dso -I../Drivers/BSP/Components/lis2dw12 -I../Drivers/BSP/Components/lis2mdl -I../Drivers/BSP/Components/hts221 -I../Drivers/BSP/Components/lps22hh -I../Drivers/BSP/Components/stts751 -I../Drivers/BSP/IKS01A3 -I../Drivers/BSP/Components/Common -I../MEMS/App -I../Drivers/BSP/STM32F7xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-lsm6dso

clean-Drivers-2f-BSP-2f-Components-2f-lsm6dso:
	-$(RM) ./Drivers/BSP/Components/lsm6dso/lsm6dso.d ./Drivers/BSP/Components/lsm6dso/lsm6dso.o ./Drivers/BSP/Components/lsm6dso/lsm6dso.su ./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.d ./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.o ./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-lsm6dso

