################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../ChatClient.o \
../ChatServer.o \
../Feld.o \
../GameClient.o \
../GameServer.o \
../MinesMulti.o \
../main.o \
../moc_Feld.o \
../moc_MinesMulti.o 

CPP_SRCS += \
../ChatClient.cpp \
../ChatServer.cpp \
../Feld.cpp \
../GameClient.cpp \
../GameServer.cpp \
../MinesMulti.cpp \
../main.cpp \
../moc_Feld.cpp \
../moc_MinesMulti.cpp 

OBJS += \
./ChatClient.o \
./ChatServer.o \
./Feld.o \
./GameClient.o \
./GameServer.o \
./MinesMulti.o \
./main.o \
./moc_Feld.o \
./moc_MinesMulti.o 

CPP_DEPS += \
./ChatClient.d \
./ChatServer.d \
./Feld.d \
./GameClient.d \
./GameServer.d \
./MinesMulti.d \
./main.d \
./moc_Feld.d \
./moc_MinesMulti.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


