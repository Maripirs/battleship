//Authors: Maripi Bartosch, Semra Ozdemir
//Purpose: 
//Description: 

#ifndef USER_H
#define USER_H
#include "player.h"
class User : public Player {
   public:
    User();
    User(string, Board&, Arr<Coor>&, Arr<Ship>&);
    User(const User&);
    Coor chooseCoor();
};
#endif