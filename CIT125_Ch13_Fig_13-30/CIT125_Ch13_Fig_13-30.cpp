// CIT125 Intro To C++ Luigi Robles
// 08-02-2020 Summer Term
// Ch.13 pg.491 Fig.13-27
// Guess the Word Game

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	//declare and initialize variables
	string origWord = "";
	string letter = "";
	char dashReplaced = 'N';
	char gameOver = 'N';
	int numIncorrect = 0;
	string displayWord = "-----";

	//get original word
	while (origWord.length() != 5) //while loop to verify word length
	{
		cout << "Enter a 5-letter word in uppercase: ";
		getline(cin, origWord); //input for word to guess
	} //end while

	system("cls"); //clear the screen

	//start guessing 
	cout << "Guess this word: " <<
		displayWord << endl;
	while (gameOver == 'N') //game loop
	{
		cout << "Enter an uppercase letter: ";
		cin >> letter; //input for letter guessed

		//search for the letter in the original word
		for (int x = 0; x < 5; x += 1) //nested for loop
		{
			//if the current character matches
			//the letter, replace the corresponding 
			//dash in the displayWord variable and then
			//set the dashReplaced variable to 'Y'
			if (origWord.substr(x, 1) == letter) //nested if statement
			{
				displayWord.replace(x, 1, letter);
				dashReplaced = 'Y';
			} //end if
		} //end for

		//if a dash was replaced, check wheter the
		//displayWord variable contains another dash
		if (dashReplaced == 'Y')
		{
			//if the displayWord variable does not
			//contain any dashes, the game is over
			if (displayWord.find("-", 0) == -1)
			{
				gameOver = 'Y';
				cout << endl << "Yes, the word is "
					<< origWord << endl;
				cout << "Great guessing!" << endl;
			}
			else //otherwise, continue guessing
			{
				cout << endl << "Guess this word: "
					<< displayWord << endl;
				dashReplaced = 'N';
			} //end if
		}
		else //processed when dashReplaced contains 'N'
		{
			//add 1 to the number of incorrect guesses
			numIncorrect += 1;
			//if the numbe of incorrect guesses is 10,
			// the game is over
			if (numIncorrect == 10)
			{
				gameOver = 'Y';
				cout << endl << "Sorry, the word is "
					<< origWord << endl;

			} //end if
		} //end if
	} //end while
	return 0;
} //end of main function