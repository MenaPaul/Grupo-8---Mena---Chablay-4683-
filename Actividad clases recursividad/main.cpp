
/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: Recursividad
Autor: Esteban Chablay & Paul Mena
Fecha de creacion: 16/05/2022
Fecha de modificacion: 16/05/2022
4683 ESTRUCTURA DE DATOS
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Recursividad.h"
#include "Ingreso.h"

using namespace std;

int main(int argc, char** argv)
{
	Ingreso ing;
    Recursividad rec;
    int n=5;
    char dato[10];
	int valor;
	valor = ing.ingresarDatos("Ingrese el valor numerico entero ");
	
   
    for(int i=1; i<=valor; i++)
    {
        cout << "\n---------------------------------------------------" << endl;
        printf("SUMA %d ",rec.suma(i));
        printf("\nfactorial = %d\n",rec.factorial(i));
        cout << "---------------------------------------------------" << endl;
    }
    return 0;
}