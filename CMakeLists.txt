# cmake_minimum_required(VERSION <specify CMake version here>)
project(Benchmark)

set(CMAKE_CXX_STANDARD 17)

add_executable(Benchmark main.cpp functions.h functions.cpp)