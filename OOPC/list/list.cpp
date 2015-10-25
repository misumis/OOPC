#include <iostream>
using namespace std;
#include "list.h"

list::list ()
{
  head = NULL;
  current = NULL;
}

list::~list ()
{
  while (head)
    {
      node *t = head->next;
      delete head;
      head = t;
    };
}

void
list::insert (int a)
{
  node *t = new node;
  t->next = head;
  head = t;
  head->val = a;
}

void
list::goToHead ()
{
  current = head;
}

int
list::getCurrentData ()
{
  return current->val;
}

void
list::advance ()
{
  current = current->next;
}

bool
list::moreData ()
{
  if (current)
    return true;
  else
    return false;
}

list::list (const list & l)
{
  current=NULL;
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  while (src)
    {
      *dst = new node;
      (*dst)->val = src->val;
      (*dst)->next = NULL;
      if(src==l.current)
        current=*dst;
      src = src->next;
      dst = &((*dst)->next);
    }
}

list & list::operator= (const list & l)
{
  if (&l == this)
    return *this;
  current=NULL;
  while (head)
    {
      node *t =	head->next;
      delete head;
      head = t;
    };
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  while (src)
    {
      *dst = new node;
      (*dst)->val = src->val;
      (*dst)->next = NULL;
      if(src==l.current)
        current=*dst;
      src = src->next;
      dst = &((*dst)->next);
    }
  return *this;
}
