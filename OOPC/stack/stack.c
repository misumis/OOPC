#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define SIZE 2

typedef struct{
	int top;
	int* data;
	int size;
}Stack;

bool isEmpty(Stack s){
  if(s.top==-1)
	return true;
  else
	return false;
}

int top(Stack s){
  return s.data[s.top];
}


void push(Stack *s,int elem){
 assert(s->top<SIZE);
	s->data[s->top++]=elem;
}
/*
void push(Stack* s, int element)
{
        if(s->top==s->size)
        {
                int *aux=s->data;
                s->data=(int*)realloc(aux,(s->size+5)*sizeof(int));
               
                if(!(s->data))
                {
                        printf("Allocation (realloc) error!\n\n");
                        //free(aux);
                        s->data=aux;
                        exit(1);
                }
                (s->size)+=5;
        }
        (s->top)++;
        *((s->data)+(s->top-1))=element;
        

    }

*/
int pop(Stack *s){
  int count =0;
  if (s->top>=0){
	count=s->data[s->top];
	s->data[s->top]=0;
	(s->top)--;
  }
  return count;
}

void stop(Stack* s){
  free(s->data);
  s->data=NULL;
  s->top=-1;
  s->size=0;
  s=NULL;
}

void initialize(Stack* s){
	s->top=-1;
	if(!s->data=(int*)calloc(SIZE,sizeof(int))){
		puts ("Error allocating memory");
		exit (1);
	}
	s->size=SIZE;
}


int main(){
	Stack s;
	initialize(&s);
	if(isEmpty(s))
	printf("Stack is empty\n");
	push(&s,7);
	if(isEmpty(s))
	printf("Stack is empty\n");
	push(&s,8);
	push(&s,2);
	push(&s,2);
	push(&s,7);
	push(&s,6);
	push(&s,5);
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	if(isEmpty(s))
	printf("Stack is empty\n");
	stop(&s);
}
