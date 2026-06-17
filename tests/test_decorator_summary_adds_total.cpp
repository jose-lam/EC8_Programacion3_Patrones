#include "expenses.h"
#include <cassert>
#include <string>

void test_decorator_summary_adds_total() {
    ExpenseList expenses{
    {"2026-06-01", "food", "lunch", 18.50},
    {"2026-06-02", "transport", "bus", 3.20}
    };
    SummaryExporter exporter{TextExporter{}};
    auto output = exporter.export_expenses(expenses);
    assert(output.contains("food"));
    assert(output.contains("total"));
    assert(output.contains("21.7") || output.contains("21.70"));
}
