//Segment Tree w/ Lazy Propagation
/*
Segment Trees is a Tree data structure for storing intervals, or segments, It allows querying which of the stored segments contain a given point.
It is, in principle, a static structure; that is, its content cannot be modified once the structure is built. It only uses O(N lg(N)) storage.

A segment trees has only three operations: build_tree, update_tree, query_tree.

Building tree: To init the tree segments or intervals values
Update tree: To update value of an interval or segment
Query tree: To retrieve the value of an interval or segment

The first node will hold the information for the interval [i, j]
If i<j the left and right son will hold the information for the intervals [i, (i+j)/2] and [(i+j)/2+1, j]
Notice that the height of a segment tree for an interval with N elements is [logN] + 1
So Maximum of elements of Segment Tree is 2^Height-1.
*/
/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */

/*
Please remember that a node in segment tree stores or represents result of a query for a range of indexes.
And if the node’s range lies within the update operation range, then all descendants of the node must also be updated.
With Lazy propagation, we update only node with value and postpone updates to its children by storing this update information
in separate nodes called lazy nodes or values.
The idea is to initialize all elements of lazy[] as 0. A value 0 in lazy[i] indicates that there are no pending updates on node i in segment tree.
A non-zero value of lazy[i] means that this amount needs to be added to node i in segment tree before making any query to the node.
*/

/*
Difference from Normal Segment Tree Algo:
Update : If current segment tree node has any pending
   		update, then first add that pending update to
  		current node.
		if the node’s range lies within the update operation range, we update only node with value and postpone updates to its children by storing this update information
		in separate nodes called lazy nodes or values.
Query : If current segment tree node has any pending
   		update, then first add that pending update to
   		current node.
*/
#include <iostream>
#include <algorithm>
using namespace std;

#include <string.h>
#include <math.h>

#define N 20
#define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff

int arr[N];
int tree[MAX];
int lazy[MAX];

/**
 * Build and init tree : Same
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 1) If current segment tree node has any pending
   update, then first add that pending update to
   current node.
2) If current node's range lies completely in
   update query range.
....a) Update current node
....b) Postpone updates to children by setting
       lazy value for children nodes.
3) If current node's range overlaps with update
   range, follow the same approach as above simple
   update.
...a) Recur for left and right children.
...b) Update current node using results of left
      and right calls.
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node];

   		//Postpone updates to children by setting lazy value for children nodes.
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j] {if interval is empty, just return from the function call}
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    	tree[node] += value;

    	//Postpone updates to children by setting lazy value for children nodes.
		if(a != b) {
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    	return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		//Postpone updates to children by setting lazy value for children nodes.
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

  if(a > b || a > j || b < i) return -inf; // Out of range {if interval is empty, just return from the function call}
  
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}

int main() {
	for(int i = 0; i < N; i++) arr[i] = 1;

	build_tree(1, 0, N-1);

	memset(lazy, 0, sizeof lazy);

	update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

	cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}
