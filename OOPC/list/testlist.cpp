#include <iostream>
using namespace std;
#include "list.h"


void
PrintList (list& toPrint, ostream & Out)
{
  int nextValue;
  Out << "Printing list contents: " << endl;
  toPrint.goToHead ();
  if (!toPrint.moreData ())
    {
      Out << "List is empty" << endl;
      return;
    }
  while (toPrint.moreData ())
    {
      nextValue = toPrint.getCurrentData ();
      Out << nextValue << " ";
      toPrint.advance ();
    }
  Out << endl;
}

int
main ()
{
  list l;
  l.insert (1);
  l.insert (2);
  l.insert (3);

  
  PrintList (l, cout);
  list l2;
  l2.insert (4);
  l2.insert (5);
  l2.insert (6);
  l2.insert (7);
  l.goToHead();
  l.advance();
  l.advance();
  l2=l;
  cout<< "Pointer points to: " << l.getCurrentData()<<endl;
  cout<< "Pointer points to: " << l2.getCurrentData()<<endl;
  PrintList (l2,cout);
  
  l.insert(8);
  
  l.goToHead();
  l.advance();
  l.advance();
  l.advance();
  l2=l;
  cout<< "Pointer points to: " << l.getCurrentData()<<endl;
  cout<< "Pointer points to: " << l2.getCurrentData()<<endl;
  PrintList(l2,cout);
  l.goToHead();
  l.advance();
  l.advance();
  l2=l;
  cout<< "Pointer points to: " << l.getCurrentData()<<endl;
  cout<< "Pointer points to: " << l2.getCurrentData()<<endl;
   PrintList(l2,cout);
}
