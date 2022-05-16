
/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: Sobrecarga de Operadores (& - &&)
Autor: Esteban Chablay & Paul Mena
Fecha de creacion: 16/05/2022
Fecha de modificacion: 16/05/2022
4683 ESTRUCTURA DE DATOS
*/

#include <iostream>
#include <bitset>
#include "Operadores.h"

using namespace std;

int main()
{
    Operadores op1(3,6);
    Operadores op2(3,2);
    cout << "           ||-||Sobrecarga del operador &&||-||" << endl;
    if(op1 && op2){
        cout << "Los datos son iguales.";
    }
    else{
        cout << "Son diferentes datos.";
    }

    cout << "\n\n           ||-||Sobrecarga del operador &=||-||" << endl;
    int a=13, b=3;
    int sumaBinaria;
    sumaBinaria = a&=b;
    cout << sumaBinaria;
    return 0;
}
