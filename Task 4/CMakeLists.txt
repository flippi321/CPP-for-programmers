cmake_minimum_required(VERSION 3.26)
project(Task4)

set(CMAKE_CXX_STANDARD 17)
INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(Task4.1 src/4.1.cpp)
add_executable(Task4.2 src/4.2.cpp)
target_link_libraries(Task4.2 ${GTKMM_LIBRARIES})