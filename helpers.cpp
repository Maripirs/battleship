#include "helpers.h"

// ORGANIZE THIS FUNCTION
void createBoard(Player& pl) {
    Arr<Ship> ships = pl.getShips();
    int currRow, currCol;
    bool human = pl.getBoard().getIsHuman();
    for (int i = 0; i < ships.getNum(); i++) {
        bool placed = false;
        Coor startCoor;
        while (!placed) {
            bool horizontal;
            bool free = false;
            while (!free) {
                if (human) {
                    cout << "Choose top left corner for your "
                         << ships.getAtIndex(i).getName()
                         << " - Size: " << ships.getAtIndex(i).getSize();
                }
                startCoor = pl.chooseCoor();
                currCol = startCoor.getX();
                currRow = startCoor.getY();
                free = pl.getBoard().checkValid(startCoor);
            }
            if (human) {
                cout << "Do you want this ship horizontal?(y/n) ";
                horizontal = getYN();
            } else {
                horizontal = rand() % 2;
            }
            bool success = true;
            for (int j = 1; j < pl.getShips().getAtIndex(i).getSize(); j++) {
                horizontal ? currCol++ : currRow++;
                Coor tempCoor(currCol, currRow, false, ' ');
                if (!pl.getBoard().checkValid(tempCoor)) {
                    success = false;
                    break;
                }
            }
            if (success) {
                pl.getBoard().placeShip(startCoor, horizontal,
                                        pl.getShips().getAtIndex(i).getSize());
                Arr<Coor> shipCoors;
                Coor temp = startCoor;
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
    Coor chosenCoor;
    while (!validChoice) {
        cout << " Choose a Coordinate to attack! " << endl;
        chosenCoor = current.chooseCoor();
        if (current.isGuessed(chosenCoor)) {
            cout << "You've already attacked this space" << endl;
        } else {
            validChoice = true;
        }
    }

    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    current.getGuessedCoors().addToEnd(chosenCoor);
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    // ADD OPERATION OVERLOAD
    int idx = translateCoor(chosenCoor);
    if (opponent.getBoard().getBoardArr().getAtIndex(idx).getIsShip()) {
        opponent.getBoard().getBoardArr().getAtIndex(idx).setCurrDisplay('X');
        Ship tempShip = opponent.findHitShip(chosenCoor);
        cout << "It's a hit!" << endl;
        cout << tempShip.getName() << " has been hit " << tempShip.getHits()
             << "times. It has a total of " << tempShip.getSize() << "spaces"
             << endl;
        // NOT WORKING AS EXPECTED!
        // NOT WORKING AS EXPECTED!
        // NOT WORKING AS EXPECTED!
        // NOT WORKING AS EXPECTED!
        // NOT WORKING AS EXPECTED!
        // NOT WORKING AS EXPECTED!
        // NOT WORKING AS EXPECTED!
        // NOT WORKING AS EXPECTED!
        if (tempShip.isDead()) {
            cout << tempShip.getName() << "sunk!" << endl;
            if (opponent.checkLost()) {
                cout << "All of the opponent ships have been sunk." << endl;
                cout << current.getName() << "Wins! Congratulations." << endl;
                return true;
            }
        }
    } else {
        opponent.getBoard().getBoardArr().getAtIndex(idx).setCurrDisplay('O');
        cout << "It's a miss!" << endl;
    }
    return false;
}

ostream& operator<<(ostream& out, const Ship& a) {
    out << "name: " << a.name << endl;
    out << "size: " << a.size << endl;

    return out;
}
ostream& operator<<(ostream& out, const Player& a) {
    out << "Player Name: " << a.name << endl;
    return out;
}
ostream& operator<<(ostream& out, const Coor& a) {
    out << "X: " << a.x << endl;
    out << "Y: " << a.y << endl;
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
        out << a.getAtIndex(i);
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

void spacer() { cout << "       "; }
// UPGRADE
void displayBoards(Player& a, Player& b) {
    cout << endl;
    cout << "    ------------- " << a.getName() << "'s Board ------------    ";
    spacer();
    cout << "    ------------- " << b.getName() << "'s Board ------------    "
         << endl
         << endl;

    printNumbers();
    spacer();
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
        cout << "  ";
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

    // for (int i = 0; i < (a.getrows * a.cols); i++) {
    //     out << "| " << a.getBoardArr().getAtIndex(i).getCurrDisplay() << " ";
    //     // cout << "|" << i;
    //     if (i % 10 == 9) {
    //         out << "|";
    //         spacer() endl;
    //         printLine();
    //         out << endl;
    //         if (count < 9) {
    //             out << letter << " ";
    //             letter++;
    //             count++;
    //         }
    //     }
    // }
}