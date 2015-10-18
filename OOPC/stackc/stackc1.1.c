#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int *array;
	int size;
	int elements;
}Stack;

void init(Stack *s);
void destroy(Stack* s);
int push(Stack* s, int element);
int pop(Stack* s);
bool isempty(Stack* s);

void show(Stack* s);

int main()
{
	Stack a;
	Stack *p=&a;

	init(p);
	bool check=isempty(p);
	printf("Is stack empty? Let's check: %d\n",check);
	show(p);
	
	

	push(p,7);
	push(p,9);
	push(p,0);
	push(p,2);
	push(p,1);
	push(p,3);
	push(p,5);
	
	show(p);

	pop(p);
	show(p);
	
	check=isempty(p);
	printf("Is stack empty? Let's check: %d\n",check);	
	
	push(p,4);
	show(p);

	pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
	
	destroy(p);

	pop(p);
    pop(p);

	return 0;
}

void init(Stack* s)
{
	s->size=5;
	s->elements=0;
	s->array=(int*)malloc(s->size*sizeof(int));
	if(!(s->array))
	{
		printf("Allocation (init) error!\n\n");
		exit(1);
	}
}

void destroy(Stack* s)
{
	s->elements=0;
	s->size=0;
	free(s->array);
	s->array=NULL;
}

int push(Stack* s, int element)
{
	if(s->elements==s->size) 
	{
		int *aux=s->array;
		s->array=(int*)realloc(aux,(2*(s->size))*sizeof(int));
		
		if(!(s->array))
		{
			printf("Allocation (realloc) error!\n\n");
			//free(aux);
			s->array=aux;
			return 0;
		}
		(s->size)=2*(s->size);
	}
	(s->elements)++;
	*((s->array)+(s->elements-1))=element;
	return 1;
}

int pop(Stack* s)
{
	if(isempty(s)) 
	{
		if (!(s->size))
		{
			printf("Stack's been destroyed.\n");
			abort();
		}
		printf("Stack is empty.\n");
		abort();
	}
	else
	{	
		printf("Popped element: %d\n",*((s->array)+(s->elements-1)));
		(s->elements)--;
		return *((s->array)+(s->elements));
	}	
	
}

bool isempty(Stack* s)
{
	if(s->elements) return false;
	else return true;
}

void show(Stack* s)
{
	int i;
	if(s->elements)
	{
		for(i=0;i<s->elements;i++)
		{
			printf("%d\t",*((s->array)+i));
		}	
	}
	else printf("The stack is empty...");
	printf("\n");
}