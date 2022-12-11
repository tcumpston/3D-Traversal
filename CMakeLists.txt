cmake_minimum_required(VERSION 3.24)
project(3D_Traversal C)

set(CMAKE_C_STANDARD 11)

add_executable(3D_Traversal main.c face.h face.c cube.h cube.c exit.h letter.h letter.c word.h word.c exit.c)
