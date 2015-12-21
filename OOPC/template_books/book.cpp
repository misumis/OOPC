

#include "book.h"
using namespace std;
Book::Book(const char* Author, const char* Category, const char* status, int Pages){
	try{
		this->Author = Author;
	}
	catch(bad_alloc&){
		throw;
	}
	try{
		this->Category = Category;
	}
	catch(bad_alloc&){
		throw;
	}
	this->Pages = Pages;
}
Book::Book(){
	this -> Author = "";
	this -> Category = "";
	this->status = status;
	this -> Pages = 0;
}
Book::Book(const Book& e){
	this->Pages = e.Pages;
	this->Author=e.Author;
	this->status = e.status;
	this->Category=e.Category;

}
Book::~Book(){
	this->Author.clear();
	this->status.clear();
	this->Category.clear();
}
Book& Book::operator=(Book& e){
	if(&e == this){
		return *this;
	}
	this->Author=e.Author;
	this->Category=e.Category;
	this->status = e.status;
	this->Pages = e.Pages;
	return *this;
}
ostream& operator<<(ostream& o, const Book& e){
	o << "Author: " << e.Author << " Category: " << e.Category << " Status: " << e.status<< " Pages: " << e.Pages << endl;
	return o;
}



