cmake_minimum_required(VERSION 3.22)
project(DES)

set(CMAKE_CXX_STANDARD 14)

add_executable(DES main.cpp DES.h DEStable.h test.cpp)
