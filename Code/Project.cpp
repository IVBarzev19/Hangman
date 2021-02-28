#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//==========================================================||
//====================|Global Variables|====================||
//==========================================================||

int optionNum;
int WordIndex;
int letterCounter;
string word[10];
string showed;

void logo()
{
	system("cls");

	cout << "/   |||      |||         |||         |||      |||      ||||||      |||         |||         |||         |||      |||   \\" << endl;
	cout << "\\   |||      |||      |||   |||      |||||    |||   |||      |||   ||||||   ||||||      |||   |||      |||||    |||   /" << endl;
	cout << "/   |||      |||   |||         |||   ||| ||   |||   |||            |||   |||   |||   |||         |||   ||| ||   |||   \\" << endl;
	cout << "\\   ||||||||||||   |||         |||   |||  ||  |||   |||            |||   |||   |||   |||         |||   |||  ||  |||   /" << endl;
	cout << "/   ||||||||||||   |||||||||||||||   |||  ||  |||   |||   ||||||   |||         |||   |||||||||||||||   |||  ||  |||   \\" << endl;
	cout << "\\   |||      |||   |||||||||||||||   |||   || |||   |||      |||   |||         |||   |||||||||||||||   |||   || |||   /" << endl;
	cout << "/   |||      |||   |||         |||   |||    |||||   |||      |||   |||         |||   |||         |||   |||    |||||   \\" << endl;
	cout << "\\   |||      |||   |||         |||   |||      |||      ||||||      |||         |||   |||         |||   |||      |||   /" << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
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

	cout << "Enter your guess: ";
}

bool hangman(int wrongCount)
{
	switch (wrongCount)
	{
	case 1:
		cout << "____________________" << endl;
		cout << "|                  |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|=======================" << endl;
		break;
	case 2:
		cout << "____________________" << endl;
		cout << "|                  |" << endl;
		cout << "|               ( X _ X)" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|=======================" << endl;
		break;
	case 3:
		cout << "____________________" << endl;
		cout << "|                  |" << endl;
		cout << "|               ( X _ X)" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|=======================" << endl;
		break;
	case 4:
		cout << "____________________" << endl;
		cout << "|                  |" << endl;
		cout << "|               ( X _ X)" << endl;
		cout << "|                  |" << endl;
		cout << "|                 /|" << endl;
		cout << "|                / |" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|=======================" << endl;
		break;
	case 5:
		cout << "____________________" << endl;
		cout << "|                  |" << endl;
		cout << "|               ( X _ X)" << endl;
		cout << "|                  |" << endl;
		cout << "|                 /|\\" << endl;
		cout << "|                / | \\" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|=======================" << endl;
		break;
	case 6:
		cout << "____________________" << endl;
		cout << "|                  |" << endl;
		cout << "|               ( X _ X)" << endl;
		cout << "|                  |" << endl;
		cout << "|                 /|\\" << endl;
		cout << "|                / | \\" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|                 /" << endl;
		cout << "|                /" << endl;
		cout << "|" << endl;
		cout << "|=======================" << endl;
		break;
	case 7:
		cout << "____________________" << endl;
		cout << "|                  |" << endl;
		cout << "|               ( X _ X)" << endl;
		cout << "|                  |" << endl;
		cout << "|                 /|\\" << endl;
		cout << "|                / | \\" << endl;
		cout << "|                  |" << endl;
		cout << "|                  |" << endl;
		cout << "|                 / \\" << endl;
		cout << "|                /   \\" << endl;
		cout << "|" << endl;
		cout << "|=======================" << endl;
		break;
	default:
		break;
	}
	return 0;
}

void gameMechanics()
{
	letterCounter = 0;

	char guess;

	char wrongGuesses[7];

	int wrongCounter = 0;

	logo();

	gameBoard();

	while ((showed.compare(word[WordIndex]) != 0) and (wrongCounter < 7))
	{

		cin >> guess;

		//checks if the player was wrong
		if (word[WordIndex].find(guess) == string::npos)
		{
			wrongCounter++;

			wrongGuesses[letterCounter] = guess;

			letterCounter++;

			logo();

			for (size_t i = 0; i < word[WordIndex].size(); i++)
			{
				cout << showed[i] << " ";
			}
			cout << endl;

			cout << "letters mistaken: ";

			for (int i = 0; i < letterCounter; i++)
			{
				cout << wrongGuesses[i] << " ";
			}
			cout << endl;

			hangman(wrongCounter);

			cout << "Enter your guess: ";
		}
		else
		{
			//a loop that shows a part of the word
			for (size_t i = 1; i < word[WordIndex].size(); i++)
			{
				for (size_t i = 0; i < word[WordIndex].size(); i++)
				{
					if (word[WordIndex][i] == guess)
					{
						showed[i] = guess;
					}
				}

				logo();

				for (size_t i = 0; i < word[WordIndex].size(); i++)
				{
					cout << showed[i] << " ";
				}
				cout << endl;

				cout << "letters mistaken: ";

				for (int i = 0; i < letterCounter; i++)
				{
					cout << wrongGuesses[i] << " ";
				}
				cout << endl;

				hangman(wrongCounter);

				cout << "Enter your guess: ";

				break;
			}
		}
	}
	system("pause");
}

void menuOptions()
{
	if (true)
	{
		cin >> optionNum;
	}

	switch (optionNum)
	{

	case 1:
	{
		gameMechanics();

		break;
	}

	case 2:
	{

		logo();

		cout << "          |     (1) You could play individually or in groups.                                                 |" << endl;
		cout << "          |     (2) The player select a letter of the alphabet.                                               |" << endl;
		cout << "          |     (3) If the letter is contained in the word/phrase, the group or individual takes another      |" << endl;
		cout << "          |         turn guessing a letter.                                                                   |" << endl;
		cout << "          |     (4) If the letter is not contained in the word/phrase, a portion of the hangman is added.     |" << endl;
		cout << "          |     (5) The game continues until:                                                                 |" << endl;
		cout << "          |            the word/phrase is guessed (all letters are revealed) = WINNER                         |" << endl;
		cout << "          |                                  or                                                               |" << endl;
		cout << "          |            all the parts of the hangman are displayed = LOSER                                     |" << endl;
		cout << endl;

		system("pause");

		break;
	}

	case 3:
	{

		logo();

		cout << "             |                    This code has been created by team \"The Dreamers\".                  |" << endl;
		cout << "             |                                                                                        |" << endl;
		cout << "             |                             Back-end Developer: Ivan Burzev                            |" << endl;
		cout << "             |                           Front-end Developer: Yoana Agafonova                         |" << endl;
		cout << "             |                            Scrum Trainer: Karina Tangarzdhieva                         |" << endl;
		cout << "             |                              Code Checker: Lyubomir Bozukov                            |" << endl;
		cout << "             |                                    QA: Yoan Dimitrov                                   |" << endl;
		cout << endl;

		system("pause");

		break;
	}

	case 4:
	{
		logo();
		cout << "See you again soon!" << endl;
		system("pause");

		break;
	}

	default:
		break;
	}
}

int main()
{
	while (optionNum != 4)
	{
		logo();

		cout << "                                                   (1) New Game" << endl;
		cout << "                                                   (2) Rules" << endl;
		cout << "                                                   (3) About" << endl;
		cout << "                                                   (4) Exit" << endl;
		cout << "                                                 Choose an option: ";

		menuOptions();
	}
}