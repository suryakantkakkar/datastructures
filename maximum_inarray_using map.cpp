#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int maximum(int a[],int size)
{
    unordered_map<int,int> mk;
    for(int i=0;i<size;i++)
    {
        if(mk.count(a[i])>0)
        {
            mk[a[i]]++;
        }
        else
        {
            mk[a[i]]=1;
        }
    }
    int max=0;
    int maxval=0;
    for(auto& x: mk)
    {
        if(max<x.second)
        {
            max=x.second;
            maxval=x.first;
        }
    }
    return maxval;
}
int main()
{
   int a[]={1,3,4,4,4,1,2,5};
   cout<<maximum(a,8);
}