#include<iostream>

using namespace std;

struct node
{
       int key;
       char color;
       node *lchild, *rchild, *parent;
};
class RBtree
{
      node *root;
      node *q;
   public :
      RBtree()
      {
              q=NULL;
              root=NULL;
      }
      void insertfn();
      void insertfix(node *);
      void leftrotate(node *);
      void rightrotate(node *);
      void del();
      node* successor(node *);
      void delfix(node *);
      void disp();
      void display( node *);
      void searchfn();
};
void RBtree::insertfn()
{
     int z,i=0;
     cout<<"\nEnter key of the node to be inserted: ";
     cin>>z;
     node *p,*q;
     node *t=new node;
     t->key=z;
     t->lchild=NULL;
     t->rchild=NULL;
     t->color='r';
     p=root;
     q=NULL;
     if(root==NULL)
     {
           root=t;
           t->parent=NULL;
     }
     else
     {
         while(p!=NULL)
         {
              q=p;
              if(p->key<t->key)
                  p=p->rchild;
              else
                  p=p->lchild;
         }
         t->parent=q;
         if(q->key<t->key)
              q->rchild=t;
         else
              q->lchild=t;
     }
     insertfix(t);
}
void RBtree::insertfix(node *t)
{
     node *u;
     if(root==t)
     {
         t->color='b';
         return;
     }
     while(t->parent!=NULL&&t->parent->color=='r')
     {
           node *g=t->parent->parent;
           if(g->lchild==t->parent)
           {
                        if(g->rchild!=NULL)
                        {
                              u=g->rchild;
                              if(u->color=='r')
                              {
                                   t->parent->color='b';
                                   u->color='b';
                                   g->color='r';
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->parent->rchild==t)
                            {
                                 t=t->parent;
                                 leftrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            rightrotate(g);
                        }
           }
           else
           {
                        if(g->lchild!=NULL)
                        {
                             u=g->lchild;
                             if(u->color=='r')
                             {
                                  t->parent->color='b';
                                  u->color='b';
                                  g->color='r';
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->parent->lchild==t)
                            {
                                   t=t->parent;
                                   rightrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            leftrotate(g);
                        }
           }
           root->color='b';
     }
}

void RBtree::del()
{
     if(root==NULL)
     {
           cout<<"\nEmpty Tree." ;
           return ;
     }
     int x;
     cout<<"\nEnter the key of the node to be deleted: ";
     cin>>x;
     node *p;
     p=root;
     node *y=NULL;
     node *q=NULL;
     int found=0;
     while(p!=NULL&&found==0)
     {
           if(p->key==x)
               found=1;
           if(found==0)
           {
                 if(p->key<x)
                    p=p->rchild;
                 else
                    p=p->lchild;
           }
     }
     if(found==0)
     {
            cout<<"\nElement Not Found.";
            return ;
     }
     else
     {
         cout<<"\nDeleted Element: "<<p->key;
         cout<<"\nColour: ";
         if(p->color=='b')
     cout<<"Black\n";
    else
     cout<<"Red\n";

         if(p->parent!=NULL)
               cout<<"\nParent: "<<p->parent->key;
         else
               cout<<"\nThere is no parent of the node.  ";
         if(p->rchild!=NULL)
               cout<<"\nrchild: "<<p->rchild->key;
         else
               cout<<"\nThere is no rchild of the node.  ";
         if(p->lchild!=NULL)
               cout<<"\nlchild: "<<p->lchild->key;
         else
               cout<<"\nThere is no lchild of the node.  ";
         cout<<"\nNode Deleted.";
         if(p->lchild==NULL||p->rchild==NULL)
              y=p;
         else
              y=successor(p);
         if(y->lchild!=NULL)
              q=y->lchild;
         else
         {
              if(y->rchild!=NULL)
                   q=y->rchild;
              else
                   q=NULL;
         }
         if(q!=NULL)
              q->parent=y->parent;
         if(y->parent==NULL)
              root=q;
         else
         {
             if(y==y->parent->lchild)
                y->parent->lchild=q;
             else
                y->parent->rchild=q;
         }
         if(y!=p)
         {
             p->color=y->color;
             p->key=y->key;
         }
         if(y->color=='b')
             delfix(q);
     }
}

void RBtree::delfix(node *p)
{
    node *s;
    while(p!=root&&p->color=='b')
    {
          if(p->parent->lchild==p)
          {
                  s=p->parent->rchild;
                  if(s->color=='r')
                  {
                         s->color='b';
                         p->parent->color='r';
                         leftrotate(p->parent);
                         s=p->parent->rchild;
                  }
                  if(s->rchild->color=='b'&&s->lchild->color=='b')
                  {
                         s->color='r';
                         p=p->parent;
                  }
                  else
                  {
                      if(s->rchild->color=='b')
                      {
                             s->lchild->color=='b';
                             s->color='r';
                             rightrotate(s);
                             s=p->parent->rchild;
                      }
                      s->color=p->parent->color;
                      p->parent->color='b';
                      s->rchild->color='b';
                      leftrotate(p->parent);
                      p=root;
                  }
          }
          else
          {
                  s=p->parent->lchild;
                  if(s->color=='r')
                  {
                        s->color='b';
                        p->parent->color='r';
                        rightrotate(p->parent);
                        s=p->parent->lchild;
                  }
                  if(s->lchild->color=='b'&&s->rchild->color=='b')
                  {
                        s->color='r';
                        p=p->parent;
                  }
                  else
                  {
                        if(s->lchild->color=='b')
                        {
                              s->rchild->color='b';
                              s->color='r';
                              leftrotate(s);
                              s=p->parent->lchild;
                        }
                        s->color=p->parent->color;
                        p->parent->color='b';
                        s->lchild->color='b';
                        rightrotate(p->parent);
                        p=root;
                  }
          }
       p->color='b';
       root->color='b';
    }
}

void RBtree::leftrotate(node *p)
{
     if(p->rchild==NULL)
           return ;
     else
     {
           node *y=p->rchild;
           if(y->lchild!=NULL)
           {
                  p->rchild=y->lchild;
                  y->lchild->parent=p;
           }
           else
                  p->rchild=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root=y;
           else
           {
               if(p==p->parent->lchild)
                       p->parent->lchild=y;
               else
                       p->parent->rchild=y;
           }
           y->lchild=p;
           p->parent=y;
     }
}
void RBtree::rightrotate(node *p)
{
     if(p->lchild==NULL)
          return ;
     else
     {
         node *y=p->lchild;
         if(y->rchild!=NULL)
         {
                  p->lchild=y->rchild;
                  y->rchild->parent=p;
         }
         else
                 p->lchild=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root=y;
         else
         {
             if(p==p->parent->lchild)
                   p->parent->lchild=y;
             else
                   p->parent->rchild=y;
         }
         y->rchild=p;
         p->parent=y;
     }
}

node* RBtree::successor(node *p)
{
      node *y=NULL;
     if(p->lchild!=NULL)
     {
         y=p->lchild;
         while(y->rchild!=NULL)
              y=y->rchild;
     }
     else
     {
         y=p->rchild;
         while(y->lchild!=NULL)
              y=y->lchild;
     }
     return y;
}

void RBtree::disp()
{
     display(root);
}
void RBtree::display(node *p)
{
     if(root==NULL)
     {
          cout<<"\nEmpty Tree.";
          return ;
     }
     if(p!=NULL)
     {
                cout<<"\n\t NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: ";
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red";
                if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->key;
                else
                       cout<<"\n There is no parent of the node.  ";
                if(p->rchild!=NULL)
                       cout<<"\n rchild Child: "<<p->rchild->key;
                else
                       cout<<"\n There is no rchild child of the node.  ";
                if(p->lchild!=NULL)
                       cout<<"\n lchild Child: "<<p->lchild->key;
                else
                       cout<<"\n There is no lchild child of the node.  ";
                cout<<endl;
    if(p->lchild)
    {
                 cout<<"\n\nlchild:\n";
     display(p->lchild);
    }
    if(p->rchild)
    {
     cout<<"\n\nrchild:\n";
                 display(p->rchild);
    }
}
}
void RBtree::searchfn()
{
     if(root==NULL)
     {
           cout<<"\nEmpty Tree\n" ;
           return  ;
     }
     int x;
     cout<<"\n Enter key of the node to be searched: ";
     cin>>x;
     node *p=root;
     int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key==x)
                found=1;
            if(found==0)
            {
                 if(p->key<x)
                      p=p->rchild;
                 else
                      p=p->lchild;
            }
     }
     if(found==0)
          cout<<"\nElement Not Found.";
     else
     {
                cout<<"\n\t FOUND NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: ";
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red";
                if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->key;
                else
                       cout<<"\n There is no parent of the node.  ";
                if(p->rchild!=NULL)
                       cout<<"\n rchild: "<<p->rchild->key;
                else
                       cout<<"\n There is no rchild child of the node.  ";
                if(p->lchild!=NULL)
                       cout<<"\n lchild: "<<p->lchild->key;
                else
                       cout<<"\n There is no lchild child of the node.  ";
                cout<<endl;

     }
}
int main()
{
    int ch,y=0;
    RBtree tree;
    cout<<"\nRED BLACK TREE " ;
    do
    {
                cout<<"\n 1. insert in the tree ";
                cout<<"\n 2. Delete a node from the tree";
                cout<<"\n 3. Search for an element in the tree";
                cout<<"\n 4. Display the tree ";
                cout<<"\n 5. Exit " ;
                cout<<"\nEnter Your Choice: ";
                cin>>ch;
                switch(ch)
                {
                          case 1 : tree.insertfn();
                                   cout<<"\nNode inserted.\n";
                                   break;
                          case 2 : tree.del();
                                   break;
                          case 3 : tree.searchfn();
                                   break;
                          case 4 : tree.disp();
                                   break;
                          case 5 : y=1;
                                   break;
                          default : cout<<"\nEnter a Valid Choice.";
                }
                cout<<endl;

    }while(y!=1);
    return 1;
}


