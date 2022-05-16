#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ingreso.h"


int Ingreso::ingresarDatos(char *msg){
	char dato[10];
	char c;
	int i=0;
	int valor=0;
	printf("%s\n",msg);
	while((c=getch())!=13){
		if(c>='0' && c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	valor = atoi(dato);
	return valor;
}

			


