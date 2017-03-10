cmake_minimum_required (VERSION 2.6)

include(linux-gcc-32-config.cmake)

project (HelloWorld)

add_executable(helloworld helloworld.cpp main.cpp)