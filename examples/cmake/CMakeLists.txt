# Top most CMakeLists.txt must start by specifying a minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Start a project
project(Tutorial VERSION 1.0)
# CMake defines Tutorial_VERSION_MAJOR and Tutorial_VERSION_MINOR behind the scenes

# tutorial.cxx is using Cpp 11 functionality
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use configure_file to configure and copy TutorialConfig.h.in to
# TutorialConfig.h
configure_file(TutorialConfig.h.in TutorialConfig.h)
# It will substitute variable values referenced as @VAR@, ${VAR}, 
# CACHE{VAR} or $ENV{VAR} in the input file content

# Add MathFunctions to this project
add_subdirectory(MathFunctions)

# Tell CMake to create an executable using the specified source code files.
add_executable(tutorial tutorial.cxx)

# Link the Math library to our executable
target_link_libraries(tutorial PUBLIC MathFunctions)

# 1. The new TutorialConfig.h will be written into the project directory,
# so add that directory to the list of paths to search for include files.
# Use target_include_directories to include ${PROJECT_BINARY_DIR}
# 2. Specify the library's header file location
target_include_directories(tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions")
# Notes
# PROJECT_BINARY_DIR is the binary directory of the most recent project() command.
# PROJECT_SOURCE_DIR is a path to the project source