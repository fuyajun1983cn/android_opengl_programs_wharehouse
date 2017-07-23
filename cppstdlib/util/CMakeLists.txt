cmake_minimum_required(VERSION 2.8)

project(cppstdlib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

#pair
add_executable(pair1 pair1.cpp)
add_executable(pair2 pair2.cpp)
