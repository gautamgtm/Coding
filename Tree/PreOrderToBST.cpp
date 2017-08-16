#include <iostream>
#include <stack>
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

//Kinda simulate the traversal, keeping a stack of nodes (just their values) of which we're still in the left subtree.
//If the next number is smaller than the last stack value, then we're still in the left subtree of all stack nodes,
//so just push the new one onto the stack. But before that, pop all smaller ancestor values, as we must now be in their right subtrees
//(or even further, in the right subtree of an ancestor). Also, use the popped values as a lower bound,
//since being in their right subtree means we must never come across a smaller number anymore.
bool canRepresentBST(int A[], int n)
{
  stack<int> s;
  int lower = -1e+9; //To keep track of the lower value.
  for(int i=0; i<n; i++)
  {
    //If new number is lower than "lower", return false;
    if(A[i] < lower)
      return false;

    //Keep updating "lower" as soon as you get a higher value.
    while(!s.empty() && s.top() < A[i])
    {
      //Inside this loop means you have entered any right subtree. So pop the left subtree and parent elements one ny
      //one and update the lower limit.
      lower = s.top();
      s.pop();
    }
    s.push(A[i]);
  }
  return true;
}

node* constructBST(int A[], int l, int r, int n)
{
  if(l>r || l>=n)
    return NULL;
  node *temp = insert(A[l]);

  if(l==r)
    return temp;

  int i = l+1;
  while(i<=r && A[i] < A[l])
    i++;
  temp->left = constructBST(A, l+1, i-1, n);
  temp->right = constructBST(A, i, r, n);

  return temp;
}

node* constructBSTOptimized(int A[], int& idx, int val, int n, int max, int min)
{
  node *root = NULL;
  if(idx>=n)
    return NULL;

  if(A[idx] < max && A[idx] > min)
  {
    root = insert(A[idx]);
    idx++;
    root->left = constructBSTOptimized(A,idx,A[idx],n,root->data,min);
    root->right = constructBSTOptimized(A,idx,A[idx],n,max,root->data);
  }
  return root;
}

void printInorder (node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
  int pre1[] = {40, 30, 35, 80, 100};
  int n = sizeof(pre1)/sizeof(pre1[0]), idx=0;
  if(canRepresentBST(pre1, n))
  {
    cout << "true\n";
    node *root = NULL;
    //root = constructBST(pre1,0,n-1,n);
    root = constructBSTOptimized(pre1,idx,pre1[0],n,1e+9,-1e+9);
    printInorder(root);
    cout<<endl;
  }
  else
   cout << "false\n";

  int pre2[] = {40, 30, 35, 20, 80, 100};
  n = sizeof(pre2)/sizeof(pre2[0]);
  idx = 0;
  if(canRepresentBST(pre2, n))
  {
    cout << "true\n";
    node *root = NULL;
    //root = constructBST(pre2,0,n-1,n);
    root = constructBSTOptimized(pre2,idx,pre2[0],n,1e+9,-1e+9);
    printInorder(root);
    cout<<endl;
  }
  else
   cout << "false\n";

  return 0;
}
