#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


void operaciones(int num1, int num2, string operacion) {
    if (operacion == "suma") {
        cout << "Resultado de la suma: " << num1 + num2 << endl;
    } else if (operacion == "resta") {
        cout << "Resultado de la resta: " << num1 - num2 << endl;
    } else if (operacion == "multiplicacion") {
        cout << "Resultado de la multiplicacion: " << num1 * num2 << endl;
    } else if (operacion == "division") {
        if (num2 != 0) {
            cout << "Resultado de la division: " << static_cast<double>(num1) / num2 << endl;
        } else {
            cout << "Error: Division por cero." << endl;
        }
    } else {
        cout << "Operacion no reconocida." << endl;
    }
}

