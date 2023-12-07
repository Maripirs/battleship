// Authors: Maripi Bartosch, Semra Ozdemir
#include "ai.h"
#include "arr.h"
#include "board.h"
#include "coor.h"
#include "helpers.h"
#include "ship.h"
#include "user.h"

// Need to fix includes and makefile
int main() {
    Arr<Coor> newArr;
    cout << newArr.getAtIndex(0).getX() << endl;
    Coor newCoor(1, 1, false, 'x');
    Coor newCoor1(1, 2, false, 'o');
    newArr.addToEnd(newCoor);
    newArr.addToEnd(newCoor1);
    cout << newCoor.getX() << " " << newCoor.getY() << endl;
    Ship newShip;
    newShip.setName("ship");
    newShip.setSize(2);
    cout << newShip.getName() << " " << newShip.getSize() << endl;

    Board newBoard;
    newBoard.displayBoard();

    Ai newAi;
    cout << newAi.getName() << endl;
    User newUser;
    cout << newUser.getName() << endl;
    return 0;
}