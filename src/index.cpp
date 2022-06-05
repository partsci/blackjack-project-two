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
char handleInput(char &input, char t1, char t2, char t3, char t4, bool validate);
void newGame();
void loadGame();
void viewStats();
int main(int argc, char *argv[])
{
    // Game start
    do
    {
        printTitle();
        printMenu();
        handleInput(input, '1', '2', '3', '4', true);
        switch (input)
        {
        case '1':
            newGame();
            break;
        case '2':
            loadGame();
            break;
        case '3':
            viewStats();
            break;
        case '4':
            run = false;
            break;
        }
    } while (!run);
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
    print("2 | Load Game\n", 0);
    print("3 | View Statistics \n", 0);
    print("4 | Quit\n", 0);
    print("\n", 0);
    return;
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

char handleInput(char &input, char t1 = 'Z', char t2 = 'Y', char t3 = 'X', char t4 = 'W', bool validate)
{
    do
    {
        print("Input : ", 0);
        cin >> input;
        if (!validate)
        {
            valid = true;
        }
        if (input == t1 || input == t2 || input == t3 || input == t4)
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
    handleInput(input, '0', '0', '0', '0', false);
};

void loadGame() {}

void viewStats() {}
