cmake_minimum_required(VERSION 3.10)

project(LeetCode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(LeetCode src/main.cpp
    include/24.hpp)

target_include_directories(LeetCode PRIVATE include)
