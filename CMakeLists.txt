cmake_minimum_required(VERSION 3.10)

# Project Name
project(StrassenCPP VERSION 1.0)

# Specified Standard for C++ (Using 23 for overall support (MSCV 19.44 doesnt support 26), but 20 or 11 could be used.)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Executable
add_executable(StrassenCPP main.cpp)

# Matrix Library.
add_subdirectory(Matrix)
target_link_libraries(StrassenCPP PUBLIC Matrix)

# Included Directories
target_include_directories(StrassenCPP PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Matrix"
                          )