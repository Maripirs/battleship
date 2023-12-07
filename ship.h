#ifndef SHIP_H
#define SHIP_H
#include "arr.h"
#include "coor.h"  //Don't think we need this one.
class Ship {
    int size;
    string name;
    int hits;
    Arr<Coor> coors;

   public:
    Ship();
    Ship(int, string, int, Arr<Coor>&);
    Ship(const Ship&);

    int getSize();
    string getName();
    int getHits();
    Arr<Coor>& getCoors();

    void setSize(int);
    void setName(string);
    void setHits(int);
    void setCoors(Arr<Coor>&);

    bool isHit(Coor);
    bool isDead();

    Ship& operator=(const Ship&);
};
#endif