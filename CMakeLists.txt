cmake_minimum_required(VERSION 3.27)
project(CSI2320_ProjectFive)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSI2320_ProjectFive
        CityClock.cpp
        CityClock.h
        main.cpp)
