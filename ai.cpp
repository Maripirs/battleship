#include "ai.h"

Ai::Ai() : Player() {}
Ai::Ai(string n, Board& b, Arr<Coor>& c, Arr<Ship>& s) : Player(n, b, c, s) {}
Ai::Ai(const Ai& rhs) : Player(rhs) {}
Coor& Ai::chooseCoor() { cout << "AI choose Coor is not implemented" << endl; }