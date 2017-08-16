#include <iostream>
using namespace std;

struct node
{
  struct node *next;
  int data;
};

struct node* insert(struct node *head, int n)
{
  //Insert a node and point head towards it.
  struct node *newNode = new node;
  newNode->data = n;
  newNode->next = head;
  return newNode;
}

void finalSumList(struct node *head1, struct node *head2)
{
  struct node *finalList = NULL, *curr1 = head1, *curr2 = head2;
  struct node *prev1 = head1, *prev2 = head2;
  int sum1 = 0, sum2 = 0;
  while(curr1 != NULL && curr2 != NULL)
  {
    if(curr1->data < curr2->data)
    {
      sum1 += curr1->data;
      curr1 = curr1->next;
    }
    else
    if(curr1->data > curr2->data)
    {
      sum2 += curr2->data;
      curr2 = curr2->next;
    }
    else
    {
      if(finalList == NULL)
        finalList = (sum1 > sum2) ? head1 : head2;
      else
      {
        if(sum1 > sum2)
          prev2->next = prev1->next;
        else
          prev1->next = prev2->next;
      }
      prev1 = curr1; prev2 = curr2;
      sum1 = 0; sum2 = 0;
      curr1 = curr1->next; curr2 = curr2->next;
    }
  }
  if(curr1 == NULL)
  {
    while(curr2 != NULL)
    {
      sum2 += curr2->data;
      curr2 = curr2->next;
    }
  }
  else
  {
    while(curr1 != NULL)
    {
      sum1 += curr1->data;
      curr1 = curr1->next;
    }
  }

  if(finalList == NULL)
    finalList = (sum1 > sum2) ? head1 : head2;
  else
  {
    if(sum1 > sum2)
      prev2->next = prev1->next;
    else
      prev1->next = prev2->next;
  }

  struct node *it = finalList;
  while(it != NULL)
  {
    printf("%d ", it->data);
    it = it->next;
  }

}

int main()
{
  int n,m;
  scanf("%d %d", &n, &m);
  int A[n], B[m], temp;
  struct node *head1 = NULL, *head2 = NULL;
  for(int i=0; i<n; i++)
  {
    scanf("%d", &temp);
    head1 = insert(head1, temp);
  }
  for(int i=0; i<m; i++)
  {
    scanf("%d", &temp);
    head2 = insert(head2, temp);
  }

  finalSumList(head1, head2);

  return 0;
}
