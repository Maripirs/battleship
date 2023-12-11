
#include "player.h"
Player::Player() {
    name = "none";
    Arr<Coor> emptyCoor;
    Ship carrier(5, "Carrier", 0, emptyCoor);
    Ship battleship(4, "Battleship", 0, emptyCoor);
    Ship destroyer(3, "Destroyer", 0, emptyCoor);
    Ship submarine(3, "Submarine", 0, emptyCoor);
    Ship patrolBoat(2, "Patrol Boat", 0, emptyCoor);

    ships.addToEnd(carrier);
    ships.addToEnd(battleship);
    ships.addToEnd(destroyer);
    ships.addToEnd(submarine);
    ships.addToEnd(patrolBoat);
}

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

Ship Player::findHitShip(Coor c) {
    for (int i = 0; i < ships.getNum(); i++) {
        if (ships.getAtIndex(i).isHit(c)) {
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            int hits = ships.getAtIndex(i).getHits();
            ships.getAtIndex(i).setHits(hits + 1);
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS
            //FIX THIS


            return ships.getAtIndex(i);
        }
    }

    Ship temp;
    return temp;
}
bool Player::checkLost() {
    for (int i = 0; i < 5; i++) {
        if (!ships.getAtIndex(i).isDead()) {
            return false;
        }
    }
    return true;
}

bool Player::isGuessed(Coor c) {
    for (int i = 0; i < guessedCoors.getNum(); i++) {
        if (guessedCoors.getAtIndex(i) == c) {
            return true;
        }
    }
    return false;
}