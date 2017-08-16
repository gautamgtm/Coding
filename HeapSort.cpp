#include <iostream>
using namespace std;

void maxHeapify(int A[], int idx, int n)
{
  int left = 2*idx+1, right = 2*idx+2, maxIdx = idx;
  if(left < n && A[left] > A[maxIdx])
    maxIdx = left;
  if(right < n && A[right] > A[maxIdx])
    maxIdx = right;

  if(maxIdx != idx)
  {
    swap(A[idx], A[maxIdx]);
    maxHeapify(A,maxIdx,n);
  }
}

void buildHeap(int A[], int n)
{
  //Call maxHeapify for every non-leaf nodes. Leaf nodes are already 1-node heaps.
  for(int i=n/2 - 1; i>=0; i--)
    maxHeapify(A,i,n);
}

void heapSort(int A[], int n)
{
  buildHeap(A,n);
  for(int i=n-1; i>0; i--)
  {
    swap(A[0], A[i]);
    maxHeapify(A,0,i);
  }
}

//Extra Utility Functions
void increaseValue(int A[], int idx, int val)
{
  if(val < A[idx])
    return;

  A[idx] = val;
  //If parent of node has lower value, correct it.
  while(A[(idx-1)/2] < A[idx])
  {
    swap(A[idx], A[(idx-1)/2]);
    idx = (idx-1)/2;
  }
}

int main()
{
  int n;
  cin>>n;
  int A[n];
  for(int i=0; i<n; i++)
    cin>>A[i];

  heapSort(A,n);

  return 0;
}
