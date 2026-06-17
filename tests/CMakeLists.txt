add_executable(run_tests test_expenses.cpp)

set_target_properties(run_tests PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_include_directories(run_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_test(NAME expenses_tests COMMAND run_tests)