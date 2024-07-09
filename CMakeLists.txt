cmake_minimum_required(VERSION 3.10)
project(MyGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable target
if(WIN32)
    add_executable(MyGameApp WIN32
        src/main.cpp
        src/player.cpp
        src/pawn.cpp
    )
else()
    add_executable(MyGameApp
        src/main.cpp
        src/player.cpp
        src/pawn.cpp
    )
endif()

# Include directories
target_include_directories(MyGameApp PRIVATE include)


# Link libraries
if(WIN32)
    target_link_libraries(MyGameApp PRIVATE raylib opengl32 gdi32 winmm)
else()
    target_link_libraries(MyGameApp PRIVATE raylib GL m pthread dl rt X11)
endif()

# Compiler options
if(MSVC)
    target_compile_options(MyGameApp PRIVATE /W4) # Warning level 4
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(MyGameApp PRIVATE /O2 /MT) # Optimization and static runtime
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(MyGameApp PRIVATE /RTC1 /MTd) # Runtime checks and debug static runtime
    endif()
else()
    target_compile_options(MyGameApp PRIVATE -Wall -Wextra -O2) # Warnings and optimization for GCC/Clang
endif()