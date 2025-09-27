#include <iostream>
#include "calculadora.hpp"

using namespace std;

int main() {
    int opcion;

    cout << "==== CALCULADORA ====" << endl;
    cout << "1.Operaciones Aritméticas: " << endl;
    cout << "2.Conversiones de Base: " << endl;
    cout << "3.Complementos a 1 y 2: " << endl;
    cout << "Seleccione una opción (1-3): ";
    cin >> opcion;  

    if (opcion==1) {
        int num1, num2;
        string operacion;
        cout << "Ingrese el primer número: "; cin >> num1;
        cout << "Ingrese el segundo número: "; cin >> num2;
        cout << "Ingrese la operación (suma, resta, multiplicacion, division): ";cin >> operacion;
        operaciones(num1, num2, operacion);

    } else if (opcion==2) {
        convertirBaseGeneral();

    } else if (opcion==3) {
        int numero;
        cout << "Ingrese un número decimal: ";
        cin >> numero;
        complementos(numero);

    } else {
        cout << "Opción inválida." << endl;
    }
    return 0;
}

