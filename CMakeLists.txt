cmake_minimum_required(VERSION 3.16)
project(game-of-life C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(lib/raylib)

add_executable(game-of-life src/main.c)

target_link_libraries(game-of-life PRIVATE raylib)
