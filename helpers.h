#include "ai.h"
#include "user.h"

void createBoard(Player&);

bool takeTurn(Player&, Player&);

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

bool getYN();
void printLine();

void displayWelcome();
void endGameMessage();
void finalMessage();
int translateCoor(Coor);

void printNumbers();
void displayBoards(Player&, Player&);
void clearScreen();

void createTestBoard(Player& pl);

char idxToLetter(int);

Coor chooseFreeCoor(Ship&, Player&);
bool shipFits(Ship&, Player&, bool, Coor);