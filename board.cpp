#include "board.h"

#include "helpers.h"
Board::Board() {
    rows = 10;
    cols = 10;
    isHuman = false;
    for (int i = 0; i < 100; i++) {
        Coor coor;
        boardArr.addToEnd(coor);
    }
}
Board::Board(Arr<Coor>& b, int r, int c, bool h) {
    boardArr = b;
    rows = r;
    cols = c;
    isHuman = h;
}
Board::Board(const Board& rhs) {
    boardArr = rhs.boardArr;
    rows = rhs.rows;
    cols = rhs.cols;
    isHuman = rhs.isHuman;
}

void Board::setBoardArr(Arr<Coor>& b) { boardArr = b; }
void Board::setRows(int r) { rows = r; }
void Board::setCols(int c) { cols = c; }

void Board::setIsHuman(bool h) { isHuman = h; }

Arr<Coor>& Board::getBoardArr() { return boardArr; }
int Board::getRows() { return rows; }
int Board::getCols() { return cols; }

bool Board::getIsHuman() { return isHuman; }

Board& Board::operator=(const Board& rhs) {
    boardArr = rhs.boardArr;
    rows = rhs.rows;
    cols = rhs.cols;
    isHuman = rhs.isHuman;
    return *this;
}
bool Board::checkValid(Coor c) {
    int idx = translateCoor(c);
    if (c.getX() > 9 || c.getY() > 9) {
        if (isHuman) {
            cout << "Your ship doesn't fit on the board. Choose a different "
                    "spot."
                 << endl;
        }
        return false;
    }
    if (boardArr.getAtIndex(idx).getIsShip()) {
        if (isHuman) {
            cout << "Your ship is overlapping with an already placed one. "
                    "Choose a "
                    "different spot."
                 << endl;
        }
        return false;
    }
    return true;
}

void Board::placeShip(Coor s, bool h, int c) {
    int index = translateCoor(s);
    for (int i = 0; i < c; i++) {
        boardArr.getAtIndex(index).setIsShip(true);
        if (isHuman) {
            boardArr.getAtIndex(index).setCurrDisplay('#');
        } else {
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            boardArr.getAtIndex(index).setCurrDisplay('&');
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
            //REMOVE BEFORE TURNING IN
        }
        if (h) {
            index++;
        } else {
            index += 10;
        }
    }
}