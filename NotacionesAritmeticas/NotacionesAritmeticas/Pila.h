#include <iostream>
#include "Nodo.h"

using namespace std;

template <typename T>
class Pila {
private:
    int tamanio = 0;
    Nodo<T>* tope = nullptr;

public:
    //Pila() = default;


    void insertar(T dato);
    T obtenerTope();
    void eliminar();
    bool estaVacia();
    void imprimir();
};

template <typename T>
bool Pila<T>::estaVacia() {
    return tope == nullptr;
}

template <typename T>
void Pila<T>::insertar(T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    nuevo->setSiguiente(tope);
    tope = nuevo;
    tamanio++;
}

template <typename T>
T Pila<T>::obtenerTope() {
    T dato;

    if (!estaVacia()) {
        dato = tope->getDato();
    }
    return dato;
}

template <typename T>
void Pila<T>::eliminar() {
    Nodo<T>* aux;
    if (estaVacia()) {
        cout << "La pila esta vacia";
    }
    else {
        aux = tope;
        tope = tope->getSiguiente();
        delete aux;
    }

    tamanio--;
}

template <typename T>
void Pila<T>::imprimir() {
    Nodo<T>* aux;
    aux = tope;

    while (aux != nullptr) {

        cout << aux->getDato() << endl;
        aux = aux->getSiguiente();
    }

}


