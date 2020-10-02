#include<iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Inorder(struct Node *p)
{
    if(p)
    {
    Inorder(p->lchild);
    cout<<p->data<<" ";
    Inorder(p->rchild);
    }
}

struct Node * Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
        else if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
return NULL;
}

struct Node *RInsert(struct Node *p,int key)
{   if(key==-1)
        return p;
    struct Node *t=NULL;
    if(p==NULL)
    {
        t= new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
    p->lchild=RInsert(p->lchild,key);
    else if(key > p->data)
    p->rchild=RInsert(p->rchild,key);
    return p;
}

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node *InPre(struct Node *p)
{
while(p && p->rchild!=NULL)
    p=p->rchild;
return p;
}

struct Node *InSucc(struct Node *p)
{
while(p && p->lchild!=NULL)
    p=p->lchild;
return p;
}

struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    int x,choice;
    struct Node *t;
    cout<<"Enter the root of the tree \n";
    cin>>x;
    root= RInsert(root,x);
    while(x!=-1){
        cout<<"Enter another value.(-1 to exit)"<<endl;
        cin>>x;
        RInsert(root,x);
    }
    do{
        cout<<"\nDo you want to delete or search  \n1.Delete \n2.Search \n3.Display Tree \n4.Exit \n" ;
        cin>>choice;
        switch(choice){
                    case 1: cout<<"Enter the value to be deleted";
                            cin>>x;
                            Delete(root,x);
                            break;
                    case 2: cout<<"Enter the value to search";
                            cin>>x;
                            t=Search(x);
                            if(t==NULL)
                                cout<<"Value not found";
                            else
                                cout<<"Value Found";
                            break;
                    case 3: Inorder(root);
                            break;
                    };
    }while(choice!=4);
return 0;
}
