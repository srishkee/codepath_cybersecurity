#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

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
void build_segment_tree(int code, vector<int> A, int node, int b, int e)
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

		//else // (code == RANGE_MIN/MAXIMUM)
		//{
		//	int lValue = A[lContent], rValue = A[rContent];
		//	if (code == RANGE_MIN) segment_tree[node] = (lValue <= rValue) ? lContent : rContent;
		//	else segment_tree[node] = (lValue >= rValue) ? lContent : rContent;
		//}
	}
}

void update(int x, int i, int node, int b, int e)
{
	if (i < b || i > e) return;
	 
	if(x == 1) segment_tree[node] += 1;
	else if (x == 0) segment_tree[node] -= 1;

	if (b == e) return;

	update(x, i, 2 * node, b, (b + e) / 2);
	update(x, i, (2 * node) + 1, (b + e) / 2 + 1, e);

}

int query(int code,  int node, int b, int e, int i, int j) {
	if (i > e || j < b) return -1; // if the current interval does not intersect query interval
	if (b >= i && e <= j) return segment_tree[node]; // if the current interval is inside query interval
													 // compute the minimum position in the left and right part of the interval
	int p1 = query(code,  2 * node, b, (b + e) / 2, i, j);
	int p2 = query(code,  2 * node + 1, (b + e) / 2 + 1, e, i, j);

	// return the position where the overall minimum is
	if (p1 == -1) return p2; // can happen if we try to access segment outside query
	if (p2 == -1) return p1; // same as above
	if (code == RANGE_SUM) return p1 + p2;
	//else if (code == RANGE_MIN) return (A[p1] <= A[p2]) ? p1 : p2;
	//else return (A[p1] >= A[p2]) ? p1 : p2; // RANGE_MAX
}

void print_segment_tree()
{
	for (int i = 0; i < segment_tree.size(); i++)
	{
		cout << segment_tree.at(i) << '\t';
	}
	cout << endl << endl;
}

int main()
{
	/*
	int A[] = { 0,0,0,1,0,0,0 }; // Initial array
	init_segment_tree(7); // Initialize tree with total size (7) 
	build_segment_tree(RANGE_SUM, A, 1, 0, 6); // Starts building at node=1, indexed from v[0]->v[6]
	printf("%d\n", query(RANGE_SUM, A, 1, 0, 6, 1, 3)); // Starts building at node=1, indexed from v[0]->v[6], query from v[1]->v[3]
	print_segment_tree(); // Print whole tree

	update(1, 2, 1, 0, 6); // Set value=1 for position=2, start updating from node=1, indexed from v[0]->v[6] 
	printf("%d\n", query(RANGE_SUM, A, 1, 0, 6, 1, 3)); // Starts building at node=1, indexed from v[0]->v[6], query from v[1]->v[3]
	print_segment_tree(); // Print whole tree

	update(1, 1, 1, 0, 6); // Set value=1 for position=2, start updating from node=1, indexed from v[0]->v[6] 
	printf("%d\n", query(RANGE_SUM, A, 1, 0, 6, 1, 3)); // Starts building at node=1, indexed from v[0]->v[6], query from v[1]->v[3]
	print_segment_tree(); // Print whole tree
	*/

	int numBits = 0, k = 0;
	cin >> numBits >> k; 

	vector<int> A(numBits+1,0);
	init_segment_tree(numBits+1); // Initialize tree with total size (7) 
	build_segment_tree(RANGE_SUM, A, 1, 0, numBits); // Starts building at node=1, indexed from v[0]->v[6]

	for (int i = 0; i < k; i++)
	{
		string s = ""; 
		int n1 = 0;
		cin >> s >> n1;

		if (s == "F")
		{
			int val = A[n1-1];
			int actualVal = (val == 1) ? 0 : 1; 
			A[n1 - 1] = actualVal;
			//build_segment_tree(RANGE_SUM, A, 1, 0, numBits); // Starts building at node=1, indexed from v[0]->v[6]
			update(actualVal, n1-1, 1, 0, numBits);
			//print_segment_tree();
		}
		else if (s == "C")
		{
			int n2 = 0;
			cin >> n2; 
			cout << query(RANGE_SUM, 1, 0, numBits, n1-1, n2-1) << endl;
			//print_segment_tree();
		}
	}

	return 0;
}
