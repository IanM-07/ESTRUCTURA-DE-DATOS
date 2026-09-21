#include <iostream>
using namespace std;

void burbuja(int numeros[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (numeros[j] > numeros[j + 1])
            {
                int temporal = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temporal;
            }
        }
    }
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

    burbuja(numeros, n);

    cout << "\nArreglo ordenado: ";

    for (int i = 0; i < n; i++)
    {
        cout << numeros[i] << " ";
    }

    cout << endl;

    return 0;
}