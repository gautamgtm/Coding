//Graph Basics
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
typedef unsigned long int ll;

// Class to represent each node
class listNode
{
	public:
		ll number;
		int from, to;
		listNode* next;
};

//Class to represent list
class list
{
	public:	
		listNode* head;
};

listNode* createNode(ll n, int l, int r)
{
	listNode* newNode = (listNode*) malloc(sizeof(listNode));
	newNode->number = n;
	newNode->from = l;
	newNode->to = r;
	newNode->next = NULL;

	return newNode;
}

//Class to represent a graph. A graph is an array of adjacency lists.
class Graph
{
	public:
		ll node;
		list* array;
};

//Create Graph
Graph* createGraph(ll n)
{
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	graph->node = n;
	graph->array = (list*) malloc(n * sizeof(list));

	for (ll i=0; i< n; i++)
	{
		graph->array[i].head = NULL;
	}
	return graph;

}

void addEdgeToGraph(Graph* graph, int start, int end, int l, int r)
{
    // Add an edge from start to end.  A new node is added to the adjacency
    // list of start .  The node is added at the begining.
	listNode* newNode = createNode(end, l, r);
	newNode->next = graph->array[start].head;
	graph->array[start].head = newNode;
}

int main()
{
	ll num, edges;
	scanf ("%ld %ld", &num, &edges);
	Graph* graph = createGraph(num);
	while(edges--)
	{
		ll i,j;
		int l,r;
		scanf("%ld %ld %d %d", &i, &j, &l, &r);
		addEdgeToGraph(graph, i-1, j-1, l-1, r-1);
	}
	//Print Graph
	for (int i=0; i< graph->node; i++)
	{
		listNode* trav = graph->array[i].head;
		printf("Node %ld : ", i);
		while(trav)
		{
			printf(" -> %ld [%d %d]", trav->number, trav->from, trav->to);
			trav = trav->next;
		}
		printf("\n");
	}

}