//Program to find the max depth of a binary tree.
#include <iostream>
#include <vector>

//Tree structure here.
typedef struct tree {
    int val;
    struct tree *right = nullptr;
    struct tree *left = nullptr;
}
Tree;

//Here we create new nodes.
Tree *new_root(int val) {
    Tree *node = (Tree*)malloc(sizeof(Tree));
    node->val = val;
    return node;
}

/*Tree creation function. For null nodes, enter number 0.
  This is a recursive approach, so a list of nodes is [1, 2, 3, 0, 0, 4, 0, 0, 5, 0, 6, 0, 0]
  the tree formed will be :

      1
     / \
    2   5
   / \   \
  3   4   6

*/
Tree *make_tree() {
    Tree *root = nullptr;
    int n;
    std::cin>>n;
    if(n != 0) {
        root = new_root(n);
        root->left = make_tree();
        root->right = make_tree();
    }
    return root;
}

//Function to find the maximum depth of the given binary tree.
int maxDepth(Tree *root) {
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr) 
        return 1;
    else 
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    std::cout<<"Tree creation.\n\nEnter the values of the nodes for making tree.\nFor null nodes, enter 0.\n\n";
    Tree *root;

    //Tree creation
    root = make_tree();

    std::cout<<"\nMax depth of binary tree : "<<maxDepth(root)<<"\n";
}