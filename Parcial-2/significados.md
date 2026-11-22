# Glosario de Términos (Portugués de Brasil a Español)

Este documento contiene la traducción, explicación y justificación de los identificadores, variables y funciones personalizadas en portugués de Brasil dentro del código del **Parcial 2: Sistema de Gestión y Control de Contenedores Portuarios**.

---

## 1. Archivos y Módulos
| Nombre en Código | Traducción al Español | Descripción |
| :--- | :--- | :--- |
| `contêiner.h` / `contêiner.c` | Contenedor (`.h` y `.c`) | Módulo que define la estructura y visualización del contenedor. |
| `list.h` / `list.c` | Lista (`.h` y `.c`) | Módulo de la lista doblemente enlazada (TAD Lista Bidireccional). |

---

## 2. Tipos de Datos y Estructuras
| Nombre en Código | Traducción al Español | Descripción |
| :--- | :--- | :--- |
| `Contêiner` | Contenedor | `struct` que representa el registro de cada contenedor portuario. |
| `Nodo` | Nodo | `struct` de la lista doblemente enlazada (posee datos, `ant` y `sig`). |

---

## 3. Campos de la Estructura (`Contêiner`)
| Campo en Código | Traducción al Español | Tipo | Propósito |
| :--- | :--- | :--- | :--- |
| `id` | Identificador único | `int` | Código numérico asignado de forma automática por el sistema. |
| `tara` | Peso vacío (tara) | `float` | Peso del contenedor cuando no lleva mercancía. |
| `pesoCarga` | Peso de la carga | `float` | Peso neto de la mercancía dentro del contenedor. |
| `pesoTotal` | Peso total | `float` | Suma de `tara + pesoCarga` calculada automáticamente. |
| `custo` | Costo o precio asociado | `float` | Tarifa, flete o costo económico del contenedor. |

---

## 4. Funciones
| Función en Código | Traducción al Español | Operación del Parcial |
| :--- | :--- | :--- |
| `showContêiner(...)` | Mostrar contenedor | Imprime en pantalla los 5 campos del contenedor con formato numérico. |
| `inserirContêiner(...)` | Insertar contenedor | **Operación 1 (Inserción):** Reserva memoria dinámica (`malloc`) y enlaza el nodo al final. |
| `buscarContêiner(...)` | Buscar contenedor | **Operación 2 (Búsqueda):** Recorre la lista buscando por ID y devuelve el puntero al nodo. |
| `atualizarContêiner(...)` | Actualizar contenedor | **Operación 3 (Actualización):** Modifica la tara, carga, costo y recalcula el peso total. |
| `removerContêiner(...)` | Remover / Eliminar contenedor | **Operación 4 (Eliminación):** Desconecta los enlaces bidireccionales y libera memoria (`free`). |
| `percorrerParaFrente(...)` | Recorrer hacia adelante | Recorrido bidireccional desde la cabeza hasta el último nodo (`sig`). |
| `percorrerParaTras(...)` | Recorrer hacia atrás | Recorrido bidireccional desde el último nodo hasta la cabeza (`ant`). |
| `liberarLista(...)` | Liberar lista | Limpia y libera toda la memoria dinámica antes de salir del programa. |

---

## 5. Variables Locales y Parámetros
| Variable en Código | Traducción al Español | Uso en el Código |
| :--- | :--- | :--- |
| `novo` / `novoDado` | Nuevo / Nuevo dato | Puntero o dato al crear un nodo recién reservado con `malloc`. |
| `atual` | Actual | Puntero iterador para recorrer los nodos (`atual = atual->sig`). |
| `proximoId` | Próximo ID / Siguiente ID | Contador autoincremental para garantizar IDs únicos (1, 2, 3...). |
| `novaTara` | Nueva tara | Valor numérico ingresado para modificar la tara. |
| `novoPesoCarga` | Nuevo peso de carga | Valor numérico ingresado para modificar el peso de carga. |
| `novoCusto` | Nuevo costo | Valor numérico ingresado para modificar el costo asociado. |
| `cab` | Cabeza (`cabeça` en portugués) | Puntero al primer nodo de la lista doblemente enlazada. |
| `ant` | Anterior | Puntero al nodo previo en la lista bidireccional. |
| `sig` | Siguiente | Puntero al siguiente nodo en la lista bidireccional. |
