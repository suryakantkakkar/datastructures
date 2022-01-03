#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *display_list(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);
int main()
{
	int option;
	do{
		printf("\n\n----Please choose---");
		printf("\n press 1 to create linked list");
	    printf("\n press 2 to insert at beggining");
	    printf("\n press 3 to insert at end");
	    printf("\n press 4 to insert before");
	    printf("\n press 5 to insert after");
	    printf("\n press 6 to delete beg");
	    printf("\n press 7 to delete end");
	    printf("\n press 8 to display list");
	    printf("\n press 9 to delete node");
	    printf("\n press 10 to delete after");
	    printf("\n press 11 to delete list");
	    printf("\n press 12 to sort list");
	    printf("\n press 13 to Exit");	
	    scanf("%d",&option);
	    switch(option)
	    {
	    	case 1:
	    		start=create(start);
	    		printf("Link list created");
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
	    		start=insert_before(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 5:
	    		start=insert_after(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 6:
	    		start=delete_beg(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 7:
	    		start=delete_end(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 8:
	    		start=display_list(start);
	    		break;
	    	case 9:
	    		start=delete_node(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 10:
	    		start=delete_after(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;
	    	case 11:
	    		start=delete_list(start);
	    		printf("\n List deleted ");
	    		break;
	    	case 12:
	    		start=sort_list(start);
	    		printf("\n Updated list is");
	    		start=display_list(start);
	    		break;	
		}
	  }while(option!=13);
	   getch();
	   return 0;
	  
}
struct node *create(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("press -1 to end");
	printf("Enter the data");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
			
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->next=NULL;
		}
	printf("Enter the data");
	scanf("%d",&num);
	}
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *newnode,*ptr;
	ptr=start;
	int num;
	printf("enter data");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=start;
	start=newnode;
	return start;
	
}
struct node *insert_end(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("Enter the data");
	scanf("%d",&num);
	newnode->data=num;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		
	}
	return start;
	
}
struct node *insert_before(struct node *start)
{
	struct node *newnode,*ptr,*preptr;
	int num,val;
	printf("Enter the data to be inserted");
	scanf("%d",&num);
	printf("Enter the before which data to be inserted");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	preptr=ptr;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr->next==NULL)
	{
		printf("\n List does not contain the value please enter correct value");
	}
	else
	{
		
		preptr->next=newnode;
		newnode->next=ptr;
	}
	return start;
	
}
struct node *insert_after(struct node *start)
{
	struct node *newnode,*ptr,*preptr;
	int num,val;
	printf("Enter the data to be inserted");
	scanf("%d",&num);
	printf("Enter the after which data to be inserted");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	newnode->next=ptr;
	preptr->next=newnode;
	return start;
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("List is empty");
	}
	else
    {
    	start=start->next;
    	free(ptr);
	}
	return start;
	
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=ptr;
	if(start==NULL||ptr->next==NULL)
	{
	    start=NULL;
		printf("List is empty");
	}
	else
	{
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=NULL;
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
		while(ptr!=NULL)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->next;
		}
	}
	return start;
	
}
struct node *delete_node(struct node *start)
{
	struct node *ptr,*preptr;
	int num;
	printf("Enter the data to be deleted");
	scanf("%d",&num);
	ptr=start;
	preptr=ptr;
	if(ptr->data==num)
	{
		start=delete_beg(start);
		return start;
	}
	else{
	while(ptr->data!=num)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("Enter the after which data to be deleted");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
struct node *delete_list(struct node *start)
{
	struct node *ptr;
	if(start!=NULL)
	{
		ptr=start;
		while(ptr!=NULL)
		{
			start=delete_beg(ptr);
			ptr=start;
		}
	}
	return start;
}
struct node *sort_list(struct node *start)
{
	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr2->data <ptr1->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
				ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	return start;
}

