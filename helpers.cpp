#include "helpers.h"

#include "ai.h"
// ORGANIZE THIS FUNCTION
void createBoard(Player& pl) {
    srand(time(NULL));
    Arr<Ship> ships = pl.getShips();
    int currRow, currCol;
    bool human = pl.getBoard().getIsHuman();
    cout << pl.getBoard();
    for (int i = 0; i < ships.getNum(); i++) {
        bool placed = false;
        Coor startCoor;
        while (!placed) {
            bool horizontal;
            startCoor = chooseFreeCoor(ships.getAtIndex(i), pl);
            currCol = startCoor.getX();
            currRow = startCoor.getY();
            if (human) {
                cout << "Do you want this ship horizontal?(y/n) ";
                horizontal = getYN();
            } else {
                horizontal = rand() % 2;
            }
            bool success = shipFits(pl.getShips().getAtIndex(i), pl, horizontal,
                                    startCoor);
            if (success) {
                pl.getBoard().placeShip(startCoor, horizontal,
                                        pl.getShips().getAtIndex(i).getSize());
                Arr<Coor> shipCoors;
                Coor temp = startCoor;
                currCol = startCoor.getX();
                currRow = startCoor.getY();
                for (int j = 0; j < pl.getShips().getAtIndex(i).getSize();
                     j++) {
                    shipCoors.addToEnd(temp);
                    horizontal ? currCol++ : currRow++;
                    temp = Coor(currCol, currRow, false, ' ');
                }
                Ship tempShip(pl.getShips().getAtIndex(i));
                tempShip.setCoors(shipCoors);
                pl.getShips().replaceAtIndex(i, tempShip);
                placed = true;
                cout << pl.getBoard();
            }
        }
    }
}

bool getYN() {
    char yesNo = 'x';
    while (true) {
        cin >> yesNo;
        if (yesNo == 'y' || yesNo == 'Y') {
            return true;
        } else
            return false;
    }
}

bool takeTurn(Player& current, Player& opponent) {
    bool validChoice = false;
    bool human = current.getBoard().getIsHuman();
    Coor chosenCoor;
    while (!validChoice) {
        if (human) {
            cout << "Choose a Coordinate to attack! " << endl;
            chosenCoor = current.chooseCoor();
            if (current.isGuessed(chosenCoor)) {
                cout << "You've already attacked this space" << endl;
            } else {
                validChoice = true;
            }
        } else {
            chosenCoor = current.chooseCoor();
            if (!current.isGuessed(chosenCoor)) {
                validChoice = true;
            }
        }
    }
    if (human) {
        displayBoards(current, opponent);
        clearScreen();
    }
    cout << current.getName() << " Targeted: " << idxToLetter(chosenCoor.getY())
         << chosenCoor.getX() + 1 << ". ";
    current.getGuessedCoors() + chosenCoor;
    int idx = translateCoor(chosenCoor);
    if (opponent.getBoard().getBoardArr().getAtIndex(idx).getIsShip()) {
        opponent.getBoard().getBoardArr().getAtIndex(idx).setCurrDisplay('X');
        Ship tempShip = opponent.findHitShip(chosenCoor);
        cout << "It's a hit!" << endl;
        if (tempShip.isDead()) {
            cout << tempShip.getName() << " Sunk!" << endl;
            if (opponent.checkLost()) {
                cout << "All of " << opponent.getName()
                     << " ships have been sunk." << endl;
                cout << current.getName() << " Wins! Congratulations." << endl;
                return true;
            }
        }
    } else {
        opponent.getBoard().getBoardArr().getAtIndex(idx).setCurrDisplay('O');
        cout << "It's a miss!" << endl;
    }
    if (!human) {
        displayBoards(opponent, current);
    }
    return false;
}

char idxToLetter(int idx) {
    char letter = 'A';
    for (int i = 0; i < idx; i++) {
        letter++;
    }
    return letter;
}
ostream& operator<<(ostream& out, const Ship& a) {
    out << "name: " << a.name << endl;
    out << "size: " << a.size << endl;
    out << "hits: " << a.hits << endl;

    return out;
}
ostream& operator<<(ostream& out, const Player& a) {
    out << "Player Name: " << a.name << endl;
    return out;
}
ostream& operator<<(ostream& out, const Coor& a) {
    out << "(x,y) :(" << a.x << "," << a.y << ")";
    return out;
}
ostream& operator<<(ostream& out, Board& a) {
    printNumbers();
    cout << endl;
    printLine();
    out << endl;
    char letter = 'A';
    out << letter << " ";
    letter++;
    int count = 0;
    for (int i = 0; i < (a.rows * a.cols); i++) {
        out << "| " << a.getBoardArr().getAtIndex(i).getCurrDisplay() << " ";
        // cout << "|" << i;
        if (i % 10 == 9) {
            out << "|" << endl;
            printLine();
            out << endl;
            if (count < 9) {
                out << letter << " ";
                letter++;
                count++;
            }
        }
    }
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const Arr<T>& a) {
    for (int i = 0; i < a.num; i++) {
        out << a.getAtIndex(i) << endl;
    }
    return out;
}

void printNumbers() {
    int num = 1;
    cout << "  ";
    for (int i = 0; i < 10; i++) {
        cout << "  " << num << " ";
        num++;
    }
}
void printLine() { cout << "   --- --- --- --- --- --- --- --- --- --- "; }
void displayWelcome() {
    cout << "Welcome to Battleship!" << endl;
    cout << "Enter your name to start: ";
}
int translateCoor(Coor c) {
    string coors = "";
    coors += to_string(c.getY());
    coors += to_string(c.getX());
    return stoi(coors);
}
void endGameMessage() {
    cout << "Game over" << endl;
    cout << "Want to play again? (y/n) ";
}
void finalMessage() { cout << "Thanks for playing!" << endl; }

void spacer() { cout << "         "; }
void displayBoards(Player& a, Player& b) {
    cout << endl;
    cout << "    --------------- Your Board ------------";
    spacer();
    cout << "    ------------- Opponent Board ----------    " << endl << endl;

    printNumbers();
    spacer();
    cout << " ";
    printNumbers();

    cout << endl << " ";
    printLine();
    spacer();

    printLine();
    cout << endl;
    char letter = 'A';

    for (int i = 0; i < 10; i++) {
        cout << " " << letter << " |";
        for (int j = 0; j < 10; j++) {
            cout << " "
                 << a.getBoard()
                        .getBoardArr()
                        .getAtIndex(i * 10 + j)
                        .getCurrDisplay()
                 << " |";
        }
        spacer();
        cout << letter << " ";
        for (int j = 0; j < 10; j++) {
            cout << "| "
                 << b.getBoard()
                        .getBoardArr()
                        .getAtIndex(i * 10 + j)
                        .getCurrDisplay()
                 << " ";
        }
        cout << "|";
        cout << endl << " ";
        letter++;
        printLine();
        spacer();
        printLine();
        cout << endl;
    }
}
void clearScreen() {
    //
    cout << "\33[2J\33[H";
    //
}

void createTestBoard(Player& pl) {
    Coor startCoor(0, 0, false, ' ');
    bool horizontal = true;
    int currCol = 0;
    int currRow = 0;
    for (int i = 0; i < 5; i++) {
        pl.getBoard().placeShip(startCoor, horizontal,
                                pl.getShips().getAtIndex(i).getSize());
        Arr<Coor> shipCoors;
        Coor temp = startCoor;
        currCol = startCoor.getX();
        currRow = startCoor.getY();
        for (int j = 0; j < pl.getShips().getAtIndex(i).getSize(); j++) {
            shipCoors.addToEnd(temp);
            horizontal ? currCol++ : currRow++;
            temp = Coor(currCol, currRow, false, ' ');
        }
        Ship tempShip(pl.getShips().getAtIndex(i));
        tempShip.setCoors(shipCoors);
        pl.getShips().replaceAtIndex(i, tempShip);
        Coor newCoor(0, i + 1, false, ' ');
        startCoor = newCoor;
    }
}
Coor chooseFreeCoor(Ship& ship, Player& pl) {
    while (true) {
        if (pl.getBoard().getIsHuman()) {
            cout << "Choose top left corner for your " << ship.getName()
                 << " - Size: " << ship.getSize();
        }
        Coor startCoor = pl.chooseCoor();

        if (pl.getBoard().checkValid(startCoor)) {
            return startCoor;
        }
    }
}

bool shipFits(Ship& ship, Player& pl, bool horizontal, Coor start) {
    int currCol = start.getX();
    int currRow = start.getY();
    for (int j = 1; j < ship.getSize(); j++) {
        horizontal ? currCol++ : currRow++;
        Coor tempCoor(currCol, currRow, false, ' ');
        if (!pl.getBoard().checkValid(tempCoor)) {
            return false;
        }
    }
    return true;
}