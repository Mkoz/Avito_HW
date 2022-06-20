cmake_minimum_required(VERSION 3.16)
project(Avito_HW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2")
add_executable(Avito_HW main.cpp service/FileHandler.cpp service/Dict.cpp)