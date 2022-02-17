#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class priorityqueue
{
	vector<int> pq;
	public:
		priorityqueue()
		{
			
		}
	bool isempty()
	{
		return pq.size()==0;
	}
	int getsize()
	{
		return pq.size();
	}
	int getmin()
	{
	 if(isempty())
	 {
	 return 0;	
     } 
     return pq[0];
	}
	void insert(int a)
	{
		pq.push_back(a);
		int child=pq.size()-1;
		while(child>0)
		{
		
		int par=(child-1)/2;
		if(pq[par]>pq[child])
		{
			int temp=pq[par];
			pq[par]=pq[child];
			pq[child]=temp;
		}
		else
		{
			break;
		}
		child=par;
		par=(child-1)/2;
    	}
	}
	int removemin()
	{
		int ans=pq[0];
		pq[0]=pq[pq.size()-1];
		pq.pop_back();
		if(isempty())
	    {
	     return ans;	
        } 
		int parentindex=0;
		int leftchildindex=(parentindex*2)+1;
		int rightchildindex=(parentindex*2)+2;
		while(leftchildindex<pq.size())
		{
		int minindex=parentindex;
		if(pq[minindex]>pq[leftchildindex])
		{
			minindex=leftchildindex;
		}
		if(rightchildindex<pq.size() && pq[rightchildindex]<pq[minindex])
		{
			minindex=rightchildindex;
		}
		if(minindex==parentindex)
		{
			break;
		}
		int temp=pq[minindex];
		pq[minindex]=pq[parentindex];
		pq[parentindex]=temp;
		parentindex=minindex;
		leftchildindex=(parentindex*2)+1;
		rightchildindex=(parentindex*2)+2;
		
	   }
	   return ans;
	}		
};
int main()
{
priorityqueue p;
p.insert(100);
p.insert(10);
p.insert(15);
p.insert(4);
p.insert(17);
p.insert(21);
p.insert(67);
cout<<p.getsize()<<"\n";
cout<<p.getmin()<<"\n";
while(!p.isempty())
{
	cout<<p.removemin()<<" ";
}


}
