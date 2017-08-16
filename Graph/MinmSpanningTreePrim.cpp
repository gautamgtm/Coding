#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;

int primMST(vector<PII> graph[], int n)
{
  bool visited[n]={};
  int cost = 0;
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  pq.push(make_pair(0,0));

  while(!pq.empty())
  {
    PII p = pq.top();
    pq.pop();
    if(visited[p.second])
      continue;
    
    cost += p.first;
    visited[p.second] = 1;
    for(auto it=graph[p.second].begin(); it!=graph[p.second].end(); it++)
      if(!visited[it->second])
        pq.push(make_pair(it->first,it->second));
  }
  return cost;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<pair<int,int> > graph[n];
  for(int i=0; i<m; i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    graph[a].push_back(make_pair(c,b));
    graph[b].push_back(make_pair(c,a));
  }

  cout<<primMST(graph,n);
}
