#include <iostream>
using namespace std;

unsigned long long contador = 0;

void torresHanoi(int n, char origen, char auxiliar, char destino)
{
    // Caso base
    if (n == 1)
    {
        contador++;

        cout << "Movimiento " << contador
             << ": " << origen << " -> " << destino << endl;
    }
    else
    {
        // Mover n-1 discos al auxiliar
        torresHanoi(n - 1, origen, destino, auxiliar);

        // Mover el disco más grande al destino
        contador++;

        cout << "Movimiento " << contador
             << ": " << origen << " -> " << destino << endl;

        // Mover n-1 discos al destino
        torresHanoi(n - 1, auxiliar, origen, destino);
    }
}

int main()
{
    int n;

    cout << "Ingresa el numero de discos: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "El numero de discos debe ser mayor que 0." << endl;
    }
    else
    {
        torresHanoi(n, 'A', 'B', 'C');

        cout << "\nTotal de movimientos necesarios: "
             << contador << endl;
    }

    return 0;
}