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

void mergeLists(node *h1, node **h2)
{
  node *it1 = h1, *it2 = *h2, *it;
  while(it1 != NULL && it2 != NULL)
  {
    it = it2->next;
    it2->next = it1->next;
    it1->next = it2;

    it1 = it2->next;
    it2 = it;
  }
  *h2 = it2;
}

int main()
{
  node *head1 = NULL, *head2 = NULL;
  head1 = insert(head1, 3);
  head1 = insert(head1, 2);
  head1 = insert(head1, 6);
  head2 = insert(head2, 5);
  head2 = insert(head2, 11);
  head2 = insert(head2, 10);
  head2 = insert(head2, 15);
  head2 = insert(head2, 12);

  mergeLists(head1, &head2);
  printList(head1);
  printList(head2);

  }
