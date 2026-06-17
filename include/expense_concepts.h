#pragma once

#include <ranges>
#include "expense_types.h"

template<class T>
concept ExpenseExporter =
requires(T exporter, const ExpenseList& expenses) {
    { exporter.export_expenses(expenses) } -> std::same_as<std::string>;
};

template<class R, class Cmp>
concept SortStrategy =
std::ranges::random_access_range<R> &&
std::sortable<std::ranges::iterator_t<R>, Cmp>;