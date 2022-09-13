################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prg.c \
../DIO_prg.c \
../EXTI_prg.c \
../MOTOR_main.c \
../MOTOR_prog.c \
../Stepper_prog.c \
../UART_prg.c \
../prog.c 

OBJS += \
./ADC_prg.o \
./DIO_prg.o \
./EXTI_prg.o \
./MOTOR_main.o \
./MOTOR_prog.o \
./Stepper_prog.o \
./UART_prg.o \
./prog.o 

C_DEPS += \
./ADC_prg.d \
./DIO_prg.d \
./EXTI_prg.d \
./MOTOR_main.d \
./MOTOR_prog.d \
./Stepper_prog.d \
./UART_prg.d \
./prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


