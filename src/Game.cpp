#include <Game.hpp>
#include <iostream>
#include <conio.h>
#include <windows.h>

Game::Game(int ancho, int alto)
    : snake(ancho / 2, alto / 2), food(ancho, alto), ancho(ancho), alto(alto), gameOver(false) {}

void Game::iniciar() {
    while (!gameOver) {
        dibujar();
        manejarInput();
        actualizar();
        Sleep(100);
    }
}

void Game::dibujar() const {
    system("cls");

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            Posicion actual(j, i);
            if (snake.obtenerCuerpo()[0] == actual)
                std::cout << "O";
            else if (food.obtenerPosicion() == actual)
                std::cout << "F";
            else {
                bool esCuerpo = false;
                for (const auto& segmento : snake.obtenerCuerpo()) {
                    if (segmento == actual) {
                        esCuerpo = true;
                        break;
                    }
                }
                std::cout << (esCuerpo ? "o" : " ");
            }
        }
        std::cout << "\n";
    }
}

void Game::manejarInput() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w': snake.cambiarDireccion(Posicion(0, -1)); break;
        case 's': snake.cambiarDireccion(Posicion(0, 1)); break;
        case 'a': snake.cambiarDireccion(Posicion(-1, 0)); break;
        case 'd': snake.cambiarDireccion(Posicion(1, 0)); break;
        }
    }
}

void Game::actualizar() {
    snake.mover();

    if (snake.obtenerCuerpo()[0] == food.obtenerPosicion()) {
        snake.crecer();
        food.regenerar(ancho, alto);
    }

    if (snake.colisiona(snake.obtenerCuerpo()[0])) {
        gameOver = true;
    }
}

bool Game::estaTerminado() const {
    return gameOver;
}