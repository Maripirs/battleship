#include "ship.h"
Ship::Ship() {
    size = -1;
    name = "NONE";
    hits = 0;
}
Ship::Ship(int s, string n, int h, Arr<Coor>& c) {
    size = s;
    name = n;
    hits = h;
    coors = c;
}
Ship::Ship(const Ship& rhs) {
    size = rhs.size;
    name = rhs.name;
    hits = rhs.hits;
    coors = rhs.coors;
}

int Ship::getSize() { return size; }
string Ship::getName() { return name; }
int Ship::getHits() { return hits; }
Arr<Coor>& Ship::getCoors() { return coors; }

void Ship::setSize(int s) { size = s; }
void Ship::setName(string n) { name = n; }
void Ship::setHits(int h) { hits = h; }
void Ship::setCoors(Arr<Coor>& c) { coors = c; }

bool Ship::isHit(Coor) { cout << "Is Hit not implemented" << endl; }
bool Ship::isDead() { cout << "Is Dead not implemented" << endl; }

Ship& Ship::operator=(const Ship& rhs) {
    size = rhs.size;
    name = rhs.name;
    hits = rhs.hits;
    coors = rhs.coors;
    return *this;
}
