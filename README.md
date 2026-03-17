# 42 Exam Exercises

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![VS Code](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)

Colección de ejercicios algorítmicos avanzados desarrollados para la evaluación técnica de École 42. Este repositorio demuestra competencias en programación de bajo nivel, estructuras de datos complejas y diseño orientado a objetos, implementando soluciones eficientes desde cero sin dependencias externas.

---

## Features

### vect2 - Clase Vector 2D
- Implementación completa de operadores aritméticos (`+`, `-`, `*`, `+=`, `-=`, `*=`)
- Sobrecarga de operadores de incremento/decremento (pre/post-fix)
- Operadores de comparación (`==`, `!=`)
- Acceso indexado mediante `operator[]`
- Operador de negación unaria
- Integración con streams de E/S (`operator<<`)

### gameoflife - Conway's Game of Life
- Simulación del autómata celular clásico
- Sistema de entrada interactivo vía stdin (controles WASD)
- Renderizado en tiempo real en terminal
- Gestión dinámica de memoria para boards de cualquier tamaño
- Algoritmo de evolución con reglas de Conway implementado desde cero

### bigint - Enteros de Precisión Arbitraria
- Suma de enteros sin límite de tamaño
- Operadores de desplazamiento bit a bit (`<<`, `>>`)
- Operadores de incremento/decremento
- Comparaciones completas (`<`, `<=`, `>`, `>=`, `==`, `!=`)
- Almacenamiento interno mediante `std::string` para precisión ilimitada

### bsq - Biggest Square Algorithm
- Algoritmo de programación dinámica O(n²) para encontrar el cuadrado más grande
- Parser robusto de mapas con validación de entrada
- Implementación propia de `getline` para lectura eficiente
- Soporta lectura desde archivos o stdin
- Gestión de errores con mensajes descriptivos

---

## Stack Tecnológico

| Lenguaje | Uso Principal |
|----------|---------------|
| **C** | Algoritmos de bajo nivel, gestión manual de memoria |
| **C++** | Programación orientada a objetos, sobrecarga de operadores |
| **GCC/G++** | Compilación y debugging |
| **Git** | Control de versiones |

### Librerías Estándar Utilizadas
- `<iostream>`, `<ostream>`, `<string>` - C++ I/O y strings
- `<cstdlib>`, `<cstddef>` - Utilidades C estándar
- `<unistd.h>`, `<stdio.h>`, `<stdlib.h>` - System calls y I/O en C

---

## Decisiones Técnicas / Arquitectura

La elección de **C/C++ sin dependencias externas** responde a los requisitos académicos de 42, donde se prioriza el entendimiento profundo de los fundamentos computacionales sobre la productividad. Esta arquitectura impone restricciones deliberadas que fomentan:

1. **Gestión manual de memoria**: Uso explícito de `malloc`/`free` y RAII en C++, demostrando control total sobre recursos
2. **Sobrecarga de operadores en C++**: Diseño de interfaces matemáticas intuitivas que mantienen semántica de valor
3. **Algoritmos eficientes**: Implementación de soluciones óptimas (O(n²) para bsq, O(n) para operaciones aritméticas en bigint)
4. **Validación robusta**: Manejo de edge cases y errores sin excepciones (siguiendo la filosofía de 42)

El proyecto **bigint** utiliza `std::string` como contenedor interno en lugar de arrays dinámicos, aprovechando la gestión automática de memoria de C++ mientras se mantiene la precisión arbitraria. Esto representa un balance pragmático entre pureza académica y robustez de producción.

## Getting Started

### Prerrequisitos
- Compilador GCC/G++ instalado
- Git
- (Opcional) VS Code con extensión C/C++

### Instalación y Ejecución

```bash
# Clonar el repositorio
git clone https://github.com/samuelhm/42-exam-exercises.git
cd 42-exam-exercises

# Compilar y ejecutar vect2
cd vect2
g++ -std=c++11 -Wall -Wextra -Werror vect2.cpp main.cpp -o vect2
./vect2

# Compilar y ejecutar bigint
cd ../bigint
g++ -std=c++11 -Wall -Wextra -Werror bigint.cpp main.cpp -o bigint
./bigint

# Compilar y ejecutar gameoflife
cd ../gameoflife
gcc -Wall -Wextra -Werror main.c -o gameoflife
echo "wasd x" | ./gameoflife 10 10 5

# Compilar y ejecutar bsq
cd ../bsq
gcc -Wall -Wextra -Werror main.c -o bsq
./bsq bsq_test_maps/map_valid_1.txt
```

### Formato de Mapas BSQ

Los archivos de mapa deben seguir este formato:
```
5 . o x
.....
.....
..o..
.....
.....
```
Donde:
- Línea 1: `<número_de_líneas> <vacío> <obstáculo> <relleno>`
- Líneas 2-N: Mapa usando los caracteres definidos

---

## Contacto

**Samuel Hurtado** - Desarrollador de Software

- **GitHub**: [https://github.com/samuelhm/](https://github.com/samuelhm/)
- **LinkedIn**: [https://www.linkedin.com/in/shurtado-m/](https://www.linkedin.com/in/shurtado-m/)

---

*Este repositorio forma parte de mi portfolio técnico. Los ejercicios han sido desarrollados siguiendo los estándares académicos de École 42, enfocándose en código limpio, eficiente y sin fugas de memoria.*
