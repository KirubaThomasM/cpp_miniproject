#ifndef LIBRARY_H
#define LIBRARY_H

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
//int i,j,n;

/**
 * @brief parent class item blueprint
 * 
 */
class item	
{
private:
	char publisher[20];
	float price;
	int stock;
	char title[20];
public:	
	void feeddata();
	void editdata();
	void showdata();
	int search(char[]);
	virtual void buy();
	friend class book;
	friend class journal;
	friend class news_article;
};
/**
 * @brief class book blueprint
 * 
 */
class book:public item
{
private:
	char author[20];
public:
    book(){}
    book(const book &b)
    {
		cout<<"\nNew entry is made successfully"<<endl;
        strcpy(author,b.author);
        strcpy(title,b.title);
        strcpy(publisher,b.publisher);
        price = b.price;
        stock = b.stock;
    }
	void additional_info();
	void showauthorinfo();
	int search(char[],char[]);
	void buy();
};
/**
 * @brief class journal blueprint
 * 
 */
class journal:public item
{
private:
	int volume;
	char issue;
public:
	void additional_info();
	void showpublishinfo();
	int search(char[],int,char);
	void buy();
};
/**
 * @brief class news article blueprint
 * 
 */
class news_article:public item
{
private:
	char time[10];
	int date;
public:
	void additional_info();
	void show_article_info();
	int search(char[],char[],int);
	void buy();
};

#endif //__LIBRARY_H__