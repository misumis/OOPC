#include <iostream>
using namespace std;
#include "complex.h"


int main()
{
    Complex a(0.0,15),b(0,13),c;
    c = 10;
    cout << c <<endl;
    c = -a;
    cout << c <<endl;  
    c = a + b;
    c = c - Complex(10);
    cout << c <<endl;  
    c = 10 - a;
    (c -=b) -=10;
    cout << c <<endl;
    Complex d(13,14);
    cout << "d:" << d << "~d:" << ~d << endl;
    cout <<"a: " << a << "b: " << b << "a*b: "<< (a*b) << endl;
    cout << "d: " << d << "d*2 "<< d*2 <<endl;
    Complex e(3,2), f(1,-1);
    cout << "e :" << e << "f: " << f << "e/f: " << e/f << endl;
    Complex g(3,2), h(3,-2);
    int i= g==h?1:0; 
    cout << "g :" << g << "h: "<<h << "g==h? " << i<< endl;
    i= g==(~h)?1:0;
    cout << "g==(~h) " << i;
    i= (~g)==h?1:0;
    cout << " ~g==h " << i << endl; 
}
