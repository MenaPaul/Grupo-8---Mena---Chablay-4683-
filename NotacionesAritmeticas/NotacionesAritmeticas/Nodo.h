template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente = nullptr;
public:
    Nodo(T _dato);
    Nodo() = default;

    T getDato();
    void setDato(T newDato);

    Nodo<T>* getSiguiente();
    void setSiguiente(Nodo<T>* newSiguiente);
};

template <typename T>
Nodo<T>::Nodo(T _dato) {
    dato = _dato;
}

template <typename T>
T Nodo<T>::getDato() {
    return dato;
}

template <typename T>
void Nodo<T>::setDato(T newDato) {
    dato = newDato;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return siguiente;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* newSiguiente) {
    siguiente = newSiguiente;
}
