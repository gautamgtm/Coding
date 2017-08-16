#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

//Only for Directed Acyclic Graph
//Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv,
//vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
void topologialSort(vector<vector<int> > graph, int n, int idx, stack<int> &s, bool visited[])
{
  visited[idx] = 1;
  for(auto it=graph[idx].begin(); it!=graph[idx].end(); it++)
    if(!visited[*it])
      topologialSort(graph,n,*it,s,visited);
  s.push(idx);
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

  stack<int> s;
  bool visited[n]={};
  topologialSort(graph,n,0,s,visited);
  while(!s.empty())
  {
    cout<<s.top()+1<<" ";
    s.pop();
  }
}
