cmake_minimum_required(VERSION 3.10)
project(game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(raylib REQUIRED)

include_directories(
    include
)

add_executable(game src/main.cpp src/snake.cpp)
target_link_libraries(game raylib)