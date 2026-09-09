#include <iostream>

using namespace std;

int main() {

    int matriz[100][100];
    int filas, columnas;
    int suma = 0;
    int mayor, menor;

    cout << "Ingresa el numero de filas: ";
    cin >> filas;

    cout << "Ingresa el numero de columnas: ";
    cin >> columnas;

    cout << "\nIngresa los elementos de la matriz:\n";

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    mayor = matriz[0][0];
    menor = matriz[0][0];

    cout << "\nMatriz:\n";

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            suma += matriz[i][j];

            if (matriz[i][j] > mayor) {
                mayor = matriz[i][j];
            }

            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }

    cout << "\nSuma de todos los elementos: " << suma << endl;
    cout << "Promedio: " << (double)suma / (filas * columnas) << endl;
    cout << "Valor mayor: " << mayor << endl;
    cout << "Valor menor: " << menor << endl;

    cout << "\nSuma de cada fila:\n";

    for (int i = 0; i < filas; i++) {

        int sumaFila = 0;

        for (int j = 0; j < columnas; j++) {
            sumaFila += matriz[i][j];
        }

        cout << "Fila " << i << ": " << sumaFila << endl;
    }

    cout << "\nSuma de cada columna:\n";

    for (int j = 0; j < columnas; j++) {

        int sumaColumna = 0;

        for (int i = 0; i < filas; i++) {
            sumaColumna += matriz[i][j];
        }

        cout << "Columna " << j << ": " << sumaColumna << endl;
    }

    return 0;
}