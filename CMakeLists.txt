cmake_minimum_required(VERSION 3.22)
project(ayed_listas_introduccion)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(ayed_listas_introduccion main.cpp
        include/pila.hpp
        include/nodo_pila.hpp)
