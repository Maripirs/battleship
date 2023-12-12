//Authors: Maripi Bartosch, Semra Ozdemir
//Purpose: 
//Description: 

#ifndef BOARD_H
#define BOARD_H
#include "arr.h" 
#include "coor.h"
class Board {
    Arr<Coor> boardArr;
    int rows;
    int cols;
    bool isHuman;

   public:
    Board();
    Board(Arr<Coor>&, int, int, bool);
    Board(const Board&);

    void setBoardArr(Arr<Coor>&);
    void setRows(int);
    void setCols(int);

    void setIsHuman(bool);

    Arr<Coor>& getBoardArr();
    int getRows();
    int getCols();

    bool getIsHuman();

    friend ostream& operator<<(ostream&, Board&);

    Board& operator=(const Board& rhs);
    bool checkValid(Coor);

    void placeShip(Coor, bool, int);
};
#endif