#include "Transformar.h"
#include <iostream>
#include <sstream>

using namespace std;

int Transformar::intercambio(char* numero) {
	string num = numero;
	stringstream sstream;
	int num2;

	sstream << num;
	sstream >> num2;

	return num2;
}

int Transformar::validacion(char* tipDato){
    int validez=0, largo=0, ascii=0;
    string dato = tipDato;
    largo = dato.length();
    for(int i=0; i<largo; i++){
        ascii = dato[i];
        if(ascii < 47 || ascii >58 ){
            validez=0;
        }
        else{
            validez=1;
        }
    }
    return validez;
}

