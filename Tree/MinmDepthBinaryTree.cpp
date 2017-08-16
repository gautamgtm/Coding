#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *left, *right;
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

void minmDepth(node *root, int height, int &ans)
{
  if(root == NULL)
  {
    ans = min(ans, height);
    return;
  }
  minmDepth(root->left, height+1, ans);
  minmDepth(root->right, height+1, ans);
}

int main()
{
  node *root 		           = insert(20);
  root->left               = insert(8);
  root->right              = insert(22);
  root->left->left         = insert(4);
  root->left->right        = insert(12);
  root->left->right->left  = insert(10);
  root->left->right->right = insert(14);

  int ans = 1e+8;
  minmDepth(root, 0, ans);
  printf("%d\n", ans);
}
