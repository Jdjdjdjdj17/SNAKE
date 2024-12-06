#ifndef GAME_H
#define GAME_H

#include "Snake.hpp"
#include "Food.hpp"

class Game {
private:
    Snake snake;
    Food food;
    int ancho, alto;
    bool gameOver;

public:
    Game(int ancho, int alto);

    void iniciar();
    void dibujar() const;
    void manejarInput();
    void actualizar();

    bool estaTerminado() const;
};

#endif // GAME_H