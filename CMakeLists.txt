cmake_minimum_required(VERSION 3.27)
project(catering_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(catering)

add_executable(catering_cpp
        catering/catering.c
        catering/catering.cpp
        catering/catering.h
        catering/main.cpp)
