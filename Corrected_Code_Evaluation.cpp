
#include <iostream>
using namespace std;

int main() {
    int aux, mul, sum, x, xl, yl, op, i;
    
    do {
        // Mostrar menú y leer la opción
        cout << "Menú de opciones:" << endl;
        cout << "1. Suma o multiplicación de dos números" << endl;
        cout << "2. Mostrar números hasta ingresar 0" << endl;
        cout << "3. Calcular factorial de un número" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> op;
        
        switch (op) {
            case 1:
                // Leer dos números
                cout << "Ingrese el primer número: ";
                cin >> xl;
                cout << "Ingrese el segundo número: ";
                cin >> yl;

                if (xl >= yl && yl % 5 == 0) {
                    sum = xl + yl;
                    cout << "La suma de los números es: " << sum << endl;
                } else {
                    mul = xl * yl;
                    cout << "El producto de los números es: " << mul << endl;
                }
                break;

            case 2:
                // Leer números hasta que el usuario ingrese 0
                cout << "Ingrese un número (0 para salir): ";
                cin >> x;
                while (x != 0) {
                    cout << "Número ingresado: " << x << endl;
                    cout << "Ingrese otro número (0 para salir): ";
                    cin >> x;
                }
                break;

            case 3:
                // Calcular el factorial de un número
                aux = 1;
                cout << "Ingrese un número para calcular su factorial: ";
                cin >> i;
                if (i < 0) {
                    cout << "El factorial no está definido para números negativos." << endl;
                } else {
                    for (int j = 1; j <= i; j++) {
                        aux *= j;
                        cout << "Factorial parcial hasta " << j << ": " << aux << endl;
                    }
                }
                break;

            case 4:
                cout << "Este es un ejemplo de examen....FIN" << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (op != 4);

    return 0;
}
