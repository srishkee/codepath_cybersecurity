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

bool cmp(const std::pair<string, int>&p1, const std::pair<string, int>&p2)
{
	return (p1.second > p2.second);
}

int main(int argc, char const *argv[])
{
	int N = 0, K = 0;
	cin >> N >> K;

	vector<pair<string, int>> attackMap;
	vector<pair<string, int>> defenseMap;
	vector<pair<string, int>> healthMap;

	for (int i = 0; i < N; ++i)
	{
		string myStr = to_string(i);

		int num1 = 0, num2 = 0, num3 = 0;
		cin >> num1 >> num2 >> num3;
		attackMap.push_back(make_pair(myStr, num1));
		defenseMap.push_back(make_pair(myStr, num2));
		healthMap.push_back(make_pair(myStr, num3));
	}

	sort(attackMap.begin(), attackMap.end(), cmp);
	sort(defenseMap.begin(), defenseMap.end(), cmp);
	sort(healthMap.begin(), healthMap.end(), cmp);

	set<string> mySet;
	for (int i = 0; i < K; ++i)
	{
		mySet.insert(attackMap.at(i).first);
		mySet.insert(defenseMap.at(i).first);
		mySet.insert(healthMap.at(i).first);
	}

	cout << mySet.size() << endl;


	return 0;
}