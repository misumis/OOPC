#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int info;
    struct Stack *ptr;
}
*top,*top1,*temp;

int top_element();
void push(int data);
void pop();
void isempty();
void display();
void empty_stack();


int count = 0;
int main(){
	
	
	isempty();
	push(1);
	isempty();
	push(2);
	push(3);
	push(4);
	push(5);
	printf("\n");
	display();
	pop();
	pop();
	pop();
	printf("\n");
	display();
	pop();
	pop();
	printf("\n");
	display();
	printf("\n");
	exit(1);
}

void empty_stack() {
    top = NULL;
}

void push(int data) {
    if (top == NULL) {
	top =(struct Stack *)malloc(1*sizeof(struct Stack));
	top->ptr = NULL;
	top->info = data;
    }
    else {
	temp =(struct Stack *)malloc(1*sizeof(struct Stack));
	temp->ptr = top;
	temp->info = data;
	top = temp;
    }
    count++;
}

void display() {
    top1 = top;

    if (top1 == NULL) {
	printf("Stack is empty");
	return;
    }
    while (top1 != NULL) {
	printf("%d ", top1->info);
	top1 = top1->ptr;
    }
}

void pop() {
    top1 = top;

    if (top1 == NULL) {
	printf("\n Error : Trying to pop from empty stack");
	return;
    }
    else
    top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
}

int top_element() {
    return(top->info);
}

void isempty()
{
if (top == NULL)
printf("\n Stack is empty\n");
else
printf("\n Stack is not empty with %d elements\n", count);
}
