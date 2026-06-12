*Este proyecto ha sido creado como parte del currículo de 42 por hfandino y daherman.*

# Push_swap

## Descripción

**Push_swap** es un proyecto del Common Core de 42 cuyo objetivo es ordenar una secuencia de números enteros utilizando únicamente un conjunto limitado de operaciones y un stack auxiliar.

A diferencia de los algoritmos de ordenación tradicionales, el reto no consiste únicamente en ordenar correctamente los datos, sino también en minimizar el número de operaciones generadas.

Este proyecto está enfocado en:

* Estructuras de datos
* Complejidad algorítmica
* Manipulación de stacks
* Técnicas de optimización
* Análisis de rendimiento
* Selección de estrategias según las características de la entrada

---

## Objetivos del proyecto

El proyecto requiere implementar múltiples estrategias de ordenación con diferentes niveles de complejidad:

| Estrategia | Complejidad Objetivo |
| ---------- | -------------------- |
| Simple     | O(n²)                |
| Intermedia | O(n√n)               |
| Compleja   | O(n log n)           |
| Adaptativa | Selección dinámica   |

La estrategia adaptativa analiza el nivel de desorden de la entrada y selecciona automáticamente el algoritmo más adecuado.

---

## Operaciones permitidas

### Swap

```text
sa
sb
ss
```

Intercambia los dos primeros elementos de uno o ambos stacks.

### Push

```text
pa
pb
```

Mueve el elemento superior de un stack al otro.

### Rotate

```text
ra
rb
rr
```

Desplaza todos los elementos una posición hacia arriba.

### Reverse Rotate

```text
rra
rrb
rrr
```

Desplaza todos los elementos una posición hacia abajo.

---

## Normalización

Antes de ordenar, cada valor recibe un índice correspondiente a su posición dentro de la secuencia ordenada.

Ejemplo:

```text
Original:
50 10 30

Ordenado:
10 30 50

Índices:
50 -> 2
10 -> 0
30 -> 1
```

Trabajar con índices normalizados simplifica la implementación de Radix Sort y evita problemas relacionados con el rango de valores de entrada.

---

## Estrategias implementadas

### Estrategia Simple — O(n²)

Implementada en:

```text
src/strategies/simple_sort.c
```

Esta estrategia busca repetidamente el elemento más pequeño, lo mueve temporalmente al stack B y posteriormente reconstruye el stack A en orden.

Conceptualmente es similar a un Selection Sort adaptado a las restricciones de Push_swap.

---

### Estrategia Intermedia — O(n√n)

Implementada en:

```text
src/strategies/medium_sort.c
```

Esta estrategia utiliza particiones por bloques o *chunks*.

El stack se divide en grupos de tamaño aproximado √n. Los elementos se distribuyen progresivamente al stack B y posteriormente se reconstruyen en orden.

---

### Estrategia Compleja — O(n log n)

Implementada en:

```text
src/sort/complex_sort.c
```

Esta estrategia utiliza Radix Sort binario sobre índices normalizados.

Para cada bit:

1. Los elementos con bit 0 se envían al stack B.
2. Los elementos con bit 1 permanecen en el stack A mediante rotaciones.
3. Los elementos vuelven al stack A.
4. El proceso se repite para el siguiente bit.

Esta estrategia proporciona un rendimiento consistente para conjuntos grandes de datos.

---

### Estrategia Adaptativa

Implementada en:

```text
src/strategies/adaptative_sort.c
```

La estrategia adaptativa calcula previamente el porcentaje de desorden de la entrada y selecciona automáticamente el algoritmo más adecuado.

Umbrales utilizados:

```text
Desorden < 20%      -> simple_sort
20% - 49%           -> medium_sort
50% o superior      -> complex_sort
```

Estos valores siguen el modelo adaptativo propuesto por el enunciado del proyecto.

---

## Justificación de las estrategias

Se implementaron tres estrategias con diferentes niveles de complejidad para adaptarse a distintos escenarios de entrada.

* La estrategia simple ofrece una solución sencilla basada en la extracción sucesiva del mínimo.
* La estrategia intermedia utiliza particiones por chunks para reducir el número de operaciones en conjuntos de tamaño medio.
* La estrategia compleja utiliza Radix Sort sobre índices normalizados, proporcionando un rendimiento estable para conjuntos grandes.

La estrategia adaptativa selecciona automáticamente una de ellas según el nivel de desorden detectado en la entrada.

---

## Cálculo del desorden

El índice de desorden se calcula contando cuántos pares de elementos aparecen en un orden incorrecto respecto al resultado final esperado.

Ejemplo:

```text
1 2 5 3 4

Solo existe una inversión:

5 > 3
```

El porcentaje obtenido permite clasificar la entrada como poco desordenada, moderadamente desordenada o altamente desordenada, determinando así la estrategia que se ejecutará.

---

## Estructura del proyecto

```text
src/
├── analysis
├── dispatch
├── operations
├── parsing
├── sort
├── stack
└── strategies
```

### analysis

* Generación de índices
* Cálculo del desorden
* Verificación de orden

### dispatch

* Selección y ejecución de estrategias

### operations

* Implementación de todas las operaciones permitidas

### parsing

* Validación de argumentos
* Construcción inicial de los stacks

### sort

* Algoritmos de ordenación especializados

### stack

* Utilidades para la gestión de listas enlazadas

### strategies

* Implementación de las distintas estrategias de ordenación

---

## Compilación

Compilar el proyecto:

```bash
make
```

Limpiar archivos objeto:

```bash
make clean
```

Eliminar todos los binarios:

```bash
make fclean
```

Recompilar completamente:

```bash
make re
```

---

## Uso

### Modo adaptativo (por defecto)

```bash
./push_swap 4 67 3 87 23
```

### Estrategia simple

```bash
./push_swap --simple 4 67 3 87 23
```

### Estrategia intermedia

```bash
./push_swap --medium 4 67 3 87 23
```

### Estrategia compleja

```bash
./push_swap --complex 4 67 3 87 23
```

### Estrategia adaptativa

```bash
./push_swap --adaptive 4 67 3 87 23
```

---

## Testing

La validación se realizó utilizando el checker proporcionado para el proyecto.

Ejemplo:

```bash
ARG="5 4 3 2 1"
./push_swap --adaptive $ARG | ./checker_linux $ARG
```

Resultado esperado:

```text
OK
```

---

## Resultados de rendimiento

| Estrategia | 100 números      | 500 números      |
| ---------- | ---------------- | ---------------- |
| Compleja   | 1084 operaciones | 6784 operaciones |
| Intermedia | 783 operaciones  | 7349 operaciones |
| Adaptativa | 799 operaciones  | 6784 operaciones |

Todos los resultados obtenidos se encuentran dentro de los objetivos de rendimiento definidos por el proyecto.

---

## Recursos

### Documentación

* cppreference
* GeeksForGeeks
* Stack Overflow
* Linux Manual Pages

### Referencias algorítmicas

* Radix Sort
* Selection Sort
* Chunk Sorting
* Análisis de complejidad Big O

---

## Uso de Inteligencia Artificial

La Inteligencia Artificial fue utilizada como herramienta de apoyo para:

* Consulta de conceptos teóricos.
* Revisión de complejidad algorítmica.
* Análisis de estrategias de ordenación.
* Generación de escenarios de prueba.
* Mejora de la documentación.

Todo el código fue diseñado, implementado, depurado y validado por los autores del proyecto.

---

## Contribución de los integrantes

### hfandino

* Operaciones del proyecto
* sort_2, sort_3, sort_5
* complex_sort (Radix)
* simple_sort
* medium_sort
* adaptive_sort

### daherman

* Sistema de parsing
* Validación de argumentos
* Gestión de flags
* Construcción de stacks
* Integración del dispatch
* Arquitectura general del proyecto

---

## Aprendizajes obtenidos

Durante este proyecto se reforzaron conocimientos relacionados con:

* Listas enlazadas
* Manipulación de stacks
* Algoritmos de ordenación
* Análisis de complejidad
* Optimización de operaciones
* Validación de entradas
* Testing a gran escala
* Desarrollo colaborativo mediante Git

Push_swap fue nuestra primera experiencia implementando múltiples algoritmos para resolver un mismo problema y seleccionando dinámicamente la solución más adecuada según las características de la entrada.

