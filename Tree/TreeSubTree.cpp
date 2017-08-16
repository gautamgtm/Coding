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

bool isIdentical(node *root1, node *root2)
{
  if(root1 == NULL && root2 == NULL)
    return true;
  if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    return false;

  if(root1->data == root2->data)
    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
  else
    return false;
}

bool isSubtree(node *root1, node *root2)
{
  if(root1 == NULL)
    return false;
  if(root2 == NULL)
    return true;
  if(isIdentical(root1,root2))
    return true;

  return (isSubtree(root1->left,root2) || isSubtree(root1->right,root2));
}

void inorderTraversal(node *root, vector<int> &v)
{
  if(root == NULL)
  {
    v.push_back(-1);
    return;
  }
  inorderTraversal(root->left, v);
  v.push_back(root->data);
  inorderTraversal(root->right, v);
}

void preorderTraversal(node *root, vector<int> &v)
{
  if(root == NULL)
  {
    v.push_back(-1);
    return;
  }
  v.push_back(root->data);
  preorderTraversal(root->left, v);
  preorderTraversal(root->right, v);
}

bool isFound(vector<int> v1, vector<int> v2)
{
  //Code WIP
  return 1;
}

bool isSubtreeOptimized(node *root1, node *root2)
{
  if(root1 == NULL)
    return false;
  if(root2 == NULL)
    return true;
  //Tree S is a subtree of T if both inorder and preorder traversals of S are substrings of inorder and preorder traversals of T respectively.
  vector<int> I1, I2, P1, P2;
  I1 = inorderTraversal(root1); I2 = inorderTraversal(root2);
  T1 = preorderTraversal(root1); T2 = preorderTraversal(root2);
  I1.push_back(-2); I2.push_back(-2);
  T1.push_back(-2); T2.push_back(-2);

  if(isFound(I1,I2) && isFound(T1,T2))
    return true;
  else
    return false;
}

int main()
{
  node *T = insert(26);
  T->right              = insert(3);
  T->right->right       = insert(3);
  T->left               = insert(10);
  T->left->left         = insert(4);
  T->left->left->right  = insert(30);
  T->left->right        = insert(6);

  node *S = insert(10);
  S->right          = insert(6);
  S->left           = insert(4);
  S->left->right    = insert(30);

  cout<<isSubtree(T, S);
}
