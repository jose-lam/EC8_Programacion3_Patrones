#pragma once

#include <string>
#include <vector>
#include <functional>

struct Expense {
    std::string date;
    std::string category;
    std::string detail;
    double amount{};

    Expense(std::string date_, std::string category_, std::string detail_, double amount_): date(std::move(date_)), category(std::move(category_)), detail(std::move(detail_)), amount(amount_) {}
};

using ExpenseList = std::vector<Expense>;
using ExportFunction = std::function<std::string(const ExpenseList&)>;