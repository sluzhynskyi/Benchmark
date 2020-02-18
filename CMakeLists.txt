# cmake_minimum_required(VERSION <specify CMake version here>)
project(Benchmark)

set(CMAKE_CXX_STANDARD 17)

add_executable(Benchmark src/main.cpp src/functions.h src/functions.cpp)