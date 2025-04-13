# Evaluacion de Polinomios



Programa en C++ que utiliza dos métodos de evaluación de Polinomimos:

**1. Método estándar (Tradicional)**  

**2. Método de Horner**

Se lleva a cabo una prueba para cada método, comenzando con polinomios cuyo grado aumenta en incrementos de 10, desde 10 hasta 1000. Los coeficientes de dichos polinomios se generan aleatoriamente dentro del rango [-10, 10], excluyendo el valor cero.

Se evalúan estos polinomios un total de 1000 veces en un punto **x ≠ 0** que, al igual que los coeficientes, es generado aleatoriamente en el mismo rango.

Al final, se imprimen los promedios para cada grado en un archivo CSV.


# Compilador

- **GCC (GNU Compiler Collection)**



# Instrucciones de compilación y ejecución:

1. Clonar el repositorio
``` sh
git clone https://github.com/mocejo/Evaluacion-de-Polinomios.git
```
2. Entrar al directorio del proyecto
```sh
cd Evaluacion-de-Polinomios
```
3. Compilar el código 
```sh
g++ "Archivo CPP/EvaluacionDePolinomios.cpp" -o EvaluacionDePolinomios
```
4. Ejecutar código
```sh
./EvaluacionDePolinomios
```
**Forma práctica:**  

Descargar el archivo ```EvaluacionDePolinomios.cpp``` y compilar desde un IDE a su preferencia.





# Descripción de los métodos

- **Método estándar:**
El método tradicional evalúa un polinomio utilizando una fórmula explícita. Para un polinomio de grado `n` con coeficientes `P` y una variable `x`, el valor del polinomio se calcula como:

```
P[0] * x^n + P[1] * x^(n-1) + ... + P[n]
```

En el código:
- Se utiliza un bucle anidado para calcular cada término del polinomio (`term = coeficiente * x^i`).
- Luego, se suma cada término al acumulador `poliVal`.

---

- **Método de Horner** 
El método de Horner es una forma más eficiente de evaluar polinomios, ya que evita el cálculo repetido de potencias. Reorganiza el polinomio de la siguiente manera:

```
P[0] * x^n + P[1] * x^(n-1) + ... + P[n]
= (...((P[0] * x + P[1]) * x + P[2]) * x + ...) + P[n]
```

En el código:
- Se utiliza un único bucle para evaluar el polinomio.
- Se acumula el resultado en la variable `valor` mediante operaciones de multiplicación y suma.

# Resultados experimentales y gráfica comparativa:

En la siguiente gráfica podemos ver el rendimiento que ha tenido cada método con distintos grados de polinomios:

![Metodos](Archivo%20CSV/Gráfica1.png)

# Analísis de resultados

La gráfica muestra una comparación clara entre los tiempos de ejecución del **método de Horner** y el **método tradicional** para evaluar polinomios de diferentes grados.

### **Método más rápido**
El **método de Horner** es significativamente más rápido que el método tradicional en todos los casos. Esto se observa en la línea azul (Horner), que permanece prácticamente constante y cercana al eje horizontal, mientras que la línea naranja (Tradicional) crece exponencialmente con el grado del polinomio.

---

### **Razón de la diferencia de tiempos**
La diferencia de rendimiento se debe a la **complejidad computacional** de cada método:
1. **Método tradicional**:
   - Tiene una complejidad de **O(n²)** debido al bucle anidado. Para cada término del polinomio, se recalculan las potencias de `x`, lo que implica un número creciente de multiplicaciones a medida que aumenta el grado del polinomio.
   - Esto explica el crecimiento exponencial de los tiempos observados en la gráfica.

2. **Método de Horner**:
   - Tiene una complejidad de **O(n)**, ya que utiliza un único bucle para evaluar el polinomio. Cada iteración realiza una multiplicación y una suma, evitando el cálculo repetido de potencias.
   - Esto explica por qué los tiempos de Horner son casi constantes y mucho menores, incluso para polinomios de grado alto.
  

# Conclusiones
El método de Horner es mucho más eficiente porque reduce el número de operaciones necesarias para evaluar el polinomio. La gráfica confirma que, en la práctica, la complejidad teórica se traduce directamente en diferencias significativas de rendimiento, especialmente para polinomios de grados altos. Por lo tanto, el método de Horner es la opción preferida para evaluar polinomios de manera eficiente.

*Autor:  Mario Alberto Ocejo Quijada*






