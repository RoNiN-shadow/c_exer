cmake_minimum_required(VERSION 3.10)
project(MyGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable target with WIN32 to prevent terminal window
add_executable(MyGameApp WIN32
    src/main.cpp
    src/player.cpp
    src/ball.cpp
)

# Include directories
target_include_directories(MyGameApp PRIVATE include)

# Specify the path to the raylib library
target_link_directories(MyGameApp PRIVATE ${CMAKE_SOURCE_DIR}/lib)

# Link libraries (example with raylib)
target_link_libraries(MyGameApp PRIVATE raylib opengl32 gdi32 winmm)

# Compiler options (example for MSVC and GCC/Clang)
if (MSVC)
    target_compile_options(MyGameApp PRIVATE /W4) # Warning level 4
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(MyGameApp PRIVATE /O2 /MT) # Optimization and static runtime
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(MyGameApp PRIVATE /RTC1 /MTd) # Runtime checks and debug static runtime
    endif ()
else()
    target_compile_options(MyGameApp PRIVATE -O2) # Optimization for GCC/Clang
endif ()
