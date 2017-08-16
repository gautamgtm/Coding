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

void split(node *head, node **a, node **b)
{
  *a = head;
  if(head == NULL || head->next == NULL)
  {
    *b = NULL;
    return;
  }

  node *it1 = head, *it2 = head;
  while(it2 != NULL && it2->next != NULL && it2->next->next != NULL)
  {
    it1 = it1->next;
    it2 = it2->next->next;
  }
  *b = it1->next;
  it1->next = NULL;//Most Important. To create a NULL pointer at the end of "a" list.
}

node* merge(node *a, node *b)
{
  if(a==NULL)
    return b;
  if(b==NULL)
    return a;

  node *result = NULL;
  if(a->data <= b->data)
  {
    result = a;
    result->next = merge(a->next,b);
  }
  else
  {
    result = b;
    result->next = merge(a,b->next);
  }
  return result;
}

void mergeSortList(node **head)
{
  //Zero or One element
  if(*head == NULL || (*head)->next == NULL)
    return;

  node *a = NULL, *b = NULL;
  split(*head, &a, &b);

  mergeSortList(&a);
  mergeSortList(&b);

  *head = merge(a,b);
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

  mergeSortList(&head);
  printList(head);
}
