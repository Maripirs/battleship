// Authors: Maripi Bartosch, Semra Ozdemir
// Purpose:
// Description:

#ifndef AI_H
#define AI_H
#include <stdlib.h>

#include "player.h"
class Ai : public Player {
   public:
    Ai();
    Ai(string, Board&, Arr<Coor>&, Arr<Ship>&);
    Ai(const Ai&);

    // puprose: Will return a random coordinate.
    // input: None
    // output: Coor. A randomly generated Coordinate for a 10x10 Grid.

    Coor chooseCoor();
};
#endif