#ifndef AYED_LISTAS_INTRODUCCION_NODO_PILA_HPP
#define AYED_LISTAS_INTRODUCCION_NODO_PILA_HPP

template<typename T>
class nodo_pila {
private:
    T dato;
    nodo_pila<T>* anterior;
public:
    // Constructor.
    nodo_pila(T dato, nodo_pila<T>* anterior);

    // Pre: -
    // Post: Devuelve el dato guardado en el nodo.
    T obtener_dato();

    // Pre: -
    // Post: Devuelve el nodo anterior.
    nodo_pila<T>* obtener_anterior();
};

template<typename T>
nodo_pila<T>::nodo_pila(T dato, nodo_pila<T>* anterior) {
    this->dato = dato;
    this->anterior = anterior;
}

template<typename T>
T nodo_pila<T>::obtener_dato() {
    return dato;
}

template<typename T>
nodo_pila<T>* nodo_pila<T>::obtener_anterior() {
    return anterior;
}

#endif