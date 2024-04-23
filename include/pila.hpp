#ifndef AYED_LISTAS_INTRODUCCION_PILA_HPP
#define AYED_LISTAS_INTRODUCCION_PILA_HPP

#include <cstddef>
#include <exception>
#include "nodo_pila.hpp"

class pila_exception : public std::exception {
};

template<typename T>
class pila {
private:
    nodo_pila<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    // Constructor.
    pila();

    // Pre: -
    // Post: Agrega el dato al final (LIFO).
    void agregar(T dato);

    // Pre: la pila no puede estar vacía.
    // Post: Elimina el dato al final (LIFO) y lo devuelve.
    T eliminar();

    // Pre: la pila no puede estar vacía.
    // Post: Devuelve el dato al final (LIFO).
    T consultar();

    // Pre: -
    // Post: Devuelve el tamaño de la pila.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la pila está vacía.
    bool vacio();

    // Destructor.
    ~pila();
};

template<typename T>
pila<T>::pila() {
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void pila<T>::agregar(T dato) {
    nodo_pila<T>* nuevo_nodo = new nodo_pila<T>(dato, ultimo_nodo);
    ultimo_nodo = nuevo_nodo;
    cantidad_datos++;
}

template<typename T>
T pila<T>::eliminar() {
    if (cantidad_datos == 0) {
        throw pila_exception();
    } else {
        nodo_pila<T>* aux = ultimo_nodo;
        ultimo_nodo = ultimo_nodo->obtener_anterior();
        T dato_eliminado = aux->obtener_dato();
        delete aux;
        cantidad_datos--;
        return dato_eliminado;
    }
}

template<typename T>
T pila<T>::consultar() {
    if (cantidad_datos == 0) {
        throw pila_exception();
    } else {
        return ultimo_nodo->obtener_dato();
    }
}

template<typename T>
bool pila<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
size_t pila<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
pila<T>::~pila() {
    while (cantidad_datos != 0) {
        eliminar();
    }
}

#endif