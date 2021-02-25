#include <iostream>
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

int main()
{
	gameBoard();
	game();
}