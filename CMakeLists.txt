cmake_minimum_required(VERSION 3.7)
project(HW04)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG")

set(SOURCE_FILES main.cpp)
add_executable(HW04 ${SOURCE_FILES})