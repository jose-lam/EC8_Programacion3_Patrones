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

    return 0;
}