//Authors: Maripi Bartosch, Semra Ozdemir
//Purpose: 
//Description: 

#ifndef AI_H
#define AI_H
#include <stdlib.h>
#include "player.h"
class Ai : public Player {
   public:
    Ai();
    Ai(string, Board&, Arr<Coor>&, Arr<Ship>&);
    Ai(const Ai&);
    Coor chooseCoor();
};
#endif