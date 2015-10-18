#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 2
typedef struct{
	int* data;
	int top;
	int size;
}Stack;
bool isEmpty(Stack s){
	if(s.top == -1)
	return true;
	else
	return false;
}
int top(Stack s){
	return s.data[s.top];
}
void push(Stack *s, int elem){
	if(s->size <= s->top+1){
		s->size*=2;
		int* new_data=(int*)realloc((void*)(s->data),s->size*sizeof(int));
		if (new_data!=NULL) {
			s->data=new_data;
		}
		else {
			free (s->data);
			puts ("Error (re)allocating memory");
			exit (1);
		}
	}
	s->data[++(s->top)]=elem;
}
int pop(Stack *s){
	int c=0;
	if(s->top>=0){
		c=s->data[s->top];
		s->data[s->top]=0;
		s->top--;
	}
	return c;

}
	void init(Stack* s){
	s->top=-1;
	if(!s->data=(int*)calloc(SIZE,sizeof(int))){
		puts ("Error allocating memory");
		exit (1);
	}
	s->size=SIZE;
}
void destroy(Stack* s){
	free(s->data);
	s->data=NULL;
	s->top=-1;
	s->size=0;
	s=NULL;
}
int main(){
	Stack s;
	init(&s);
	if(isEmpty(s))
	printf("Stack is empty\n");
	push(&s,7);
	if(isEmpty(s))
	printf("Stack is empty\n");
	push(&s,9);
	push(&s,4);
	push(&s,2);
	push(&s,9);
	push(&s,4);
	push(&s,2);
	push(&s,9);
	push(&s,4);
	push(&s,2);
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	if(isEmpty(s))
	printf("Stack is empty\n");
	destroy(&s);
}


