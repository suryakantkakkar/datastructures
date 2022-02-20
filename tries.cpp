#include <iostream>
using namespace std;
class trienode
{
	public:
	char data;
	trienode **children;
	bool isterminal;
	trienode(char data)
	{
		this->data=data;
		children=new trienode*[26];
		for(int i=0;i<26;i++)
		{
			children[i]=NULL;
		}
		isterminal=false;
	}
};
class trie
{
	public:
	trienode *root;
	trie()
	{
		root=new trienode(NULL);
	}
	public:
	void insertword(trienode *root,string word)
	{
		if(word.size()==0)
		{
			root->isterminal=true;
			return;
		}
		int index=word[0]-'a';
		trienode *child;
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			child=new trienode(word[0]);
			root->children[index]=child;
		}
		insertword(child,word.substr(1));
	}
	void insertword(string word)
	{
		insertword(root,word);
	}
	void search(trienode *root,string word)
	{
		if(word.size()==0)
		{
			if(root->isterminal==true)
			{
			cout<<"present";	
			return ;
		    }
		}
		int index=word[0]-'a';
		trienode *child;
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			cout<<"not present";
			return ;
	    }
		search(child,word.substr(1));
	}
	void search(string word)
	{
		search(root,word);
	}
	void remove(trienode *root,string word)
	{
		if(word.size()==0)
		{
			root->isterminal=false;
			return;
		}
		trienode *child;
		int index=word[0]-'a';
		if(root->children[index]!=NULL)
		{
			child=root->children[index];
		}
		else
		{
			return;
		}
		remove(child,word.substr(1));
		if(child->isterminal==false)
		{
			for(int i=0;i<26;i++)
			{
				if(child->children[i]!=NULL)
				{
					return;
				}
			}
			delete child;
			root->children[index]=NULL;
		}
	}
	void remove(string word)
	{
		remove(root,word);
	}
};
int main()
{
	trie t;
	t.insertword("ab");
	t.insertword("abcde");
	t.insertword("abcd");
	t.remove("abcde");
	t.search("abcde");
}
