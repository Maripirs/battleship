//Authors: Maripi Bartosch, Semra Ozdemir
//Purpose: Helper functions that manage turn-taking, board creation, menus, and message displays

#include "ai.h"
#include "user.h"

//purpose: Sets up the fleet board for both the user and the AI
//input: Player object passed by reference
//output: none; player's board is updated inside function
void createBoard(Player&);

//purpose: Gets a coordinate that the player wishes to attack, 
//input:
//output:
bool takeTurn(Player&, Player&);

//purpose:
//input:
//output:
template <typename T>
T getValidInput(T min, T max) {
    // cout << "Get Valid input is not implemented" << endl;
    T temp;

    while (true) {
        cin >> temp;
        if (temp >= min && temp <= max) {
            return temp;
        }
        cout << "Invalid entry. Try again." << endl;
    }
}

//purpose:
//input:
//output:
bool getYN();
//purpose:
//input:
//output:
void printLine();

//purpose:
//input:
//output:
void displayWelcome();
//purpose:
//input:
//output:
void endGameMessage();
//purpose:
//input:
//output:
void finalMessage();

//purpose:
//input:
//output:
int translateCoor(Coor);

//purpose:
//input:
//output:
void printNumbers();
//purpose:
//input:
//output:
void displayBoards(Player&, Player&);
//purpose:
//input:
//output:
void clearScreen();

//void createTestBoard(Player& pl);  //only for testing purposes

//purpose:
//input:
//output:
char idxToLetter(int);

//purpose:
//input:
//output:
Coor chooseFreeCoor(Ship&, Player&);

//purpose:
//input:
//output:
bool shipFits(Ship&, Player&, bool, Coor);