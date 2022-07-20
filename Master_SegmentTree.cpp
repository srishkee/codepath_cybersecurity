#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Master code for Fenwick Tree!

// Segment Tree Library
typedef vector<int> vi;

// The segment tree is stored like a heap array
#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2
vi segment_tree;

void init_segment_tree(int N) // if original array size is N,
{
	// the required segment_tree array length is 2*2^(floor(log2(N)) + 1);
	//int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
	segment_tree.resize(4 * N, 0); // resize this vector and fill with 0
}
void build_segment_tree(int code, int A[], int node, int b, int e)
{
	if (b == e)
	{
		if (code == RANGE_SUM) segment_tree[node] = A[b]; // store value of this cell
		else segment_tree[node] = b; // if RANGE_MIN/MAXIMUM, store index
	}

	else // recursively compute the values in the left and right subtrees
	{
		int leftIdx = 2 * node, rightIdx = 2 * node + 1;
		build_segment_tree(code, A, leftIdx, b, (b + e) / 2);
		build_segment_tree(code, A, rightIdx, (b + e) / 2 + 1, e);
		int lContent = segment_tree[leftIdx], rContent = segment_tree[rightIdx];

		if (code == RANGE_SUM) // make this segment contains sum of left and right subtree
			segment_tree[node] = lContent + rContent;

		else // (code == RANGE_MIN/MAXIMUM)
		{
			int lValue = A[lContent], rValue = A[rContent];
			if (code == RANGE_MIN) segment_tree[node] = (lValue <= rValue) ? lContent : rContent;
			else segment_tree[node] = (lValue >= rValue) ? lContent : rContent;
		}
	}
}
int query(int code, int A[], int node, int b, int e, int i, int j) {
	if (i > e || j < b) return -1; // if the current interval does not intersect query interval
	if (b >= i && e <= j) return segment_tree[node]; // if the current interval is inside query interval
													 // compute the minimum position in the left and right part of the interval
	int p1 = query(code, A, 2 * node, b, (b + e) / 2, i, j);
	int p2 = query(code, A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

	// return the position where the overall minimum is
	if (p1 == -1) return p2; // can happen if we try to access segment outside query
	if (p2 == -1) return p1; // same as above
	if (code == RANGE_SUM) return p1 + p2;
	else if (code == RANGE_MIN) return (A[p1] <= A[p2]) ? p1 : p2;
	else return (A[p1] >= A[p2]) ? p1 : p2;
}

void print_segment_tree()
{
	for (int i = 0; i < segment_tree.size(); i++)
	{
		cout << segment_tree.at(i) << '\t';
	}
	cout << endl << endl;
}

void update(int x, int i, int node, int b, int e)
{
	if (i < b || i > e) return;
	segment_tree[node] += x;
	if (b == e) return;

	update(x, i, 2 * node, b, (b + e) / 2);
	update(x, i, (2 * node) + 1, (b + e) / 2 + 1, e);
}

int main()
{
	int A[] = { 0,0,0,1,0,0,0 }; // Initial array
	init_segment_tree(7); // Initialize tree with total size (7) 
	build_segment_tree(RANGE_SUM, A, 1, 0, 6); // Starts building at node=1, indexed from v[0]->v[6]
	printf("%d\n", query(RANGE_SUM, A, 1, 0, 6, 1, 3)); // Starts building at node=1, indexed from v[0]->v[6], query from v[1]->v[3]
	print_segment_tree(); // Print whole tree

	update(1, 2, 1, 0, 6); // Set value=1 for posiiton=2, start updating from node=1, indexed from v[0]->v[6] 
	printf("%d\n", query(RANGE_SUM, A, 1, 0, 6, 1, 3)); // Starts building at node=1, indexed from v[0]->v[6], query from v[1]->v[3]
	print_segment_tree(); // Print whole tree

	return 0;
}
