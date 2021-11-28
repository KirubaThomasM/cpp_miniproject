#include "library.h"

void journal::additional_info()
{
	cout<<"Enter Volume No.: ";       cin>>volume;
	cout<<"Enter Issue: ";    	  	  cin>>issue;
}

void journal::showpublishinfo()
{
	cout<<"\nVolume No.: "<<volume;
	cout<<"\nIssue: "<<issue;
}

int journal::search(char *tbuy, int vol, char iss )	
{
	if(strcmp(tbuy,title)==0 && vol == volume && iss == issue)
		return 1;
	else return 0;	
}

void journal::buy()	
{
	int count;
	cout<<"\nEnter Number Of journals to buy: ";
	cin>>count;
	if(count<=stock)	
	{
		stock=stock-count;
		cout<<"\njournals Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}

