#include "expenses.h"
#include <cassert>
#include <string>

void test_strategy_sort_by_amount_descending() {
    ExpenseList expenses{
    {"2026-06-01", "food", "lunch", 18.50},
    {"2026-06-02", "transport", "bus", 3.20},
    {"2026-06-03", "books", "cpp", 45.00}
    };
    auto by_amount = [](const Expense& a, const Expense& b) {
        return a.amount > b.amount;
    };
    sort_with(expenses, by_amount);
    assert(expenses.front().amount == 45.00);
    assert(expenses.back().amount == 3.20);
}