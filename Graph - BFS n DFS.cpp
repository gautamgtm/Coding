//Breadth First Search & Depth First Search
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


int main()
{
	cin.sync_with_stdio(0);
	int n,m;
	scanf("%d %d", &n, &m);
	vector< vector<int> > myGraph(n);

	FOR(i,0,m-1)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		a--;b--;
		myGraph[a].PB(b);
	}

	int start = 0;
	//BFS
	printf("BFS\n");
	queue<int> q;
	vector<bool> visited(n, 0);
	q.push(start);
	visited[start] = 1;

	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		printf("%d ", front);

		for(auto it=myGraph[front].begin(); it != myGraph[front].end(); it++)
		{
			if(visited[*it] == 0)
			{
				q.push(*it);
				visited[*it] = 1;
			}

		}
	}
	fill(visited.begin(), visited.end(), 0);
	printf("\n");

	//DFS
	printf("DFS\n");
	stack<int> s;
	s.push(start);

	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		printf("%d ", top);
		if(!visited[top])
		{
			visited[top] = 1;
			for(auto it=myGraph[top].begin(); it != myGraph[top].end(); it++)
				if(!visited[*it])
					s.push(*it);
		}

	}
	fill(visited.begin(), visited.end(), 0);
	printf("\n");

	return 0;
}
