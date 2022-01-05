#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void push(int *,int);
int pop(int *);
void display(int *);
int peek(int *);
int top=-1,n;
int main()
{
    printf("Please insert the size of stack");
    scanf("%d",&n);
    int *st=new int[n];  
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
			push(st,val);
			break;
		case 2:
			val=pop(st);
			if(val!=-1)
			{
				printf("Value deleted from stack is %d",val);
			}
			break;
		case 3:
			val=peek(st);
			printf("peek value is %d",val);
			break;
		case 4:
			display(st);
			break;
			
	}
	}while(option!=5);
	return 0;
}
void push(int *st,int val)
{
	if(top==n-1)
	{
		printf("stack full");
	}
	else
	{
		top=top+1;
		st[top]=val;
	}
}
void display(int *st)
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("\n %d",st[i]);
	}
}
int pop(int *st)
{
	int val;
	if(top==-1)
	{
		printf("stack is  empty");
		return -1;
	}
	else
	{
		val=st[top];
		top=top-1;
		return val;
	}
}
int peek(int *st)
{
	int val;
	if(top==-1)
	{
		printf("stack is  empty");
		return -1;
	}
	else
	{
		val=st[top];
		return val;
	}
}

