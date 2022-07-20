#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <limits.h>
//#include <set>
#include <cmath>
using namespace std;

bool cmp(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
	if (lhs.first < rhs.first) return true;
	else return (lhs.second < rhs.second); 
}

int findSet(int i, vector<int> &parent)
{
	if (parent.at(i) == i) return i;
	else
	{
		parent.at(i) = findSet(parent.at(i), parent);
		return parent.at(i);
	}
}

void unionSet(int i, int j, vector<int> &parent)
{
	int idx1 = findSet(i, parent);
	int idx2 = findSet(j, parent);

	parent.at(idx2) = idx1;
}

bool isSameSet(int i, int j, vector<int> &parent)
{
	int idx1 = findSet(i, parent);
	int idx2 = findSet(j, parent);

	return(idx1 == idx2);
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	for (int k = 0; k < t; ++k)
	{
		int n = 0;
		cin >> n;

		// int start1 = 0, start2 = 0;
		// cin >> start1 >> start2;

		std::vector<std::pair<int, int>> v;
		for (int j = 0; j < n + 2; j++)
		{
			int num1 = 0, num2 = 0;
			cin >> num1 >> num2;
			v.push_back(make_pair(num1, num2));
		}

		sort(v.begin(), v.end(), cmp);

		vector<int> parent(n + 2);
		for (int z = 0; z < parent.size(); z++)
		{
			parent.at(z) = z;  
		}

		for (int i = 0; i < v.size() - 1; ++i)
		{
			int dist1 = abs(v.at(i + 1).first - v.at(i).first);
			int dist2 = abs(v.at(i + 1).second - v.at(i).second);

			int dist = dist1 + dist2;
			if (!(dist <= 1000))
			{
				cout << "sad" << endl;
				return 0;
			}
			else
			{
				unionSet(i, i+1, parent);
			}
		}

		if(isSameSet(0, parent.size() - 1, parent)) cout << "happy" << endl;

	}

	return 0;
}

