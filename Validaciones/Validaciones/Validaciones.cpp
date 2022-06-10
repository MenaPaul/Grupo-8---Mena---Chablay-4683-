#include "Validaciones.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using std::transform;
using std::toupper;
using namespace std;


//Validacion de entero retorna int
int Validaciones::validacionEntero(const char* msj) {
    char* dato = new char[10000];
    char c;
    int valor, i = 0, cont = 0;
    printf_s("%s", msj);
    while ((c = _getch()) != 13 || cont == 0) {
        if ((c >= '0' && c <= '9')) {
            printf_s("%c", c);
            *(dato + i++) = c;
            cont++;
        }
    }
    *(dato + i) = '\0';
    valor = atoi(dato);
    return valor;

}

//Validacion de flotante retorna float
float Validaciones::validacionDecimal(const char* msj) {

    char* dato = new char[10000];
    char c;
    int i = 0, cont = 0;
    float valor = 0.0f;
    printf_s("%s", msj);
    while ((c = _getch()) != 13 || cont == 0) {
        if ((c >= '0' && c <= '9') || (c == '.')) {
            printf_s("%c", c);
            *(dato + i++) = c;
            cont++;
        }
    }
    *(dato + i) = '\0';
    valor = atof(dato);
    return valor;
}

//Valida cedula ecuatoriana
bool Validaciones::validarCedula(string dato) {
    bool veri = false;
    int cedula[10];
    string aux;
    for (int i = 0; i < 10; i++) {
        aux = dato[i];
        cedula[i] = stoi(aux);
    }

    int verif[10], num, i;

    if (cedula[2] < 0 || cedula[2]>6) {

        return veri;
    }

    if (cedula[0] < 0 || cedula[0]>2) {

        return veri;
    }
    if (cedula[0] == 2 && (cedula[1] < 1 || cedula[1]>4)) {

        return veri;
    }

    for (i = 0; i <= 8; i++) {
        if (i % 2 == 0) {
            verif[i] = cedula[i] * 2;
            if (verif[i] >= 10) {
                verif[i] = verif[i] - 9;

            }
        }
        else {
            verif[i] = cedula[i] * 1;
            if (verif[i] >= 10) {
                verif[i] = verif[i] - 9;

            }
        }
    }

    verif[9] = 90 - suma(verif);
    num = verif[9] % 10;

    if (cedula[9] == num) {

        veri = true;
        return veri;
    }
    else {

        return veri;
    }
    return veri;
}


int Validaciones::suma(int verif2[9]) {
    int i, suma = 0;
    for (i = 0; i <= 8; i++) {
        suma = suma + verif2[i];
    }
    return suma;
}

//Valida ingreso de texto retorna string
string Validaciones::texto(string mensaje) {
    string text = "";
    char letter;
    //cout << "\n\t" << mensaje << " ";
    cout << mensaje;
    letter = _getch();
    while (letter != 13 || text.length() == 0) {

        if ((letter < 91 && letter > 64) || (letter < 123 && letter > 96) || letter == 48 || letter == 64) {
            text.push_back(letter);
            cout << letter;
        }
        letter = _getch();
    }
    return text;
}

//Valida numeros retorna string
string Validaciones::numeros(string mensaje) {
    char* dato = new char[10000];
    char c;
    int valor, i = 0, cont = 0;
    cout << mensaje;
    while ((c = _getch()) != 13 || cont == 0) {
        if ((c >= '0' && c <= '9')) {
            printf_s("%c", c);
            *(dato + i++) = c;
            cont++;
        }
    }
    *(dato + i) = '\0';
    return dato;
}

//Convierte en mayusculas
string Validaciones::mayusculas(string s) {
    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return toupper(c); });
    return s;
}