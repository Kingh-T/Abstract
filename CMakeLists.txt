cmake_minimum_required(VERSION 3.7)
project(AbstracVm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IOperand.cpp IOperand.h Int32.cpp Int32.h IOfactory.cpp IOfactory.h Operand.cpp Operand.h Error.cpp Error.h)
add_executable(AbstracVm ${SOURCE_FILES})