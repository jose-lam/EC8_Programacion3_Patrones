### ¿Qué patrón desacopla qué parte del diseño?

**Factory Method**: Desacopla la instanciación de los exportadores de la lógica de uso.

**Decorator**: Desacopla la extensión de funcionalidades (como auditoría o resumen) de la implementación base del exportador.

**Strategy**: Desacopla el algoritmo de ordenamiento de la estructura de datos que se está procesando, permitiendo variar el criterio de orden sin alterar la lista de gastos.


## Descripción General
**Expense System** es un sistema modular robusto desarrollado en **C++20** diseñado para la gestión, ordenación y exportación avanzada de listas de gastos. Se aprovecha las capacidades de la programación moderna en C++, tales como *Concepts*, *Templates* avanzadas y el patrón de diseño *Decorator*, para ofrecer una solución altamente extensible, eficiente y con tipado seguro en tiempo de compilación.

---

## Características Principales

| Característica           | Descripción                                                                                                                                                                                                    |
|:-------------------------|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Flexibilidad**         | Soporte nativo y extensible para múltiples formatos de exportación como `CSV`, `JSON` y `Texto Plano`.                                                                                                         |
| **Extensibilidad**       | Arquitectura basada en el patrón **Decorador**, permitiendo añadir capas de funcionalidad adicionales (como auditorías detalladas o resúmenes) de forma dinámica sobre cualquier exportador base. |
| **Tipado Seguro**        | Implementación estricta de **C++20 Concepts** para validar las interfaces en tiempo de compilación, garantizando la compatibilidad absoluta entre componentes y reduciendo errores de diseño.                  |
| **Factoría Funcional** | Proporciona la utilidad estandarizada `make_exporter` para instanciar de manera limpia, desacoplada y sencilla diferentes configuraciones de exportadores.                                                     |

---

## Estructura del Proyecto
```text
src/
├── expense_types.h       # Estructuras de datos base (Expense) y alias globales.
├── expense_concepts.h    # Restricciones de compilación (Concepts) para exportadores y ordenamiento.
├── expense_exporters.h   # Implementaciones base de exportación (CSV, JSON, Texto).
├── expense_decorators.h  # Decoradores de comportamiento (Auditoría, Resumen).
├── expense_strategy.h    # Estrategias y algoritmos de ordenamiento (Por fecha, monto, categoría).
└── expense_factory.h     # Factoría funcional para instanciación mediante `make_exporter`.