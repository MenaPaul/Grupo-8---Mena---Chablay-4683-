#include "Recursividad.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int Recursividad::factorial(int n){
    if(n==0)
        return 1;
    else
    {
        return n*factorial(n-1);
    }
}

int Recursividad::suma(int n){
    if(n==0)
        return 0;
    else
    {
        return n+suma(n-1);
    }
}