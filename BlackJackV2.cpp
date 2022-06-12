#include <iostream>	//Input/Output Library
#include <string>  	// String library
#include <cstdlib> 	//Random number library
#include <ctime>   	// Time library
#include <fstream> 	// File library
#include <vector>  	// Vector library

using namespace std;
const int CARD_VALUES[11] = { 1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10
};
const string CARD_FACES[11] = { "ACE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE",
	"TEN" };

// Execution Begins Here!
void printTitle();
void print(int);
void print(char);
void print(string);
string printCard(int);
void printMainMenu(float);
vector<int> setCards();
int returnCard(vector < int>);
string handleInput();
void clearConsole(string);
void calDisFrom21(unsigned int &, unsigned int, unsigned int);
void printEndGameStats(string, unsigned int, unsigned int, string, unsigned int, unsigned int);
bool someoneBusted(unsigned int, unsigned int, unsigned int, unsigned int);
void printChoice(string);
void printPlayerData(string, unsigned int, unsigned int, unsigned int);
void printDealerData(string, unsigned int, unsigned int);
bool determineWinner(string, string, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int &, unsigned int, unsigned int);
int main(int argc, char **argv)
{

	// Set random number seed
	srand(static_cast< unsigned int > (time(0)));

	// Navigation variables
	string mnCh;	// Menu choice variable
	// Stats variables
	unsigned int p = 0;	// Player
	// Player variables
	string pNme;	// Player name
	unsigned int pCD = 0;	// Card value that was just dealt to player
	unsigned int pCC = 0;	// Players current card count not including their facedown card
	unsigned int pCP = 0;	// Players facedown card value
	unsigned int pd = 0;	// Players count distance from 21
	bool plWon = false;	// Player won game
	string pCh;	// Players choice to hit or stand
	// Dealer variables
	string dNme;	// Dealer name
	unsigned int dCD = 0;	// Card value that was just dealt to a dealer
	unsigned int dCC = 0;	// Dealers current card cout not inclduing their facedown card
	unsigned int dCP = 0;	// Dealers facedown card value
	unsigned int dd = 0;	// Dealers count distance from 21
	// Loop variables
	bool bst = false;	// Someone busted
	bool folded = false;
	// File variables
	ifstream cFsi;	// Config file in
	ifstream stsFi;	// Stats file in
	ofstream stsFo;	// Stats file out
	string os;	// Operating system from config file
	// Other variables
	float vsn = 1.00;
	bool vd = false;	// Validation boolean for inputs
	unsigned int cLw = 1;	// Lowest possible value a card could have
	unsigned int cHg = 11;	// Highest possible value a card could have
	vector<int> CARDS = setCards();
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
	printMainMenu(vsn);
	// While loop to validate user input to ensure that is is either 1 2 or 3
	while (!vd)
	{
		mnCh = handleInput();
		if (mnCh != "1" && mnCh != "2" && mnCh != "3")
		{
			cout << "Invalid Selection. Try again" << endl;
			cin.clear();
		}
		else
		{
			vd = true;
		}
	}
	vd = false;
	// Executes system commands to clear the terminal/console
	clearConsole("mac");
	// Handle selection
	switch (stoi(mnCh))
	{
		case 1:
			cout << "=====BlackJack=====\n\n";

			// Input player name and dealer name
			cout << "Type Player Name: ", cin>> pNme;
			cout << "Type Dealer Name: ", cin>> dNme;

			// Executes system commands to clear the terminal/console
			clearConsole("mac");

			// Give player their facedown card (hidden card)
			pCP = 0 + returnCard(CARDS);
			dCP = 0 + returnCard(CARDS);

			// Main logic of game
			do { 	cout << "=====BlackJack=====\n\n";
				printPlayerData(pNme, pCD, pCC, pCP);
				printDealerData(dNme, dCD, dCC);
				printChoice(pNme);
				vd = false;

				// Validate input fields to ensure they are only 1 or 2

				do { 	pCh = handleInput();
					cout << "CHOICE " << pCh << endl;

					if (mnCh != "1" && pCh != "2" && pCh != "3")
					{
						cout << "Invalid Selection. Try again" << endl;
						cin.clear();
					}
					else
					{
						vd = true;
					}
				} while (!vd);

				// If hit we get the player a random value representing a card 1 to 10;
				if (pCh == "1")
				{
					pCD = returnCard(CARDS);
					pCC = pCC + pCD;
				}

				// Dealer logic BASED ON BLACK JACK STRATEGY CHARTS
				if (pCC > 17)
				{
					dCD = returnCard(CARDS);
					dCC = dCC + dCD;
				}
				else if (pCC <= 2 && pCC <= 6)
				{
					dCD = returnCard(CARDS);
					dCC = dCC + dCD;
				}
				else if (pCC < 12)
				{
					dCD = returnCard(CARDS);
					dCC = dCC + dCD;
				}

				// Executes system commands to clear the terminal/console
				// os == "mac" ? system("clear") : system("cls");
				clearConsole("mac");

				// Check if someone busted the game
				if (someoneBusted(pCC, pCP, dCC, dCP))
				{
					bst = true;
				}
			} while (pCh != "3" && !bst);

			cout << "=====BlackJack=====\n\n";

			printEndGameStats(pNme, pCC, pCP, dNme, dCC, dCP);
			calDisFrom21(pd, pCC, pCP);
			calDisFrom21(dd, dCC, dCP);
			plWon = determineWinner(dNme, pNme, pCC, pCP, dCC, dCP, p, pd, dd);
			stsFo.open("./Desktop/Project/stats.dat");
			if (stsFo)
			{
				if (plWon)
				{
					stsFo << (static_cast<int> (p)) << endl;
				}
			}
			break;
		case 2:
			cout << "=====BlackJack=====\n\n";
			cout << "Player has won " << p << " times!";
			break;
		case 3:
			cFsi.close();
			stsFi.close();
			stsFo.close();
			exit(0);
		default:
			break;
	}
	cFsi.close();
	stsFi.close();
	stsFo.close();
	return 0;
}

void printMainMenu(float vsn)
{
	cout << "=====Welcome To BlackJack Version" << vsn << "=====\n";

	cout << "It's Las Vegas but at home!\n";

	cout << "\n";

	cout << "Main Menu" << endl;
	cout << " 1 | New Game\n";
	cout << " 2 | Display Player Wins \n";
	cout << " 3 | Quit\n";
}
void printTitle()
{
	print("██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗░░░░░██╗░█████╗░░█████╗░██╗░░██╗");
	cout << "\n";
	print("██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝░░░░░██║██╔══██╗██╔══██╗██║░██╔╝");
	cout << "\n";
	print("██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░░░░░░██║███████║██║░░╚═╝█████═╝░");
	cout << "\n";
	print("██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░██╗░░██║██╔══██║██║░░██╗██╔═██╗░");
	cout << "\n";
	print("██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗╚█████╔╝██║░░██║╚█████╔╝██║░╚██╗");
	cout << "\n";
	print("╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝");
}
bool someoneBusted(unsigned int pCC, unsigned int pCP, unsigned int dCC, unsigned int dCP)
{
	if (pCC + pCP >= 21 || dCC + dCP >= 21)
	{
		return true;
	}
	return false;
}
void printEndGameStats(string pNme, unsigned int pCC, unsigned int pCP, string dNme, unsigned int dCC, unsigned int dCP)
{
	cout << "Player " << pNme << endl;
	cout << " Hand Count | " << pCC << "\n";
	cout << " Facedown Card | " << printCard(pCP) << "\n";
	cout << " Total Count | " << pCC + pCP << "\n\n";

	// Display stats for dealer
	cout << "Dealer " << dNme << endl;
	cout << " Hand Count | " << dCC << "\n";
	cout << " Facedown Card | " << printCard(dCP) << "\n";
	cout << " Total Count | " << dCC + dCP << "\n\n";
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
void calDisFrom21(unsigned int &distance, unsigned int countOne, unsigned int countTwo)
{
	distance = 21 - (countOne + countTwo);
}
string handleInput()
{
	string input;
	cout << "Input: ";
	cin >> input;
	return input;
}
void printChoice(string pNme)
{
	cout << pNme << ",\ndo you Hit, Stand, or Fold?\n";
	cout << " 1 | Hit\n";
	cout << " 2 | Stand\n";
	cout << " 3 | Fold\n";
}
void printPlayerData(string pNme, unsigned int pCD, unsigned int pCC, unsigned int pCP)
{
	cout << "█▀█ █░░ ▄▀█ █▄█ █▀▀ █▀█\n";
	cout << "█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄\n";
	cout << " Card Dealt | " << printCard(pCD) << "\n";
	cout << " Current Hand | " << pCC << "\n";
	cout << " Facedown Card | " << printCard(pCP) << "\n";
	cout << " Total Count | " << pCC + pCP << "\n\n";
}
void print(string data)
{
	cout << data << endl;
}
void print(int data)
{
	cout << data << endl;
}
void print(char data)
{
	cout << data << endl;
}
void printDealerData(string dNme, unsigned int dCD, unsigned int dCC)
{
	cout << "█▀▄ █▀▀ ▄▀█ █░░ █▀▀ █▀█\n";
	cout << "█▄▀ ██▄ █▀█ █▄▄ ██▄ █▀▄\n";
	cout << " Card Dealt | " << printCard(dCD) << "\n";
	cout << " Current Hand | " << dCC << "\n";
	cout << " Facedown Card | " <<
		"Hidden" <<
		"\n";
	cout << " Total Count | Hidden \n\n";
}
bool determineWinner(string dNme, string pNme, unsigned int pCC, unsigned int pCP, unsigned int dCC, unsigned int dCP, unsigned int &p, unsigned int pd, unsigned int dd)
{
	// Determine winner from a tie
	if (pCC + pCP == 21 && dCC + dCP == 21)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "~";
		}

		cout << "█▀▄ █▀█ ▄▀█ █░█░█\n";
		cout << "█▄▀ █▀▄ █▀█ ▀▄▀▄▀\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "~";
		}
		cout << "\n";
		return false;
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

		cout << "█▀▄ █▀▀ ▄▀█ █░░ █▀▀ █▀█   █░█░█ █▀█ █▄░█\n";
		cout << "█▄▀ ██▄ █▀█ █▄▄ ██▄ █▀▄   ▀▄▀▄▀ █▄█ █░▀█\n";
		cout << "Dealer " << dNme << " You Won!\n";
		cout << "Player Busted\n";
		return false;
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
		cout << "█▀█ █░░ ▄▀█ █▄█ █▀▀ █▀█   █░█░█ █▀█ █▄░█\n";
		cout << "█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄   ▀▄▀▄▀ █▄█ █░▀█\n";
		cout << "Player " << pNme << " You Won!\n";
		cout << "Dealer Busted\n";
		p++;
		return true;
	}
	else if (pCC + pCP > 21 && dCC + dCP > 21)
	{
		cout << "OOPS Dealer " << dNme << " &" <<
			"Player " << pNme << " Both Busted\n";
	}
	else if (pd < dd)	// Determine winner from whoever is closer to 21
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

		cout << "█▀█ █░░ ▄▀█ █▄█ █▀▀ █▀█   █░█░█ █▀█ █▄░█\n";
		cout << "█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄   ▀▄▀▄▀ █▄█ █░▀█\n";
		cout << "Player " << pNme << " You Won!\n";
		cout << "Dealer was farther from 21\n";
		p++;
		return true;
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
		cout << "█▀▄ █▀▀ ▄▀█ █░░ █▀▀ █▀█   █░█░█ █▀█ █▄░█\n";
		cout << "█▄▀ ██▄ █▀█ █▄▄ ██▄ █▀▄   ▀▄▀▄▀ █▄█ █░▀█\n";
		cout << "Dealer " << dNme << " You Won!\n";
		cout << "Player was farther from 21\n";
		return false;
	};
}
void clearConsole(string sys = "windows")
{
	if (sys == "windows")
	{
		system("cls");
	}
	else
	{
		system("cls");
		system("clear");
	}
}
string printCard(int card)
{
	string toReturn;
	for (int i = 0; i < 11; i++)
	{
		if (CARD_VALUES[i] == card)
		{
			cout << CARD_FACES[i];
		}
	}
	return toReturn;
}