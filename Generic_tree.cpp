#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class treeNode
{
	public:
	T data;
	vector<treeNode<T>*>children;
	treeNode(T data)
	{
		this->data=data;
	}
};
void printTree(treeNode<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<":";
	for(int i =0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
    }
   cout<<"\n";
	for(int i =0;i<root->children.size();i++)
	{
		printTree(root->children[i]);
	}
}
treeNode<int>* takeInput()
{
	cout<<"Enter data";
	int rootdata;
	cin>>rootdata;
	treeNode<int>* root=new treeNode<int>(rootdata);
	int n;
	cout<<"Enter no of children"<<rootdata<<"\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		treeNode<int>* child=takeInput();
		root->children.push_back(child);
    }
    return root;
}
void depth(treeNode<int>*root,int k)
{
	if(k==0)
	{
		cout<<root->data<<"";
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		depth(root->children[i],k-1);
	}
}
int numnodes(treeNode<int>*root)
{
	int ans=1;
	for(int i=0;i<root->children.size();i++)
	{
		ans=ans+numnodes(root->children[i]);
	}
	return ans;
}
int getheight(treeNode<int>*root,int height,int result)
{
	if(root->children.size()==0)
	{
		return height;
	}
	height++;
	for(int i=0;i<root->children.size();i++)
	{	
	 height=getheight(root->children[i],height,result);
	 if(height>result)
	 {
	 	result=height;
	 }
	 height=0;
	}
    return result;
}
int leaf(treeNode<int>*root)
{
	int j=0;
	if(root->children.size()==NULL)
	{
		return 1;
	}
	else
	{
	for(int i=0;i<root->children.size();i++)
	{
		j=j+leaf(root->children[i]);
	}	
	}
	return j;
}
int main()
{
		treeNode<int>* root=takeInput();
		printTree(root);
		int nn=numnodes(root);
		cout<<"No of nodes"<<nn<<"\n";
		cout<<getheight(root,0,0)<<"\n";
		int k;
		cin>>k;
		depth(root,k);
		cout<<"total leaf are"<<leaf(root);
}
