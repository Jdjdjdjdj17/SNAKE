#include "Food.hpp"
#include <cstdlib>

Food::Food(int ancho, int alto) {
    regenerar(ancho, alto);
}

const Posicion& Food::obtenerPosicion() const {
    return posicion;
}

void Food::regenerar(int ancho, int alto) {
    posicion.x = rand() % ancho;
    posicion.y = rand() % alto;
}