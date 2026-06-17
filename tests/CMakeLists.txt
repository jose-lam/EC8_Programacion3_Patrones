add_executable(run_tests test_expenses.cpp
        test_decorator_audit_preserves_inner_export.cpp
        test_decorator_summary_adds_total.cpp
        test_factory_create_csv_exporter.cpp
        test_factory_create_json_exporter.cpp
        test_strategy_sort_by_amount_descending.cpp
        test_strategy_sort_by_category_then_date.cpp
        test_integration_export_sorted_expenses.cpp)

set_target_properties(run_tests PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_include_directories(run_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_test(NAME expenses_tests COMMAND run_tests)