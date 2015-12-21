#include <iostream>
using namespace std;


#include "map_template.h"		//defines template map_template<Key,Value>
#include "book.h"
int main(void)
{

	
	
	typedef string Title;
	map_template<Title,Book> Database_Books;					//Database of books
	Database_Books.Add("Lot",Book("Eldo","Crime","not available",228)); 		
	cout << Database_Books << endl;							//Print databese

	map_template<string,Book> NewDatabase_Books = Database_Books;	//Make a copy of database
	
	Book* bK;
	bK = NewDatabase_Books.Find("Lot");					//Find employee using its ID
	bK->Author = "Ken Kesey";							//Modify the position of employee
														//Modify the age of employee

	Database_Books = NewDatabase_Books;								//Update original database
	
	cout << Database_Books << endl;							//Print original databese
	
}
