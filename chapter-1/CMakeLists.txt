cmake_minimum_required(VERSION 3.10)

# set the project name
project(chapter1_exercises)

# set the C++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED  true)

# add the executable
add_executable(removeComments ex1-23.c)
