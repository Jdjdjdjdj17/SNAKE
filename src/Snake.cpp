#include "Snake.hpp"

Snake::Snake(int xInicial, int yInicial) {
    cuerpo.push_back(Posicion(xInicial, yInicial));
    direccion = Posicion(1, 0); // Inicia moviéndose a la derecha
}

void Snake::mover() {
    Posicion nuevaCabeza = cuerpo.front();
    nuevaCabeza.x += direccion.x;
    nuevaCabeza.y += direccion.y;

    cuerpo.insert(cuerpo.begin(), nuevaCabeza);
    cuerpo.pop_back();
}

void Snake::crecer() {
    cuerpo.push_back(cuerpo.back());
}

bool Snake::colisiona(const Posicion& pos) const {
    for (const auto& segmento : cuerpo) {
        if (segmento == pos) return true;
    }
    return false;
}

const std::vector<Posicion>& Snake::obtenerCuerpo() const {
    return cuerpo;
}

void Snake::cambiarDireccion(const Posicion& nuevaDireccion) {
    if (direccion.x + nuevaDireccion.x != 0 || direccion.y + nuevaDireccion.y != 0) {
        direccion = nuevaDireccion;
    }
}