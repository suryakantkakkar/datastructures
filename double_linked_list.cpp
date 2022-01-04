#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	struct node *pre;
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
struct node *delete_before(struct node *);
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
	    printf("\n press 4 to insert before");
	    printf("\n press 5 to insert after");
	    printf("\n press 6 to delete beg");
	    printf("\n press 7 to delete end");
	    printf("\n press 8 to display list");
	    printf("\n press 9 to delete before");
	    printf("\n press 10 to delete after");
	    printf("\n press 11 to delete list");
	    printf("\n press 12 to Exit");	
	    scanf("%d",&option);
	    switch(option)
	    {
	    	case 1:
	    		start=create(start);
	    		printf("Doubly Link list created");
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
	    		start=delete_before(start);
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
		}
	  }while(option!=12);
	   getch();
	   return 0;
	  
}
struct node *create(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("Press -1 to end");
	printf("Please enter the data");
	scanf("%d",&num);
	while(num!=-1)
	{
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	if(start==NULL)
	{
		newnode->pre=NULL;
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
		newnode->pre=ptr;
	}
	printf("Please enter the data");
	scanf("%d",&num);
}
return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *newnode;
	int num;
	printf("Please enter the data");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->pre=NULL;
	newnode->next=start;
	start=newnode;
	return start;
	
}
struct node *insert_end(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("Please enter the data");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	if(start==NULL)
	{
		newnode->pre=NULL;
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
		newnode->pre=ptr;
	}
	return start;
}
struct node *insert_before(struct node *start)
{
	struct node *ptr,*newnode;
	int num,val;
	printf("Please enter the data");
	scanf("%d",&num);
	printf("Please value before which the data to be inserted");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	if(ptr->data==val)
	{
		newnode->pre=ptr->pre;
		newnode->next=ptr;
		ptr->pre=newnode;
		start=newnode;
	}
	else
	{
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
    newnode->next=ptr;
	newnode->pre=ptr->pre;
	ptr->pre->next=newnode;
	ptr->pre=newnode;
	return start; 	
}
}
struct node *insert_after(struct node *start)
{
	struct node *ptr,*newnode;
	int num,val;
	printf("Please enter the data");
	scanf("%d",&num);
	printf("Please value after which the data to be inserted");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}	

	newnode->next=ptr->next;
	newnode->pre=ptr;
	ptr->next->pre=newnode;
	ptr->next=newnode;
	return start;
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	start->pre=NULL;
	free(ptr);
	return start;
     
}
struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->pre->next=NULL;
	free(ptr);
	return start;
	
}
struct node *display_list(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr!=NULL)
  {
  	printf("\n %d",ptr->data);
  	ptr=ptr->next;
	
  }	
  return start;
}
struct node *delete_before(struct node *start)
{
	struct node *ptr,*temp;
	int num;
	printf("Enter the data before which to be deleted");
	scanf("%d",&num);
	ptr=start;
	while(ptr->data!=num)
	{
		ptr=ptr->next;
	}
	temp=ptr->pre;
	if(temp==start)
	{
		start=delete_beg(start);
		return start;
	}
	else
	{
	temp->pre->next=ptr;
	ptr->pre=temp->pre;
	free(temp);
	return start;
}
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*temp;
	int num;
	printf("Enter the data before which to be deleted");
	scanf("%d",&num);
	ptr=start;
	while(ptr->data!=num)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->pre=ptr;
	free(ptr);
	return start;
}
struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(start!=NULL);
	{
		start=delete_beg(start);
		return start;
	}
}
