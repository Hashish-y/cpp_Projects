/*C++ progarm for Login System with registration adn file storing file system
In the same way we can use for storing other information also   */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsloggedIn(){
	string username, password, un, pw;
	cout << "Enter user name: ";
	cin >> username;

	cout << "Enter password: ";
	cin >> password;

	ifstream read("c:\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password){
    	return true;
    }
    else
    	return false;
}

int main(){
	int choice;

	cout << "1.Register \n2.Login \nYour choice: "; 
	cin >> choice;

	if(choice == 1){
		string username, password;

		cout << "Select a user name: ";
		cin >> username ;
		cout << "Select a password: ";
		cin >> password;

		ofstream file;
		file.open("c:\\" + username + ".txt");
		file << username << endl << password ;
		file.close(); 		

		main();
	}

	else if(choice == 2){
		bool status = IsloggedIn();

		if(status){
			cout << "False login..!!" << endl;
			system("PAUSE");
			return 0; 
		}
		else
		{
			cout << "Succesfully Logged in..!!!" << endl;
			system("PAUSE");
			return 1;
		}
	}
}
