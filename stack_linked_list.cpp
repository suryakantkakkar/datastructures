#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack*,int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
void peek(struct stack *);
int main()
{
	int val,option;
	do{
	printf("\n Please choose");
	printf("\n Press 1 for push to stack");
	printf("\n Press 2 for pop from stack");
	printf("\n Press 3 to peek the stack");
	printf("\n Press 4 to display");
	printf("\n Press 5 TO Exit");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			printf("\n Enter the number to be pushed on stack");
			scanf("%d",&val);
			top=push(top,val);
			break;
		case 2:
			top=pop(top);
			if(top!=-NULL)
			{
				printf("\n Updated list is");
				top=display(top);
			}
			break;
		case 3:
			peek(top);
			break;
			
		case 4:
			top=display(top);
			break;
			
	}
	}while(option!=5);
	return 0;
}
struct stack *push(struct stack* top,int val)
{
   struct stack *newnode;
   newnode=(struct stack *)malloc(sizeof (struct stack));
   newnode->data=val;
   newnode->next=top;
   top=newnode;
   return top;
   
}
struct stack *pop(struct stack *top)
{
	int val;
	if(top==NULL)
	{
		printf("stack is empty");
		return NULL;
	}
	else
	{
		val=top->data;
		printf("Deleted data is %d",val);
		top=top->next;
		return top;
	}
}
struct stack *display(struct stack *top)
{
	struct stack *ptr;
	if(top==NULL)
	{
		printf("stack is empty");
		return top;
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->next;
		}
		return top;
	}
	
}
void peek(struct stack *top)
{
	if(top==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Peeked data is \n %d",top->data);
	}
}

