#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int maxFlow(vector<vector<int> > graph, int n)
{
  int source = 0, sink = n-1;
  int maxm = 0;

  while(true)
  {
    //Find a path using BFS
    int parent[n];
    queue<int> q;
    for(int i=0; i<n; i++)
      parent[i] = -1;
    q.push(source);
    while(!q.empty())
    {
      int p = q.front();
      q.pop();
      for(int i=0; i<n; i++)
        if(parent[i] == -1 && graph[p][i] > 0)
        {
          parent[i] = p;
          q.push(i);
        }
    }
    //No path found from source to sink
    if(parent[sink] == -1)
      break;
    int flow = 1e+9, v = sink;
    while(v != source)
    {
      flow = min(flow, graph[parent[v]][v]);
      v = parent[v];
    }
    maxm += flow;

    //Update the residual graph
    v = sink;
    while(v != source)
    {
      graph[parent[v]][v] -= flow;
      graph[v][parent[v]] += flow;
      v = parent[v];
    }
  }

  return maxm;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int> > graph(n, vector<int>(n,0));
  for(int i=0; i<m; i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    graph[a][b] = c;
  }

  cout<<maxFlow(graph,n);
}
