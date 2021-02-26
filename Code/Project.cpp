// include libraries with commands
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//==========================================================||
//====================|Global Variables|====================||
//==========================================================||

int WordIndex;
int wrong = 0;
char wrongGuesses[10];
int letterCounter = 0;
string word[10];
string showed;
char guess;

void menu()
{
	//hangman, intro of game

	/*1*/ cout << "/   |||      |||         |||         |||      |||      ||||||      |||         |||         |||         |||      |||   \\" << endl;

	/*2*/ cout << "\\   |||      |||      |||   |||      |||||    |||   |||      |||   ||||||   ||||||      |||   |||      |||||    |||   /" << endl;

	/*3*/ cout << "/   |||      |||   |||         |||   ||| ||   |||   |||            |||   |||   |||   |||         |||   ||| ||   |||   \\" << endl;

	/*4*/ cout << "\\   ||||||||||||   |||         |||   |||  ||  |||   |||            |||   |||   |||   |||         |||   |||  ||  |||   /" << endl;

	/*5*/ cout << "/   ||||||||||||   |||||||||||||||   |||  ||  |||   |||   ||||||   |||         |||   |||||||||||||||   |||  ||  |||   \\" << endl;

	/*6*/ cout << "\\   |||      |||   |||||||||||||||   |||   || |||   |||      |||   |||         |||   |||||||||||||||   |||   || |||   /" << endl;

	/*7*/ cout << "/   |||      |||   |||         |||   |||    |||||   |||      |||   |||         |||   |||         |||   |||    |||||   \\" << endl;

	/*8*/ cout << "\\   |||      |||   |||         |||   |||      |||      ||||||      |||         |||   |||         |||   |||      |||   /" << endl;

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "                                                   (1) New Game" << endl;
	cout << "                                                   (2) Rules" << endl;
	cout << "                                                   (3) About" << endl;
	cout << "                                                   (4) Exit" << endl;
	cout << "                                             Choose an option: ";
}

void gameBoard()
{
	//list of the words
	word[0] = "Columbia";
	word[1] = "Accommodation";
	word[2] = "Crocodile";
	word[3] = "Paradise";
	word[4] = "CountryFive";
	word[5] = "CountrySix";
	word[6] = "CountrySeven";
	word[7] = "CountryEight";
	word[8] = "CountryNine";
	word[9] = "CountryTen";

	srand(time(0));
	WordIndex = rand() % 11;

	showed = word[WordIndex];

	for (size_t i = 1; i < word[WordIndex].size() - 1; i++)
	{
		showed[i] = '_';
	}

	//prints the game board
	for (size_t j = 0; j < word[WordIndex].size(); j++)
	{
		cout << showed[j] << " ";
	}
	cout << endl;
}

void game()
{
	gameBoard();
	while ((showed.compare(word[WordIndex]) != 0) and (wrong < 5))
	{
		//get user's guess and checks if it doubles
		cin >> guess;

		//checks if the player was wrong
		if (word[WordIndex].find(guess) == string::npos)
		{
			wrong++;

			wrongGuesses[letterCounter] = guess;

			letterCounter++;

			system("cls");

			for (size_t i = 0; i < word[WordIndex].size(); i++)
			{
				cout << showed[i] << " ";
			}
			cout << endl;

			if (letterCounter > 0)
			{
				cout << "letters guessed: ";

				for (int i = 0; i < letterCounter; i++)
				{
					cout << wrongGuesses[i] << " ";
				}
				cout << endl;

				cout << letterCounter << "/5" << endl;
			}
		}
		else
		{
			//a loop that checks if the guess was right and if so shows a part of the word
			for (size_t i = 1; i < word[WordIndex].size(); i++)
			{

				for (size_t i = 0; i < word[WordIndex].size(); i++)
				{
					if (word[WordIndex][i] == guess)
					{
						showed[i] = guess;
					}
				}

				system("cls");

				for (size_t i = 0; i < word[WordIndex].size(); i++)
				{
					cout << showed[i] << " ";
				}
				cout << endl;

				if (letterCounter > 0)
				{
					cout << "letters guessed: ";

					for (int i = 0; i < letterCounter; i++)
					{
						cout << wrongGuesses[i] << " ";
					}
					cout << endl;
				}

				cout << letterCounter << "/5" << endl;

				break;
			}
		}
	}
}

void menuOptions(int optionNum)
{
	switch (optionNum)
	{
	case 1:
		game();
		break;
	case 2:
		cout << endl << endl << endl;
		cout << "          |     (1) You could play individually or in groups.                                                 |" << endl;
		cout << "          |     (2) The player select a letter of the alphabet.                                               |" << endl;
		cout << "          |     (3) If the letter is contained in the word/phrase, the group or individual takes another      |" << endl;
		cout << "          |         turn guessing a letter.                                                                   |" << endl;
		cout << "          |     (4) If the letter is not contained in the word/phrase, a portion of the hangman is added.     |" << endl;
		cout << "          |     (5) The game continues until:                                                                 |" << endl;
		cout << "          |            the word/phrase is guessed (all letters are revealed) – WINNER                         |" << endl;
		cout << "          |                                  or                                                               |" << endl;
		cout << "          |            all the parts of the hangman are displayed – LOSER                                     |" << endl;
		break;
	case 3:
		cout << endl << endl << endl;
		cout << "                        |                                                           This code has been created by team \"The Dreamers\".          |" << endl;
		cout << "                        |                                         Back-end Developer:  Ivan Burzev                            |" << endl;
		cout << "                        |                                              Front-end Developer:  Yoana Agafonova                       |" << endl;
		cout << "                        |                                             Scrum Trainer:  Karina Tangarzdhieva                        |" << endl;
		cout << "                        |                                        Code Checker:  Lyubomir Bozukov                             |" << endl;
		cout << "                        |                           QA:  Yoan Dimitrov                                          |" << endl;
		break;
	case 4:
		cout << "See you again soon!" << endl;
		break;
	}
}

int main()
{
	int optionNum;

	cin >> optionNum;

	while (optionNum != 4)
	{
		menu();

		menuOptions(optionNum);
	}
}