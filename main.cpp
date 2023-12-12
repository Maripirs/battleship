//Authors: Maripi Bartosch, Semra Ozdemir
//Date Completed: 12/11/2023
//Purpose: PA5 - Battleship
//Description: This program emulates a single player version of the classic game of Battleship in which the user attempts to sink all the ships of an AI opponent before the AI destroys the user's fleet.

#include "helpers.h"

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
        // createBoard(userPlayer);
        createTestBoard(userPlayer);
        createBoard(aiPlayer);
        clearScreen();
        displayBoards(userPlayer, aiPlayer);
        while (!gameOver) {
            currPlayer = (currPlayer == 1 ? 0 : 1);
            switch (currPlayer) {
                case 1:
                    // displayBoards(userPlayer, aiPlayer);
                    gameOver = takeTurn(userPlayer, aiPlayer);
                    break;
                case 0:
                    gameOver = takeTurn(aiPlayer, userPlayer);
                    break;
            }
        }
        endGameMessage();
        exitProgram = !getYN();
    }
    finalMessage();
    return 0;
}