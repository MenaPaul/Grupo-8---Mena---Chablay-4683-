#pragma once
#include <string>
//#include "ListaDobleCircular.h"
using namespace std;

class Validaciones
{
public:
	int validacionEntero(const char*);

	float validacionDecimal(const char*);

	bool validarCedula(string);

	int suma(int verif2[9]);

	string texto(string);

	string numeros(string);

	string mayusculas(string s);
};
