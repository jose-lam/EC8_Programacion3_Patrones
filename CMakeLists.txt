cmake_minimum_required(VERSION 3.22)
project(EC8_Programacion3_Patrones LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(EC8_Programacion3_Patrones
        main.cpp
)
target_include_directories(EC8_Programacion3_Patrones PRIVATE include)

add_executable(run_tests
        tests/test_expenses.cpp
)
target_include_directories(run_tests PRIVATE include)

enable_testing()
add_test(NAME expenses_tests COMMAND run_tests)