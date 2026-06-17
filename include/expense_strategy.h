#pragma once

#include <algorithm>
#include "expense_concepts.h"


void sort_with(auto& values, auto cmp)
requires SortStrategy<decltype(values), decltype(cmp)> {
    std::ranges::sort(values, cmp);
}