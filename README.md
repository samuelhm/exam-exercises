# Exam Exercises

[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https:/README.md creado correctamente en `/home/shurtado/readmes/exam-exercises/README.md`.
/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Algorithms](https://img.shields.io/badge/Algorithms-FF6F00?style=flat&logo=bookstack&logoColor=white)](#)
[![Data Structures](https://img.shields.io/badge/Data_Structures-3776AB?style=flat&logoColor=white)](#)
[![Problem Solving](https://img.shields.io/badge/Problem_Solving-8B5CF6?style=flat&logoColor=white)](#)

Colección de ejercicios de algoritmos y estructuras de datos implementados en C y C++, diseñados para demostrar dominio de programación de bajo nivel, manejo de memoria manual y técnicas de optimización.

## Características Principales

- **BigInt**: Implementación completa de enteros de precisión arbitraria con sobrecarga de operadores aritméticos, bitwise y de comparación.
- **Vect2**: Clase vector 2D con operadores matemáticos sobrecargados para álgebra vectorial.
- **Game of Life**: Simulación del autómata celular de Conway con renderizado en terminal.
- **BSQ**: Algoritmo O(n) para encontrar el cuadrado más grande libre de obstáculos en un mapa (Dynamic Programming).

## Stack Tecnológico

| Tecnología | Uso |
|------------|-----|
| C (C11) | Implementación de bajo nivel, gestión manual de memoria |
| C++ (C++17) | Programación orientada a objetos, templates, sobrecarga de operadores |
| GCC/g++ | Compilación y debugger |

## Decisiones Técnicas

El stack C/C++ fue elegido intencionalmente para estos ejercicios de examen: permite demostrar competencias fundamentales de ingeniería de software que suelen evaluarse en procesos de reclutamiento técnico —gestión manual de memoria, aritmética de punteros, sobrecarga de operadores y optimización algorítmica. La implementación manual de `getline` en BSQ y el uso de programación dinámica con tabulación evidencian comprensión profunda de estructuras de datos y eficiencia computacional.

## Arquitectura

```mermaid
flowchart TD
    subgraph C++ ["C++ Modules"]
        BIGINT[BigInt<br/>Arbitrary Precision Integers]
        VECT2[Vect2<br/>2D Vector Algebra]
    end
    
    subgraph C ["C Modules"]
        GOL[Game of Life<br/>Cellular Automaton]
        BSQ[BSQ Algorithm<br/>Dynamic Programming]
    end
    
    BIGINT --> OPS[Operator Overloading<br/>+, <<, >>, ++, ==]
    VECT2 --> MATH[Math Operators<br/>+, -, *, []]
    GOL --> GRID[Grid Processing<br/>Board Iteration]
    BSQ --> DP[DP Matrix<br/>O n Complexity]
```

## Instalación y Uso

### Requisitos
- GCC o g++ compilador

### Compilar y ejecutar

```bash
# BigInt
g++ -std=c++17 bigint/main.cpp bigint/bigint.cpp -o bigint_demo && ./bigint_demo

# Vect2
g++ -std=c++17 vect2/main.cpp vect2/vect2.cpp -o vect2_demo && ./vect2_demo

# Game of Life
gcc gameoflife/main.c -o gameoflife && ./gameoflife 20 20 10 < input_file

# BSQ
gcc bsq/main.c -o bsq && ./bsq bsq/bsq_test_maps/map_valid_1.txt
```

---

## Contacto

[![GitHub](https://img.shields.io/badge/GitHub-samuelhm-181717?style=flat&logo=github)](https://github.com/samuelhm/)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-shurtado--m-0A66C2?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/shurtado-m/)