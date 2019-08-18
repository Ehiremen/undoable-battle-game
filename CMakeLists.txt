cmake_minimum_required(VERSION 3.14)
project(program_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(program_2 main.cpp GameClasses.hpp Stack.hpp GameLogic.hpp MoveManager.hpp)