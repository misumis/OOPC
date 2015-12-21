/*
 * employee.cpp
 *
 *  Created on: 14-11-2012
 *      Author: michal
 */
#include "employee.h"
using namespace std;
Employee::Employee(const char* Name, const char* Position, int Age){
	try{
		this->Name = Name;
	}
	catch(bad_alloc&){
		throw;
	}
	try{
		this->Position = Position;
	}
	catch(bad_alloc&){
		throw;
	}
	this->Age = Age;
}
Employee::Employee(){
	this -> Name = "";
	this -> Position = "";
	this -> Age = 0;
}
Employee::Employee(const Employee& e){
	this->Age = e.Age;
	this->Name=e.Name;
	this->Position=e.Position;

}
Employee::~Employee(){
	this->Name.clear();
	this->Position.clear();
}
Employee& Employee::operator=(Employee& e){
	if(&e == this){
		return *this;
	}
	this->Name=e.Name;
	this->Position=e.Position;
	this->Age = e.Age;
	return *this;
}
ostream& operator<<(ostream& o, const Employee& e){
	o << "Name: " << e.Name << " Position: " << e.Position << " Age: " << e.Age << endl;
	return o;
}


