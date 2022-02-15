#include <iostream>
#include <queue>
using namespace std;
template<typename t>
class Node
{
	public:
	t data;
	Node *left;
	Node *right;
	Node(t data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
Node<int> * takeinput()
{
	int rootdata;
	cout<<"Enter data";
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	Node<int> *root=new Node<int>(rootdata);
	queue<Node<int>*> pending;
	pending.push(root);
	while(pending.size()!=NULL)
	{
		Node<int> * front=pending.front();
		pending.pop();
		int leftdata;
		cout<<"Enter left child of"<<root->data;
		cin>>leftdata;
		if(leftdata!=-1)
		{
		Node<int> *child=new Node<int>(leftdata);
		front->left=child;
		pending.push(child);	
		}
		cout<<"Enter right child of "<<front->data<<"\n";
		int rightchilddata;
		cin>>rightchilddata;
		if(rightchilddata!=-1)
		{
		 Node<int>* child=new Node<int>(rightchilddata);
		 front->right=child;
		 pending.push(child);
		}
	}
	return root;
}
int minimum(Node<int>* root)
{
	if(root==NULL)
	{
		return INT_MAX;
	}
	return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(Node<int>* root)
{
	if(root==NULL)
	{
		return INT_MIN;
	}
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isbst(Node<int> * root)
{
	if(root==NULL)
	{
		return true;
	}
	int leftmax=maximum(root->left);
	int rightmin=minimum(root->right);
	bool output=(root->data>leftmax)&&(root->data<=rightmin)&&isbst(root->left)&&isbst(root->right);
}

int main()
{
	Node<int> *root=takeinput();
}
