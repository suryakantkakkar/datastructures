#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insert_element(struct node *,int);
void pre_order(struct node *);
void post_order(struct node *);
void in_order(struct node *);
struct node * find_smallest(struct node *);
struct node *find_largest(struct node *);
struct node *delete_element(struct node *,int);
struct node *mirror_image(struct node *);
int total_node(struct node *);
int total_external_node(struct node *);
int total_internal_node(struct node *);
int height(struct node *);
struct node *delete_tree(struct node *);
int main()
{
	int option,val;
	struct node *ptr;
	create_tree(tree);
	do
	{
		printf("\n please choose");
		printf("\n press 1 to insert element");
		printf("\n press 2 to preorder of tree");
		printf("\n press 3 to postorder of tree");
		printf("\n press 4 to inorder of tree");
		printf("\n press 5 to get smallest element");
		printf("\n press 6 to get largest element");
		printf("\n press 7 to delete element of tree");
		printf("\n press 8 to count total no nodes of tree");
		printf("\n press 9 to count total no external nodes of tree");
		printf("\n press 10 to count total no internal nodes of tree");
		printf("\n press 11 to determine height of tree");
		printf("\n press 12 to determine mirror image of tree");
		printf("\n press 13 to delete a tree");
		printf("\n press 14 to exit");
		printf("\n Enter option");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("enter the value of node");
				scanf("%d",&val);
				tree=insert_element(tree,val);
				break;
			case 2:
				printf("preorder of tree is \n ");
				pre_order(tree);
				break;
			case 3:
			    printf("postorder of tree is \n ");
			    post_order(tree);
			    break;
			case 4:
			    printf("inorder of tree is \n ");
			    in_order(tree);
			    break;
			case 5:
				printf("Smallest element is \n");
				ptr=find_smallest(tree);
				printf("%d",ptr->data);
				break;
		    case 6:
				printf("Largest element is \n");
				ptr=find_largest(tree);
				printf("%d",ptr->data);
				break;
		    case 7:
				printf("Enter the element to be deleted");
				scanf("%d",&val);
				tree=delete_element(tree,val);
				break;
			case 8:
				printf("Total no of nodes are  %d",total_node(tree));
				break;
			case 9:
				printf("Total no of external nodes are  %d",total_external_node(tree));
				break;
			case 10:
				printf("Total no of internal nodes are  %d",total_internal_node(tree));
				break;
			case 11:
				printf("Total height of tree is %d",height(tree));
				break;
			case 12:
				tree=mirror_image(tree);
				break;
			case 13:
				delete_tree(tree);
				break;			
		}
		
	}while(option!=14);
	getch();
	return 0;	
}
void create_tree(struct node *tree)
{
	tree=NULL;
}
struct node *insert_element(struct node *tree,int val)
{
	struct node *ptr,*nodeptr,*parentptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL)
	{
		tree=ptr;
		ptr->left=NULL;
	    ptr->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			if(val<nodeptr->data)
			{
				nodeptr=nodeptr->left;
			}
			else
			{
				nodeptr=nodeptr->right;
			}
		}
		if(val<parentptr->data)
		{
			parentptr->left=ptr;
		}
		else
		{
			parentptr->right=ptr;
		}
	}
	return tree;
}
void pre_order(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		pre_order(tree->left);
		pre_order(tree->right);
	}
	
}
void post_order(struct node *)
{
	if(tree!=NULL)
	{
		pre_order(tree->left);
		pre_order(tree->right);
		printf("%d\t",tree->data);
	}
}
void in_order(struct node *)
{
	if(tree!=NULL)
	{
		pre_order(tree->left);
		printf("%d\t",tree->data);
		pre_order(tree->right);
		
	}
}
struct node * find_smallest(struct node *tree)
{
	if(tree==NULL||tree->left==NULL)
	{
		return tree;
	}
	else return find_smallest(tree->left);
	
}
struct node *find_largest(struct node *tree)
{
	if(tree==NULL||tree->right==NULL)
	{
		return tree;
	}
	else return find_largest(tree->right);
}
struct node *delete_element(struct node *tree,int val)
{
	struct node *cur,*parent,*ptr;
	parent=NULL;
	cur=tree;
	while(val!=cur->data && cur!=NULL)
	{
		if(val<cur->data)
		{
			parent=cur;
			cur=cur->left;
		}
		else
		{
		    parent=cur;	
		    cur=cur->right;
		}
	}
	if(cur==NULL)
	{
		printf("The tree does'nt contain the given node");
		return tree;
	}
	if((cur->left==NULL)&&(cur->right==NULL))
		{
			if(cur!=tree)
			{
			if(parent->left==cur)
			{
				parent->left=NULL;
			}
			else
			{
				parent->right=NULL;
			}
			return tree;
		}
		else
		{
			tree=NULL;
		}
	    }
	else if(cur->left && cur->right)
	{
		ptr=find_smallest(cur->right);
		int key=ptr->data;
		delete_element(tree,ptr->data);
		cur->data=key;
	}
	else 
	{
	  struct node *child;
	  if(cur->left)
	  {
	  	child=cur->left;
	  }
	  else
	  {
	  	child=cur->right;
	  }
	  if(cur!=tree)
	  {
	  	if(cur==parent->left)
	  	{
	  		parent->left=child;
		}
		else
		{
			parent->right=child;
		}
	  }
	  else
	  {
	  	tree=child;
	  }
    }
	  	
}
struct node *mirror_image(struct node *)
{
	struct node *ptr;
	if(tree!=NULL)
	{
		mirror_image(tree->left);
		mirror_image(tree->right);
		ptr=tree->left;
		tree->left=tree->right;
		tree->right=ptr;		
	}
}
int total_node(struct node *tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		return(total_node(tree->left)+total_node(tree->right)+1);
	}
}
int total_external_node(struct node * tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	else if((tree->left==NULL)&&(tree->right==NULL))
	{
		return 1;
	}
	else
	{
		return(total_external_node(tree->left)+total_external_node(tree->right));
	}
	
}
int total_internal_node(struct node *tree)
{
	if((tree==NULL)||(tree->left==NULL)&&(tree->right==NULL))
	{
		return 0;
	}
	else
	{
	return(total_internal_node(tree->left)+total_internal_node(tree->right)+1);
	}
	
	
}
int height(struct node *tree)
{
	int lh,rh;
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		lh=height(tree->left);
		rh=height(tree->right);
		if(lh>rh)
		{
			return lh+1;
		}
		else
		{
			return rh+1;
		}
	}
	
}
struct node *delete_tree(struct node *tree)
{
	if(tree!=NULL)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		free(tree);
	}
	
}
