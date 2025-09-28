#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

//1.operaciones aritmeticas
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

    // complemento a 1
    bitset<16> comp1 = ~bitset<16>(n);
    cout << "Complemento a 1: " << comp1 << endl;

    // complemento a 2
    unsigned short comp2_val = static_cast<unsigned short>(comp1.to_ulong() + 1);
    bitset<16> comp2(comp2_val);
    cout << "Complemento a 2: " << comp2 << endl;
}


void convertirBaseGeneral(const std::string& numero_str, const std::string& base_str) {
    int base = 10;
    if (base_str == "decimal") base = 10;
    else if (base_str == "binario") base = 2;
    else if (base_str == "octal") base = 8;
    else if (base_str == "hexadecimal") base = 16;
    else {
        cout << "Base no reconocida." << endl;
        return;
    }

    int numero_decimal = 0;
    try {
        numero_decimal = stoi(numero_str, nullptr, base);
    } catch (...) {
        cout << "Número inválido para la base indicada." << endl;
        return;
    }

    cout << "Decimal: " << numero_decimal << endl;
    cout << "Binario: " << bitset<16>(numero_decimal).to_string().substr(bitset<16>(numero_decimal).to_string().find('1')) << endl;

    stringstream ss;
    ss << oct << numero_decimal;
    cout << "Octal: " << ss.str() << endl;

    ss.str(""); ss.clear();
    ss << hex << uppercase << numero_decimal;
    cout << "Hexadecimal: " << ss.str() << endl;
}

// Generador pseudoaleatorio: método del medio del cuadrado
unsigned int medioCuadrado(unsigned int seed) {
    unsigned int n = seed * seed; //multiplico la semilla por ella misma, uso los centraless
    // Si la semilla es pequeña, ajusta el cálculo
    if (seed < 1000) n *= 1009;   // es menor a 1000, se multiplica n por 1009.
    return (n / 100) % 10000; //elimino los ultimos dos digitos y tomo los centrales 
}





