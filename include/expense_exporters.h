#pragma once

#include <string>
#include "expense_types.h"


struct CsvExporter {
    [[nodiscard]] static std::string export_expenses(const ExpenseList& expenseList) {
        std::string result;
        std::string delimiter = " , ";
        for (const auto& e : expenseList) {
            result += e.date + delimiter;
            result += e.category + delimiter;
            result += e.detail + delimiter;
            result += std::to_string(e.amount);
            result += "\n";
        }
        return result;
    }
};

struct JsonExporter {
    [[nodiscard]] static std::string export_expenses(const ExpenseList& expenseList) {
        if (expenseList.empty()) {
            return "{\n  \"expenses\": []\n}";
        }

        std::string result;
        result += "{\n  \"expenses\": [\n";
        for (const auto& e : expenseList) {
            result += "    {\n";
            result += R"(      "date": ")" + e.date + "\",\n";
            result += R"(      "category": ")" + e.category + "\",\n";
            result += R"(      "detail": ")" + e.detail + "\",\n";
            result += R"(      "amount":")" + std::to_string(e.amount) + "\n";
            result += "    },";
        }
        result.pop_back();
        result += "  ]\n}";
        return result;
    }
};

struct TextExporter {
    [[nodiscard]] static std::string export_expenses(const ExpenseList& expenseList) {
        std::string vacio = "No hay expenses";
        if (expenseList.empty()) {
            return vacio;
        }
        std::string result;
        int i = 1;
        for (const auto& e : expenseList) {
            result += std::to_string(i) + ". En la fecha " + e.date + " hiciste un expense de " + std::to_string(e.amount) + " en la categoria " + e.category + " cuyo detalle es " + e.detail + "\n";
            i++;
        }
        return result;
    }
};