#include <iostream>
#include <stdlib.h>
template <typename T>
class Numero {
public:
void setNum(T n);
T getNum() const;
private:
T num;
};
template <typename T>
void Numero<T>::setNum(T n) {
 this->num = n;
}
template <typename T>
T Numero<T>::getNum() const {
return this->num;
}
int main(){
Numero<int> entero;
Numero<float> flotante;
Numero<double> real;
entero.setNum(5);
flotante.setNum(5.6f);
real.setNum(3.141592);
std::cout<<"\n Numero tipo int: "<<entero.getNum();
std::cout<<"\n Numero tipo float: "<<flotante.getNum()<<"f";
std::cout<<"\n Numero tipo double: "<<real.getNum();
return 0;
}
