#include "user.h"

User::User() : Player() {}
User::User(string n, Board& b, Arr<Coor>& c, Arr<Ship>& s)
    : Player(n, b, c, s) {}
User::User(const User& rhs) : Player(rhs) {}
Coor& User::chooseCoor() {
    cout << "User choose Coor is not implemented" << endl;
}