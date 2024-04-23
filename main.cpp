#include "pila.hpp"
#include <iostream>

int main() {
    pila<int> pila1;
    for (int i = 0; i < 10; i++) {
        pila1.agregar(i);
    }
    std::cout << "El ultimo dato es " << pila1.consultar() << std::endl;
    std::cout << "Se elimino el dato " << pila1.eliminar() << std::endl;
    std::cout << "El ultimo dato es " << pila1.consultar() << std::endl;
    return 0;
}