#pragma once

#include <chrono>
#include <format>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "expense_concepts.h"

template<ExpenseExporter Inner>
struct AuditedExporter {
    Inner inner;

    [[nodiscard]] std::string export_expenses(const ExpenseList& expenses) const {
        auto ahora_utc = std::chrono::system_clock::now();
        std::chrono::zoned_time tiempo_lima{"America/Lima", ahora_utc};
        std::time_t t = std::chrono::system_clock::to_time_t(tiempo_lima.get_sys_time());
        std::tm tm_local = *std::localtime(&t);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm_local);
        std::string fecha_hora(buffer);

        std::string base_export = inner.export_expenses(expenses);

        std::string audit_log = "[audit] Exportacion realizada " + fecha_hora + "\n";

        return audit_log + base_export + "\n";
    }
};

template<ExpenseExporter Inner>
struct SummaryExporter {
    Inner inner;
    [[nodiscard]] std::string export_expenses(const ExpenseList& expenses) const {
        std::string base_export = inner.export_expenses(expenses);
        std::string summary_export = "[summary]\n";
        std::unordered_map<std::string, double> summary;
        double sum = 0;
        for (const auto& e : expenses) {
            summary[e.category] += e.amount;
            sum += e.amount;
        }
        auto max_pair = std::ranges::max_element(summary, [](const auto& a, const auto& b) {
        return a.second < b.second; });

        summary_export += "El total gastado es: " + std::to_string(sum);
        summary_export += "\nLa categoria con mayor gasto: " + max_pair->first + "\n";

        return summary_export + base_export;
    }
};