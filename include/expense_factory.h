#pragma once

#include "expense_concepts.h"

template<ExpenseExporter E, class... Args>
ExportFunction make_exporter(Args&&... args) {
    return [](const ExpenseList& expenseList) {
        return E::export_expenses(expenseList);
    };
}