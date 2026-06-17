#include "expenses.h"
#include <cassert>
#include <string>

void test_decorator_audit_preserves_inner_export() {
    ExpenseList expenses{
    {"2026-06-01", "food", "lunch", 18.50},
    {"2026-06-02", "transport", "bus", 3.20}
    };
    AuditedExporter exporter{CsvExporter{}};
    auto output = exporter.export_expenses(expenses);
    assert(output.contains("date,category,detail,amount"));
    assert(output.contains("transport"));
    assert(output.contains("audit"));
}