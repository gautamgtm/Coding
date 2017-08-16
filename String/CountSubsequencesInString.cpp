#include <iostream>
#include <string>
using namespace std;

int countSubsequence(string a, string b)
{
  int n=a.length(), m=b.length();
  if(m == 0 || n == 0)
    return 0;
  int DP[n][m];
  for(int i=0; i<m; i++)
    DP[0][i] = 0;
  if(a[0] == b[0])
    DP[0][0] = 1;

  for(int i=1; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if(a[i] == b[j])
        DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
      else
        DP[i][j] = DP[i-1][j];
    }
  }
  return DP[n-1][m-1];
}

int main()
{
  string a,b;
  cin>>a>>b;

  cout<<countSubsequence(a,b);
}
