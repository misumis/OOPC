/*
 * employee.h
 *
 *  Created on: 14-11-2012
 *      Author: michal
 */
#include <string.h>
#include <iostream>
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
using namespace std;
class Employee{
public:
	string Name;
	string Position;
	int Age;
	Employee();
	Employee(const char * name, const char * position, int age);
	Employee(const Employee& e);
	~Employee();
	Employee& operator=(Employee& e);
	friend ostream& operator<<(ostream& o, const Employee& e);
};



#endif /* EMPLOYEE_H_ */
