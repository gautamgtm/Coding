#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int> > graph, int n)
{
  int color[n];
  for(int i=0; i<n;i++)
    color[i] = -1;
  queue<int> q;
  q.push(0);
  color[0] = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(auto it=graph[u].begin(); it!=graph[u].end(); it++)
    {
      int v = *it;
      if(color[v] == -1)
      {
        color[v] = 1 - color[u];
        q.push(v);
      }
      else
      {
        if(color[u] == color[v])
          return false;
      }
    }
  }

  return true;
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
    graph[b].push_back(a);
  }

  cout<<isBipartite(graph,n);

}
