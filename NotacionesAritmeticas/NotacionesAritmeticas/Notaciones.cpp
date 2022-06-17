#include "Notaciones.h"
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

void Notaciones::ingresarExpresion(string _expresion) {
    this->expresion = _expresion;
}

string Notaciones::convertirPostfija() {
    string salida1="";
    string inf = this->expresion;
    char* post = new char[401];
    char* pila = new char[200];
    int ptr = 0;

    int n = 1, j = 0;

    while (n > 0)
    {
        for (int i = 0; inf[i] != '\0'; i++)
        {
            if (!Operador(inf[i]))
            {
                post[j] = inf[i];
                j++;
            }
            else if (inf[i] == '(')
            {
                pila[++ptr] = '(';
            }
            else if (inf[i] == ')')
            {
                while (pila[ptr] != '(' && ptr > 0)
                {
                    post[j] = pila[ptr--];
                    j++;
                }
                if (pila[ptr] == '(')
                    ptr--;
            }
            else
            {
                while (prioridad(inf[i], pila[ptr]) < 0 && pila[ptr] != '(' && ptr > 0)
                {
                    post[j] = pila[ptr--];
                    j++;
                }
                pila[++ptr] = inf[i];
            }

        }

        while (ptr > 0)
        {
            post[j] = pila[ptr--];
            j++;
        }
        post[j] = '\0';

        j = 0;
        ptr = 0;
        n--;
    }

    return post;
}



int Notaciones::verificarJerarquia(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    }
    else if (operador == '*' || operador == '/') {
        return 2;
    }
    else if (operador == '^' || operador == '%' || operador == '=') {
        return 3;
    }
    else if (operador == '(' || operador == ')') {
        return 4;
    }
    else if (operador == 'r') {
        return 5;
    }
    return 0;
}

string Notaciones::convertirPrefija() {
    string infix = this->expresion;
    Pila<char> pOperators;
    Pila<string> pOperands;


    for (int i = 0; i < infix.length(); i++) {

        if (infix[i] == '(') {
            pOperators.insertar(infix[i]);
        }

        else if (infix[i] == ')') {
            while (!pOperators.estaVacia() &&
                pOperators.obtenerTope() != '(') {


                string op1 = pOperands.obtenerTope();
                pOperands.eliminar();

                string op2 = pOperands.obtenerTope();
                pOperands.eliminar();

                char op = pOperators.obtenerTope();
                pOperators.eliminar();

                string tmp = op + op2 + op1;
                pOperands.insertar(tmp);
            }

            pOperators.eliminar();
        }

        else if (!esOperador(infix[i])) {
            pOperands.insertar(string(1, infix[i]));
        }

        else {
            while (!pOperators.estaVacia() &&
                prioridadPref(infix[i]) <=
                prioridadPref(pOperators.obtenerTope())) {

                string op1 = pOperands.obtenerTope();
                pOperands.eliminar();

                string op2 = pOperands.obtenerTope();
                pOperands.eliminar();

                char op = pOperators.obtenerTope();
                pOperators.eliminar();

                string tmp = op + op2 + op1;
                pOperands.insertar(tmp);
            }

            pOperators.insertar(infix[i]);
        }
    }

    while (!pOperators.estaVacia()) {
        string op1 = pOperands.obtenerTope();
        pOperands.eliminar();

        string op2 = pOperands.obtenerTope();
        pOperands.eliminar();

        char op = pOperators.obtenerTope();
        pOperators.eliminar();

        string tmp = op + op2 + op1;
        pOperands.insertar(tmp);
    }

    return pOperands.obtenerTope();
}

bool Notaciones::comprobarSigno(char temporal) {
    if (temporal == '+' || temporal == '-' || temporal == '*' || temporal == '/' ||
        temporal == '^' || temporal == '%' || temporal == '=' || temporal == 'r' || temporal == '(' || temporal == ')') {
        return true;
    }
    return false;
}

bool Notaciones::compararFunciones(int j) {
    char funcion;
    bool compare = false;
    if (expresion[j] == 83 || expresion[j] == 67 || expresion[j] == 84) {
        funcion = expresion[j];
        switch (funcion) {
        case 'S':
            if (expresion[j + 1] == 101 && expresion[j + 2] == 110) {
                compare = true;
            }
            break;
        case 'C':
            if (expresion[j + 1] == 111 && expresion[j + 2] == 115) {
                compare = true;
            }
            break;
        case 'T':
            if (expresion[j + 1] == 97 && expresion[j + 2] == 110) {
                compare = true;
            }
            break;
        case 'R':
            if (expresion[j + 1] == 114 && expresion[j + 2] == 101) {
                compare = true;
            }
            break;
        }
    }
    return compare;
}

bool Notaciones::compararFun(int i) {
    if (expresion[i] == 101 || expresion[i] == 111 ||
        expresion[i] == 115 || expresion[i] == 97 || expresion[i] == 110) {
        return true;
    }
    return false;
}

string Notaciones::compararSigno(char temporal) {
    switch (temporal) {
    case '+': return "Suma";
        break;
    case '-': return "Resta";
        break;
    case '*': return "Producto";
        break;
    case '/': return "Division";
        break;
    case '=': return "Igual";
        break;
    case '%': return "Modulo";
        break;
    case '^': return "Potencia";
        break;
    case 'r': return "Raiz";
        break;
    case '(': return "Abre parentesis";
        break;
    case ')': return "Cierra parentesis";
        break;
    }
    return "";
}

bool Operador(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
        return true;

    return false;
}

int prioridad(char x, char y)
{
    int prec1=0, prec2=0;

    switch (x)
    {
    case '+':
        prec1 = 1;
        break;

    case '-':
        prec1 = 2;
        break;

    case '*':
        prec1 = 3;
        break;

    case '/':
        prec1 = 4;
        break;

    case '^':
        prec1 = 5;
    }

    switch (y)
    {
    case '+':
        prec2 = 1;
        break;

    case '-':
        prec2 = 2;
        break;

    case '*':
        prec2 = 3;
        break;

    case '/':
        prec2 = 4;
        break;

    case '^':
        prec2 = 5;
    }

    return prec1 - prec2;
}

bool esOperador(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int prioridadPref(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}