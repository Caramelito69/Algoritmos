
#include <iostream>
using namespace std;

int main() {
    int op, xl, yl, mul, sum, x, aux, i;

    do {
        // Mostrar menú y leer la opción
        cout << "Menú de opciones:" << endl;
        cout << "1. Suma o multiplicación de dos números" << endl;
        cout << "2. Leer números hasta ingresar 0" << endl;
        cout << "3. Calcular factorial" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> op;

        switch (op) {
            case 1:
                // Leer xl y yl
                cout << "Ingrese el primer número (xl): ";
                cin >> xl;
                cout << "Ingrese el segundo número (yl): ";
                cin >> yl;

                if (xl >= yl && yl % 5 == 0) {
                    sum = xl + yl;
                    cout << "La suma es: " << sum << endl;
                } else {
                    mul = xl * yl;
                    cout << "El producto es: " << mul << endl;
                }
                break;

            case 2:
                // Leer números hasta que sea 0
                cout << "Ingrese un número (x): ";
                cin >> x;
                while (x != 0) {
                    cout << "Número ingresado: " << x << endl;
                    cout << "Ingrese otro número (0 para salir): ";
                    cin >> x;
                }
                break;

            case 3:
                // Calcular factorial
                aux = 1;
                cout << "Ingrese un número (i) para calcular su factorial: ";
                cin >> i;

                for (int j = 1; j <= i; j++) {
                    aux *= j;
                    cout << "Factorial parcial hasta " << j << ": " << aux << endl;
                }
                break;

            case 4:
                cout << "Este es un ejemplo de examen....FIN" << endl;
                break;

            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (op != 4);

    return 0;
}
