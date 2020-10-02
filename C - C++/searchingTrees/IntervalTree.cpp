#include <iostream>
using namespace std;

struct Interval
{
   int low, high;
};
struct Node
{
   Interval *i;
   int maximum;
   Node *lchild, *rchild;
};
Node * newNode(Interval i)
{
   Node *t = new Node;
   t->i = new Interval(i);
   t->maximum = i.high;
   t->lchild = t->rchild = NULL;
};
Node *insert(Node *p, Interval i)
{
   if (p== NULL)
      return newNode(i);
      int l = p->i->low;
   if (i.low< l)
      p->lchild = insert(p->lchild, i);
   else
      p->rchild = insert(p->rchild, i);
   if (p->maximum < i.high)
      p->maximum = i.high;
   return p;
}
bool Overlap(Interval i1, Interval i2)
{
   if (i1.low <= i2.high && i2.low<= i1.high)
      return true;
   return false;
}
Interval *intervalFind(Node *root, Interval i)
 {
   if (root == NULL)
      return NULL;
   if (Overlap(*(root->i), i))
      return root->i;
   if (root->lchild!= NULL && root->lchild->maximum >= i.low)
      return intervalFind(root->lchild, i);
      return intervalFind(root->rchild, i);
}

void Inorder(Node *root)
{
   if (root == NULL)
      return;
   Inorder(root->lchild);
   cout << "[" << root->i->low<< ", " << root->i->high << "]" << " maximum = "<< root->maximum << endl;
   Inorder(root->rchild);
}
int main(int argc, char **argv)
{
   Interval intervals[] = { { 6, 21 }, { 9, 10 }, { 1, 5 }, { 45, 24 }, { 3, 4 } };
   int n = sizeof(intervals) / sizeof(intervals[0]);
   Node *root = NULL;
   for (int i = 0; i < n; i++)
      root = insert(root, intervals[i]);
   cout << "In-order traversal of the constructed Interval Tree is\n";
   Inorder(root);
   Interval x = { 6, 7 };
   cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
   Interval *res = intervalFind(root, x);
   if (res == NULL)
     cout << "\nNo Overlapping Interval";
   else
     cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
}
