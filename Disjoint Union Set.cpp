/*
Disjoint Set Union (DSU) or Union-Find is a graph algorithm that is very useful in situations when you have to determine the connected components in a graph.

Suppose that we have N nodes numbered from 1 to N and M edges. The graph can be disconnected and may have multiple connected components. Our job is to find out how many connected components are there in the graph and the number of nodes in each of them.

The basic idea behind DSU is the following:
Initially, all nodes are isolated i.e. there are no edges in the graph. We add edges to the graph one by one.
While adding an edge, check if the two nodes that the edge connects are already present in the same connected component.
– if they are, then do nothing.
– if they aren’t, then make the smaller of the two connected components a part of the larger one.
(So, we are making union of disjoint connected components; therefore the name Disjoint Set Union)
*/

#include<cstdio>
#inlcude<iostream>
using namespace std;
#define MOD 1000000007

int findParent(int x,int parent[])
//function to find the connected component that the xth node belongs to
{
	while(parent[x] != x)
	{
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void unionNodes(int a,int b,int parent[],int size[])
//to merge the connected components of nodes a and b
{
    int parent_a=findParent(a,parent),parent_b=findParent(b,parent);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])//the larger connected component eats up the smaller one
    {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}
 
int main()
{
 
    int N,M,i,a,b;
    scanf(" %d %d",&N,&M);
    int parent[10001]={0},size[10001]={0};
    for(int i=1;i<=N;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
 
    for(int i=1;i<=M;i++)
    {
        //scan each edge and merge the connected components of the two nodes
        scanf(" %d %d",&a,&b);
        unionNodes(a,b,parent,size);
    }
 
    int nos=0;
    for(int i=1;i<=N;i++)
    {
        if(findParent(i,parent)==i)//this condition is true only for disjoint connected components
        {
            printf("%d leader %d size\n",i,size[i]);
            nos++;
        }
 
    }
    printf("Total connected components : %d",nos);
 
    return 0;
}