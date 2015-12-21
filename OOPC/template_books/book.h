
#include <string.h>
#include <iostream>
#ifndef Book_H_
#define Book_H_
using namespace std;
class Book{
public:
	string Author;
	string Category;
	int Pages;
	string status;
	Book();
	Book(const char * Author, const char * Category, const char *  status, int Pages );
	Book(const Book& e);
	~Book();
	Book& operator=(Book& e);
	friend ostream& operator<<(ostream& o, const Book& e);
};



#endif /* Book_H_ */
