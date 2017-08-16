#include <iostream>
using namespace std;

int solve(string str, string optr)
{
  int n = str.size();
  int T[n][n]={}, F[n][n]={};
  for(int i=0; i<n; i++)
  {
    T[i][i] = (str[i] == 'T') ? 1 : 0;
    F[i][i] = (str[i] == 'F') ? 1 : 0;
  }

  for(int l=1; l<n; l++)
  {
    for(int i=0; i<n; i++)
    {
      int j = i+l;
      if(j>=n)
        continue;
      for(int k=i; k<j; k++)
      {
        //And Operator
        if(optr[k] == '&')
        {
          T[i][j] += T[i][k]*T[k+1][j];
          F[i][j] += T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
        }
        //Or Operator
        if(optr[k] == '|')
        {
          T[i][j] += T[i][k]*T[k+1][j] + T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j];
          F[i][j] += F[i][k]*F[k+1][j];
        }
        //Xor Operator
        if(optr[k] == '^')
        {
          T[i][j] += T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j];
          F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
        }
      }
    }
  }

  return T[0][n-1];
}

int main()
{
  string str,optr;
  cin>>str>>optr;

  int ans = solve(str,optr);
  cout<<ans<<endl;
}
