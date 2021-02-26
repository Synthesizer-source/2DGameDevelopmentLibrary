cmake_minimum_required(VERSION 3.10)

# set the project name
project(GDL)

set(SOURCE "src")
set(INCLUDE "include")

file(GLOB_RECURSE all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

add_library(GDL ${all_SRCS})

target_include_directories(GDL PUBLIC "${PROJECT_BINARY_DIR}")