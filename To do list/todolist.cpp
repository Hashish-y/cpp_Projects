#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
 
using namespace std;
 
string path;
ofstream the_path(path.c_str(), ios::out);
 
void clean_buffer() {
 
    cin.clear();
    cin.sync();
 
}
 
void addItems(int amount_items) {
    clean_buffer();
    ofstream add(path.c_str(), ios::app);
    string item;
    for(int i = 1; i <= amount_items; i++) {
        cout << "Enter item #" << i << " ";
        getline(cin, item);
        add << item << endl;
    }
    add.close();
    cout << endl;
 
}
 
int menu() {
 
    int choice;
    cout << "\t The Menu\n" << endl;
    cout << "[1] - Show To Do list." << endl;
    cout << "[2] - Add new items to To Do list." << endl;
    cout << "[3] - Remove items from To Do list." << endl;
    cout << "[4] - Exit the program." << endl;
    cin >> choice;
    cout << endl;
 
        return choice;
}
 
bool showList() {
    bool stop = true;
    cout << "\t The To Do List\n" << endl;
    string line;
    ifstream show(path.c_str(), ios::in);
    getline(show, line);
    if(show.eof()) {
        cout << "\t**********************" << endl;
        cout << "\t*To Do list is empty.*" << endl;
        cout << "\t**********************" << endl;
            return stop;
    }
    for(int i = 1; !show.eof(); i++) {
        cout << i << "." << " " << line << endl;
        getline(show, line);
 
    }
    show.close();
    cout << endl;
 
 
 
}
 
void removeItems() {
 
    int choice;
    bool check = showList();
    if (check == true) {
        cout << endl;
        cout << "There are no items to remove." << endl;
        exit(1);
    }
    clean_buffer();
    int a_items;
    ifstream removeFile(path.c_str(), ios::in);
    cout << "How many items do you want to remove?" << endl;
    cin >> a_items;
    vector <int> items;
    clean_buffer();
    for(int k = 1; k <= a_items; k++) {
            int item;
            cout << "Item #" << k << " - " ;
            cin >> item;
            if(k != item) {
                items.push_back(item);
            }
    }
    removeFile.close();
    ofstream outFile(path.c_str(), ios::out);
    for (int i = 0 ; i < items.size(); i++)
            outFile << items[i] << endl;
    outFile.close();
 
    return ;
}
 
int main()
{
    system("COLOR A");
    cout << "Enter the path of your file: ";
    cin >> path;
    cout << "Path has been set up.\n" << endl;
    system("COLOR FC");
    bool working = true;
    cout << "Welcome to To-Do list program!\n" << endl;
    int choice;
    do {
 
        int choice = menu();
 
        switch(choice) {
 
            case 1:
                showList();
                break;
            case 2:
                int amount;
                cout << "\t Add New Items\n" << endl;
                cout << "Enter how many items do you want to add: ";
                clean_buffer();
                cin >> amount;
                addItems(amount);
                break;
            case 3:
                removeItems();
                break;
            case 4:
                cout << "Have a nice day!" << endl;
                working = false;
                break;
            default:
                cout << "Input was not recognized. Try again or "
                     << "\nenter 4 to exit." << endl;
                     bool working = true;
 
 
        }
    } while (working == true);
 
 
    return 0;
}