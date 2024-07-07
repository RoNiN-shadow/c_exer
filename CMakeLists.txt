cmake_minimum_required(VERSION 3.10)
project(CppRaylibGame)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)  # This assumes 'include' contains 'raylib.h'

# Library directories (if needed)
link_directories(lib)

add_executable(game WIN32  # Add WIN32 here
    src/main.cpp
    src/player.cpp
    src/ball.cpp
)

# Link libraries
target_link_libraries(game raylib opengl32 gdi32 winmm)

# Compiler options (adjust as needed)
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(game PRIVATE /W4)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(game PRIVATE /O2 /MT)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(game PRIVATE /RTC1 /MTd)
    endif ()
else()
    target_compile_options(game PRIVATE -O2 -static)
    # Remove -mwindows from here as it's not needed with WIN32
endif ()

# Set the subsystem to Windows
set_target_properties(game PROPERTIES
    WIN32_EXECUTABLE TRUE
)