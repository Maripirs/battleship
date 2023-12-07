#ifndef BOARD_H
#define BOARD_H
#include "Arr.h"  //Don't think we need it
#include "Coor.h"
class Board {
    Arr<Arr<Coor>> board;
    int rows;
    int cols;

    bool isHuman;

   public:
    Board();
    Board(Arr<Arr<Coor>>&, int, int, bool);
    Board(const Board&);

    void setBoard(Arr<Arr<Coor>>&);
    void setRows(int);
    void setCols(int);

    void setIsHuman(bool);

    Arr<Arr<Coor>>& getBoard();
    int getRows();
    int getCols();

    bool getIsHuman();

    void displayBoard();
};
#endif