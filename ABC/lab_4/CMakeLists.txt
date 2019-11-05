cmake_minimum_required(VERSION 3.15)
project(lab_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_4 main.c BLAS.c BLAS.h)