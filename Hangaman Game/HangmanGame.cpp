#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_TRIES=5;
int letterFill(char guess, string secretword, string &guessword){
	int i, matches=0, l=secretword.length();
	for(i=0; i<l; i++){
		if(guess = guessword[i])
			return 0;
		if(guess = secretword[i]){
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

int main(){
	string name, word;
	char letter;
	int num_of_wrong_guesses = 0;
	string words[] = {"india", "nepal", "malaysia","philippines","australia","usa","iran","ethiopia","oman","indonesia","pakistan"};

	//choose and cop a word from array of words randomly 
	srand(time(NULL));
	int n = rand()%10;
	word = words[n];

	string unknown(word.length(), '*');

	cout << "\n\nWelcome to hangman...Guess the country name";
	cout << "\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "you have " << MAX_TRIES << " tries to try and guess the word !";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while(num_of_wrong_guesses < MAX_TRIES){
		cout << "\n\n" << unknown;
		cout << "\n\nGuess the letter: ";
		cin >> letter;
		//fill the secret word with letter if the guess is correct, otherwise increment of wrong guess
		if(letterFill(letter, word, unknown) == 0){
			cout << endl << "Whoops !That letter isn't there !!!" << endl;
			num_of_wrong_guesses++;
		}
		else
			cout << endl << "You found a letter !" << endl;

		cout << "You have " << MAX_TRIES- num_of_wrong_guesses << " guess left !";

		if(word == unknown){
			cout << word << endl;
			cout << "You got it !!";
			break;
		}
	}

	if(num_of_wrong_guesses == MAX_TRIES){
		cout << "\nSorry, you loose...You've been hanged !"<<endl;
		cout << "Correct word is: " << word << endl;
	}

	cin.ignore();
	cin.get();
	return 0;


}