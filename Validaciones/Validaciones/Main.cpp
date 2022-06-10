#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Validaciones.h"

using namespace std;

int main()
{
    
    int entero;
    string enteroString;
    string texto;
    string mayusculas;
    float flotante;
    Validaciones val;

    cout << "\t\tIngreso de numeros" << endl;
    cout << "- Retorno de string." << endl;
    enteroString = val.numeros("Ingrese un entero: ");

    cout << "\n- Retorno int. " << endl;
    entero = val.validacionEntero("Ingrese un entero: ");

    cout << "\n\n\t\tIngreso de flotantes" << endl;
    cout << "- Retorno float." << endl;
    flotante = val.validacionDecimal("Ingrese un flotante: ");
    cout << "\n" << flotante;

    cout << "\n\n\t\tIngreso de texto" << endl;
    texto = val.texto("Ingrese texto: ");
    mayusculas = val.mayusculas(texto);
    cout << "\nTexto en mayusculas: " << mayusculas;
} 
