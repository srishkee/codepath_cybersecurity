#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#include <functional>
#include <cmath>
#include <math.h>       /* log */
using namespace std;

int main(long long int argc, char const *argv[])
{
	long long int n = 0;
	cin >> n;

	/*if (n < 2)
	{
		cout << 0 << endl;
		return 0;
	}*/

	std::vector<long long int> v(n);
	for (long long int i = 0; i < n; ++i)
	{
		cin >> v.at(i);
	}

	sort(v.begin(), v.end(), std::greater<long long int>());

	long long int sum = 0;
	for (long long int i = 2; i < v.size(); i += 3)
	{
		if(i < v.size()) sum += v.at(i);
	}

	cout << sum << endl;

	return 0;
}