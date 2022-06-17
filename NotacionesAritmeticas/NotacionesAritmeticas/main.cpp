#include <iostream>
#include "Menu.h"
#include "Notaciones.h"




using namespace std;
int main(int, char**) {
    Menu menu;
    int opc;
    Notaciones nt;
    string post;
    string pre;

    do
    {
        opc = menu.menuPrincipal();
        switch (opc) {
        case 1:
            system("cls");
            cout << "\t\t** CONVERSION **" << endl;
            cout << "Ingrese la expresion (Infija): ";
            cin >> post;
            nt.ingresarExpresion(post);
            post = nt.convertirPostfija();
            pre = nt.convertirPrefija();
            cout << "\n Expresion postfija: " << post << endl;
            cout << "\n Expresion prefija: " << pre << endl;
            system("pause");
            break;
        }
    } while (opc != 2);
}