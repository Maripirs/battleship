// Authors: Maripi Bartosch, Semra Ozdemir
#include "ai.h"
#include "arr.h"
#include "board.h"
#include "coor.h"
#include "helpers.h"
#include "ship.h"
#include "user.h"

// Need to fix includes and makefile
int main() {
    bool exitProgram = false;

    while (!exitProgram) {
        Board board;
        User userPlayer;
        Ai aiPlayer;
        string name;
        int currPlayer = 0;
        bool gameOver = false;
        displayWelcome();
        cin >> name;
        userPlayer.setName(name);
        createBoard(userPlayer);
        createBoard(aiPlayer);


        while (!gameOver) {
            currPlayer = (currPlayer == 1 ? 0 : 1);
            switch (currPlayer) {
                case 1:
                    displayBoards(userPlayer, aiPlayer);
                    gameOver = takeTurn(userPlayer, aiPlayer);
                    break;
                case 0:
                    displayBoards(aiPlayer, userPlayer);
                    gameOver = takeTurn(aiPlayer, userPlayer);
                    break;
            }
        }
        endGameMessage();
        exitProgram = getValidInput(1, 2);
        exitProgram = true;
    }
    finalMessage();
    return 0;
}