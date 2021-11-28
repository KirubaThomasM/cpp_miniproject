#include "library.h"
#include "declaration.h"

/**
 * @brief main routine
 * 
 * @return int 
 */
int main()	
{
	book B[20];
	journal J[20];
	news_article N[20];
	int type,choice;
	while(1)	
	{
		cout<<"\n**********Welcome to E-library*********\n";
		cout<<"\nEnter\n	1 for book\n	2 for journals\n	3 for News Articles\n	4 to quit\n";           
		cin>>type;
		if(type < 1 || type > 3)
		{
			cout<<"User requested quit";
			exit(0);
		}
		choice = menu();
	switch(choice)	
	{
		case 1:
			New_entry(B,J,N,type);
			break;	
		case 2: 
			cin.ignore();
			Buy_item(B,J,N,type);
			break;
		case 3: 
			cin.ignore();
			Display_item(B,J,N,type);
			break;
		case 4: 
			cin.ignore();
			Edit_item(B,J,N,type);
			break;
		case 5: exit(0);
		default: cout<<"\nInvalid Choice Entered";
		}
	}
	return 0;
}