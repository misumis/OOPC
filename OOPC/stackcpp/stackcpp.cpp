#include <iostream>
#include <cstdlib>
using namespace std;

class stack { 
  char *stackData; 
  int topOfStack;  
  int size;        
public:
  stack(int s);    
  ~stack();        
  void push(char ch); 
  char pop();
};

stack::stack(int s)
{
  cout << "Constructing a stack\n";
  topOfStack = 0;
  stackData = (char *) malloc(s);
  if(!stackData) {
    cout << "Allocation error\n";
    exit(1);
  }
  size = s;
}

stack::~stack()
{
  free(stackData);
}

void stack::push(char ch)
{
  if(topOfStack==size) {
    cout << "Stack is full\n";
    return;
  }
  stackData[topOfStack] = ch;
  topOfStack++;
}

char stack::pop()
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
  stack stackObject1(10), stackObject2(10); 
  int i;

  stackObject1.push('a');
  stackObject2.push('x');
  stackObject1.push('b');
  stackObject2.push('y');
  stackObject1.push('c');
  stackObject2.push('z');

  for(i = 0; i <3; i++) 
     cout << "Pop stackObject1: " << stackObject1.pop() << endl;
  for(i = 0; i <3; i++) 
     cout << "Pop stackObject2: " << stackObject2.pop() << endl;

  return 0;
}