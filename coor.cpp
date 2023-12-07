#include "coor.h"
Coor::Coor() {
    x = -1;
    y = -1;
    isShip = false;
    currDisplay = '-';
}
Coor::Coor(int newX, int newY, bool s, char c) {
    x = newX;
    y = newY;
    isShip = s;
    currDisplay = c;
}
Coor::Coor(const Coor& rhs) {
    x = rhs.x;
    y = rhs.y;
    isShip = rhs.isShip;
    currDisplay = rhs.currDisplay;
}

void Coor::setX(int newX) { x = newX; }
void Coor::setY(int newY) { y = newY; }
void Coor::setIsShip(bool s) { isShip = s; }
void Coor::setCurrDisplay(char c) { currDisplay = c; }

int Coor::getX() { return x; }
int Coor::getY() { return y; }
bool Coor::getIsShip() { return isShip; }
char Coor::getCurrDisplay() { return currDisplay; }

bool Coor::operator==(const Coor& other) {
    return (y == other.y && x == other.x);
}
