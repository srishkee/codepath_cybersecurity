#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       /* log */
using namespace std;

int main(int argc, char const *argv[])
{
	long long int t = 0;
	cin >> t;
	for (long long int i = 0; i < t; ++i)
	{
		long long int n = 0;
		cin >> n;
		std::vector<long long int> v1(n);
		std::vector<long long int> v2(n);
		for (long long int j = 0; j < n; ++j)
		{
			cin >> v1.at(j);
		}
		for (long long int j = 0; j < n; ++j)
		{
			cin >> v2.at(j);
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end(), std::greater<long long int>());

		long long int sum = 0;
		for (long long int j = 0; j < n; ++j)
		{
			sum += (v1.at(j) * v2.at(j));
		}

		cout << "Case #" << (i+1) << ": " << sum << endl;
	}
	return 0;
}