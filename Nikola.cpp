#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       
using namespace std;

#define N 2000 // Make larger!

vector<vector<int>> memo(N, vector<int>(N, -1));
vector<int> v[N];
int cin_n;

int nikola(int c, int ps) // c = currPos, ps = numberOfPreviousStepsTaken 
{
	if (c == cin_n - 1) return v[cin_n - 1]; // Reach the end (0-indexing!)
	else if (c >= cin_n || c < 0) return INT_MAX; // Reach out of bounds

	int &ans = memo[c][ps]; // Reference to array so don't have to directly change memo 
	if (ans == -1)
	{
		ans = v[c] + min(nikola(c + ps + 1, ps + 1), nikola(c - ps, ps));
	}
	
	return ans;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			memo[i][j] = -1;
		}
	}

	cin_n = 0;
	cin >> cin_n;
	for (int i = 0; i < cin_n; ++i)
	{
		cin >> v[i];
	}

	cout << nikola(1, 1) << endl;

	return 0;
}