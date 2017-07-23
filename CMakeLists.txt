cmake_minimum_required(VERSION 2.8)
project(MyPrograms)

#LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_PREFIX}")
set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include_directories("${PROJECT_BINARY_DIR}")

find_package(CP)
if (NOT CP_FOUND)
   message(FATAL_ERROR "failed to find libcpluff")
   return()
endif()

include_directories(${CP_INCLUDE_DIRS})


add_executable(main main.c)
target_link_libraries(main ${CP_LIBRARIES})
