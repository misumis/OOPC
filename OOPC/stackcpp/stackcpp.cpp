#include <iostream>
#include <cstdlib>
using namespace std;

class stack { 
  int *stackData; 
  int topOfStack;  
  int size;        
public:
  stack() {cout << "Stack Constructed\n"; }   
  ~stack(){cout << "Stack Deconstructed\n"; }    
  void push(int ch); 
  int pop();
};


void stack::push(int ch)
{
  if(topOfStack==size) {
	*stackData=(int*)realloc(ch,(2*(size))*sizeof(int));
    cout << "Stack is full\n";
    return;
  }
  stackData[topOfStack] = ch;
  topOfStack++;
}

int stack::pop()
{
  if(topOfStack==0) {
    cout << "Stack is empty\n";
    return 0; // return null on empty stack 
  }
  topOfStack--;
  return stackData[topOfStack];
}

int main()
{
  stack stackObject1; 
  int i;

  stackObject1.push(1);
  
  stackObject1.push(2);
  
  stackObject1.push(3);
  

  for(i = 0; i <3; i++) 
     cout << "Pop stackObject1: " << stackObject1.pop() << endl;

  return 0;
}