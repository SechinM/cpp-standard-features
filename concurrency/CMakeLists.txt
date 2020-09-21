cmake_minimum_required(VERSION 3.16)
project(MutexTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(MutexTest main.cpp RequestProcessing.h)

target_link_libraries(MutexTest pthread)
