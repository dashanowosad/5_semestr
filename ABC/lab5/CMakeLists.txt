cmake_minimum_required(VERSION 3.15)
project(lab5 C)

set(CMAKE_C_STANDARD 11)

find_library(PTHREAD_LIBRARY pthread)

add_executable(lab5 main.c BLAS.c BLAS.h)

target_link_libraries(lab5 ${PTHREAD_LIBRARY})