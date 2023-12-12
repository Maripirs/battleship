//Authors: Maripi Bartosch, Semra Ozdemir
//Purpose: Creating a "Player" class that serves as a virtual base class from which "AI" and "User" inherit
//Description: The player's name is stored in "name"; "board" consists of an array of 100 Coordinate objects that make up the player's 10x10 board;
//the player's guessed coordinates are tracked in "guessedCoors"; and the player's five-ship fleet is held in "ships".

#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "ship.h"
class Player {
   protected:
    string name;
    Board board;
    Arr<Coor> guessedCoors;
    Arr<Ship> ships;

   public:
    Player();
    Player(string, Board&, Arr<Coor>&, Arr<Ship>&);
    Player(const Player&);

    void setName(string);
    void setBoard(Board&);
    void setGuessedCoors(Arr<Coor>);
    void setShips(Arr<Ship>);

    string getName();
    Board& getBoard();
    Arr<Coor>& getGuessedCoors();
    Arr<Ship>& getShips();

    virtual Coor chooseCoor() = 0;
    Ship findHitShip(Coor);
    bool checkLost();
    bool isGuessed(Coor);
    friend ostream& operator<<(ostream&, const Player&);
};
#endif