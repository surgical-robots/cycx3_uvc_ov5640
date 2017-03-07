################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cy_ov5640.c \
../cycx3_uvc.c \
../cycx3_uvcdscr.c \
../cyfxtx.c 

S_UPPER_SRCS += \
../cyfx_gcc_startup.S 

OBJS += \
./cy_ov5640.o \
./cycx3_uvc.o \
./cycx3_uvcdscr.o \
./cyfx_gcc_startup.o \
./cyfxtx.o 

C_DEPS += \
./cy_ov5640.d \
./cycx3_uvc.d \
./cycx3_uvcdscr.d \
./cyfxtx.d 

S_UPPER_DEPS += \
./cyfx_gcc_startup.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=arm926ej-s -marm -mthumb-interwork -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D__CYU3P_TX__=1 -I"C:\Program Files (x86)\Cypress\EZ-USB FX3 SDK\1.3\/fw_lib/1_3_3/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=arm926ej-s -marm -mthumb-interwork -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -I"C:\Program Files (x86)\Cypress\EZ-USB FX3 SDK\1.3\/fw_lib/1_3_3/inc" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


