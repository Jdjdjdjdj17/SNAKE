#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Position.hpp"

class Snake {
private:
    std::vector<Posicion> cuerpo; // Segmentos de la serpiente
    Posicion direccion;

public:
    Snake(int xInicial, int yInicial);

    void mover();
    void crecer();
    bool colisiona(const Posicion& pos) const;

    const std::vector<Posicion>& obtenerCuerpo() const;
    void cambiarDireccion(const Posicion& nuevaDireccion);
};

#endif // SNAKE_H