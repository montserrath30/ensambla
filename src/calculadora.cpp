#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

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


//2.conversiones de base
void convertitBase(int numero) {
    cout << "Decimal: " << numero << endl;
    cout << "Binario: " << bitset<16>(numero) << endl;

    stringstream ss;
    ss << oct << numero;
    cout << "Octal: " << ss.str() << endl;

    ss.str(""); ss.clear();
    ss << hex << uppercase << numero;
    cout << "Hexadecimal: " << ss.str() << endl;
}


//3.complementos a 1 y 2
void complementos(int numero) {
    unsigned short n = static_cast<unsigned short>(numero);

    // Complemento a 1
    bitset<16> comp1 = ~bitset<16>(n);
    cout << "Complemento a 1: " << comp1 << endl;

    // Complemento a 2
    unsigned short comp2_val = static_cast<unsigned short>(comp1.to_ulong() + 1);
    bitset<16> comp2(comp2_val);
    cout << "Complemento a 2: " << comp2 << endl;
}


void convertirBaseGeneral() {
    string numero_str, base_str;
    int base = 10;
    cout << "Ingrese el número: ";
    cin >> numero_str;
    cout << "Ingrese la base de entrada (decimal, binario, octal, hexadecimal): ";
    cin >> base_str;

    // Determinar la base
    if (base_str == "decimal") base = 10;
    else if (base_str == "binario") base = 2;
    else if (base_str == "octal") base = 8;
    else if (base_str == "hexadecimal") base = 16;
    else {
        cout << "Base no reconocida." << endl;
        return;
    }

    // Convertir a decimal
    int numero_decimal = 0;
    try {
        numero_decimal = stoi(numero_str, nullptr, base);
    } catch (...) {
        cout << "Número inválido para la base indicada." << endl;
        return;
    }

    // Mostrar en todas las bases
    cout << "Decimal: " << numero_decimal << endl;
    cout << "Binario: " << bitset<16>(numero_decimal).to_string().substr(bitset<16>(numero_decimal).to_string().find('1')) << endl;

    stringstream ss;
    ss << oct << numero_decimal;
    cout << "Octal: " << ss.str() << endl;

    ss.str(""); ss.clear();
    ss << hex << uppercase << numero_decimal;
    cout << "Hexadecimal: " << ss.str() << endl;
}





