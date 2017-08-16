#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *left, *right;
};

struct node* insert(int val)
{
  struct node *newNode = new node();
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int height(struct node* root)
{
  if(root == NULL)
    return 0;

  return 1 + max(height(root->left), height(root->right));
}

int diameter(struct node *root)
{
  if(root == NULL)
    return 0;

  int ld = diameter(root->left), rd = diameter(root->right);
  int lh = height(root->left), rh = height(root->right);

  return max(max(ld, rd), 1 + lh + rh);
}

int diameterOptimized(struct node *root, int &height)
{
  if(root == NULL)
  {
    height = 0;
    return 0;
  }

  int lh, rh;
  int ld = diameterOptimized(root->left, lh), rd = diameterOptimized(root->right, rh);

  height = 1 + max(lh, rh);

  return max(max(ld, rd), 1 + lh + rh);
}

int main()
{
  struct node *root = insert(10);
  root->left        = insert(2);
  root->right       = insert(3);
  root->left->left  = insert(4);
  root->left->right = insert(5);

  int height;
  cout<<diameter(root)<<endl<<diameterOptimized(root, height);


}
