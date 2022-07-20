#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <cmath>
#include <math.h>       
using namespace std;

bool cmp1(const pair<long long int, long long int>& p1, const pair<long long int, long long int>& p2)
{
	return (p1.first > p2.first);
}

bool cmp2(const pair<long long int,long long int>& p1, const pair<long long int, long long int>& p2)
{
	return (p1.second < p2.second);
}

void print(std::vector<pair<long long int, long long int>> v)
{
	for (long long int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i).second << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	while (true)
	{
		long long int n = 0;
		cin >> n;
		if (n == 0) break;

		map<long long int, long long int> m;
		for (long long int i = 0; i < n; ++i) // 1. Insert elements long long into map
		{
			long long int num = 0;
			cin >> num;

			auto it = m.find(num);
			if (it == m.end()) m.insert(std::make_pair(num, 1));
			else m[num]++;
		}

		// 2. Flip pair order & put pairs in set
		vector<pair<long long int,long long int>> mySet;
		long long int maxOccurence = INT_MIN;
		for (auto it : m)
		{
			long long int num1 = it.first;
			long long int num2 = it.second;
			mySet.push_back(std::make_pair(num2, num1)); // Flip order!
			maxOccurence = (it.second > maxOccurence) ? it.second : maxOccurence;
		}

		sort(mySet.begin(), mySet.end(), cmp1); 

		//long long int interval = (n%maxOccurence == 0) ? n / maxOccurence : ceil(n / (maxOccurence + 1));
		long long int interval = ceil((long double)n / maxOccurence);

		cout << maxOccurence << endl;

			for (long long int i = 0; i < maxOccurence; ++i)
			{
				std::vector<pair<long long int, long long int>> v;
				for (long long int j = 0; j < interval; ++j)
				{
					if (mySet.at(j).first != 0)
					{
						v.push_back(mySet.at(j));
						mySet.at(j).first--;
					}
				}
				sort(v.begin(), v.end(), cmp2);
				sort(mySet.begin(), mySet.end(), cmp1);
				print(v);
			}

		cout << endl;
	}

	return 0;
}