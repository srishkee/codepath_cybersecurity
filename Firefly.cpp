#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
#include <cmath>
#include <math.h>       /* log */
using namespace std;

int main(int argc, char const *argv[])
{
	long long int N = 0, H = 0;
	cin >> N >> H;

	std::vector<long long int> v(N);
	for (long long int i = 0; i < N; ++i)
	{
		cin >> v.at(i);
	}

	// Don't need first & top! 
	map<long long int, long long int> myMap;
	for (long long int h = 0; h < H; ++h)
	{
		long long int numCollisionsRow = 0;
		for (long long int i = 1; i < v.size(); ++i)
		{
			if (i % 2 == 0) // top
			{
				if (h >= (H - v.at(i) + 1) && h <= H) numCollisionsRow++;
			}
			else if (i % 2 == 1) // bottom 
			{
				if (h <= v.at(i))  numCollisionsRow++;
			}
		}
		auto it = myMap.find(numCollisionsRow);
		if (it != myMap.end())
		{
			myMap[numCollisionsRow]++;
		}
		else myMap.insert(make_pair(numCollisionsRow, 1));
	}

	long long int min = 1000000;
	long long int num = 0;
	for (auto it : myMap)
	{
		if (it.first < min)
		{
			min = it.first;
			num = it.second;
		}
	}

	cout << min << " " << num << endl;

	return 0;
}

