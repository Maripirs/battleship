// Authors: Maripi Bartosch, Semra Ozdemir
// Purpose: Creating a "Player" class that serves as a virtual base class from
// which "AI" and "User" inherit Description: The player's name is stored in
// "name"; "board" consists of an array of 100 Coordinate objects that make up
// the player's 10x10 board; the player's guessed coordinates are tracked in
// "guessedCoors"; and the player's five-ship fleet is held in "ships".

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
    // purpose: Virtual method to get a Coordinate from the player to target.
    // input: None
    // output: Coor: The coordinate that the player will target.
    virtual Coor chooseCoor() = 0;
    // purpose: Once a ship's been hit, this function will identify which of the
    // ships was attacked. input: Coor: Coordinate that was attacked. output:
    // Ship: Ship object that includes the coordinate in question on it's array.
    Ship findHitShip(Coor);
    // purpose: Simple function to determine whether all of the player's ships
    // are dead. input: None. output: Bool inicating whether all of the player's
    // ships are dead.
    bool checkLost();
    // purpose: Checks whether the Coordinate provided has already been guessed
    // by the current player input:Coor. Coordinate in question. output: Bool
    // whether the Coordinate provided has already been guessed by the current
    // player.
    bool isGuessed(Coor);
    // purpose:  Insertion operator overload. Used to display a Player object.
    // input: Ostream object to hold the output
    //        Player object to display
    // output:Ostream object holding the output
    friend ostream& operator<<(ostream&, const Player&);
};
#endif