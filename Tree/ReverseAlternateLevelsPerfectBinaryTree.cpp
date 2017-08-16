#include <iostream>
#include <stack>
using namespace std;

struct node
{
  char data;
  node *left, *right;
};
typedef struct node node;

node *insert(char val)
{
  node *newNode = new node();
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void printInorder(node *root)
{
    if (root == NULL)
       return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void reverseOrder(node *root1, node *root2, int level)
{
  if(root1 == NULL || root2 == NULL)
    return;
  if(level%2 == 0)
    swap(root1->data, root2->data);

  reverseOrder(root1->left, root2->right, level+1);
  reverseOrder(root1->right, root2->left, level+1);
}

int main()
{
  node *root = insert('a');
  root->left = insert('b');
  root->right = insert('c');
  root->left->left = insert('d');
  root->left->right = insert('e');
  root->right->left = insert('f');
  root->right->right = insert('g');
  root->left->left->left = insert('h');
  root->left->left->right = insert('i');
  root->left->right->left = insert('j');
  root->left->right->right = insert('k');
  root->right->left->left = insert('l');
  root->right->left->right = insert('m');
  root->right->right->left = insert('n');
  root->right->right->right = insert('o');

  printInorder(root);
  cout<<endl;
  reverseOrder(root->left,root->right,0);
  printInorder(root);
}
