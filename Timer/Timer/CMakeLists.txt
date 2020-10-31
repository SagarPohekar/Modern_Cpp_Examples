# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Timer")

# Include sub-projects.
add_subdirectory ("Timer")

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED 17)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)
