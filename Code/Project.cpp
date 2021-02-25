// include libraries with commands
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

void menu()
{
	//hangman, intro of game

	/*1*/ cout << "/" << setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(12) << "|||" << /*__*/ setw(12) << "|||" << setw(9) << "|||" << /*__*/ setw(12) << "||||||" << /*__*/ setw(9) << "|||" << setw(12) << "|||" << /*__*/ setw(12) << "|||" << /*__*/ setw(12) << "|||" << setw(9) << "|||" << setw(4) << "\\" << endl;

	/*2*/ cout << "\\" << setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(9) << "|||" << setw(6) << "|||" << /*__*/ setw(11) << "|||||" << setw(7) << "|||" << /*__*/ setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(9) << "||||||" << setw(9) << "||||||" << /*__*/ setw(9) << "|||" << setw(6) << "|||" << /*__*/ setw(11) << "|||||" << setw(7) << "|||" << setw(4) << "/" << endl;

	/*3*/ cout << "/" << setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(3) << "||" << setw(6) << "|||" << /*__*/ setw(6) << "|||" << /*__*/ setw(15) << "|||" << setw(6) << "|||" << setw(6) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(3) << "||" << setw(6) << "|||" << setw(4) << "\\" << endl;

	/*4*/ cout << "\\" << setw(15) << "||||||||||||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(4) << "||" << setw(5) << "|||" << /*__*/ setw(6) << "|||" << /*__*/ setw(15) << "|||" << setw(6) << "|||" << setw(6) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(4) << "||" << setw(5) << "|||" << setw(4) << "/" << endl;

	/*5*/ cout << "/" << setw(15) << "||||||||||||" << /*__*/ setw(18) << "|||||||||||||||" << /*__*/ setw(6) << "|||" << setw(4) << "||" << setw(5) << "|||" << /*__*/ setw(6) << "|||" << setw(9) << "||||||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(18) << "|||||||||||||||" << /*__*/ setw(6) << "|||" << setw(4) << "||" << setw(5) << "|||" << setw(4) << "\\" << endl;

	/*6*/ cout << "\\" << setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(18) << "|||||||||||||||" << /*__*/ setw(6) << "|||" << setw(5) << "||" << setw(4) << "|||" << /*__*/ setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(18) << "|||||||||||||||" << /*__*/ setw(6) << "|||" << setw(5) << "||" << setw(4) << "|||" << setw(4) << "/" << endl;

	/*7*/ cout << "/" << setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(9) << "|||||" << /*__*/ setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(9) << "|||||" << setw(4) << "\\" << endl;

	/*8*/ cout << "\\" << setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(9) << "|||" << /*__*/ setw(12) << "||||||" << /*__*/ setw(9) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(12) << "|||" << /*__*/ setw(6) << "|||" << setw(9) << "|||" << setw(4) << "/" << endl;

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << setw(63) << " (1) New Game" << endl;
	cout << setw(60) << " (2) Rules" << endl;
	cout << setw(60) << " (3) About" << endl;
	cout << setw(63) << "Choose an option: ";
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
		cout << setw(10) << "|" << setw(50) << "(1) You could play individually or in groups." << setw(49) << "|" << endl;
		cout << setw(10) << "|" << setw(52) << "(2) The player select a letter of the alphabet." << setw(47) << "|" << endl;
		cout << setw(10) << "|" << setw(93) << "(3) If the letter is contained in the word/phrase, the group or individual takes another" << setw(6) << "|" << endl;
		cout << setw(10) << "|" << setw(32) << "turn guessing a letter." << setw(67) << "|" << endl;
		cout << setw(10) << "|" << setw(94) << "(4) If the letter is not contained in the word/phrase, a portion of the hangman is added." << setw(5) << "|" << endl;
		cout << setw(10) << "|" << setw(34) << "(5) The game continues until:" << setw(65) << "|" << endl;
		cout << setw(10) << "|" << setw(78) << "       the word/phrase is guessed (all letters are revealed) – WINNER" << setw(23) << "|" << endl;
		cout << setw(10) << "|" << setw(45) << "                             or" << setw(54) << "|" << endl;
		cout << setw(10) << "|" << setw(66) << "       all the parts of the hangman are displayed – LOSER" << setw(35) << "|" << endl;
		break;
	case 3:
		cout << endl << endl << endl;
		cout << setw(25) << "|" << setw(59) << "This code has been created by team \"The Dreamers\"." << setw(10) << "|" << endl;
		cout << setw(25) << "|" << setw(41) << "Back-end Developer:  Ivan Burzev" << setw(28) << "|" << endl;
		cout << setw(25) << "|" << setw(46) << "Front-end Developer:  Yoana Agafonova" << setw(23) << "|" << endl;
		cout << setw(25) << "|" << setw(45) << "Scrum Trainer:  Karina Tangarzdhieva" << setw(24) << "|" << endl;
		cout << setw(25) << "|" << setw(40) << "Code Checker:  Lyubomir Bozukov" << setw(29) << "|" << endl;
		cout << setw(25) << "|" << setw(27) << "QA:  Yoan Dimitrov" << setw(42) << "|" << endl;
		break;
	}
}

int main()
{
	menu();

	int optionNum;

	cin >> optionNum;

	menuOptions(optionNum);
}