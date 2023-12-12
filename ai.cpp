#include "ai.h"

Ai::Ai() : Player() { name = "AI"; }
Ai::Ai(string n, Board& b, Arr<Coor>& c, Arr<Ship>& s) : Player(n, b, c, s) {}
Ai::Ai(const Ai& rhs) : Player(rhs) {}
Coor Ai::chooseCoor() {
    Coor tempCoor;
    tempCoor.setY(rand() % 10);
    tempCoor.setX(rand() % 10);
    return tempCoor;
}