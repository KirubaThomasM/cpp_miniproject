#include "library.h"
#include "declaration.h"
int i,j,n;
/**
 * @brief Sub menu for user selection
 * @param choice selection variable
 * @return int 
 */
int menu()
{
	int choice;
	cout<<"\n\n\t\tMENU"
		<<"\n1. New Entry"
		<<"\n2. Buy"
		<<"\n3. Search"
		<<"\n4. Edit Details"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		return choice;
}
/**
 * @brief Flexible Item Entry function
 * 
 * @tparam T 
 * @param item_type 
 * @return T 
 */
template <typename T>
T Choosen_item_entry(int item_type)
{
	T temp,temp2;
	temp.feeddata();
	temp.additional_info();
	return true?temp:temp2;
}
/**
 * @brief Admin Authentication function
 * 
 * @return true 
 * @return false 
 */
bool Authenticate()
{
	char admin[10],password[20];
	cout<<"Enter admin ID:";
	cin>>admin;
	cout<<"Enter admin Password:";
	cin>>password;
	if((!strcmp(admin,"admin")) && (!strcmp(password,"iamtheadmin")))
		return false;
	cout<<"Admin authenication Failed\n";
	return true;
}
/**
 * @brief New Item Entry routine
 * 
 * @param B 
 * @param J 
 * @param N 
 * @param item_type 
 */
void New_entry(book *B,journal *J,news_article *N,int item_type) 
{
	if(Authenticate())
		return;
	cout<<"\nAdmin authentication successful\n\n"<<endl;
	if (item_type == 1)
	{
		book temp = Choosen_item_entry<book>(item_type);
		B[i++] = temp;
	}
	else if (item_type == 2)
		J[j++] = Choosen_item_entry<journal>(item_type);
	else if (item_type == 3)
		N[n++] = Choosen_item_entry<news_article>(item_type);
	else
		printf("Invalid Choice \n");
}
/**
 * @brief Get User inputs to search
 * @section function overloading
 * @param titleptr 
 * @param authorptr 
 */
void search_inputs(char *titleptr,char *authorptr)
{
	cout<<"\nEnter Title Of Book: "; cin.getline(titleptr,20);
	cout<<"Enter Author Of Book: ";  cin.getline(authorptr,20);
}
void search_inputs(char *titleptr,int *volumeptr,char *issueptr)
{
	cout<<"\nEnter Title Of Journal: "; cin.getline(titleptr,20);
	cout<<"Enter Volume No.: "; cin>>*volumeptr;
	cout<<"Enter Issue type: "; cin>>*issueptr;
}
void search_inputs(char *titleptr,char *timeptr, int *dateptr)
{
	cout<<"\nEnter Title Of News Article: "; cin.getline(titleptr,20);
	cout<<"Enter time of day: "; cin>>timeptr;
	cout<<"Enter date: "; cin>>*dateptr;
}
/**
 * @brief Buy an item function
 * 
 * @param B 
 * @param J 
 * @param N 
 * @param item_type 
 */
void Buy_item(book *B,journal *J,news_article *N,int item_type)
{
	int t, vol;
	char iss;
	char titlebuy[20],authorbuy[20],timebuy[10];
	int datebuy;
	item *temp;
	if (item_type == 1)
	{
		search_inputs(titlebuy,authorbuy);
		for(t=0;t<i;t++)	
		{
			if(B[t].search(titlebuy,authorbuy))	
			{
				temp = B+t;
				temp->buy();
				return;
			}
		}
	}
	else if (item_type == 2)
	{
		search_inputs(titlebuy,&vol,&iss);
		for(t=0;t<j;t++)	
		{
			if(J[t].search(titlebuy,vol,iss))	
			{
				temp = J+t;
				temp->buy();
				return;
			}
		}
	}
	else
	{
		search_inputs(titlebuy,timebuy,&datebuy);
		for(t=0;t<n;t++)	
		{
			if(N[t].search(titlebuy,timebuy,datebuy))	
			{
				temp = N+t;
				temp->buy();
				return;
			}
		}
	}
	if((t==i && (item_type==1))|| (t==j && (item_type==2)) || (t==n && (item_type==3)))
		cout<<"\nThis Book/Journal/Article is Not in Stock";
}
/**
 * @brief Validate Time format input function
 * 
 * @param time 
 * @param date 
 * @return true 
 * @return false 
 */
bool validate_inputs(char *time,int date)
{
	try
	{
		if(strcmp(time,"morning")||strcmp(time,"evening"))
		 throw "Input error (please use either \"morning\" or \"evening\"";
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
		return true;
	}
	return false;
}
/**
 * @brief Display matched item information
 * 
 * @param B 
 * @param J 
 * @param N 
 * @param item_type 
 */
void Display_item(book *B,journal *J,news_article *N,int item_type)
{
	int t, vol;
	char iss;
	char titlebuy[20],authorbuy[20],timebuy[10];
	int datebuy;
	if (item_type == 1)
	{
		search_inputs(titlebuy,authorbuy);
		for(t=0;t<i;t++)	
		{
			if(B[t].search(titlebuy,authorbuy))	
			{
				cout<<"\nBook Found Successfully";
				B[t].showauthorinfo();
				B[t].showdata();
				return;
			}
		}
	}
	else if (item_type == 2)
	{
		search_inputs(titlebuy,&vol,&iss);
		for(t=0;t<j;t++)	
		{
			if(J[t].search(titlebuy,vol,iss))	
			{
				cout<<"\nJournal Found Successfully";
				J[t].showpublishinfo();
				J[t].showdata();
				return;
			}
		}
	}
	else
	{
		search_inputs(titlebuy,timebuy,&datebuy);
		if (validate_inputs(timebuy,datebuy))
			return;
		for(t=0;t<n;t++)	
		{
			if(N[t].search(titlebuy,timebuy,datebuy))	
			{
				cout<<"\nNews Article Found Successfully";
				N[t].show_article_info();
				N[t].showdata();
				return;
			}
		}
	}
	if((t==i && (item_type==1))|| (t==j && (item_type==2)) || (t==n && (item_type==3)))
		cout<<"\nThis Book/Journal/Article is Not in Stock";
}
/**
 * @brief Edit the existing parameters of items
 * 
 * @param B 
 * @param J 
 * @param N 
 * @param item_type 
 */
void Edit_item(book *B,journal *J,news_article *N,int item_type)
{
	if(Authenticate())
		return;
	int t, vol;
	char iss;
	char titlebuy[20],authorbuy[20],timebuy[10];
	int datebuy;
	if (item_type == 1)
	{
		search_inputs(titlebuy,authorbuy);
		for(t=0;t<i;t++)	
		{
			if(B[t].search(titlebuy,authorbuy))	
			{
				cout<<"\nBook Found Successfully";
				B[t].editdata();
				return;
			}
		}
	}
	else if (item_type == 2)
	{
		search_inputs(titlebuy,&vol,&iss);
		for(t=0;t<j;t++)	
		{
			if(J[t].search(titlebuy,vol,iss))	
			{
				cout<<"\nJournal Found Successfully";
				J[t].editdata();
				return;
			}
		}
	}
	else
	{
		search_inputs(titlebuy,timebuy,&datebuy);
		for(t=0;t<n;t++)	
		{
			if(N[t].search(titlebuy,timebuy,datebuy))	
			{
				cout<<"\nNews Article Found Successfully";
				N[t].editdata();
				return;
			}
		}
	}
	if((t==i && (item_type==1))|| (t==j && (item_type==2)) || (t==n && (item_type==3)))
		cout<<"\nThis Book/Journal/Article is Not in Stock";
}