#include <iostream>
using namespace std;

void mostrarArreglo(int numeros[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << numeros[i] << " ";
    }

    cout << endl;
}

void insertionSort(int numeros[], int n)
{
    int comparaciones = 0;
    int desplazamientos = 0;
    int inserciones = 0;

    for (int i = 1; i < n; i++)
    {
        int clave = numeros[i];
        int j = i - 1;

        cout << endl;
        cout << "Insertando: " << clave << endl;

        while (j >= 0)
        {
            comparaciones++;

            if (numeros[j] > clave)
            {
                numeros[j + 1] = numeros[j];
                desplazamientos++;
                j--;
            }
            else
            {
                break;
            }
        }

        numeros[j + 1] = clave;
        inserciones++;

        mostrarArreglo(numeros, n);
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "           ESTADISTICAS" << endl;
    cout << "========================================" << endl;

    cout << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Desplazamientos: " << desplazamientos << endl;
    cout << "Inserciones: " << inserciones << endl;
}

int main()
{
    int numeros[] = {7, 3, 8, 2, 6, 4, 5};
    int n = 7;

    cout << "Arreglo original:" << endl;
    mostrarArreglo(numeros, n);

    insertionSort(numeros, n);

    return 0;
}