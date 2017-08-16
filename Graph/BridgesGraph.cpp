#include <iostream>
#include <vector>

using namespace std;

int t, t1;

void dfs(vector<vector<int> > graph, int n, int u, int visited[], int parent[], int disc[], int low[])
{
  visited[u] = 1;
  t++;
  disc[u] = t; low[u] = t;

  for(auto it=graph[u].begin(); it!=graph[u].end();it++)
  {
    int v = *it;
    if(!visited[v])
    {
      parent[v] = u;
      dfs(graph, n, v, visited, parent, disc, low);
      low[u] = min(low[u], low[v]);

      //No back edge of the child "v" of "u" , or even if it has a back-edge it is upto u only. So if u-v is removed, graph => disconnected
      //No equal sign => means if there is a path from v to u apart from the (u,v) then (u,w) is not bridge.
      if(low[v] > disc[u])
        cout<<u+1<<" "<<v+1<<endl;
    }
    else
    {
      //If v has been visited and it was not in the dfs() where you reach u from v [=> parent[u] = v], then it have been visited through some other node dfs.
      //So Back edge there for u [through v]. So update low[u].
      if(v != parent[u])
        low[u] = min(low[u], disc[v]);
    }
  }
}

void dfs1(vector<vector<int> > graph, int n, int u, int visited[], int parent[], int disc[], int low[], int isArtPoint[])
{
  visited[u] = 1;
  t1++;
  low[u] = disc[u] = t1;

  int child = 0;
  for(auto it=graph[u].begin(); it!=graph[u].end();it++)
  {
    int v = *it;
    if(!visited[v])
    {
      child++;
      parent[v] = u;
      dfs1(graph, n, v, visited, parent, disc, low, isArtPoint);
      low[u] = min(low[u], low[v]);

      //u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
      //No back edge of the child "v" of "u" , or even if it has a back-edge it is upto u only. So if u is removed, graph => disconnected
      if(parent[u] != -1 && low[v] >= disc[u])
        isArtPoint[u] = 1;

      //u is root of DFS tree and it has at least two children.
      if(parent[u] == -1 && child > 1)
        isArtPoint[u] = 1;

    }
    else
    {
      //If v has been visited and it was not in the dfs() where you reach u from v [=> parent[u] = v], then it have been visited through some other node dfs.
      //So Back edge there for u [through v]. So update low[u].
      if(v!=parent[u])
        low[u] = min(low[u], disc[v]);
    }
  }
}

void findBridges(vector<vector<int> > graph, int n)
{
  int visited[n]={}, parent[n];
  int disc[n], low[n];
  for(int i=0; i<n; i++)
    parent[i] = -1;
  t = 0;
  for(int i=0; i<n; i++)
    if(visited[i] == 0)
      dfs(graph, n, i, visited, parent, disc, low);
  cout<<endl;
}


void findArticulationPoints(vector<vector<int> > graph, int n)
{
  int visited[n]={}, parent[n], isArtPoint[n]={};
  int disc[n], low[n];
  for(int i=0; i<n; i++)
    parent[i] = -1;
  t1 = 0;
  for(int i=0; i<n; i++)
    if(!visited[i])
      dfs1(graph, n, i, visited, parent, disc, low, isArtPoint);
  for(int i=0; i<n; i++)
    if(isArtPoint[i] == 1)
      cout<<i+1<<" ";
  cout<<endl;
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

  findArticulationPoints(graph,n);
  findBridges(graph,n);

}
