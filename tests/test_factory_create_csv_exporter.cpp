#include "expenses.h"
#include <cassert>
#include <string>

void test_factory_create_csv_exporter() {
    ExpenseList expenses{
    {"2026-06-01", "food", "lunch", 18.50},
    {"2026-06-02", "transport", "bus", 3.20}
    };
    auto exporter = make_exporter<CsvExporter>();
    auto output = exporter(expenses);
    assert(output.contains("date,category,detail,amount"));
    assert(output.contains("food"));
    assert(output.contains("transport"));
}
