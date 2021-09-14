cmake_minimum_required(VERSION 3.8)

set(this uri)

project(${this})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)


set(source
        source/Uri.cpp
    )

add_library(${this} SHARED ${source})

target_include_directories(${this} PUBLIC include)

# add_subdirectory(tests)