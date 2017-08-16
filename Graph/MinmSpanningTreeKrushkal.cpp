#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(const pair<int, pair<int,int> >& p1, const pair<int, pair<int,int> >& p2)
{
  return p1.first < p2.first;
}

int root(int p[], int x)
{
  int ans = x;
  while(p[x] != x)
  {
    p[x] = p[p[x]];
    x = p[x];
  }
  return x;
}

void unionNodes(int p[], int x, int y)
{
  int p1 = root(p,x);
  int p2 = root(p,y);
  p[p1] = p2;
}

int krushkalMST(pair<int, pair<int,int> > edge[], int n, int m)
{
  vector<pair<int, int> > mstVec;
  int cost = 0;
  int parent[n];
  for(int i=0; i<n; i++)
    parent[i] = i;
  for(int i=0; i<m; i++)
  {
    int temp = edge[i].first, x = edge[i].second.first, y = edge[i].second.second;
    if(root(parent,x) != root(parent,y))
    {
      cost += temp;
      unionNodes(parent,x,y);
      cout<<x+1<<" "<<y+1<<endl;
    }
  }
  return cost;
}

int main()
{
  int n,m;
  cin>>n>>m;
  pair<int, pair<int,int> > edge[m];
  for(int i=0; i<m; i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    edge[i] = make_pair(c,make_pair(a,b));
  }
  sort(edge, edge+m, comp);
  cout<<krushkalMST(edge,n,m);
}
