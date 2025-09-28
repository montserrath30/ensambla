#include <iostream>
#include "calculadora.hpp"
#include <bitset>
#include <sstream>

using namespace std;

int main() {
    int opcion;

    cout << "==== CALCULADORA ====" << endl;
    cout << "1.Operaciones Aritméticas: " << endl;
    cout << "2.Conversiones de Base: " << endl;
    cout << "3.Complementos a 1 y 2: " << endl;
    cout << "Seleccione una opción (1-3): ";
    cin >> opcion;  

    if (opcion == 1) {
        int num1, num2;
        string operacion;

        cout << "Ingrese el primer número o 'rand': "; 
        string entrada1;
        cin >> entrada1;
        if (entrada1 == "rand") {
            cout << "Ingrese semilla para el primer número: ";
            unsigned int seed1; cin >> seed1;
            num1 = medioCuadrado(seed1) % 1000;
            cout << "Número aleatorio generado: " << num1 << endl;
        } else {
            num1 = stoi(entrada1);
        }

        cout << "Ingrese el segundo número o 'rand': ";
        string entrada2;
        cin >> entrada2;
        if (entrada2 == "rand") {
            cout << "Ingrese semilla para el segundo número: ";
            unsigned int seed2; cin >> seed2;
            num2 = medioCuadrado(seed2) % 1000;
            cout << "Número aleatorio generado: " << num2 << endl;
        } else {
            num2 = stoi(entrada2);
        }

        cout << "Ingrese la operación (suma, resta, multiplicacion, division): ";
        cin >> operacion;
        operaciones(num1, num2, operacion);


    } else if (opcion == 2) {    //debo pedir primero la base y luego la semilla o numero
        string numero_str, base_str;

        cout << "Ingrese la base de entrada (decimal, binario, octal, hexadecimal): ";
        cin >> base_str;

        cout << "Ingrese el número o 'rand': ";
        cin >> numero_str;


        if (numero_str == "rand") {
            cout << "Ingrese semilla para el número: ";
            unsigned int seed; cin >> seed;
            int num = medioCuadrado(seed) % 1000;
            cout << "Número aleatorio generado: " << num << endl;

            stringstream ss;
            if (base_str == "decimal") {
                numero_str = to_string(num);
            } else if (base_str == "binario") {
                string bin_str = bitset<16>(num).to_string();
                // Elimina ceros a la izquierda
                size_t first_one = bin_str.find('1');
                if (first_one != string::npos)
                    numero_str = bin_str.substr(first_one);
                else
                    numero_str = "0";
           
            } else if (base_str == "octal") {
                ss << oct << num;
                numero_str = ss.str();

            } else if (base_str == "hexadecimal") {
                ss << hex << uppercase << num;
                numero_str = ss.str();

            } else {
                cout << "Base no reconocida." << endl;
                return 0;
            
            
            }
            cout << "Número y base elegidos: " << numero_str << ", " << base_str << endl;
        }
         convertirBaseGeneral(numero_str, base_str);
        }
       


      else if (opcion == 3) {
        string entrada;
        cout << "Ingrese el número o 'rand': ";
        cin >> entrada;
        int num;
        if (entrada == "rand") {
            cout << "Ingrese semilla para el número: ";
            unsigned int seed; cin >> seed;
            num = medioCuadrado(seed) % 1000;
            cout << "Número aleatorio generado: " << num << endl;
        } else {
            num = stoi(entrada);
        }
        complementos(num);

    }else {
        cout << "Opción inválida." << endl;
    }

    return 0;
}

