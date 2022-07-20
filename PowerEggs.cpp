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

#define N 100

//long long int memo[N][N];
vector<vector<long long int>> memo(N, vector<long long int>(N, -1));

long long int dp(long long int eggs, long long int drops)
{
	if (eggs == 1) return drops;
	else if (eggs == 0) return 0;
	else if (drops == 0) return 0;

	long long int &ans = memo[eggs][drops];
	if (ans == -1)
	{
		ans = 1 + dp(eggs - 1, drops - 1) + dp(eggs, drops - 1);
	}

	return ans;
}

int main(int argc, char const *argv[])
{

	long long int t = 0;
	cin >> t;
	for (long long int i = 0; i < t; ++i) // Number of test cases
	{

		for (long long int j = 0; j < N; ++j) // Initialize to -1 
		{
			for (long long int k = 0; k < N; ++k)
			{
				memo[j][k] = -1;
			}
		}

		long long int floors = 0, eggs = 0;
		cin >> floors >> eggs;

		bool flag = 0;
		for (long long int j = 0; j <= 32; ++j) // Fill 32x32 matrix 
		{
			if(dp(eggs, j) >= floors)
			{
				cout << j << endl; // Print drops 
				flag = 1;
				break; 
			}
		}

		if (!flag) cout << "Impossible" << endl; 

	}

	return 0;
}