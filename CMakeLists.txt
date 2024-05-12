cmake_minimum_required(VERSION 3.7)

project(EssaiWeakPtr)

option(WEAKPTR "Using weak_ptr" ON)
if(WEAKPTR)
    MESSAGE(STATUS "Using weak_ptr")
    add_definitions(-DWEAKPTR)
endif()

add_executable(essai_weak_ptr
  main.cpp
  bus_line.cpp
)