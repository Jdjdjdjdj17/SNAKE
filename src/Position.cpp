#include "Position.hpp"

// Constructor que inicializa las coordenadas x e y
Posicion::Posicion(int x, int y) : x(x), y(y) {}

// Operador de igualdad para comparar dos objetos Posicion
bool Posicion::operator==(const Posicion& other) const {
    return x == other.x && y == other.y;
}