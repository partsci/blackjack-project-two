/* Library declarations */

#include <iostream>
#include <iomanip>

using namespace std;

/* Variable declarations */

/* Game state variables */
bool run = true; // Game running

/* Input/Output variables */
bool valid;
char input;

/* Game Variables */
string player;
string dealer;

/* Core function prototypes */

/* Utilitie function prototypes */

// Prints game home
void printHome();

void printMainMenu();

void printDetails();

// Handles clearing the screen
void cleanScreen();

// Handles setting the config
void setConfig();

void homeCaller();

void endCaller();

void gameCaller();

// Resets all the running game variables
void setVariables(){

};

// Handles printing content to the window
void print(string content, int width);

void printTitle();
void printMenu();
void printTopBar(string player, string dealer);
void handleInput(char &input, bool validate, char t1, char t2, char t3, char t4);
void newGame();
void loadGame();
void viewStats();
int main(int argc, char *argv[])
{
    printTitle();
}

/* Functions */

void printTitle()
{
    print("\n", 0);
    print("\n", 0);
    print("██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗░░░░░██╗░█████╗░░█████╗░██╗░░██╗\n", 0);
    print("██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝░░░░░██║██╔══██╗██╔══██╗██║░██╔╝\n", 0);
    print("██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░░░░░░██║███████║██║░░╚═╝█████═╝░\n", 0);
    print("██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░██╗░░██║██╔══██║██║░░██╗██╔═██╗░\n", 0);
    print("██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗╚█████╔╝██║░░██║╚█████╔╝██║░╚██╗\n", 0);
    print("╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝\n", 0);
    print("\n", 0);
};

void printMenu()
{
    print("\n", 0);
    print("1 | Start New Game\n", 0);
    print("3 | View Statistics \n", 0);
    print("4 | Quit\n", 0);
    print("\n", 0);
    return;
}

void printGameMenu(){

};

void printPlayerData()
{
    print("█▀█ █░░ ▄▀█ █▄█ █▀▀ █▀█\n", 0);
    print("█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄\n", 0);
    print("\n", 0);
    print("HAND VALUE | 0\n", 0);
    print("CARD VALUE | 10 \n", 0);
    print("\n", 0);
}
void printDealerData()
{
    print("█▀▄ █▀▀ ▄▀█ █░░ █▀▀ █▀█\n", 0);
    print("█▄▀ ██▄ █▀█ █▄▄ ██▄ █▀▄\n", 0);
    print("\n", 0);
    print("HAND VALUE | 0\n", 0);
    print("CARD VALUE | 10 \n", 0);
    print("\n", 0);
}
void printTopBar(string player)
{
    print("Player Name: ", 27);
    print(player, 0);
    print("\n", 0);
    print("\n", 0);
    print("\n", 0);
    print("█▀█ █░░ ▄▀█ █▄█ █▀▀ █▀█                           █▀▄ █▀▀ ▄▀█ █░░ █▀▀ █▀█\n", 0);
    print("█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄                           █▄▀ ██▄ █▀█ █▄▄ ██▄ █▀▄", 0);
    print("\n\n", 0);
    print("    HAND VALUE | 1                                     HAND VALUE | 1\n", 0);
    print("    HAND VALUE | 1                                     HAND VALUE | 1", 0);
};
void printBottomBar()
{
    print("\n\n", 0);
    print("                           █▀▀ █░█ █▀█ █ █▀▀ █▀▀                                                      \n", 0);
    print("                           █▄▄ █▀█ █▄█ █ █▄▄ ██▄                                                      \n", 0);
    print("\n", 0);
    print("                                1 | Hit\n", 0);
    print("                                2 | Stand\n", 0);
    print("                                3 | Fold \n", 0);
}
void clearScreen()
{
    system("cls");
    system("clear");
    return;
}

void setConfig()
{
    // Handle setting the config
    return;
};

void print(string content, int width)
{

    for (int i = 0; i < width; i++)
    {
        cout << " ";
    }
    cout << content;
}

void handleInput(char &input, bool validate, char t1 = 'Z', char t2 = 'Y', char t3 = 'X', char t4 = 'W')
{
    do
    {
        print("Input : ", 0);
        cin >> input;
        if (!validate)
        {
            valid = true;
        }
        else if (input == t1 || input == t2 || input == t3 || input == t4)
        {
            valid = true;
        }
        else
        {
            print("Invalid Selection", 0);
            print("\n", 0);
        }
    } while (!valid);
    valid = false;
}

void newGame()
{
    clearScreen();
    printTitle();
    print("Enter Players Name: ", 0);
    cin >> player;
    print("\n", 0);
    clearScreen();
    printTitle();
    printTopBar(player);
    printBottomBar();
    handleInput(input, true, '1', '2', '3', '3');
};

void loadGame() {}

void viewStats() {}