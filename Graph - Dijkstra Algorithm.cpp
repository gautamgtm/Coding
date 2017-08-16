//Shortest Path : Dijkstra's Algorithm using Priority Queue
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <climits>
#include <utility>
using namespace std;

#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define LDB long double
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,a,b) for (auto i = (a); i <= (b); i++)
#define FORD(i,a,b) for (auto i = (a); i >= (b); i--)
#define FIT(it,v) for (auto it = v.begin(); it != v.end(); it++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x < 0)?-(x):x)

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity

struct prioritize
{
	bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2)
			{return p1.second>p2.second;}
};


int main()
{
	cin.sync_with_stdio(0);
	int n,m;
	scanf("%d %d", &n, &m);
	vector< vector<PII> > myGraph(n);
	FOR(i,0,m-1)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		a--;b--;
		myGraph[a].PB(MP(b,c));
		myGraph[b].PB(MP(a,c));
	}


	//Dijkstra Algorithm
	int start = 0;
	//priority_queue<PII> pq;
	priority_queue<PII ,vector<PII>, prioritize> pq;
	vector<int> distance(n, INF);
	distance[start] = 0;
	pq.push(MP(start,distance[start]));

	while(!pq.empty())
	{
		PII top = pq.top();
		int currVertex = top.first, currDistance = top.second;
		pq.pop();

		for(auto it=myGraph[currVertex].begin(); it!=myGraph[currVertex].end(); it++)
		{
			if(it->second + currDistance < distance[it->first])
			{
				distance[it->first] = it->second + currDistance;
				pq.push(MP(it->first, distance[it->first]));
			}
		}
	}

	//Print Distance
	cout<<"Source is: 0. The shortest distance to every other vertex from here is: \n";
    for(int i=0;i<n;i++)
    {
    	int dis = -1;
    	if(distance[i] != INF)
    	{
    		dis = distance[i];
    	}
        cout<<"Vertex: "<<i<<" , Distance: "<<dis<<"\n";
    }

}
