#include <iostream>
using namespace std;
template<typename v>
class mapnode
{
    public:
    v value;
    string key;
    mapnode *next;
    mapnode(string key,v value)
    {
        this->value=value;
        this->key=key;
        next=NULL;
    }
};
template<typename v>
class ourmap
{
    int count;
    int numofbucket;
    mapnode<v> ** buckets;
    public:
    ourmap()
    {
        count=0;
        numofbucket=5;
        buckets=new mapnode<v>*[numofbucket];
        for(int i=0;i<numofbucket;i++)
        {
            buckets[i]=NULL;
        }
    }
    int getbucketindex(string key)
    {
        int hashcode=0;
        int cc=1;
        for(int i=key.length()-1;i>=0;i--)
        {
            hashcode+=key[i]*cc;
            hashcode=hashcode%numofbucket;
            cc*=37;
            cc=cc%numofbucket;
        }
        return hashcode%numofbucket;
    }
    int size()
    {
        return count;
    }
    void insert(string key, v value)
    {
      int bucketindex= getbucketindex(key);
      mapnode<v> * head=buckets[bucketindex];
      while(head!=NULL)
      {
          if(head->key==key)
          {
              head->value=value;
              return;
          }
          head=head->next;
      }
      head=buckets[bucketindex];
      mapnode<v> *newnode=new mapnode<v>(key,value);
      newnode->next=head;
      buckets[bucketindex]=newnode;
      count++;
    
    }
    v getvalue(string key)
    {
     int bucketindex=getbucketindex(key);
     mapnode<v> * head=buckets[bucketindex];  
      while(head!=NULL)
      {
          if(head->key==key)
          {
              return head->value;
          }
          head=head->next;
      }
      return 0;
    }
    v deletes(string key)
    {
        int bucketindex=getbucketindex[key];
        mapnode<v> * head=buckets[bucketindex];
        mapnode<v> * preptr=NULL;
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(preptr==NULL)
                {
                    buckets[bucketindex]=head->next;
                }
                else
                {
                preptr->next=head->next;
                }
                v value=head->value;
                count--;
                return value;
            }
            
            preptr=head;
            head=head->next;
           
        }
        return 0;
    }
};
int main()
{
	ourmap<int> a;
    a.insert("abc",2);
    a.insert("def",3);
    
    cout<<a.size();
    cout<<"\n"<<a.getvalue("abc");
}
