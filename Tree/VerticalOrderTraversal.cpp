#include <iostream>
#include <map>
#include <vector>
#include <queue>
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

void helperFunc(node *root, int level, map<int, vector<int> > &myMap)
{
  if(root == NULL)
    return;

  myMap[level].push_back(root->val);
  if(root->left != NULL)
    helperFunc(root->left, level-1, myMap);
  if(root->right != NULL)
    helperFunc(root->right, level+1, myMap);
}

void printVerticalOrderTraversal(node *root)
{
  if(root == NULL)
    return;

  map<int, vector<int> > myMap;
  helperFunc(root, 0, myMap);

  for(auto it=myMap.begin(); it != myMap.end(); it++)
  {
    for(auto i=0; i<it->second.size(); i++)
      printf("%d ", it->second[i]);
    printf("\n");
  }
}

void printVerticalOrderTraversalIterative(node *root)
{
  if(root == NULL)
    return;

  map<int, vector<int> > myMap;
  queue<pair<node *, int> > q;
  q.push(make_pair(root,0));
  while(!q.empty())
  {
    pair<node *, int> p = q.front();
    q.pop();
    myMap[p.second].push_back(p.first->val);

    if(p.first->left != NULL)
      q.push(make_pair(p.first->left, p.second-1));
    if(p.first->right != NULL)
      q.push(make_pair(p.first->right, p.second+1));
  }

  for(auto it=myMap.begin(); it != myMap.end(); it++)
  {
    for(auto i=0; i<it->second.size(); i++)
      printf("%d ", it->second[i]);
    printf("\n");
  }
}

int main()
{
  struct node *root = insert(1);
  root->left = insert(2);
  root->right = insert(3);
  root->left->left = insert(4);
  root->left->right = insert(5);
  root->right->left = insert(6);
  root->right->right = insert(7);
  root->right->left->right = insert(8);
  root->right->right->right = insert(9);

  printVerticalOrderTraversalIterative(root);
}
