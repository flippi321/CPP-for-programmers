cmake_minimum_required(VERSION 3.26)
project(Task6)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Task6a src/6a.cpp)
add_executable(Task6b src/6b.cpp)