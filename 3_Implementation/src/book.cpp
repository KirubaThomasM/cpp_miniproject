#include "library.h"

void book::additional_info()
{
	cin.ignore();
	cout<<"Enter Author Name: ";      cin.getline(author,20);
}

void book::showauthorinfo()
{
	cout<<"\nAuthor Name: "<<author;
}

int book::search(char *tbuy,char *abuy )	
{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;	
}

void book::buy()	
{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=stock)	
	{
		stock=stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}
