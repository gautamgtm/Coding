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

void nodesChildKDistance(node *root, int d)
{
  if(root == NULL || d < 0)
    return;
  if(d == 0)
  {
    cout<<root->data<<" ";
    return;
  }
  nodesChildKDistance(root->left, d-1);
  nodesChildKDistance(root->right, d-1);
}

int nodesAncestorKDistance(node *root, node *target, int d)
{
  if(root == NULL)
    return -1;
  if(root == target)
    return 0;

  //Search and left subtree
  int ld = nodesAncestorKDistance(root->left, target, d);
  if(ld != -1)
  {
    if(ld + 1 == d)
      cout<<root->data<<" ";
    else
      nodesChildKDistance(root->right, d-ld-2);
    return ld + 1;
  }

  //Search in Right subtree, if not found in left subtree
  int rd = nodesAncestorKDistance(root->right, target, d);
  if(rd != -1)
  {
    if(rd+1 == d)
      cout<<root->data<<" ";
    else
      nodesChildKDistance(root->left, d-rd-2);
    return rd + 1;
  }
  //Node not found in the tree
  return -1;
}

void nodeKDistance(node *root, node *target, int d)
{
  nodesChildKDistance(target, d);
  nodesAncestorKDistance(root, target, d);
}

int main()
{
  node *root = insert(20);
  root->left = insert(8);
  root->right = insert(22);
  root->left->left = insert(4);
  root->left->right = insert(12);
  root->left->right->left = insert(10);
  root->left->right->right = insert(14);
  node * target = root->left->right;

  nodeKDistance(root, target, 2);
}
