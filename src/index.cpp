/* Library declarations */

#include <iostream>
#include <iomanip>

using namespace std;

/* Variable declarations */
char input;
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

bool validateInput(char &input);

void handleHome(char &input);
// Handles printing content to the window
void print(string content, int width);
int main(int argc, char *argv[])
{
    // Game start
    printHome();
    handleHome(input);
}

/* Core functions */

/* Utilitie functions */
void printHome()
{
    print("██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗░░░░░██╗░█████╗░░█████╗░██╗░░██╗\n", 0);
    print("██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝░░░░░██║██╔══██╗██╔══██╗██║░██╔╝\n", 0);
    print("██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░░░░░░██║███████║██║░░╚═╝█████═╝░\n", 0);
    print("██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░██╗░░██║██╔══██║██║░░██╗██╔═██╗░\n", 0);
    print("██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗╚█████╔╝██║░░██║╚█████╔╝██║░╚██╗\n", 0);
    print("╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝\n", 0);
    print("\n", 0);
    print("Welcome", 32);

    printMainMenu();
    return;
}

void printMainMenu()
{
    print("\n", 0);
    print("1 | Start New Game\n", 0);
    print("2 | Load Game\n", 0);
    print("3 | View Statistics \n", 0);
    print("4 | Quit\n", 0);
    print("\n", 0);
    print("Input : ", 0);
    return;
}
void printDetails() {}

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

void handleHomeInput(char &input)
{
    cin >> input;
    validateInput(input);
}

bool validateInput(char &input)
{
    return false;
}