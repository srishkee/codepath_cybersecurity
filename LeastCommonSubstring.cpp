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


int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v.at(i);
	}

	vector<int> ans;
	ans.push_back(1); 
	int maxLen = 0;
	for (int i = 0; i < n; i++)
	{
		ans[i] = 1; 
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i])
			{
				ans[i] = max(ans[i], ans[j] + 1);
			}
			maxLen = max(ans[i], maxLen);
		}
	}

	cout << maxLen << endl;

	return 0;
}