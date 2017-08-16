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

void deleteNode(node **head, int num)
{
  if((*head)->data == num)
  {
    (*head) = (*head)->next;
    return;
  }

  node *it = *head;
  while(it->next != NULL && it->next->data != num)
    it = it->next;
  it->next = it->next->next;
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
  printList(head);
  
  deleteNode(&head, 5);
  printList(head);

  deleteNode(&head, 12);
  printList(head);
}
