cmake_minimum_required (VERSION 2.6)

#include(linux-gcc-32-config.cmake)

include(linux-gcc-5-32-config.cmake)

project (HelloWorld)

add_executable(helloworld helloworld.cpp main.cpp)

add_executable(base main_base.cpp)

add_executable(derive main_derive.cpp)

add_executable(myvec ../cpp/advance/myvec.cpp)