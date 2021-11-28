#include "library.h"

void item::feeddata()	
{
	cin.ignore();
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>price;
	cout<<"Enter Stock Position: ";   cin>>stock;   
}

void item::editdata()	
{
	cout<<"\nEnter Price: ";          cin>>price;
	cout<<"Enter Stock Position: ";   cin>>stock;   
}
void item::showdata()	
{
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<price;
	cout<<"\nStock Position: "<<stock;   
}

int item::search(char *tbuy )	
{
	if(strcmp(tbuy,title)==0 )
		return 1;
	else return 0;	
}

void item::buy()	
{
	int count;
	cout<<"\nEnter Number Of items to buy: ";
	cin>>count;
	if(count<=stock)	
	{
		stock=stock-count;
		cout<<"Items Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}