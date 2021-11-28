#ifndef DECLARATION_H
#define DECLARATION_H
//#include "library.h"

int menu();
template <typename T>
T Choosen_item_entry(int);
bool Authenticate();
void New_entry(book *,journal *,news_article *,int);
void search_inputs(char *,char *);
void search_inputs(char *,int *,char *);
void search_inputs(char *,char *, int *);
void Buy_item(book *,journal *,news_article *,int );
bool validate_inputs(char *,int );
void Display_item(book *,journal *,news_article *,int );
void Edit_item(book *,journal *,news_article *,int );
#endif