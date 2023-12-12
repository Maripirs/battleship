//Authors: Maripi Bartosch, Semra Ozdemir
//Purpose: 
//Description: 

#ifndef COOR_H
#define COOR_H
#include <iostream>
using namespace std;
class Coor {
    int y;
    int x;
    bool isShip;
    char currDisplay;

   public:
    Coor();
    Coor(int, int, bool, char);
    Coor(const Coor&);

    void setX(int);
    void setY(int);
    void setIsShip(bool);
    void setCurrDisplay(char);

    int getX();
    int getY();
    bool getIsShip();
    char getCurrDisplay();

    bool operator==(const Coor&);
    Coor& operator=(const Coor&);
    friend ostream& operator<<(ostream&, const Coor&);
};
#endif