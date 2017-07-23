cmake_minimum_required(VERSION 2.8)

project(tests)

add_definitions("-g")

include_directories(../)

set(COMMON_SRC "../list.c"
               "../dlist.c")

add_executable(frames frames.c ${COMMON_SRC})
