#include "expenses.h"
#include <cassert>
#include <string>

void test_integration_export_sorted_expenses() {
    ExpenseList expenses{
    {"2026-06-01", "food", "lunch", 18.50},
    {"2026-06-02", "transport", "bus", 3.20},
    {"2026-06-03", "books", "cpp", 45.00}
    };
    auto by_amount = [](const Expense& a, const Expense& b) {
        return a.amount > b.amount;
    };
    sort_with(expenses, by_amount);
    auto exporter =
    AuditedExporter{
        SummaryExporter{
            CsvExporter{}
        }
    };
    auto output = exporter.export_expenses(expenses);
    assert(expenses.front().amount == 45.00);
    assert(output.contains("date,category,detail,amount"));
    assert(output.contains("total"));
    assert(output.contains("audit"));
}