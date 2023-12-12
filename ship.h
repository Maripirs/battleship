// Authors: Maripi Bartosch, Semra Ozdemir
// Purpose:
// Description:

#ifndef SHIP_H
#define SHIP_H
#include "arr.h"
#include "coor.h"
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
    // purpose: Determine whether a given Coordinate belongs to this ship.
    // input: Coor. Coordinate in question
    // output:Bool. whether a given Coordinate belongs to this ship
    bool isHit(Coor);
    // purpose: Compares the size of the ship with the times it's been hit to
    // determine whether the ship is dead.
    // input: None
    // output:Bool. Whether the ship is dead
    bool isDead();
    // purpose:  Assignment operator overload. Used to copy a Ship object.
    // input: Ship to copy
    // output:Updated ship object.
    Ship& operator=(const Ship&);
    // purpose:  Insertion operator overload. Used to display a Ship object.
    // input: Ostream object to hold the output
    //        Ship object to display
    // output:Ostream object holding the output
    friend ostream& operator<<(ostream&, const Ship&);
};
#endif