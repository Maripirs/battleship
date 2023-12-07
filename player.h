#ifndef PLAYER_H
#define PLAYER_H
#include "arr.h"  //alreadu in coor
#include "board.h"
#include "coor.h"  //already in board
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
    Ship findHitShip();
    bool checLost();
};
#endif