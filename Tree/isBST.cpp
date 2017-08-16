#include <iostream>
using namespace std;

struct node
{
  int data;
  node *left, *right;
};
typedef struct node node;

node *insert(int val)
{
  node *newNode = new node();
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

bool isBST(node *root, int max, int min)
{
  if(root == NULL)
    return true;
  if(root->data >= max || root->data <= min)
    return false;

  return(isBST(root->left, root->data, min) && isBST(root->right,max,root->data));
}

//Also we can store the inorder representation in array and check if it is sorted.

int main()
{
  node *root = insert(4);
  root->left        = insert(2);
  root->right       = insert(5);
  root->left->left  = insert(1);
  root->left->right = insert(3);

  cout<<isBST(root,1e+9,-1e+9);
}
