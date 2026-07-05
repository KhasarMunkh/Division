cmake_minimum_required(VERSION 3.20)

project(Division)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}")

# Enable position-independent code for shared libraries
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

# This is important for shared libraries on Linux to ensure that the code can be loaded at any memory address. 
add_subdirectory(Engine/vendor/spdlog)

# set GLFW options to off, see more in glfw/cmakelists.txt 
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
add_subdirectory(Engine/vendor/glfw)

add_subdirectory(Engine)
add_subdirectory(Sandbox)

# Linux runtime path (RPATH), so that the executable can find the shared libraries in the same directory
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")
