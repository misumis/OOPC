#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

int main()
{
	try
	{
	 Matrix a(3,3), b(3,3), c(4,4), d(1,1);

       for(unsigned int i = 0; i < 3; i++)
        	for(unsigned int j = 0; j < 3; j++)
        	{
        		a(i,j) = i+j+4;
        		b(i,j) = 1;
        	}
        	
        cout << "a " << a << " b " << b << endl << endl;
        cout << "a(0,0) = " << a(0,0) << " " << "a(1,1) = " << a(1,1) << " " << "a(2,2) = " <<  a(2,2) << endl << endl;
        a(0,0) = 9;
        cout << "a(0,0) = " << a(0,0) << endl << endl;	
       	
        d = a;
        cout << "d = a :" << d << endl;
        if(d == a)
                cout << "d = a :"<< d << endl;
        d = b;
        cout << "d = b : " << d << endl;
                
       
        d = a + b;
        cout << "d = a + b " << d << endl;
        d += b;
        cout << "d += b " << d << endl;
        d += b += a;
        cout << "d += b += a " << d << endl;   
       
       
        c = a + b;
        cout << "c = a + b " << c << endl;
        c += b;
        cout << "c += b " << c << endl;
        c += b += a;
        cout << "c += b += a " << c << endl; 
        
        c = a * b;
        cout << "c = a * b " << c << endl;
        c *= b;
        cout << "c *= b " << c << endl;


        fstream file;
		file.open("matrix.dat", fstream::in);
		Matrix e(file);								
		cout << "Data from matrix.dat file: "<< e << endl;
		file.close();
        
	}
	catch(Out_Of_Range&)
	{
		cout << "Out of Range" << endl;
	}
	catch(Wrong_Dimmension&)
	{
		cout << "Wrong Dimensions" << endl;
	}
	catch(Bad_Alloc&)
	{
		cout << "Out of Memory" << endl;
	}

}
