#include "expenses.h"
#include <cassert>
#include <string>
#include <tuple>

void test_strategy_sort_by_category_then_date() {
    ExpenseList expenses{
    {"2026-06-03", "transport", "bus", 3.20},
    {"2026-06-01", "books", "cpp", 45.00},
    {"2026-06-02", "books", "algorithms", 38.00}
    };
    auto by_category_then_date = [](const Expense& a, const Expense& b) {
        return std::tie(a.category, a.date) < std::tie(b.category, b.date);
    };
    sort_with(expenses, by_category_then_date);
    assert(expenses[0].category == "books");
    assert(expenses[0].date == "2026-06-01");
    assert(expenses[2].category == "transport");
}
