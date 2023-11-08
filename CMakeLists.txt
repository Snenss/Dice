#Minimum Version of CMake
cmake_minimum_required (VERSION 3.19)

#Include libraries /pico sdk
include(pico_sdk_import.cmake)

project(JanProg_project)

pico_sdk_init()

#This creates an executable target "dice" from a single source file dice.c
add_executable(dice dice.c)


#Generates different file formats such as .uf2 .elf .bin
pico_add_extra_outputs(dice)

#Specifies libraries - flags to use when linking a given target
target_link_libraries(dice pico_stdlib)
