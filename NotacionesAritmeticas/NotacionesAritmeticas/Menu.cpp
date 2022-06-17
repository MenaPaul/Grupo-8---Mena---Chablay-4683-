#include <stdlib.h>
#include "Menu.h"
#include <stdio.h>
#include <conio.h>



#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define ENTER 13
using namespace std;

void Menu::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}


int Menu::crearMenu(string titulo, string* opciones, int nOpciones) {



	int seleccion = 1, tecla;
	bool repite = true;
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	WORD csbi_defaults;

	GetConsoleScreenBufferInfo(H, &csbi);
	csbi_defaults = csbi.wAttributes;
	do {

		system("cls");
		gotoxy(15, 2); cout << titulo;

		gotoxy(5, 3 + seleccion); cout << ">>";


		for (int i = 0; i < nOpciones; i++) {


			if (seleccion == (i + 1)) {

				SetConsoleTextAttribute(H, 1);
			}
			gotoxy(10, 4 + i);
			cout << (i + 1) << "." << *(opciones + i);
			SetConsoleTextAttribute(H, csbi_defaults);


		}

		do {
			tecla = _getch();
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

		switch (tecla) {
		case ARRIBA:
			seleccion--;
			if (seleccion < 1) {
				seleccion = nOpciones;
			}
			break;
		case ABAJO:
			seleccion++;
			if (seleccion > nOpciones) {
				seleccion = 1;
			}
			break;
		case ENTER:
			repite = false;
			break;
		}

	} while (repite);

	return seleccion;
}

string Menu::crearMenuTipoMatriz(string** opciones) {

	string expresion = "";
	string capturado;


	int fila = 1, columna = 1, tecla;
	bool repite = true;
	int espaciadoH = 0, espaciadoV = 0;
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	WORD csbi_defaults;

	GetConsoleScreenBufferInfo(H, &csbi);
	csbi_defaults = csbi.wAttributes;

	do {
		system("cls");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {

				if (fila == (i + 1) && columna == (j + 1)) {
					SetConsoleTextAttribute(H, 23);
				}
				gotoxy((j + 5) + espaciadoH, (i + 5) + espaciadoV);
				cout << *(*(opciones + i) + j);
				SetConsoleTextAttribute(H, csbi_defaults);
				espaciadoH += 7;
			}
			espaciadoH = 0;
			espaciadoV += 2;

		}
		espaciadoV = 0;
		cout << "\n\n\nExpresion: " << expresion;
		do {
			tecla = _getch();
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != DERECHA && tecla != IZQUIERDA && tecla != ENTER);

		switch (tecla) {
		case ARRIBA:
			fila--;
			if (fila < 1) {
				fila = 5;
			}
			break;

		case ABAJO:
			fila++;
			if (fila > 5) {
				fila = 1;
			}
			break;

		case IZQUIERDA:
			columna--;
			if (columna < 1) {
				columna = 6;
			}
			break;

		case DERECHA:
			columna++;
			if (columna > 6) {
				columna = 1;
			}
			break;

		case ENTER:

			if ((fila - 1) == 4 && (columna - 1) == 5) {
				repite = false;
			}
			else if (((fila - 1) == 0 && (columna - 1) == 5)) {

				if (expresion != "") {
					if (capturado == "sen" || capturado == "cos" || capturado == "tan") {
						for (int i = 0; i < 3; i++) {
							expresion.pop_back();
						}
					}
					else {
						expresion.pop_back();
					}
				}

			}
			else {
				capturado = *(*(opciones + (fila - 1)) + (columna - 1));
				expresion += capturado;
			}

			break;
		}

	} while (repite);


	return expresion;
}





int Menu::menuPrincipal() {
	string* opciones = new string[2];

	*(opciones + 0) = "Infija a Postfija y Prefija";

	*(opciones + 1) = "Salir";

	return crearMenu(" ||--|| Conversion de notaciones ||--|| ", opciones, 2);
}