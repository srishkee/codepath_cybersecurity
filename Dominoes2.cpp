#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <cmath>
#include <math.h>       
using namespace std;

long long int getDominoeCount(long long int i, vector<long long int> &parent)
{
	if (parent.at(i) == i) return 1;
	else
	{
		return getDominoeCount(parent.at(i), parent) + 1;
	}
}

long long int findSet(long long int i, vector<long long int> &parent)
{
	if (parent.at(i) == i) return i;
	else
	{
		return findSet(parent.at(i), parent);
	}
}

void unionSet(long long int i, long long int j, vector<long long int> &parent)
{
	long long int idx1 = findSet(i, parent);
	long long int idx2 = findSet(j, parent);

	parent.at(idx1) = idx2;
}

bool isSameSet(long long int i, long long int j, vector<long long int> &parent)
{
	long long int idx1 = findSet(i, parent);
	long long int idx2 = findSet(j, parent);

	return(idx1 == idx2);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long int t = 0;
	cin >> t;
	for (long long int i = 0; i < t; ++i) // Number of test cases
	{
		long long int n = 0, m = 0, l = 0;
		cin >> n >> m >> l;

		std::vector<long long int> parent(n+1);
		for (long long int j = 0; j <= n; ++j)
		{
			parent.at(j) = j;
		}

		for (long long int j = 0; j < m; ++j)
		{
			long long int x = 0, y = 0;
			cin >> x >> y;

			unionSet(x, y, parent);
		}

		long long int sum = 0;
		for (long long int j = 0; j < l; j++)
		{
			long long int z = 0;
			cin >> z;
			sum += getDominoeCount(z, parent);
		}
		cout << sum << endl;
	}

	return 0;
}