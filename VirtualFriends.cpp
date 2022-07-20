#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
// #include <list>
// #include <algorithm>
using namespace std;

//void initSet(int sz, vector<int> &parent)
//{
//	for (int i = 0; i < sz; ++i)
//	{
//		parent.at(i) = i;
//	}
//}

int findSet(int i, string s, map<string, int>&parent)
{
	if (parent[s] == i) return parent[s];
	else
	{
		parent[s] = findSet(i, s, parent);
		return parent[s];
	}
}

void unionSet(string s1, string s2, map<string, int>&parent)
{
	int idx1 = findSet(parent[s1], s1, parent);
	int idx2 = findSet(parent[s2], s2, parent);

	parent[s1] = parent[s2];
}

bool isSameSet(string s1, string s2, map<string, int>&parent)
{
	int idx1 = findSet(parent[s1], s1, parent);
	int idx2 = findSet(parent[s2], s2, parent);

	return(idx1 == idx2);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t = 0, f = 0; 
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> f;

		map<string, int> m; 
		for (int j = 0; j < f; j++) // Get input 
		{
			string s1 = "", s2 = "";
			cin >> s1 >> s2; 

			map<string, int>::iterator it1, it2;
			it1 = m.find(s1);
			it2 = m.find(s2);
			if (it1 == m.end()) m.insert(make_pair(s1, m.size() + 1));
			if (it2 == m.end()) m.insert(make_pair(s2, m.size() + 1));

			unionSet(s1, s2, m);
			
			int ctr = 0;
			int val = m[s2];
			for (auto elem : m)
			{
				if (elem.second == val) ctr++;
			}
			cout << ctr << endl;

		}
/*
		for (auto elem : m)
		{
			cout << elem.first << " " << elem.second << endl;
		}*/


	}

	return 0;
}