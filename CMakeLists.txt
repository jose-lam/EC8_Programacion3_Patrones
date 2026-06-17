cmake_minimum_required(VERSION 3.22)
project(EC8_Programacion3_Patrones LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(EC8_Programacion3_Patrones main.cpp)
target_include_directories(EC8_Programacion3_Patrones PRIVATE include)

enable_testing()
add_subdirectory(tests)