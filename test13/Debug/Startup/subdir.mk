################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32l011f3px.s 

OBJS += \
./Startup/startup_stm32l011f3px.o 

S_DEPS += \
./Startup/startup_stm32l011f3px.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32l011f3px.o: ../Startup/startup_stm32l011f3px.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g3 -c -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32l011f3px.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

