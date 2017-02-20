cmake_minimum_required(VERSION 3.6)
project(Database)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES catch.hpp DatabaseTest.cpp database.h dlibrary.h record.h table.h database.cpp record.cpp table.cpp)
add_executable(Database ${SOURCE_FILES})