#include <iostream>

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

bool findDeleteLoop(node *head)
{
  bool flag = false;
  node *slow=head, *fast=head;
  while(slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
    {
      flag = true;
      break;
    }
  }

  if(slow == fast)
  {
    slow = head;
    while(slow->next != fast->next)
    {
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = NULL;
  }
  return flag;
}

int main()
{
  node *head = NULL;
  head = insert(head, 3);
  head = insert(head, 2);
  head = insert(head, 6);
  head = insert(head, 5);
  head = insert(head, 11);

  /* Create a loop for testing */
  head->next->next->next->next->next = head->next->next;

  cout<<findDeleteLoop(head)<<endl;
  printList(head);
}
