#include<stdio.h>
#include<string.h>
#define MAX 20
int top=-1;
int stk[MAX];
void push(char);
char pop();
int main()
{
	char exp[MAX],temp;
	int i,flag =1;
	printf("Enter the string \n");
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		{
			push(exp[i]);
		}
		if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			if(top==-1)
			{
				flag =0;
			}
			else
			{
				temp=pop();
				if(exp[i]==')'&&(temp=='{'||temp=='['))
				{
					flag =0;
				}
				if(exp[i]=='}'&&(temp=='('||temp=='['))
				{
					flag=0;
		      	}
		      	if(exp[i]==']'&&(temp=='('||temp=='{'))
				{
					flag=0;
		      	}
	        	}
	}	
}
if(top>=0)
{
	flag=0;
}
if(flag==1)
{
	printf("valid");
}
else
{
	printf("invalid");
}
}
void push(char a)
{
	if(top==MAX)
	{
		printf("stack overflow");
	}
	else
	{
	top=top+1;
	stk[top]=a;
    }
}
char pop()
{
	char b;
	b=stk[top];
	top=top-1;
	return b;
}
