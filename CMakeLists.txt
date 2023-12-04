#Minimum Version of CMake
cmake_minimum_required (VERSION 3.19)

#Include libraries /pico sdk
include(pico_sdk_import.cmake)

include(pico_extras_import.cmake)

project(JanProg_project)

pico_sdk_init()

#This creates an executable target "dice" from source files
add_executable(dice dice.c dice_hardware.c)


#Generates different file formats such as .uf2 .elf .bin
pico_add_extra_outputs(dice)

#Specifies libraries - flags to use when linking a given target
target_link_libraries(dice pico_stdlib hardware_sleep) 

