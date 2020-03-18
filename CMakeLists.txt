cmake_minimum_required(VERSION 3.15)
project(ProjetoLI2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetoLI2 main.c camadaDeDados.c camadaDeDados.h interface.c interface.h logica.c logica.h)