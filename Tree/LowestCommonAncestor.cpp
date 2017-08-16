#include <iostream>
#include <vector>
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

node *LCABST(node *root, int a, int b)
{
  if(root == NULL) return NULL;

  if(root->data > a && root->data > b)
    return LCABST(root->left, a, b);
  else
  if(root->data < a && root->data < b)
    return LCABST(root->right, a, b);

  return root;
}

node *LCABSTIterative(node *root, int a, int b)
{
  if(root == NULL) return NULL;

  while(root != NULL)
  {
    if(root->data > a && root->data > b)
      root = root->left;
    else
    if(root->data < a && root->data < b)
      root = root->right;
    else
      return root;
  }
  return root;
}

bool findPath(node *root, vector<int> &path, int a)
{
  if(root == NULL)  return 0;
  if(root->data == a)
  {
    path.push_back(root->data);
    return 1;
  }

  path.push_back(root->data);
  if((root->left && findPath(root->left, path, a)) || (root->right && findPath(root->right, path, a)))
    return 1;
  path.pop_back();
  return 0;
}

void findPath2(node *root, vector<int> &path, int a)
{
  if(root=NULL) return 0;
  if(root->data == a)
  {
    path.push_back(root->data);
    return 1;
  }

  path.push_back(root->data);
  findPath2(root->left, path, a);
  findPath2(root->right, path, a);
  path.pop_back();

}

int LCABinaryTree(node *root, int a, int b)
{
  if(root == NULL)  return NULL;

  vector<int> path1, path2;
  bool p1 = findPath(root, path1, a), p2 = findPath(root, path2,b);
  if(p1 == 0 || p2 == 0)
    return -1;

  int i;
  for(i=0; i<min(path1.size(), path2.size()); i++)
    if(path1[i] != path2[i])
      break;
  return i;
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

  node *lca = LCABSTIterative(root, 12, 14);
  cout<<lca->data;
}
