#ifndef CALCULADORA_HPP
#define CALCULADORA_HPP
#include <string>

using namespace std;


void operaciones(int num1, int num2, string operacion);

void convertirBaseGeneral(const std::string& numero_str, const std::string& base_str);

void complementos(int numero);

void generadorNumerosPseudoaleatorios(unsigned int seed);


// declaracion par usar el metodo del medio cuadrado 
unsigned int medioCuadrado(unsigned int seed);  //recibe el parametro semilla 

#endif // CALCULADORA_HPP
