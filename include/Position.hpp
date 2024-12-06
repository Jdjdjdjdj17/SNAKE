#ifndef POSICION_H
#define POSICION_H

class Posicion {
public:
    int x, y;

    Posicion(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Posicion& other) const {
        return x == other.x && y == other.y;
    }
};

#endif // POSICION_H