cmake_minimum_required(VERSION 2.8)
project(GL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Symbols/Line.cpp Symbols/Line.h Symbols/Read.cpp Symbols/Read.h Symbols/Symbol.cpp Symbols/Symbol.h)
add_executable(GL ${SOURCE_FILES})