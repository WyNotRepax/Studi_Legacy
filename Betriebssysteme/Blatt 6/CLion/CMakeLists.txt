cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(include/curl)
include_directories(lib)

add_executable(CLion
        main.cpp
        lib/web_request.c
)