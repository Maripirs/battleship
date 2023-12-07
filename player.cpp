
#include "player.h"
Player::Player() { name = "none"; }

Player::Player(string n, Board& b, Arr<Coor>& c, Arr<Ship>& s) {
    name = n;
    board = b;
    guessedCoors = c;
    ships = s;
}
Player::Player(const Player& rhs) {
    name = rhs.name;
    board = rhs.board;
    guessedCoors = rhs.guessedCoors;
    ships = rhs.ships;
}

void Player::setName(string n) { name = n; }
void Player::setBoard(Board& b) { board = b; }
void Player::setGuessedCoors(Arr<Coor> c) { guessedCoors = c; }
void Player::setShips(Arr<Ship> s) { ships = s; }

string Player::getName() { return name; }
Board& Player::getBoard() { return board; }
Arr<Coor>& Player::getGuessedCoors() { return guessedCoors; }
Arr<Ship>& Player::getShips() { return ships; }

Ship Player::findHitShip() {
    cout << "Find hit ship is not implemented" << endl;
}
bool Player::checLost() { cout << "Check Lost is not implemented" << endl; }