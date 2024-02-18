cmake_minimum_required(VERSION 3.22)
project(custom_c_library C)

set(CMAKE_C_STANDARD 11)

add_executable(custom_c_library main.c
        string.h
        string.c
        string.c
        dynamic_array.c
        dynamic_array.h
)
