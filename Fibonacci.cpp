#include <iostream>
using namespace std;

long long fibonacci(int n)
{
    // Casos base
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    cout << "Hasta que termino de Fibonacci deseas calcular: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Error: el numero debe ser mayor o igual a 0." << endl;
        return 1;
    }

    for (int i = 0; i <= n; i++)
    {
        cout << "Fibonacci(" << i << ") = " << fibonacci(i) << endl;
    }

    return 0;
}