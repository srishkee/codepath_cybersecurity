#include <iostream>
#include <math.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	map<string, vector<int>> myMap; 
	for (int i = 0; i < n; ++i)
	{
		string s = "";
		int year = 0;
		cin >> s >> year;
		myMap[s].push_back(year); 
	}

	map<string, vector<int>>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		sort(it->second.begin(), it->second.end()); // sorts every time! 
	}

	int q = 0;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		string s = "";
		int num = 0;
		cin >> s >> num;

		map<string, vector<int>>::iterator it;
		it = myMap.find(s);

		//sort(it->second.begin(), it->second.end()); // sorts every time! 

		cout << it->second.at(num - 1) << endl;

	}


	return 0;
}