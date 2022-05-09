#include <iostream>
#include <stdlib.h>
class Funciones {
public:
template<class... Args>
auto Suma(Args... arg);
};

//Implementación de la función que suma n cantidad de números ingresados
template<class... Args>
auto Funciones::Suma(Args...arg){
auto suma = 0.0;
for(auto &v : {arg...}){
suma += v;
}
return suma;
}
int main(){
Funciones f;
//llamada a la función con distinta cantidad de parametros y distinto tipo de dato
std::cout<<"\n Suma tipo double: "<<f.Suma(1.5,2.5,3.5,4.5,6.5);
std::cout<<"\n Suma tipo entero: "<<f.Suma(1,2,3,4,5);
std::cout<<"\n Suma tipo float: "<<f.Suma(1.1f,2.2f,3.3f,4.4f,5.5f)<<"f";
return 0;
}