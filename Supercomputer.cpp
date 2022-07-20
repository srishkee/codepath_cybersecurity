#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Segment Tree Library
typedef vector<int> vi;

// The segment tree is stored like a heap array
//#define RANGE_SUM 0
//#define RANGE_MIN 1
//#define RANGE_MAX 2
vi segment_tree;

// if original array size is N, the required segment_tree array length is 2*2^(floor(log2(N)) + 1)
void init_segment_tree(int N)
{
	//int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
	segment_tree.resize(4*N, -1); // resize  vector and fill with 0
}

void init_populate(int A[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		segment_tree[i] = A[i-1]; 
	}
}

int query(int qs, int qe, int u, int st, int en)
{
	if (qs <= st && qe >= en) return segment_tree[u];
	if (qs > en || qe < st) return 0;

	return query(qs, qe, (2 * u), st, (st + en) / 2) + query(qs, qe, (2 * u) + 1, 1 + (st + en) / 2, en); 
}

void update(int x, int i, int u, int start, int end, int n)
{
	if (i > n) return;
	if (i < start || i > end) return;
	if (start == end) { u = x; return; }

	update(x, i, (2 * u), start, (start + end) / 2, n);
	update(x, i, (2 * u) + 1, 1 + ((start + end) / 2), end, n);
	segment_tree[u] = segment_tree[2*u] + segment_tree[2*u + 1];
}

void build(int A[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		update(A[i-1], i, 1, 1, n, n);
	}
}

void print_segment_tree()
{
	for (int i = 1; i < segment_tree.size(); ++i)
	{
		cout << segment_tree.at(i) << '\t';
	}
	cout << endl;
}

int main()
{
	int A[] = { 1,0,0,0,0,0 };
	int n = 6;

	init_segment_tree(n);
	init_populate(A, n);
	build(A, n);
	print_segment_tree();
	
	printf("%d\n", query(2, 5, 0, 0, n-1)); // RMQ: (1-3) answer is index 2

	return 0;
}