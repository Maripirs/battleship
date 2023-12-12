// Authors: Maripi Bartosch, Semra Ozdemir
// Purpose:
// Description:

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

    /*
    Puprose: Insertion operator overload. Used to display a single board.
    Input:
        Ostrem:  ostream object to output onto.
        Board: Board object to output
    Output: The output stream.
    */
    friend ostream& operator<<(ostream&, Board&);
    /*
    Puprose: Asignment operator overload.
    Input:
        Board: Object to copy.
    Output: The updated version of the Board object.
    */
    Board& operator=(const Board& rhs);

    /*
    Puprose: Will check if the coordinate in question is within the edges of the
    board and if it's empty. Input: Coor: The coordinate to check. Output: Bool.
    Wheter the coordinate is a valid choice for ship placement.
    */
    bool checkValid(Coor);

    /*
    Puprose: Will update the appropiate coordinates to contain a ship and their
    appropiate display. Input: Coor: The starting coordinate to place the ship.
        Bool: Whether the ship is being placed horizontally.
        Int: The size of the ship.
    Output: None. All updates directly on the Board object.
    */
    void placeShip(Coor, bool, int);
};
#endif