#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct node
{
  int val;
  struct node *left, *right;
};
typedef struct node node;

node *insert(int val)
{
  node *newNode = new node();
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void printBottomViewIterative(node *root)
{
  if(root == NULL)
    return;

  map<int, int> myMap;
  queue<pair<node *, int> > q;
  q.push(make_pair(root,0));
  while(!q.empty())
  {
    pair<node *, int> p = q.front();
    q.pop();
    myMap[p.second] = p.first->val;

    if(p.first->left != NULL)
      q.push(make_pair(p.first->left, p.second-1));
    if(p.first->right != NULL)
      q.push(make_pair(p.first->right, p.second+1));
  }

  for(auto it=myMap.begin(); it != myMap.end(); it++)
    printf("%d ", it->second);
  printf("\n");
}

int main()
{
  struct node *root = insert(1);
  root->left = insert(2);
  root->right = insert(3);
  root->left->right = insert(4);
  root->left->right->right = insert(5);
  root->left->right->right->right = insert(6);

  printBottomViewIterative(root);
}
