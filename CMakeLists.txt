cmake_minimum_required(VERSION 3.7)
project(HW04)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS  "-std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG")

#Whole Program
#set(SOURCE_FILES test1.cpp Company.h Enigma.h EscapeRoom.c EscapeRoom.h EscapeRoomWrapper.h Exceptions.h mtmtest.h list_example.cpp EscapeRoomWrapper.cpp Enigma.cpp)


#Test Wrapper And Enigma
#set(SOURCE_FILES Enigma.h EscapeRoom.c EscapeRoom.h EscapeRoomWrapper.h Exceptions.h mtmtest.h EscapeRoomWrapper.cpp Enigma.cpp EscapeRoomWrapper_Test.cpp ScaryRoom.cpp ScaryRoom.h KidsRoom.cpp KidsRoom.h KidsRoom_test.cpp)

#List
#set(SOURCE_FILES list.h list_test.cpp Exceptions.h)

#Test Enigma
#set(SOURCE_FILES Enigma.h Enigma.cpp Enigma_test.cpp list.h)
#set(SOURCE_FILES Exceptions.h list_test.cpp list.h)

#test KidsRoom
#set(SOURCE_FILES KidsRoom.cpp KidsRoom_test.cpp KidsRoom.h)

#test company
set(SOURCE_FILES Company.h Company.cpp Company_test.cpp Company.cpp Company_test.cpp Enigma.h Enigma.cpp KidsRoom.h KidsRoom.cpp ScaryRoom.h ScaryRoom.cpp EscapeRoomWrapper.h EscapeRoomWrapper.cpp EscapeRoom.h EscapeRoom.c)

add_executable(HW04 ${SOURCE_FILES})