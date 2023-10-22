################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_Program.c \
../Src/GI_Program.c \
../Src/KPAD_Program.c \
../Src/LCD_Configurations.c \
../Src/LCD_Program.c \
../Src/SS_Configurations.c \
../Src/SS_Program.c \
../Src/TIMER0_Program.c \
../Src/TIMER2_Program.c \
../Src/main.c 

OBJS += \
./Src/DIO_Program.o \
./Src/GI_Program.o \
./Src/KPAD_Program.o \
./Src/LCD_Configurations.o \
./Src/LCD_Program.o \
./Src/SS_Configurations.o \
./Src/SS_Program.o \
./Src/TIMER0_Program.o \
./Src/TIMER2_Program.o \
./Src/main.o 

C_DEPS += \
./Src/DIO_Program.d \
./Src/GI_Program.d \
./Src/KPAD_Program.d \
./Src/LCD_Configurations.d \
./Src/LCD_Program.d \
./Src/SS_Configurations.d \
./Src/SS_Program.d \
./Src/TIMER0_Program.d \
./Src/TIMER2_Program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


