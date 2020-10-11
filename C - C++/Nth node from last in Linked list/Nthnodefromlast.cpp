#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct linkedlist
{
    struct node *front;
};
void init(linkedlist *a)
{
    a->front = NULL;
}
void insert(linkedlist *a,int x)
{
    node *p=a->front;
    node *t=new node;
    t->data=x;
    if(!p)
    {
        t->next=a->front;
        a->front=t;
    }
    else
    {
        while(p->next)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
node *nthnodefromlast(linkedlist *a,int n)
{
    node *p=a->front;
    int countNodes=0;
    while(p)
    {
        p=p->next;
        countNodes++;
    }
    p=a->front;
    countNodes=countNodes-n;
    if(countNodes<0)
    {
        return NULL;
    }
    while(countNodes--)
    {
        p=p->next;
    }
    return p;
}
int main()
{
    linkedlist *a=new linkedlist;
    init(a);
    insert(a,1);
    insert(a,2);
    insert(a,3);
    insert(a,4);
    insert(a,5);
    insert(a,6);
    insert(a,7);
    node *ans=nthnodefromlast(a,1);
    if(ans)
    {
    cout<<ans->data<<endl;
    }
    else
    {
        cout<<"NODE DOES NOT EXIST"<<endl;
    }
    return 0;
}
