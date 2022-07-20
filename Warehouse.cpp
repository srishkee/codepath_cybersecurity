#include <iostream>
//#include <functional>
//#include <math.h>
//#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const std::pair<int, string> &p1, const std::pair<int, string> &p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first > p2.first;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n = 0;
		cin >> n;
		vector<pair<int, string>> myMap;
		for (int i = 0; i < n; ++i)
		{
			string s = "";
			int ctr = 0;
			cin >> s >> ctr;

			bool flag = false;
			for (int i = 0; i < myMap.size(); i++)
			{
				if (myMap.at(i).second == s)
				{
					flag = true;
					myMap.at(i).first += ctr; 
				}
			}
			if (!flag) myMap.push_back(make_pair(ctr, s));
		}

		sort(myMap.begin(), myMap.end(), cmp);

		cout << myMap.size() << endl;
		for(int i = 0; i < myMap.size(); i++)
		{
			cout << myMap.at(i).second << " " << myMap.at(i).first << endl;
		}

	}
	return 0;
}