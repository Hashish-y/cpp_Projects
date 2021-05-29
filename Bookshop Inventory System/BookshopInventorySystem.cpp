#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class book{
private:
	char *author, *title, *publisher;
	float *price;
	int *stock;

public:
	book(){
		author = new char[20];
		title = new char[20];
		publisher = new char[20];
		price = new float;
		stock = new int;
	}

	void feeddata();
	void editdata();
	void showdata();
	int search(char[], char[]);
	void buybook();
};

void book::feeddata(){
	cin.ignore();
	cout << "\nEnter Author name: "; 
	cin.getline(author, 20);

	cout << "Enter Book Title: " ;   
	cin.getline(title, 20);

	cout << "Enter publisher name: "; 
	cin.getline(publisher, 20);

	cout << "Enter price: "; 
	cin >> *price;

	cout << "Enter stock position: "; 
	cin >> *stock;

}

void book::editdata()	{
	
	cout<<"\nEnter Author Name: ";      
	cin.getline(author,20);

	cout<<"Enter Title Name: ";       
	cin.getline(title,20);

	cout<<"Enter Publisher Name: ";   
	cin.getline(publisher,20);

	cout<<"Enter Price: ";            
	cin>>*price;

	cout<<"Enter Stock Position: ";   
	cin>>*stock;   
	
}

void book::showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;   
	
}

int book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;
		
}

void book::buybook()	{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}

int main(){
	book *B[20];

	int i=0,r,t,choice;
    char titlebuy[20], authorbuy[20];

    while(1){
    	cout << "\n\n\t\tMENU\n";
    	cout << "1.Entry of new book \n2.Buy book\n3.Search for a book\n4.Edit book details\n5.Exit";
    	cout << "\nEnter your choice: "; cin >> choice;

    	switch(choice){
    		case 1: B[i] = new book;
    		        B[i]->feeddata();
    		        i++;  
    		        break;

    		case 2: cin.ignore();
    		        cout << "\nEnter title of the book: "; 
    		        cin.getline(titlebuy, 20);

    		        cout << "Enter Author of book: ";
    		        cin.getline(authorbuy, 20);

    		        for(t =0; t<i; t++){
    		        	if(B[t]->search(titlebuy, authorbuy)){
    		        		B[t]->buybook();
    		        		break;
    		        	}
    		        }
    		        if(t==1)
    		        	cout << "\nThis book isn't in stock";
                    
                    break;

    		case 3: cin.ignore();
    		        cout << "\nEnter title of book: ";
    		        cin.getline(titlebuy,20);

    		        cout << "Enter author of the book: ";
    		        cin.getline(authorbuy, 20);

    		        for(t=0; t<i; t++){
    		        	if(B[t]->search(titlebuy,authorbuy)){
    		        		cout << "\nBook found successfully";
    		        		B[t]->showdata();
    		        		break;
    		        	}
    		        }        
    		        if(t==i)
    		        	cout<<"\nThis Book is Not in Stock";

    		        break;

    		case 4: cin.ignore();
    		        cout << "\nEnter title of the book: ";
    		        cin.getline(titlebuy,20);

    		        cout << "Enter author of the book: ";
    		        cin.getline(authorbuy,20);
                    
                    for(t=0; t<i; t++){
    		        	if(B[t]->search(titlebuy,authorbuy)){
    		        		cout << "\nBook found successfully";
    		        		B[t]->showdata();
    		        		break;
    		        	}
    		        }        
    		        if(t==i)
    		        	cout<<"\nThis Book is Not in Stock";

    		        break;
            
            case 5: exit(0);

            default: cout << "\nInvalid choice";

    	}
    }

    return 0;
}