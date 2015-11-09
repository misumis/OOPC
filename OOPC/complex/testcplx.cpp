#include <iostream>
using namespace std;
#include "complex.h"


int main()
{
    Complex a(3,11),b(0,13),c;
	cout << "a : " << a <<"b : " << b <<endl;
    c = 10;
    cout <<"c: "<< c <<endl;
    cout <<"-a : " << -a <<endl;  
	cout <<"a + b : "<< a + b <<endl;  
    cout<< "c-Complex(0,20) : " <<c -Complex(0,20) <<endl;  
	cout <<"10 - a : "<< 10 - a <<endl;
	cout <<"10 * a : "<< 10 * a <<endl;
	cout <<"a * 10 : "<< a * 10 <<endl;
    cout << "c -=b :" << (c -=b) <<endl;
    cout << "c +=b :" << (c +=b) <<endl;
    Complex d(13,14),j(0,1);
	cout << "j * d : " << j * d << endl;
	cout<<"j phase : "<<j.phase() << endl;
	cout << "j Amplitude : " << j.amplitude() << endl;
    cout << "d:" << d << "~d:" << ~d << endl;
    cout <<"a: " << a << "b: " << b << "a*b: "<< (a*b) << endl;
    cout << "d: " << d << "d*2 "<< d*2 <<endl;
    Complex e(3,2), f(1,-1);
    cout << "e :" << e << "f: " << f << "e/f: " << e/f << endl;
    Complex g(3,2), h(3,-2);
    bool i= g==h?true:false; 
    cout << "g :" << g << "h: "<<h<<endl << "g==h? " << i<< endl;
    i= g==(~h)?true:false;
    cout << "g==(~h) " << i<< endl;
    i= (~g)==h?true:false;
    cout << "~g==h " << i << endl; 
}
