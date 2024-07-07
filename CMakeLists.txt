cmake_minimum_required(VERSION 3.10)
project(CppRaylibGame)

#C++ standart
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)

#include directories
include_directories(include)

#library directories
link_directories(lib)

add_executable(game
    src/main.cpp
    src/player.cpp
    src/ball.cpp
)

#link libraries
target_link_libraries(game raylib opengl32 gdi32 winmm)

# compiler options
target_compile_options(game PRIVATE -O2 -static -mwindows)