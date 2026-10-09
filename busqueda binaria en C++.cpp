
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

// Busqueda secuencial
int busquedaSecuencial(const vector<int>& arreglo, int numero, int &comparaciones) {
    comparaciones = 0;

    for (int i = 0; i < arreglo.size(); i++) {
        comparaciones++;

        if (arreglo[i] == numero) {
            return i;
        }
    }

    return -1;
}

// Busqueda binaria
int busquedaBinaria(const vector<int>& arreglo, int numero, int &comparaciones) {
    int inicio = 0;
    int fin = arreglo.size() - 1;
    comparaciones = 0;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        comparaciones++;

        if (arreglo[medio] == numero) {
            return medio;
        }

        if (numero < arreglo[medio]) {
            fin = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }

    return -1;
}

// Mostrar resultado de una busqueda binaria
void pruebaBinaria(const vector<int>& arreglo, int numero) {
    int comparaciones = 0;

    int posicion = busquedaBinaria(arreglo, numero, comparaciones);

    cout << "Numero buscado: " << numero << endl;
    cout << "Resultado: "
         << (posicion != -1 ? "Encontrado" : "No encontrado") << endl;
    cout << "Posicion: " << posicion << endl;
    cout << "Iteraciones: " << comparaciones << endl;
}

// Comparar busqueda secuencial y binaria
void comparar(const vector<int>& arreglo, int numero) {
    int compSec = 0;
    int compBin = 0;

    auto inicio1 = high_resolution_clock::now();
    int posSec = busquedaSecuencial(arreglo, numero, compSec);
    auto fin1 = high_resolution_clock::now();

    auto inicio2 = high_resolution_clock::now();
    int posBin = busquedaBinaria(arreglo, numero, compBin);
    auto fin2 = high_resolution_clock::now();

    double tiempoSec = duration<double, micro>(fin1 - inicio1).count();
    double tiempoBin = duration<double, micro>(fin2 - inicio2).count();

    cout << "\nNumero buscado: " << numero << endl;
    cout << "Resultado: "
         << (posSec != -1 ? "Encontrado" : "No encontrado") << endl;

    cout << left << setw(15) << "Algoritmo"
         << setw(15) << "Posicion"
         << setw(18) << "Comparaciones"
         << "Tiempo (us)" << endl;

    cout << left << setw(15) << "Secuencial"
         << setw(15) << posSec
         << setw(18) << compSec
         << tiempoSec << endl;

    cout << left << setw(15) << "Binaria"
         << setw(15) << posBin
         << setw(18) << compBin
         << tiempoBin << endl;

    if (posSec == posBin) {
        cout << "Validacion: Resultados iguales" << endl;
    } else {
        cout << "Validacion: Resultados diferentes" << endl;
    }
}

int main() {
    cout << fixed << setprecision(3);

    // PARTE 1: Arreglo desordenado y ordenado
    vector<int> desordenado = {38, 12, 57, 4, 91, 26, 73, 15};
    vector<int> ordenado = {4, 12, 15, 26, 38, 57, 73, 91};

    cout << "====================================" << endl;
    cout << "PRUEBA DE BUSQUEDA BINARIA" << endl;
    cout << "====================================" << endl;

    cout << "\n--- ARREGLO DESORDENADO ---" << endl;
    pruebaBinaria(desordenado, 73);

    cout << "\n--- ARREGLO ORDENADO ---" << endl;
    pruebaBinaria(ordenado, 73);

    // PARTE 2: Comparacion de algoritmos
    int tamanos[] = {100, 1000, 10000, 100000};

    for (int n : tamanos) {
        vector<int> arreglo;

        for (int i = 1; i <= n; i++) {
            arreglo.push_back(i);
        }

        cout << "\n====================================" << endl;
        cout << "ARREGLO DE " << n << " ELEMENTOS" << endl;
        cout << "====================================" << endl;

        cout << "\n--- BUSQUEDA EXITOSA ---" << endl;
        comparar(arreglo, n);

        cout << "\n--- BUSQUEDA FALLIDA ---" << endl;
        comparar(arreglo, n + 1);
    }

    return 0;
}
