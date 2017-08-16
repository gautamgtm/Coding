//Graph Theory - Maximum Flow Problem
#include <iostream>
#include <cstdio>
#include <climits>
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
	vector< vector<int> > myGraph(n, vector<int>(n,0));
	FOR(i,0,m-1)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		a--;b--;
		myGraph[a][b] = c;
	}

	//Maximum Flow : Ford Fulkerson Algorithm
	int maxFlow =0;
	int start = 0, end = n-1;
	//Find a path from source to sink
	while(true)
	{
		vector<int> parent(n,-1);//Vertices initialized as not visited
		queue<int> q;
		q.push(start);
		parent[start] = 0;//Parent marked as visited
		int canFlow = INT_MAX;
		while(!q.empty())
		{
			int front = q.front();
			q.pop();
			FOR(i,0,n-1)
			{
				if(parent[i] == -1 && myGraph[front][i] > 0)
				{
					parent[i] = front;
					q.push(i);
					canFlow = min(canFlow, myGraph[front][i]);
				}
			}
		}
		//Path not found, done
		if(parent[end] == -1) break;
		//Path found
		maxFlow += canFlow;

		int goBack = n-1;
		while(goBack > 0)
		{
			int t=parent[goBack];
			//Increasing the forward flow
			myGraph[t][goBack] -= canFlow;
			//Increasing the reverse flow [To maintain equilibrium]
			myGraph[goBack][t] += canFlow;
			goBack = t;
		}
		//Continue to find more paths
	}
	printf("Maxflow between vertex %d and %d is %d.\n", start+1, end+1, maxFlow);

}