#include <iostream>
using namespace std;

int factorial(int n)
{
    cout << "Calculando factorial(" << n << ")" << endl;

    if (n == 0)
    {
        cout << "factorial(0) = 1" << endl;
        return 1;
    }

    int resultado = n * factorial(n - 1);

    cout << "factorial(" << n << ") = "
         << n << " x " << resultado / n
         << " = " << resultado << endl;

    return resultado;
}

int main()
{
    int numero;

    do
    {
        cout << "Ingresa un numero entero no negativo: ";
        cin >> numero;

        if (numero < 0)
        {
            cout << "Valor no valido. Ingresa un numero positivo o cero." << endl;
        }

    } while (numero < 0);

    cout << endl;

    factorial(numero);

    return 0;
}