//C++ program for a casino number guessing game 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void rules() {
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n";
    cout << "\t4. If you cheat the game, you have to pay 5 times of the money bet\n\n" ;
}

int main(){
	string playername;
	int balance, bettingAmount, guess, dice;
	char choice;
	srand(time(0));

	cout << "\n\t\t===========WELCOME TO CASINO !!!===========\n\n";
	cout << "Enter your name: ";
	getline(cin, playername);

	cout <<"\nEnter the starting balance to play in ₹: ";
	cin >> balance;

	do{
		system("cls");
		rules();
		cout << "\n\nYour current balance is: ₹" << balance << endl;

		do{
			cout << "Yo!!, " << playername << ",Enter amount to bet: ₹";
			cin >> bettingAmount;

			if(bettingAmount > balance)
				cout << "Betting amount is more than your balance...!!!\nRe-enter balance: ";
		}while(bettingAmount > balance);

		do{
			cout << "Guess any betting number between 1 & 10: ";
			cin >> guess;
			if(guess <= 0 || guess >10)
				cout << "\nNumber isn't in range of 1 to 10\nRe-enter number: ";
		}while(guess<=0 || guess > 10);

		dice = rand()%10 +1;
		if(dice == guess){
			cout << "\n\nHey you are lucky !!! You have won ₹" << bettingAmount*10 << endl;
			balance = balance + bettingAmount*10;
		}
		else{
			cout << "Oops, better luck next time !! You lost ₹" << bettingAmount << endl;
			balance = balance - bettingAmount;
		}

		cout << "The winning number is: " << dice << endl;
		cout << "\nHey, " << playername << "your current balance is: " << balance << endl;

		if(balance == 0){
			cout << "You have no money to play !!!";
			break;
		}

		cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is ₹" << balance << "\n\n";
    return 0;
}

