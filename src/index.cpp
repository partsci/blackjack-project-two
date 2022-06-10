

#include <iostream> //Input/Output Library
#include <string>   // String library
#include <cstdlib>  //Random number library
#include <ctime>    // Time library
#include <fstream>  // File library

using namespace std;

// Execution Begins Here!
int main(int argc, char **argv)
{

    // Set random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Navigation variables
    char mnCh; // Menu choice variable
    // Stats variables
    unsigned int p = 0; // Player
    // Player variables
    string pNme;          // Player name
    unsigned int pCD = 0; // Card value that was just dealt to player
    unsigned int pCC = 0; // Players current card count not including their facedown card
    unsigned int pCP = 0; // Players facedown card value
    unsigned int pd = 0;  // Players count distance from 21
    bool plWon = false;   // Player won game
    char pCh;             // Players choice to hit or stand
    // Dealer variables
    string dNme;          // Dealer name
    unsigned int dCD = 0; // Card value that was just dealt to a dealer
    unsigned int dCC = 0; // Dealers current card cout not inclduing their facedown card
    unsigned int dCP = 0; // Dealers facedown card value
    unsigned int dd = 0;  // Dealers count distance from 21
    // Loop variables
    bool bst = false; // Someone busted
    // File variables
    ifstream cFsi;  // Config file in
    ifstream stsFi; // Stats file in
    ofstream stsFo; // Stats file out
    string os;      // Operating system from config file
    // Other variables
    float vsn = 2.00;
    bool vd = false;       // Validation boolean for inputs
    unsigned int cLw = 1;  // Lowest possible value a card could have
    unsigned int cHg = 11; // Highest possible value a card could have

    /*End of variable declarations*/

    // Read in files

    // This was the only way I could get my project to read in the file. I could not read it in locally from my working directory due to the way my computer is setup
    cFsi.open("./Desktop/Project/config.dat");
    if (cFsi)
    {
        while (cFsi >> os)
        {
            if (os != "windows" || os != "mac")
            {
                os = "mac";
            }
        }
    };

    stsFi.open("./Desktop/Project/stats.dat");
    {
        stsFi >> p;
    };

    // Out statements for initial menu
    cout << showpoint << setprecision(2);
    cout << "=====Welcome To BlackJack Version " << vsn << "=====\n";
    cout << "It's Las Vegas but at home!\n";

    cout << "\n";

    cout << "Main Menu" << endl;
    cout << " 1 | New Game\n";
    cout << " 2 | Display Player Wins \n";
    cout << " 3 | Quit\n";

    // While loop to validate user input to ensure that is is either 1 2 or 3
    do
    {
        cout << "Input: ", cin >> mnCh;
        if (mnCh != '1' && mnCh != '2' && mnCh != '3')
        {
            cout << "Invalid Selection. Try again" << endl;
            cin.clear();
        }
        else
        {
            vd = true;
        }
    } while (!vd);

    // Executes system commands to clear the terminal/console
    // os == "mac" ? system("clear") : system("cls");
    system("clear"), system("cls");
    // Handle selection
    switch (mnCh)
    {
    case '1':
        cout << "=====BlackJack=====\n\n";

        // Input player name and dealer name
        cout << "Type Player Name: ", cin >> pNme;
        cout << "Type Dealer Name: ", cin >> dNme;

        // Executes system commands to clear the terminal/console
        // os == "mac" ? system("clear") : system("cls");
        system("clear"), system("cls");

        // Give player their facedown card (hidden card)
        pCP = 0 + (rand() % cHg + cLw);
        dCP = 0 + (rand() % cHg + cLw);

        // Main logic of game
        do
        {
            cout << "                           =====BLACK JACK=====                            \n\n";
            cout << "█▀█ █░░ ▄▀█ █▄█ █▀▀ █▀█                           █▀▄ █▀▀ ▄▀█ █░░ █▀▀ █▀█\n";
            cout << "█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄                           █▄▀ ██▄ █▀█ █▄▄ ██▄ █▀▄";
            cout << "\n\n";
            cout << "     Card Dealt | " << pCD << setw(50) << "     Card Dealt | " << dCD << "\n";
            cout << "   Current Hand | " << pCD << setw(50) << "   Current Hand | " << dCD << "\n";
            cout << "  Facedown Card | " << pCD << setw(50) << "Facedown Card | " << dCD << "\n";
            cout << "     Card Dealt | " << pCD << setw(50) << " Card Dealt | " << dCD << "\n";
            cout << "                           █▀▀ █░█ █▀█ █ █▀▀ █▀▀                                                      \n";
            cout << "                           █▄▄ █▀█ █▄█ █ █▄▄ ██▄                                                      \n\n";
            cout << setw(40) << pNme << "\n\n";
            cout << "                                  1 | Hit\n";
            cout << "                                  2 | Stand\n";
            cout << "                                  3 | Fold\n";
            cout << "                                  1 | Hit\n\n";
            vd = false;

            // Validate input fields to ensure they are only 1 or 2
            do
            {
                cout << "                            Type Selection: ", cin >> pCh;
                if (pCh != '1' && pCh != '2')
                {
                    cout << "Invalid Selection. Try again" << endl;
                    cin.clear();
                }
                else
                {
                    vd = true;
                }
            } while (!vd);

            // Handle either hit or stand

            // If hit we get the player a random value representing a card 1 to 11;
            if (pCh == '1')
            {
                pCD = (rand() % cHg + cLw);
                pCC = pCC + pCD;
            }

            // Dealer logic BASED ON BLACK JACK STRATEGY CHARTS
            if (pCC > 17)
            {
                dCD = (rand() % cHg + cLw);
                dCC = dCC + dCD;
            }
            else if (pCC <= 2 && pCC <= 6)
            {
                dCD = (rand() % cHg + cLw);
                dCC = dCC + dCD;
            }
            else if (pCC < 12)
            {
                dCD = (rand() % cHg + cLw);
                dCC = dCC + dCD;
            }

            // Executes system commands to clear the terminal/console
            // os == "mac" ? system("clear") : system("cls");
            system("clear"), system("cls");

            // Check if
            if (pCC + pCP >= 21 || dCC + dCP >= 21)
            {
                bst = true;
            }

        } while (pCh != '2' && !bst);

        cout << "=====BlackJack=====\n\n";

        // Display stats for player
        cout << "Player " << pNme << endl;
        cout << " Hand Count | " << pCC << "\n";
        cout << " Facedown Card | " << pCP << "\n";
        cout << " Total Count | " << pCC + pCP << "\n\n";

        // Display stats for dealer
        cout << "Dealer " << dNme << endl;
        cout << " Hand Count | " << dCC << "\n";
        cout << " Facedown Card | " << dCP << "\n";
        cout << " Total Count | " << dCC + dCP << "\n\n";

        pd = 21 - (pCC + pCP); // Calculate players count distance from 21
        dd = 21 - (dCC + dCP); // Calculate players count distance from 21

        // Determine winner from a tie
        if (pCC + pCP == 21 && dCC + dCP == 21)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "DRAW";
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "\n";
        }

        // Determine winner from a bust
        if (pCC + pCP > 21 && dCC + dCP <= 21)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "CONGRATS";
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "\n";
            cout << "Dealer " << dNme << " You Won!\n";
            cout << "Player Busted\n";
        }
        else if (pCC + pCP <= 21 && dCC + dCP > 21)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "CONGRATS";
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "\n";
            cout << "Player " << pNme << " You Won!\n";
            cout << "Dealer Busted\n";
            p++;
            plWon = true;
        }
        else if (pCC + pCP > 21 && dCC + dCP > 21)
        {
            cout << "OOPS Dealer " << dNme << " & "
                 << "Player " << pNme << " Both Busted\n";
        }
        else if (pd < dd) // Determine winner from whoever is closer to 21
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "CONGRATS";
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "\n";
            cout << "Player " << pNme << " You Won!\n";
            cout << "Dealer was farther from 21\n";
            p++;
            plWon = true;
        }
        else if (pd > dd)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "CONGRATS";
            for (int i = 0; i < 5; i++)
            {
                cout << "~";
            }
            cout << "\n";
            cout << "Dealer " << dNme << " You Won!\n";
            cout << "Player was farther from 21\n";
        };
        stsFo.open("./Desktop/Project/stats.dat");
        if (stsFo)
        {
            if (plWon)
            {
                stsFo << (static_cast<int>(p)) << endl;
            }
        }
        break;
    case '2':
        cout << "=====BlackJack=====\n\n";
        cout << "Player has won " << p << " times!";
        break;
    default:
        break;
    }

    // No need to check if the choice is 3. If it isnt 1 or 2 we exit
    cFsi.close();
    stsFi.close();
    stsFo.close();
    return 0;
}
