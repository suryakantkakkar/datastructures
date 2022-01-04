#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_cll(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *display_list(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
int main()
{
	int option;
	do{
		printf("\n\n----Please choose---");
		printf("\n press 1 to create linked list");
	    printf("\n press 2 to insert at beggining");
	    printf("\n press 3 to insert at end");
	    printf("\n press 4 to delete beg");
	    printf("\n press 5 to delete end");
	    printf("\n press 6 to display list");
	    printf("\n press 7 to delete after");
	    printf("\n press 8 to delete list");
	    printf("\n press 9 to Exit");	
	    scanf("%d",&option);
	    switch(option)
	    {
	    	case 1:
	    		start=create_cll(start);
	    		printf("Circular Link list created");
	    		break;
	    	case 2:
	    		start=insert_beg(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 3:
	    		start=insert_end(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 4:
	    		start=delete_beg(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 5:
	    		start=delete_end(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 6:
	    		start=display_list(start);
	    		break;
	    		break;
	    	case 7:
	    		start=delete_after(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 8:
	    		start=delete_list(start);
	    		printf("\n Circular linked List deleted ");
	    		break;
		}
	  }while(option!=9);
	   getch();
	   return 0;
	  
}
struct node *create_cll(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("press -1 to end");
	printf("Enter the data");
	scanf("%d",&num);
	while(num!=-1)
	{
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	if(start==NULL)
	{
		newnode->next=newnode;
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		newnode->next=start;
		ptr->next=newnode;
		
	}
	printf("Enter the data");
	scanf("%d",&num);
	
}return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *newnode,*ptr;
	int num;	
	printf("Enter the data");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	if(start==NULL)
	{
		newnode->next=newnode;
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		newnode->next=start;
		start=newnode;
		ptr->next=newnode;
		
	}
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *newnode,*ptr;
	int num;	
	printf("Enter the data");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	if(start==NULL)
	{
		newnode->next=newnode;
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
		
	}
	return start;
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List empty");
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		ptr->next=start->next;
		free(start);
		start=ptr->next;
	}
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	if(start==NULL||start==start->next)
	{
		free(start);
		printf("list empty");
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		
	}
	return start;
}
struct node *display_list(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("List empty");
	}
	else
	{
		while(ptr->next!=start)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->next;
		}
		printf("\n %d",ptr->data);
	}
	return start;
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*preptr;
	int num;
	printf("Enter the value after which data is to be deleted");
	scanf("%d",&num);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=num)
	{
		preptr=ptr;
		ptr=ptr->next;
	}

		preptr->next=ptr->next;
	if(ptr==start)
	{
		start=ptr->next;
	}
	free(ptr);
	return start;
}
struct node *delete_list(struct node *start)
{
	struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
    	start=delete_end(start);
	}
	free(start);
	return start;
}
