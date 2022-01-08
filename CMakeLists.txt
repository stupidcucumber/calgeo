cmake_minimum_required(VERSION 3.21)
project(calgeo)

set(CMAKE_CXX_STANDARD 17)

add_executable(calgeo main.cpp Vectors.h CONSTANTS.h ComplexNumbers.cpp ComplexNumbers.h Matrices.cpp Matrices.h Geometry.cpp Geometry.h)
