#include<iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
    int height;
}*root = NULL;

int BalanceFactor(struct Node *p)
{
    int hl,hr;
    hl=(p&&p->lchild)?p->lchild->height:0 ;
    hr=(p&&p->rchild)?p->rchild->height:0 ;
    return hl-hr;
}

int NodeHeight(struct Node *p)
{
    int hl,hr;
    hl=(p&&p->lchild)?p->lchild->height:0 ;
    hr=(p&&p->rchild)?p->rchild->height:0 ;
    return hl>hr? hl+1:hr+1;
}

void Inorder(struct Node *p)
{
    if(p)
    {
    Inorder(p->lchild);
    cout<<p->data<<" "<<BalanceFactor(p)<<endl;
    Inorder(p->rchild);
    }
}

struct Node *RotateRight(struct Node *p)
{
    Node *t= p->lchild;
    p->lchild = t->rchild;
    t->rchild =p;
    p->height = NodeHeight(p);
    t->height = NodeHeight(t);
    return t;
};

struct Node *RotateLeft(struct Node *p)
{
    struct Node *t=p->rchild;
    p->rchild = t->lchild;
    t->lchild =p;
    p->height = NodeHeight(p);
    t->height = NodeHeight(t);
    return t;
};

struct Node *RR(struct Node *p)
{
    p=RotateLeft(p);
    return p;
};

struct Node *LL(struct Node *p)
{
    p=RotateRight(p);
    return p;
};

struct Node *LR(struct Node *p)
{
    p->lchild=RotateLeft(p->lchild);
    p=RotateRight(p);
    return p;
};

struct Node *RL(struct Node *p)
{
    p->rchild=RotateRight(p->rchild);
    p=RotateLeft(p);
    return p;
};

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
    else
        {
        if(key < p->data)
        {
            p->lchild=RInsert(p->lchild,key);
            if(BalanceFactor(p)==2)
                if(key<p->lchild->data)
                    p=LL(p);
                else
                    p=LR(p);
        }
        else
        {
            if(key > p->data)
            {
                p->rchild=RInsert(p->rchild,key);
                if(BalanceFactor(p)==-2)
                    if(key>p->rchild->data)
                        p=RR(p);
                    else
                        p=RL(p);
            }
        }
    p->height = NodeHeight(p);
    return p;
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
        cout<<"\nChoose: \n1.Search \n2.Display Tree \n3.Exit \n" ;
        cin>>choice;
        switch(choice){
                    case 1: cout<<"Enter the value to search";
                            cin>>x;
                            t=Search(x);
                            if(t==NULL)
                                cout<<"Value not found";
                            else
                                cout<<"Value Found";
                            break;
                    case 2: Inorder(root);
                            break;
                    };
    }while(choice!=3);
return 0;
}
