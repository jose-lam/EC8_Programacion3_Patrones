#include <iostream>

#include "include/expenses.h"

int main() {
    // 1. Construir ExpenseList con 5 gastos de muestra
    Expense e1 = Expense("2026-01-10", "food", "Compra de la semana en supermercado", 145.50);
    Expense e2 = Expense("2025-02-20", "transport", "Uber al aeropuerto", 42.90);
    Expense e3 = Expense("2025-05-30", "books", "Libro 'Clean Code' en Amazon", 38.99);
    Expense e4 = Expense("2025-09-09", "travel", "Vuelo de ida y vuelta a Cusco", 185.00);
    Expense e5 = Expense("2025-12-16", "food", "Cena por aniversario en restaurante", 120.30);
    ExpenseList expenses = {e3, e1, e5, e2, e4};

    // 2. Uso de Exporters con std::cout
    std::cout << CsvExporter::export_expenses(expenses) << std::endl;
    std::cout << JsonExporter::export_expenses(expenses) << std::endl;
    std::cout << TextExporter::export_expenses(expenses) << std::endl;

    // 3. sort_with con comparador por monto (mayor→menor)
    auto monto_mayor = [](const Expense &e1, const Expense &e2)->bool {
        return e1.amount > e2.amount;
    };
    sort_with(expenses, monto_mayor);
    // 4. Mostrar lista ordenada
    std::cout << CsvExporter::export_expenses(expenses) << std::endl;
    // 5. make_exporter<TextExporter>()  → imprimir resultado
    auto funcText = make_exporter<TextExporter>();
    std::cout << funcText(expenses) << std::endl;
    // 6. Componer AuditedExporter{ SummaryExporter{ JsonExporter{} } }
    //    → export_expenses → imprimir resultado
    std::cout << AuditedExporter{ SummaryExporter{CsvExporter{}} }.export_expenses(expenses) << std::endl;
    // 7. sort_with con comparador por categoría+fecha y exportar a texto

    return 0;
}