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

int height(node *root)
{
  if(root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

void printLevelOrderTraversal(node *root, int level)
{
  if(root == NULL)
    return;

  if(level == 1)
    cout<<root->data<<" ";
  else
  {
    printLevelOrderTraversal(root->left, level-1);
    printLevelOrderTraversal(root->right, level-1);
  }
}

int main()
{
  node *root 		    = insert(1);
  root->left        = insert(2);
  root->right       = insert(3);
  root->left->left  = insert(4);
  root->left->right = insert(5);

  for(int i=1; i<=height; i++)
    printLevelOrderTraversal(root, i);
}
