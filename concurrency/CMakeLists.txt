cmake_minimum_required(VERSION 3.16)
project(Mutex)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mutex main.cpp RequestProcessing.h)

target_link_libraries(Mutex pthread)
