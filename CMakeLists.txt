cmake_minimum_required(VERSION 3.15)
project(PA5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA5
        concord.cpp
        grades.cpp
        listFuncs.cpp
        listFuncs.h
        Makefile
        melville.txt
        pa5list.cpp
        poe.txt
        README
        Table.cpp
        Table.h)
