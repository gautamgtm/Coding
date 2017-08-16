#include <iostream>
#include <vector>
using namespace std;

struct node
{
  int data;
  struct node *left, *right, *nextRight;
};
typedef struct node node;

node *insert(int val)
{
  node *newNode = new node();
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->nextRight = NULL;
  return newNode;
}

int height(node *root)
{
  if(root == NULL)
    return 0;

  return 1 + max(height(root->left), height(root->right));
}

void connectNodesSameLevel(node *root, int level, vector<node *> &vec)
{
  if(root == NULL)
    return;

  if(level == 1)
    vec.push_back(root);
  else
  {
    connectNodesSameLevel(root->left, level-1, vec);
    connectNodesSameLevel(root->right, level-1, vec);
  }
}

int main()
{
  node *root 		    = insert(10);
  root->left        = insert(8);
  root->right       = insert(2);
  root->left->left  = insert(3);

  for(int i=1; i<=height(root); i++)
  {
    vector<node *> vec;
    connectNodesSameLevel(root, i, vec);
    for(int i=0; i<vec.size()-1; i++)
      vec[i]->nextRight = vec[i+1];
  }

  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);
}
