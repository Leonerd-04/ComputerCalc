cmake_minimum_required(VERSION 3.25)
project(Functions)

set(CMAKE_CXX_STANDARD 17)

add_executable(Functions main.cpp functions/function.h functions/polynomial.h)
