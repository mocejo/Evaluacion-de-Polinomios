# Evaluacion de Polinomios

Programa en C++ que utiliza dos métodos de evaluación de Polinomimos:

**1. Método estándar (Tradicional)**  

**2. Método de Horner**

Se lleva a cabo una prueba para cada método, comenzando con polinomios cuyo grado aumenta en incrementos de 10, desde 10 hasta 1000. Los coeficientes de dichos polinomios se generan aleatoriamente dentro del rango [-10, 10], excluyendo el valor cero.

Se evalúan estos polinomios un total de 1000 veces en un punto **x ≠ 0** que, al igual que los coeficientes, es generado aleatoriamente en el mismo rango.

Al final, se imprimen los promedios para cada grado en un archivo CSV.




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

![Metodos](Grafica1.png)



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
g++ EvaluacionDePolinomios.cpp -o EvaluacionDePolinomios
```
4. Ejecutar código
```sh
./EvaluacionDePolinomios
```
**Forma práctica:**  

Descargar el archivo ```EvaluacionDePolinomios.cpp``` y compilar desde un IDE a su preferencia.





