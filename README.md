*Este proyecto ha sido desarrollado como parte del Common Core de 42 por hfandino y daherman.*

# Push_swap

---

# Descripción

**Push_swap** es un proyecto cuyo objetivo consiste en ordenar una secuencia de números enteros utilizando únicamente un conjunto limitado de operaciones sobre stacks.

A diferencia de los algoritmos clásicos de ordenación, el reto no consiste únicamente en obtener una secuencia ordenada, sino en hacerlo utilizando el menor número posible de operaciones.

Durante el desarrollo de este proyecto se trabajaron conceptos relacionados con:

* Estructuras de datos.
* Listas doblemente enlazadas.
* Complejidad algorítmica.
* Optimización de operaciones.
* Manipulación de stacks.
* Estrategias adaptativas.
* Benchmarking y análisis de rendimiento.

---

# Objetivos

El proyecto implementa distintas estrategias de ordenación para comparar su comportamiento según el nivel de desorden de la entrada.

| Estrategia | Complejidad              |
| ---------- | ------------------------ |
| Simple     | O(n²)                    |
| Intermedia | O(n√n)                   |
| Compleja   | O(n log n)               |
| Adaptativa | Dependiente del desorden |

La estrategia adaptativa selecciona automáticamente el algoritmo más adecuado en función de las características de la entrada.

---

# Operaciones permitidas

## Swap

```text
sa
sb
ss
```

Intercambia los dos primeros elementos del stack.

## Push

```text
pa
pb
```

Mueve el elemento superior de un stack al otro.

## Rotate

```text
ra
rb
rr
```

Desplaza todos los elementos una posición hacia arriba.

## Reverse Rotate

```text
rra
rrb
rrr
```

Desplaza todos los elementos una posición hacia abajo.

---

# Normalización

Antes de comenzar la ordenación, cada número recibe un índice correspondiente a su posición dentro de la secuencia ordenada.

Ejemplo:

```text
Entrada:
50 10 30

Ordenado:
10 30 50

Índices:
50 -> 2
10 -> 0
30 -> 1
```

La normalización permite trabajar con índices consecutivos en lugar de valores reales, simplificando algoritmos como Radix Sort y evitando problemas con números negativos o valores muy grandes.

---

# Estrategias implementadas

## Estrategia Simple — O(n²)

Archivo:

```text
src/strategies/simple_sort.c
```

Basada en la búsqueda repetida del valor mínimo.

Funcionamiento:

1. Localiza el elemento más pequeño.
2. Lo mueve al stack auxiliar.
3. Repite el proceso hasta vaciar el stack principal.
4. Reconstruye el stack original utilizando `pa`.

Características:

* Fácil de implementar.
* Muy eficiente para entradas pequeñas.
* Coste elevado en conjuntos grandes.

---

## Estrategia Intermedia — O(n√n)

Archivo:

```text
src/strategies/medium_sort.c
```

Implementa una estrategia basada en *chunks*.

Funcionamiento:

1. Divide la entrada en bloques de tamaño aproximado √n.
2. Envía cada bloque al stack B.
3. Reordena los elementos durante la reconstrucción.
4. Recupera los elementos al stack A.

Características:

* Menor número de operaciones que la estrategia simple.
* Muy competitiva para tamaños medianos.
* Buen equilibrio entre complejidad y rendimiento.

---

## Estrategia Compleja — O(n log n)

Archivo:

```text
src/strategies/complex_sort.c
```

Implementa Radix Sort binario sobre índices normalizados.

Funcionamiento:

Para cada bit del índice:

* Bit = 0 → `pb`
* Bit = 1 → `ra`

Al finalizar cada pasada:

```text
pa
```

recupera los elementos almacenados en B.

Características:

* Rendimiento estable.
* Escala correctamente con entradas grandes.
* Excelente comportamiento para conjuntos aleatorios.

---

## Estrategia Adaptativa

Archivo:

```text
src/strategies/adaptative_sort.c
```

La estrategia adaptativa analiza previamente el nivel de desorden de la entrada y selecciona automáticamente el algoritmo más adecuado.

Funcionamiento:

1. Calcula el índice de desorden.
2. Compara el resultado con los umbrales definidos.
3. Selecciona la estrategia correspondiente.
4. Ejecuta el algoritmo elegido.

### Umbrales utilizados

```text
Desorden < 20%       -> simple_sort
20% ≤ Desorden < 50% -> medium_sort
Desorden ≥ 50%       -> complex_sort
```

### Justificación

Los umbrales fueron seleccionados tras realizar pruebas con distintos tamaños de entrada.

* Menos del 20% suele indicar una lista casi ordenada.
* Entre el 20% y el 50% los chunks generan menos operaciones.
* Por encima del 50% Radix Sort ofrece resultados más consistentes.

---

# Índice de desorden

Antes de ordenar se calcula el nivel de desorden de la entrada.

Se contabilizan todas las inversiones presentes:

```text
a[i] > a[j]
```

para:

```text
i < j
```

La fórmula utilizada es:

```text
disorder = inversiones / pares_totales
```

Interpretación:

```text
0.00 -> completamente ordenado
1.00 -> máximo desorden posible
```

Este valor es utilizado por la estrategia adaptativa.

---

# Modo Benchmark

El proyecto incorpora un modo opcional de benchmarking mediante la flag:

```bash
./push_swap --bench <números>
```

La información se envía a **stderr** para no interferir con el flujo de operaciones utilizado por el checker.

Información mostrada:

* Porcentaje de desorden.
* Estrategia utilizada.
* Complejidad teórica.
* Número total de operaciones.
* Número de operaciones de cada tipo.

Ejemplo:

```text
[BENCH MODE]
[bench] Disorder: 52.06%
[bench] Strategy: Adaptive / O(n log n)
[bench] Total_ops: 1084
[bench] sa: 0 sb: 0 ss: 0 pa: 384 pb: 384
[bench] ra: 316 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

---

# Estructura del proyecto

```text
.
├── include
│   ├── bench_struct.h
│   ├── flag_struct.h
│   ├── node_struct.h
│   ├── parse_struct.h
│   ├── push_swap.h
│   └── sort_struct.h
├── libs
│   └── libft
├── src
│   ├── analysis
│   ├── bench
│   ├── dispatch
│   ├── operations
│   ├── parsing
│   ├── sort
│   ├── stack
│   └── strategies
├── Makefile
└── README.md
```

### include

Definición de estructuras y cabeceras del proyecto.

### analysis

Cálculo de índices, desorden y comprobación de orden.

### bench

Implementación del modo benchmark.

### dispatch

Selección y ejecución de estrategias.

### operations

Implementación de las operaciones permitidas.

### parsing

Validación de argumentos y construcción inicial de stacks.

### sort

Algoritmos para conjuntos pequeños.

### stack

Gestión de listas doblemente enlazadas.

### strategies

Implementación de las estrategias principales.

---

# Compilación

```bash
make
```

Limpiar objetos:

```bash
make clean
```

Eliminar binarios:

```bash
make fclean
```

Recompilar:

```bash
make re
```

---

# Uso

Modo adaptativo:

```bash
./push_swap 4 67 3 87 23
```

Estrategia simple:

```bash
./push_swap --simple 4 67 3 87 23
```

Estrategia intermedia:

```bash
./push_swap --medium 4 67 3 87 23
```

Estrategia compleja:

```bash
./push_swap --complex 4 67 3 87 23
```

Estrategia adaptativa:

```bash
./push_swap --adaptive 4 67 3 87 23
```

Benchmark:

```bash
./push_swap --bench 4 67 3 87 23
```

---

# Testing

Las pruebas realizadas incluyen:

* Checker oficial.
* Casos pequeños.
* Casos aleatorios de 100 elementos.
* Casos aleatorios de 500 elementos.
* Pruebas de estrés.
* Casos límite con INT_MIN e INT_MAX.
* Validación de errores.
* Valgrind.
* Benchmark.

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

# Resultados de rendimiento

### Estrategia Compleja

```text
100 números -> 1084 operaciones
500 números -> 6784 operaciones
```

### Estrategia Intermedia

```text
100 números -> ~760 - 820 operaciones
500 números -> ~7200 - 7400 operaciones
```

### Estrategia Adaptativa

```text
100 números -> ~760 - 1084 operaciones
500 números -> ~6700 - 7400 operaciones
```

Dependiendo del índice de desorden detectado.

---

# Recursos

* cppreference
* Linux Manual Pages
* GeeksForGeeks
* Stack Overflow
* The Art of Computer Programming — Donald Knuth

---

# Uso de Inteligencia Artificial

La Inteligencia Artificial fue utilizada como herramienta de apoyo para:

* Consulta de conceptos teóricos.
* Discusión de complejidad algorítmica.
* Generación de escenarios de prueba.
* Revisión de documentación.

Todas las decisiones de diseño, implementación, depuración, validación y pruebas fueron realizadas por los autores del proyecto.

---

# Contribuciones

## hfandino

* Operaciones
* sort_2
* sort_3
* sort_5
* simple_sort
* medium_sort
* complex_sort
* adaptive_sort
* Testing
* Benchmark testing
* Documentación técnica

## daherman

* Parsing
* Validación de argumentos
* Gestión de flags
* Dispatch
* Arquitectura general
* Sistema benchmark
* Integración general

---

# Aprendizajes obtenidos

Durante el desarrollo de este proyecto se reforzaron conocimientos relacionados con:

* Listas doblemente enlazadas.
* Manipulación de stacks.
* Algoritmos de ordenación.
* Complejidad algorítmica.
* Optimización de operaciones.
* Normalización de datos.
* Benchmarking.
* Instrumentación.
* Testing automatizado.
* Valgrind.
* Desarrollo colaborativo mediante Git.

