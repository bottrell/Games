#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include "ctype.h"
//#include <stdlib.h> srand, rand
//#include <time.h>
using namespace std;

// srand(time(NULL));
// rand%

//printGameBoard declaration
void printGameBoard(string gameWord, vector<char> guessed_letters);
// getPlayerInput declaration
char getPlayerInput(string name, vector<char> gl);
// isInside declaration
bool isInside(string gameString, char guess);
// lossEndGame declaration
void lossEndGame(string gamePhrase);
// winEndGame declaration
void winEndGame(string playername, string gamePhrase, int lives);
// checkIfWin declaration
bool checkIfWin(string random_element, vector <char> guessed_letters);

//printGameBoard definiton
void printGameBoard(string random_element, vector<char> guessedLetters) {
	std::cout << "******************************" << endl;


	for (int i = 0; i < random_element.length(); i++) {

		bool alreadyGuessedUpper = find(begin(guessedLetters), end(guessedLetters), toupper(random_element[i])) != end(guessedLetters);
		bool alreadyGuessedLower = find(begin(guessedLetters), end(guessedLetters), tolower(random_element[i])) != end(guessedLetters);

		// if the character is a space, print out a space
		if (random_element[i] == ' ') {
			std::cout << " ";
		}
		// if the character is already guessed (in guessedLetters), print out the letter
		else if (alreadyGuessedLower == true) {

			std::cout << random_element[i];

		}
		else if (alreadyGuessedUpper == true) {
			std::cout << random_element[i];
		}
		// if the character isn't alphanumeric, print it out
		else if (isalnum(random_element[i]) == false) {
			std::cout << random_element[i];
		}
		// else print out an underscore (player still needs to guess that character)
		else {

			std::cout << "_";
		}

	}
	
	std::cout << endl << "******************************" << endl;
	return;
}

//function definition of getPlayerInput
char getPlayerInput(string name, vector<char> gl) {
	std::cout << name << ", guess a letter or guess the phrase!" << endl;

	char playerGuess = ' ';
	bool alreadyGuessed = true;
	
	while (alreadyGuessed = true) {
		cout << "> ";
		cin >> playerGuess;
		if (std::find(gl.begin(), gl.end(), playerGuess) != gl.end()) {
			cout << "You've already guessed that letter!" << endl;

		}
		else {
			break;
		}
	}

	for (int i = 0; i < 32; i++) {
		cout << endl;
	}
	return playerGuess;
}

//isInside definition
bool isInside(string gameString, char g) {
	return gameString.find(g) != std::string::npos;
}

//lossEndGame definition
void lossEndGame(string gamePhrase) {
	//endGame
	for (int i = 0; i < 32; i++) {
		cout << endl;
	}
	cout << "***************************************************" << endl;
	cout << "You ran out of lives! Better Luck Next Time! xD" << endl;
	cout << "The phrase was '" << gamePhrase << "'" << endl;
	cout << "***************************************************" << endl;

	return;
}

//winEndGame definition
void winEndGame(string playername, string gamePhrase, int lives) {
	//endGame
	for (int i = 0; i < 32; i++) {
		cout << endl;
	}
	cout << "***************************************************" << endl;
	cout << "You Win!" << endl;
	cout << "The phrase was '" << gamePhrase << "'" << endl;
	cout << "You had " << lives << " lives remaining" << endl;
	cout << "***************************************************" << endl;
	return;
}

bool checkIfWin(string random_element, vector <char> guessedLetters) {
	string testString = " ";
	for (int i = 0; i < random_element.length(); i++) {

		bool alreadyGuessedUpper = find(begin(guessedLetters), end(guessedLetters), toupper(random_element[i])) != end(guessedLetters);
		bool alreadyGuessedLower = find(begin(guessedLetters), end(guessedLetters), tolower(random_element[i])) != end(guessedLetters);
	
		// if the character is a space, print out a space
		if (random_element[i] == ' ') {
			testString+=(" ");
		}
		// if the character is already guessed (in guessedLetters), print out the letter
		else if (alreadyGuessedLower == true) {

			testString += ( random_element[i]);

		}
		else if (alreadyGuessedUpper == true) {
			testString += ( random_element[i]);
		}
		// if the character isn't alphanumeric, print it out
		else if (isalnum(random_element[i]) == false) {
			testString += (random_element[i]);
		}
		// else print out an underscore (player still needs to guess that character)
		else {

			testString += "_";
		}

	}
	
	for (int x = 0; x < random_element.length(); x++) {
		if (isInside(testString, toupper(random_element[x])) == 0 || isInside(testString, tolower(random_element[x])) == 0) {
			return false;
			}
	}	
		return true;

}

// Vector storing the phrases that will be picked for the game
vector<string> phrases = { "This is Hard", "So many possibilities", "School of Information", "Peter's Pipe", "University of Michigan" };




//main game loop
int main() {
	//Enter the player's name
	for (int i = 0; i < 32; i++) {
		cout << endl;
	}
	string playerName = "Player1";
	std::cout << "Player1, what is your name?" << endl << "> ";
	std::cin >> playerName;
	for (int i = 0; i < 32; i++) {
		cout << endl;
	}

	// chooses a random phrase from the 'phrases' vector
	random_device random_device;
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> dist(0, phrases.size() - 1);
	string random_element = phrases[dist(engine)];

	//character vector of guessed letters
	vector<char> guessedLetters = {};

	int numLives = 5;
	bool isWin = false;
	
	// main game loop
	while (numLives > 0 && isWin == false) {
		//check if isWin == true
		isWin = checkIfWin(random_element, guessedLetters);
		if (isWin) {
			break;
		}
		
		char guess = ' ';
		printGameBoard(random_element, guessedLetters);
		guess = getPlayerInput(playerName, guessedLetters);	

		//adds guess to guessedLetters
		guessedLetters.push_back(guess);
		//print out letters the player has already guessed
		cout << "Guessed Letters: ";
		for (int i = 0; i < guessedLetters.size(); i++) {
			cout << guessedLetters[i] << ",";
		}
		cout << endl;

		cout << "Lives Remaining: ";
		// checks if the guess was inside of random_element, if it isn't, lose a life.
		if (isInside(random_element, toupper(guess)) == 1 || isInside(random_element, tolower(guess)) == 1) {
			numLives = numLives;
		}
		else {
			numLives--;
		}
		cout << numLives << endl;

		//end of game loop
	}

	if (isWin == true) {
		winEndGame(playerName, random_element, numLives);
	}
	
	else if (isWin == false) {
		lossEndGame(random_element);
	}


	return 0;
}
