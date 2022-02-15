#include <iostream>
#include <bits/stdc++.h>
#include <list>
using namespace std;
int josephus(list <int> l1,int n,int k);
int main()
{
	int i,n,k;
	cin>>n;
	list <int> l1;
	for(i=1;i<=n;i++)
	{
	   l1.push_back(i);
	}
	cin>>k;
	int p=josephus(l1,n,k);
	cout<<p;
}
int josephus(list <int> l1,int n,int k)
{
    list<int>::iterator it;
    it=l1.begin();
	while(l1.size()>1)
	{
		
		for(int count=1;count<k;count++)
		{
			it++;
			if(it==l1.end())
			{
				it=l1.begin();
			}
		}
		it=l1.erase(it);
		if(it==l1.end())
			{
				it=l1.begin();
			}
	}
	return l1.front();
}


