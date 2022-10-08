################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32F7xx_Nucleo/stm32f7xx_nucleo.c 

C_DEPS += \
./Drivers/BSP/STM32F7xx_Nucleo/stm32f7xx_nucleo.d 

OBJS += \
./Drivers/BSP/STM32F7xx_Nucleo/stm32f7xx_nucleo.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F7xx_Nucleo/%.o Drivers/BSP/STM32F7xx_Nucleo/%.su: ../Drivers/BSP/STM32F7xx_Nucleo/%.c Drivers/BSP/STM32F7xx_Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../MEMS/Target -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dso -I../Drivers/BSP/Components/lis2dw12 -I../Drivers/BSP/Components/lis2mdl -I../Drivers/BSP/Components/hts221 -I../Drivers/BSP/Components/lps22hh -I../Drivers/BSP/Components/stts751 -I../Drivers/BSP/IKS01A3 -I../Drivers/BSP/Components/Common -I../MEMS/App -I../Drivers/BSP/STM32F7xx_Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32F7xx_Nucleo

clean-Drivers-2f-BSP-2f-STM32F7xx_Nucleo:
	-$(RM) ./Drivers/BSP/STM32F7xx_Nucleo/stm32f7xx_nucleo.d ./Drivers/BSP/STM32F7xx_Nucleo/stm32f7xx_nucleo.o ./Drivers/BSP/STM32F7xx_Nucleo/stm32f7xx_nucleo.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32F7xx_Nucleo

