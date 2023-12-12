// Authors: Maripi Bartosch, Semra Ozdemir
// Purpose:
// Description:

#ifndef USER_H
#define USER_H
#include "player.h"
class User : public Player {
   public:
    User();
    User(string, Board&, Arr<Coor>&, Arr<Ship>&);
    User(const User&);
    // puprose: Will prompt the user to select a coordinate within range.
    // input: None
    // output: Coor. The coordinate selected by the user.
    Coor chooseCoor();
};
#endif