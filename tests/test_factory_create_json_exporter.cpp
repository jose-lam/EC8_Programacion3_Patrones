#include "expenses.h"
#include <cassert>
#include <string>

void test_factory_create_json_exporter() {
    ExpenseList expenses{
    {"2026-06-01", "food", "lunch", 18.50}
    };
    auto exporter = make_exporter<JsonExporter>();
    auto output = exporter(expenses);
    assert(output.contains("\"category\""));
    assert(output.contains("\"food\""));
    assert(output.contains("\"amount\""));
}
