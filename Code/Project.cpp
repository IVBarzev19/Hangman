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



//print out the logo of the game
void logo()
{
	​​​​
		system("cls");



	cout << "/ ||| ||| ||| ||| ||| |||||| ||| ||| ||| ||| ||| \\" << endl;
	cout << "\\ ||| ||| ||| ||| ||||| ||| ||| ||| |||||| |||||| ||| ||| ||||| ||| /" << endl;
	cout << "/ ||| ||| ||| ||| ||| || ||| ||| ||| ||| ||| ||| ||| ||| || ||| \\" << endl;
	cout << "\\ |||||||||||| ||| ||| ||| || ||| ||| ||| ||| ||| ||| ||| ||| || ||| /" << endl;
	cout << "/ |||||||||||| ||||||||||||||| ||| || ||| ||| |||||| ||| ||| ||||||||||||||| ||| || ||| \\" << endl;
	cout << "\\ ||| ||| ||||||||||||||| ||| || ||| ||| ||| ||| ||| ||||||||||||||| ||| || ||| /" << endl;
	cout << "/ ||| ||| ||| ||| ||| ||||| ||| ||| ||| ||| ||| ||| ||| ||||| \\" << endl;
	cout << "\\ ||| ||| ||| ||| ||| ||| |||||| ||| ||| ||| ||| ||| ||| /" << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}​​​​



//get a random word from the word list
void gameBoard()
{
	​​​​
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
		​​​​
			showed[i] = '_';
	}​​​​



		//prints the game board
		for (size_t j = 0; j < word[WordIndex].size(); j++)
		{
			​​​​
				cout << showed[j] << " ";
		}​​​​
			cout << endl;



		cout << "Enter your guess: ";
}​​​​



//print out the hangman acording to the user's mistakes
bool hangman(int wrongCount)
{
	​​​​
		switch (wrongCount)
		{
			​​​​
		case 1:
			cout << "____________________" << endl;
			cout << "| |" << endl;
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
			cout << "| |" << endl;
			cout << "| ( X _ X)" << endl;
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
			cout << "| |" << endl;
			cout << "| ( X _ X)" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|=======================" << endl;
			break;
		case 4:
			cout << "____________________" << endl;
			cout << "| |" << endl;
			cout << "| ( X _ X)" << endl;
			cout << "| |" << endl;
			cout << "| /|" << endl;
			cout << "| / |" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|=======================" << endl;
			break;
		case 5:
			cout << "____________________" << endl;
			cout << "| |" << endl;
			cout << "| ( X _ X)" << endl;
			cout << "| |" << endl;
			cout << "| /|\\" << endl;
			cout << "| / | \\" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|=======================" << endl;
			break;
		case 6:
			cout << "____________________" << endl;
			cout << "| |" << endl;
			cout << "| ( X _ X)" << endl;
			cout << "| |" << endl;
			cout << "| /|\\" << endl;
			cout << "| / | \\" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "| /" << endl;
			cout << "| /" << endl;
			cout << "|" << endl;
			cout << "|=======================" << endl;
			break;
		case 7:
			cout << "____________________" << endl;
			cout << "| |" << endl;
			cout << "| ( X _ X)" << endl;
			cout << "| |" << endl;
			cout << "| /|\\" << endl;
			cout << "| / | \\" << endl;
			cout << "| |" << endl;
			cout << "| |" << endl;
			cout << "| / \\" << endl;
			cout << "| / \\" << endl;
			cout << "|" << endl;
			cout << "|=======================" << endl;
			break;
		default:
			break;
		}​​​​
			return 0;
}​​​​



//get the user's input and decides if they were wrong or right
void gameMechanics()
{
	​​​​
		letterCounter = 0;



	//a valuable that contains the user's input
	char guess;



	//a valuable for the user's wrong guesses
	char wrongGuesses[7];



	//a counter for the wrong guesses
	int wrongCounter = 0;



	logo();



	gameBoard();



	//a loop that cycles until either the word is completely guessed or the hangman is complete
	while ((showed.compare(word[WordIndex]) != 0) and (wrongCounter < 7))
	{
		​​​​



			cin >> guess;



		//checks if the player was wrong
		if (word[WordIndex].find(guess) == string::npos)
		{
			​​​​
				wrongCounter++;



			wrongGuesses[letterCounter] = guess;



			letterCounter++;



			logo();



			//prints out the showed part of the word and the mistaken letters
			for (size_t i = 0; i < word[WordIndex].size(); i++)
			{
				​​​​
					cout << showed[i] << " ";
			}​​​​
				cout << endl;



			cout << "letters mistaken: ";



			for (int i = 0; i < letterCounter; i++)
			{
				​​​​
					cout << wrongGuesses[i] << " ";
			}​​​​
				cout << endl;



			hangman(wrongCounter);



			cout << "Enter your guess: ";
		}​​​​
		else
		{
			​​​​
				//a loop that shows a part of the word
				for (size_t i = 1; i < word[WordIndex].size(); i++)
				{
					​​​​
						//inserts the right guess in it's place
						for (size_t i = 0; i < word[WordIndex].size(); i++)
						{
							​​​​
								if (word[WordIndex][i] == guess)
								{
									​​​​
										showed[i] = guess;
								}​​​​
						}​​​​



							//prints out the showed part of the word and the mistaken letters
									logo();



								for (size_t i = 0; i < word[WordIndex].size(); i++)
								{
									​​​​
										cout << showed[i] << " ";
								}​​​​
									cout << endl;



								cout << "letters mistaken: ";



								for (int i = 0; i < letterCounter; i++)
								{
									​​​​
										cout << wrongGuesses[i] << " ";
								}​​​​
									cout << endl;



								hangman(wrongCounter);



								cout << "Enter your guess: ";



								break;
				}​​​​
		}​​​​
	}​​​​
		cout << endl;
				system("pause");
}​​​​



//the options in the main menu
void menuOptions()
{
	​​​​
		cin >> optionNum;



	switch (optionNum)
	{
		​​​​



	case 1:
		{​​​​
			//run the game
			gameMechanics();
		break;
		}​​​​



	case 2:
		{​​​​
			//print out the rules
			logo();



		cout << " | (1) You could play individually or in groups. |" << endl;
		cout << " | (2) The player select a letter of the alphabet. |" << endl;
		cout << " | (3) If the letter is contained in the word/phrase, the group or individual takes another |" << endl;
		cout << " | turn guessing a letter. |" << endl;
		cout << " | (4) If the letter is not contained in the word/phrase, a portion of the hangman is added. |" << endl;
		cout << " | (5) The game continues until: |" << endl;
		cout << " | the word/phrase is guessed (all letters are revealed) = WINNER |" << endl;
		cout << " | or |" << endl;
		cout << " | all the parts of the hangman are displayed = LOSER |" << endl;
		cout << endl;



		system("pause");
		break;
		}​​​​



	case 3:
		{​​​​
			//print out the team members
			logo();



		cout << " | This code has been created by team \"The Dreamers\". |" << endl;
		cout << " | |" << endl;
		cout << " | Back-end Developer: Ivan Burzev |" << endl;
		cout << " | Front-end Developer: Yoana Agafonova |" << endl;
		cout << " | Scrum Trainer: Karina Tangarzdhieva |" << endl;
		cout << " | Code Checker: Lyubomir Bozukov |" << endl;
		cout << " | QA: Yoan Dimitrov |" << endl;
		cout << endl;



		system("pause");



		break;
		}​​​​



	case 4:
		{​​​​
			//stop the game
			logo();
		cout << "See you again soon!" << endl;
		system("pause");



		break;
		}​​​​



	default:
		break;
	}​​​​
}​​​​



int main()
	{
		​​​​
			//run until the user chooses the "exit" option
			while (optionNum != 4)
			{
				​​​​
					logo();



				cout << " (1) New Game" << endl;
				cout << " (2) Rules" << endl;
				cout << " (3) About" << endl;
				cout << " (4) Exit" << endl;
				cout << " Choose an option: ";



				menuOptions();
			}​​​​
	}​​​​

