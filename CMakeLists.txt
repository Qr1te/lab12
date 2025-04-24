cmake_minimum_required(VERSION 3.29)
project(lab12 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab12 main.c
        functions.c
        functions.h
        queue.h
        tasks.c
        tasks.h)
