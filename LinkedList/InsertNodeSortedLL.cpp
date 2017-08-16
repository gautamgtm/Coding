#include <iostream>

using namespace std;

struct node
{
  int data;
  struct node *next;
};

node *newNode(int data)
{
  node *tempNode = new node();
  tempNode->data = data;
  tempNode->next = NULL;
  return tempNode;
}

void printList(node *head)
{
  node *it = head;
  while(it != NULL)
  {
    cout<<it->data<<" ";
    it = it->next;
  }
}

void sortedInsert(node **head, node *new_node)
{
  if(*head == NULL || (*head)->data > new_node->data)
  {
    new_node->next = (*head);
    *head = new_node;
    return;
  }

  node *it = *head;
  while(it->next != NULL && it->next->data < new_node->data)
    it = it->next;

  new_node->next = it->next;
  it->next = new_node;

}

int main()
{
  node *head = NULL;
  node *new_node = newNode(5);
  sortedInsert(&head, new_node);
  new_node = newNode(10);
  sortedInsert(&head, new_node);
  new_node = newNode(7);
  sortedInsert(&head, new_node);
  new_node = newNode(3);
  sortedInsert(&head, new_node);
  new_node = newNode(1);
  sortedInsert(&head, new_node);
  new_node = newNode(9);
  sortedInsert(&head, new_node);
  printf("Created Linked List\n");
  printList(head);
}
