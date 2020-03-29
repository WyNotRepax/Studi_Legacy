cmake_minimum_required(VERSION 3.14)
project(Projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/curl)

add_executable(Projekt
        include/curl/curl.h
        include/curl/curlver.h
        include/curl/easy.h
        include/curl/mprintf.h
        include/curl/multi.h
        include/curl/stdcheaders.h
        include/curl/system.h
        include/curl/typecheck-gcc.h
        include/curl/urlapi.h
        include/web_request.h
        include/web_request.hpp
        lib/web_request.c
        simple_bot.c include/prosumer.h)
