cmake_minimum_required(VERSION 3.6)
project(LabPrograms)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(SOURCE_FILES infixtopostfix.c)

add_executable(LabPrograms ${SOURCE_FILES})