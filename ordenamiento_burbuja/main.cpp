#include <iostream>
using namespace std;

void burbuja(int numeros[], int n)
{
    int comparaciones = 0;
    int intercambios = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            comparaciones++;

            if (numeros[j] > numeros[j + 1])
            {
                int temporal = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temporal;

                intercambios++;
            }
        }

        cout << "Pasada " << i + 1 << ": ";

        for (int j = 0; j < n; j++)
        {
            cout << numeros[j] << " ";
        }

        cout << endl;
    }

    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios: " << intercambios << endl;
}

int main()
{
    int numeros[] = {5, 1, 4, 2, 8};
    int n = 5;

    cout << "Arreglo original: ";

    for (int i = 0; i < n; i++)
    {
        cout << numeros[i] << " ";
    }

    cout << endl;

    burbuja(numeros, n);

    cout << "Arreglo ordenado: ";

    for (int i = 0; i < n; i++)
    {
        cout << numeros[i] << " ";
    }

    cout << endl;

    return 0;
}