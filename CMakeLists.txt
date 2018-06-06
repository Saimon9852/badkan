cmake_minimum_required(VERSION 3.8)
project(badkan)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TestCase.cpp TestCase.hpp)
add_executable(badkan ${SOURCE_FILES})