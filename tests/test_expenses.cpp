void test_strategy_sort_by_amount_descending();
void test_strategy_sort_by_category_then_date();
void test_factory_create_csv_exporter();
void test_factory_create_json_exporter();
void test_decorator_audit_preserves_inner_export();
void test_decorator_summary_adds_total();
void test_integration_export_sorted_expenses();

int main() {
    test_strategy_sort_by_amount_descending();
    test_strategy_sort_by_category_then_date();
    test_factory_create_csv_exporter();
    test_factory_create_json_exporter();
    test_decorator_audit_preserves_inner_export();
    test_decorator_summary_adds_total();
    test_integration_export_sorted_expenses();
    return 0;
}