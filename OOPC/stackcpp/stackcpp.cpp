#include <iostream>
#include <cstdlib>
using namespace std;

class stack { 
  int *stackData; 
  int topOfStack;  
  int size;        
public:
  stack()  ;
  ~stack() ;  
  void push(int ch); 
  int pop();
};

stack::stack()
{
  topOfStack=0;
  size=2;
  stackData =(int*) malloc( size*sizeof(int));
}

stack::~stack()
{
  free(stackData);
  topOfStack=0;
}

void stack::push(int ch)
{
  if(topOfStack==size) {
	size*=2;
	stackData=(int*)realloc(stackData,((size))*sizeof(int));
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
    exit(0); 
  }
  topOfStack--;
  return stackData[topOfStack]+1;
}

int main()
{
  stack stackObject1; 
  int i;

  stackObject1.push(2);
  
  stackObject1.push(3);
  
  stackObject1.push(4);
  

  for(i = 0; i <3; i++) 
     cout << "Pop stackObject1: " << stackObject1.pop() << endl;

  return 0;
}