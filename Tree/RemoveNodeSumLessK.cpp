#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *left, *right;
};

struct node* newNode(int data)
{
  struct node* tempNode = new node();
  tempNode->data = data;
  tempNode->left = NULL;
  tempNode->right = NULL;
  return tempNode;
}

void printTree(struct node* root)
{
  if(root == NULL)
    return;
  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);
}

struct node* removeNode(struct node* root, int k)
{
  if(root == NULL)
    return NULL;

  root->left = removeNode(root->left, k - root->data);
  root->right = removeNode(root->right, k - root->data);

  if(root->left == NULL && root->right == NULL)
  {
    if(root->data < k)
    {
      free(root);
      return NULL;
    }
  }
  return root;
}

int main()
{
  int k = 45;

  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->left = newNode(12);
  root->right->right->left = newNode(10);
  root->right->right->left->right = newNode(11);
  root->left->left->right->left = newNode(13);
  root->left->left->right->right = newNode(14);
  root->left->left->right->right->left = newNode(15);

  printTree(root);
  printf("\n");
  root = removeNode(root,k);
  printTree(root);

  return 0;
}
