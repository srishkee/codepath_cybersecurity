#include <iostream>
#include <string>
#include <vector>
#include <map>
// #include <list>
#include <algorithm>
using namespace std;

int getMax(std::vector<int> v)
{
	int max = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		max = (v.at(i) > max) ? v.at(i) : max;
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int l = 0, n = 0;
		cin >> l >> n;

		std::vector<int> minVect;
		std::vector<int> maxVect;

		for (int i = 0; i < n; ++i)
		{
			int ant = 0;
			cin >> ant;

			if (ant < l / 2)
			{
				minVect.push_back(ant);
				maxVect.push_back(l - ant);
			}
			else
			{
				minVect.push_back(l - ant);
				maxVect.push_back(ant);
			}
		}

		// sort(minVect.begin(), minVect.end());
		// sort(maxVect.begin(), maxVect.end());

		cout << getMax(minVect) << " " << getMax(maxVect) << endl;
	}
	return 0;
}