cmake_minimum_required(VERSION 3.15)
project(CppFeatures)

set(CMAKE_CXX_STANDARD 17)

add_executable(CppFeatures main.cpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        stdc++fs
)