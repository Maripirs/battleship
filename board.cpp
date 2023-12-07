#include "board.h"

Board::Board() {
    rows = 10;
    cols = 10;
    isHuman = false;
}
Board::Board(Arr<Arr<Coor> >& b, int r, int c, bool h) {
    board = b;
    rows = r;
    cols = c;
    isHuman = h;
}
Board::Board(const Board& rhs) {
    board = rhs.board;
    rows = rhs.rows;
    cols = rhs.cols;
    isHuman = rhs.isHuman;
}

void Board::setBoard(Arr<Arr<Coor> >& b) { board = b; }
void Board::setRows(int r) { rows = r; }
void Board::setCols(int c) { cols = c; }

void Board::setIsHuman(bool h) { isHuman = h; }

Arr<Arr<Coor> >& Board::getBoard() { return board; }
int Board::getRows() { return rows; }
int Board::getCols() { return cols; }

bool Board::getIsHuman() { return isHuman; }

void Board::displayBoard() { cout << "Display Board not implemented" << endl; }