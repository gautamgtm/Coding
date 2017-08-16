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

int findMax(node *root)
{
  if(root == NULL)
    return 0;

  return (root->data + max(findMax(root->left), findMax(root->right)));
}

int maxmSumPath(node *root)
{
  if(root == NULL)
    return 0;

  return max( max(maxmSumPath(root->left), maxmSumPath(root->right)),
        root->data + max( max(0,findMax(root->left)), max(0,findMax(root->right)) ));
}

int maxmSumPathOptimized(node *root, int &sum)
{
  if(root == NULL)
  {
    sum = 0;
    return 0;
  }

  int ls, rs;
  int l = maxmSumPathOptimized(root->left, ls), r = maxmSumPathOptimized(root->right, rs);

  sum = root->data + max(max(0,ls), max(0,rs)) ;

  return max(max(l, r), sum);
}

int main()
{
  node *root = insert(20);
  root->left = insert(8);
  root->right = insert(-22);
  root->left->left = insert(4);
  root->left->right = insert(-12);
  root->left->right->left = insert(10);
  root->left->right->right = insert(17);

  int sum;
  printf("%d %d\n", maxmSumPath(root), maxmSumPathOptimized(root, sum));
}
