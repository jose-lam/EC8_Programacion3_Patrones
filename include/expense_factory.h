#pragma once

#include "expense_concepts.h"

template<ExpenseExporter E, class... Args>
auto make_exporter(Args&&... args) {
    return [exporter = E{std::forward<Args>(args)...}](const ExpenseList& expenseList) {
        return exporter.export_expenses(expenseList);
    };
}