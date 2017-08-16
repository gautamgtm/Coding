#include <iostream>
#include <stack>
using namespace std;

struct node
{
  int data;
  node *next;
};

node *insert(node *head, int data)
{
  node *it = new node();
  it->data = data;
  it->next = head;
  return it;
}

void printList(node *head)
{
  node *it = head;
  while(it != NULL)
  {
    cout<<it->data<<" ";
    it = it->next;
  }
  cout<<endl;
}

void reverse(node *head, int k)
{
  node *it = head;
  stack<int> s;
  while(it!=NULL)
  {
    int i = 0;
    node *it1 = it;
    while(it1!=NULL && i<k)
    {
      s.push(it1->data);
      it1 = it1->next;
      i++;
    }
    while(!s.empty())
    {
      it->data = s.top();
      s.pop();
      it = it->next;
    }
  }
}

node* reverseOptimized(node *head, int k)
{
  node *it = head, *prev = NULL, *next = NULL;
  int i=0;
  while(it != NULL and i<k)
  {
    next = it->next;
    it->next = prev;
    prev = it;
    it = next;
    i++;
  }
  if(it != NULL)
    head->next = reverseOptimized(it,k);
  return prev;
}

int main()
{
  node *head = NULL;
  head = insert(head, 3);
  head = insert(head, 2);
  head = insert(head, 6);
  head = insert(head, 5);
  head = insert(head, 11);
  head = insert(head, 10);
  head = insert(head, 15);
  head = insert(head, 12);

  reverse(head, 3);
  printList(head);
  head = reverseOptimized(head, 3);
  printList(head);
}
