project(UnitTests)

set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.16)

################################
# Indx_impl
################################
include_directories(${UnitTests_SOURCE_DIR}/../service)

################################
# GTest
################################
ADD_SUBDIRECTORY(gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable( UnitTests test.cpp Dict_test.cpp FileHandler_test.cpp ../service/FileHandler.cpp ../service/Dict.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(UnitTests gtest gtest_main)
add_test( UnitTests ./UnitTests)