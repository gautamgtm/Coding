#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int> > graph, int n, int idx, int color[])
{
  color[idx] = 1;
  for(auto it=graph[idx].begin(); it!=graph[idx].end(); it++)
  {
    if(color[*it] == 1)
      return true;
    if(color[*it] == 0 && dfs(graph,n,*it,color) == 1)
      return true;
  }
  color[idx] = 2;
  return false;
}

bool isCyclePresent(vector<vector<int> > graph, int n)
{
  int color[n]={};

  for(int i=0; i<n; i++)
    if(color[i] == 0)
      if(dfs(graph,n,i,color) == 1)
        return true;
  return false;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int> > graph(n);
  for(int i=0; i<m; i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    graph[a].push_back(b);
  }

  cout<<isCyclePresent(graph, n);
}
