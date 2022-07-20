#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <set>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	std::vector<long long int> v(100000000, -1);
	//int v[100000000]; 
	long long int min = INT_MAX; 
	for (int i = 0; i < n; ++i)
	{
		int num = 0;
		cin >> num; 

		if (v.at(num) == -1)
		{
			v.at(num) = i;
		}
		else
		{
			long long int dist = i - v.at(num); 
			if (dist == 1)
			{
				cout << 1 << endl;
				return 0; 
			}
			else min = (dist < min) ? dist : min; 
		}
	}

	if (min == INT_MAX) cout << n << endl;
	else cout << min << endl; 

	


	return 0;
}

