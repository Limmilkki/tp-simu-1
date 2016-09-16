cmake_minimum_required(VERSION 3.5)
project(tp_simu_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(tp_simu_1 ${SOURCE_FILES})