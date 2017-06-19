cmake_minimum_required(VERSION 3.7)
project(HW04)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG")

set(SOURCE_FILES test1.cpp Company.h Enigma.h EscapeRoom.c EscapeRoom.h EscapeRoomWrapper.h Exceptions.h mtmtest.h list_example.cpp EscapeRoomWrapper.cpp)
add_executable(HW04 ${SOURCE_FILES})