#include "Operadores.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Operadores::Operadores(int a, int b){
    this->num1=a;
    this->num2=b;
}

bool Operadores::operator&&(Operadores otro){
    if(num1==otro.num1 && num2==otro.num2){
        //cout << "Valor correcto";
        return true;
    }else{
        //cout << "Valor incorrecto";
        return false;
    }
}

int Operadores::operator&=(int nuevoNum){
    num3&=nuevoNum;
    cout << num3;
    return num3;
}
