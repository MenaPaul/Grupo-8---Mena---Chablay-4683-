#include <iostream>
#include <windows.h>
using namespace std;


class Menu {

public:
	Menu() = default;
	void gotoxy(int, int);
	int crearMenu(string, string*, int);
	string crearMenuTipoMatriz(string**);
	int menuPrincipal();
};

