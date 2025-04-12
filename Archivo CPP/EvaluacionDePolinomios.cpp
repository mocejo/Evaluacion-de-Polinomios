#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono> // Para medir tiempos

int aleatorio(int inicio, int fin);
long double EvaluarPolinomioHorner(int *P, int grado, int x);
long double EvaluarPolinomio(int *P, int grado, int x);

using namespace std;

#define GradoMaximo 1000

int aleatorio(int inicio, int fin) {
    return inicio + rand() % (fin - inicio + 1);
}

long double EvaluarPolinomioHorner(int *P, int grado, int x) {
    double valor = P[0]; // Primer coeficiente

    for(int i = 1 ; i <= grado ; ++i){
       valor = valor*x + P[i];
    }

    return valor;
}

long double EvaluarPolinomio(int *P, int grado, int x) {

    double poliVal = *P; // Primer coeficiente

    double term;

    for(int i = 1; i <= grado; ++i){
        term = P[grado - i]; // Coeficiente del polinomio
        for(int j = 1 ; j <= i; ++j){
            term = term*x;
        }
        poliVal = poliVal + term;
    }


    return poliVal;
}

int main() {
    srand(time(NULL)); // Inicializa la semilla para el generador de números aleatorios

    short int x;
    ofstream archivoCSV("EvaluacionPolinomios.csv"); // Crear archivo CSV
    archivoCSV << "Grado,Promedio_Horner,Promedio_Tradicional\n"; // Encabezados

    cout << "Este es un programa experimental que compara el rendimiento del metodo de Horner con el metodo tradicional para evaluar polinomios." << endl;


    cout << "Generando archivo CSV..." << endl;

    for (int grado = 10; grado <= GradoMaximo; grado += 10) { // Se evalua el polinomio de grado 10 a 1000 en incrementos de 10
        int *P = new int[grado + 1];

        // Generar coeficientes aleatorios para el polinomio
        for (int j = 0; j <= grado; j++) {
            do {
                P[j] = aleatorio(-10, 10); // Se generan coeficientes aleatorios entre -10 y 10
            } while (P[j] == 0); // Se asegura que el coeficiente no sea cero
        }

        do{
        x = aleatorio(-10, 10); // Se genera un valor aleatorio para x entre -10 y 10
        } while (x == 0); // Se asegura que x no sea cero



        // Medir tiempo del método de Horner
        auto inicioHorner = chrono::high_resolution_clock::now();
        for (int k = 0; k < 1000; k++) { // Repetir 1000 veces para obtener el promedio
            EvaluarPolinomioHorner(P, grado, x);
        }
        auto finHorner = chrono::high_resolution_clock::now();
        double promedioHorner = chrono::duration_cast<chrono::microseconds>(finHorner - inicioHorner).count() / 100.0;

        // Medir tiempo del método tradicional
        auto inicioTradicional = chrono::high_resolution_clock::now();
        for (int k = 0; k < 1000; k++) { // Repetir 1000 veces para obtener el promedio
            EvaluarPolinomio(P, grado, x);
        }
        auto finTradicional = chrono::high_resolution_clock::now();
        double promedioTradicional = chrono::duration_cast<chrono::microseconds>(finTradicional - inicioTradicional).count() / 100.0;

        // Escribir resultados en el archivo CSV
        archivoCSV << grado << "," << promedioHorner << "," << promedioTradicional << "\n";

        // Liberar memoria
        delete[] P;
    }

    archivoCSV.close(); // Cerrar archivo CSV
    cout << "Resultados guardados en 'EvaluacionPolinomios.csv'." << endl;

    return 0;
}
