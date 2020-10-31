# CMakeList.txt : CMake project for Timer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Timer "Timer.cpp" "Timer.h")

# TODO: Add tests and install targets if needed.

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED 17)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)