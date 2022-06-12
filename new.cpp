
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

void startGame();
void printTitle();
void printMenu();
void doGame();
void doStats();
void clearConsole();
void printTopBar();
void printTopData(int pCV, int pFDCV, int pHV, int dCV, int dFDCV, int dHV);
void printChoiceMenu();
vector<int> setCards();
void removeCard(vector<int>, int);
int returnCard(vector<int>);

string handleInput();

int main(int argc, char **argv)
{
    srand(static_cast<unsigned int>(time(0)));

    // Game state variables
    bool validated = false;
    string input;

    startGame();
    return 0;
}

void printTitle()
{
    cout << "\n░█▀▀█ ░█─── ─█▀▀█ ░█▀▀█ ░█─▄▀ ───░█ ─█▀▀█ ░█▀▀█ ░█─▄▀\n";
    cout << "░█▀▀▄ ░█─── ░█▄▄█ ░█─── ░█▀▄─ ─▄─░█ ░█▄▄█ ░█─── ░█▀▄─\n";
    cout << "░█▄▄█ ░█▄▄█ ░█─░█ ░█▄▄█ ░█─░█ ░█▄▄█ ░█─░█ ░█▄▄█ ░█─░█\n\n";
};
void startGame()
{
    printTitle();
    printMenu();

    bool validated = false;
    string input;
    while (!validated)
    {
        input = handleInput();
        if (input == "1" || input == "2" || input == "3")
        {
            validated = true;
        }
        else
        {
            cout << "Invalid Input\n";
        }
    }
    switch (stoi(input))
    {
    case 1:
        doGame();
        break;
    case 2:
        cout << "2" << endl;
        doStats();
        break;
    case 3:
        exit(0);
        break;
    default:
        break;
        ;
    }
}
void printMenu()
{
    cout << "Main Menu" << endl;
    cout << " 1 | New Game\n";
    cout << " 2 | Display Player Wins \n";
    cout << " 3 | Quit\n";
}
string handleInput()
{
    string input;
    cout << "Input: ";
    cin >> input;
    return input;
}
void doGame()
{
    string input;
    vector<int> cards = setCards();

    bool busted = false;
    bool folded = false;
    bool validated = false;

    clearConsole();

    while (!folded && !busted)
    {
        validated = false;
        input = "";
        printTitle();
        printTopBar();
        printTopData(0, 0, 0, 0, 0, 0);
        printChoiceMenu();
        int card = returnCard(cards);
        cout << "CARD VALUE " << card << endl;
        while (!validated)
        {
            input = handleInput();
            if (input == "1" || input == "2" || input == "3")
            {
                validated = true;
            }
            else
            {
                cout << "Invalid Input\n";
            }
        }
        switch (stoi(input))
        {
        case 1:
            cout << "HITTING" << endl;
            break;
        case 2:
            cout << "STANDING" << endl;
            break;
        case 3:
            cout << "FOLDING" << endl;
            folded = true;
            break;
        }
        clearConsole();
    }
};

void doStats()
{
}
void clearConsole()
{
    system("cls");
    system("clear");
}
void printTopBar()
{
    cout << "█▀█ █░░ ▄▀█ █▄█ █▀▀ █▀█       "
            "█▀▄ █▀▀ ▄▀█ █░░ █▀▀ █▀█\n";
    cout << "█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄       "
            "█▄▀ ██▄ █▀█ █▄▄ ██▄ █▀▄\n\n";
}

void printTopData(int pCV, int pFDCV, int pHV, int dCV, int dFDCV, int dHV)
{
    cout << "   Card Value | 1                        Card Value | 1\n";
    cout << "Facedown Card | 1                     Facedown Card | 1\n";
    cout << "   Hand Value | 1                        Hand Value | 1\n\n";
}

void printChoiceMenu()
{
    cout << "Hit, Stand, Or Fold" << endl;
    cout << " 1 | Hit\n";
    cout << " 2 | Stand\n";
    cout << " 3 | Fold\n";
}

int returnCard(vector<int> cards)
{
    int card = cards[rand() % cards.size()];
    return card;
}
vector<int> setCards()
{
    vector<int> cards(48, 0);
    int i = 0;
    while (i < 4)
    {
        cards[i] = 1;
        i++;
    }
    while (i < 8)
    {
        cards[i] = 2;
        i++;
    }
    while (i < 12)
    {
        cards[i] = 3;
        i++;
    };
    while (i < 16)
    {
        cards[i] = 4;
        i++;
    }
    while (i < 20)
    {
        cards[i] = 5;
        i++;
    }
    while (i < 24)
    {
        cards[i] = 6;
        i++;
    }
    while (i < 28)
    {
        cards[i] = 7;
        i++;
    }
    while (i < 32)
    {
        cards[i] = 8;
        i++;
    }
    while (i < 36)
    {
        cards[i] = 9;
        i++;
    }
    while (i < 48)
    {
        cards[i] = 10;
        i++;
    }
    return cards;
};
