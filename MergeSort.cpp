#include <iostream>

using namespace std;

void merge(int A[], int l, int mid, int r)
{
  int p=l, q=mid+1;
  int Arr[r-l+1], k=0;
  for(int i=l; i<=r; i++)
  {
    if(p>mid)
      Arr[k++] = A[q++];
    else
    if(q>r)
      Arr[k++] = A[p++];
    else
    if(A[p] <= A[q])
      Arr[k++] = A[p++];
    else
      Arr[k++] = A[q++];
  }

  for(int i=0; i<k; i++)
    A[l++] = Arr[i];
}

void mergeSort(int A[], int l, int r)
{
  if(l>=r) return;
  int mid = (l+r)/2;
  mergeSort(A,l,mid);
  mergeSort(A,mid+1,r);
  merge(A,l,mid,r);
}

int main()
{
  int n;
  cin>>n;
  int A[n];
  for(int i=0; i<n; i++)
    cin>>A[i];
  mergeSort(A,0,n-1);
  for(int i=0; i<n; i++)
    cout<<A[i]<<" ";
}
