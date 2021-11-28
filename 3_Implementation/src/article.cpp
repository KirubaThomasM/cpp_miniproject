#include "library.h"

void news_article::additional_info()
{
	cout<<"Enter Time Of Day.: ";     cin>>time;
	cout<<"Enter Date: ";    	  	  cin>>date;
}


void news_article::show_article_info()
{
	cout<<"\nTime Of day: "<<time;
	cout<<"\nDate: "<<date;
}


int news_article::search(char *ttbuy,char *tbuy,int dbuy )	
{
	if(strcmp(ttbuy,title)==0 && strcmp(tbuy,time)==0 && (dbuy == date))
		return 1;
	else return 0;	
}


void news_article::buy()	
{
	int count;
	cout<<"\nEnter Number Of news articles to buy: ";
	cin>>count;
	if(count<=stock)	
	{
		stock=stock-count;
		cout<<"\nNews articles Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}