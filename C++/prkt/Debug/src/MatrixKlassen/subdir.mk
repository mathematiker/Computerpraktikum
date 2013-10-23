################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MatrixKlassen/main-crtp.cpp \
../src/MatrixKlassen/main.cpp 

OBJS += \
./src/MatrixKlassen/main-crtp.o \
./src/MatrixKlassen/main.o 

CPP_DEPS += \
./src/MatrixKlassen/main-crtp.d \
./src/MatrixKlassen/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/MatrixKlassen/%.o: ../src/MatrixKlassen/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


