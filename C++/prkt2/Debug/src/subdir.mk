################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dreieck.cpp \
../src/Gitter.cpp \
../src/main.cpp \
../src/victor.cpp 

OBJS += \
./src/Dreieck.o \
./src/Gitter.o \
./src/main.o \
./src/victor.o 

CPP_DEPS += \
./src/Dreieck.d \
./src/Gitter.d \
./src/main.d \
./src/victor.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


