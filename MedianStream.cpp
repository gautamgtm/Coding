#include <iostream>
using namespace std;

int medianInsertionSort(int A[], int idx)
{
  if(idx == 0)
    return A[idx];

  int j=idx;
  while(j>0 && A[j-1]>A[j])
  {
    swap(A[j], A[j-1]);
    j--;
  }
  if(idx%2)
    return (A[idx/2] + A[1 + idx/2])/2;
  else
    return A[idx/2];
}

int main()
{
  int n;
  cin>>n;
  int A[n];
  for(int i=0; i<n; i++)
  {
    cin>>A[i];
    cout<<medianInsertionSort(A,i)<<" ";
  }
}
