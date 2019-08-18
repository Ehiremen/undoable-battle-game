cmake_minimum_required(VERSION 3.14)
project(undoable_gaming)

set(CMAKE_CXX_STANDARD 11)

add_executable(undoable_gaming main.cpp GameClasses.hpp Stack.hpp GameLogic.hpp MoveManager.hpp)
