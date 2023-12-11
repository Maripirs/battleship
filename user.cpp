#include "user.h"

#include "helpers.h"

User::User() : Player() { board.setIsHuman(true); }
User::User(string n, Board& b, Arr<Coor>& c, Arr<Ship>& s)
    : Player(n, b, c, s) {}
User::User(const User& rhs) : Player(rhs) {}
Coor& User::chooseCoor() {
    int row, col;
    // cout << "User choose Coor is not implemented" << endl;
    cout << "Enter Row (A-J): ";
    row = getValidInput('A', 'J') - 65;
    cout << "Enter Column (1 - 10): ";
    col = getValidInput(1, 10) - 1;
    Coor newCoor(col, row, false, ' ');
    // DONT KNOW IF IT EXISTS OUT OF SCOPE
    return newCoor;
}