cmake_minimum_required(VERSION 4.0)
project(EC8_Programacion3_Patrones)

set(CMAKE_CXX_STANDARD 23)

add_executable(EC8_Programacion3_Patrones
        main.cpp
        include/expense_types.h
        include/expenses.h
        include/expense_exporters.h
        include/expense_factory.h
        include/expense_strategy.h
        include/expense_decorators.h
        include/expense_concepts.h
)

add_executable(run_tests
        tests/test_expenses.cpp
        include/expense_types.h
        include/expenses.h
        include/expense_exporters.h
        include/expense_factory.h
        include/expense_strategy.h
        include/expense_decorators.h
        include/expense_concepts.h
)