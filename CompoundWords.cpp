#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <set>
#include <cmath>
using namespace std;


int main(int argc, char const *argv[])
{
	std::vector<string> v;

	while(!cin.eof())
	{
		string s = "";
		getline(cin, s);

		if (cin.eof()) break;

		int idx = 0;
		string tmp = "";
		while (idx < s.size())
		{
			if (s.at(idx) == ' ')
			{
				v.push_back(tmp);
				tmp = "";
			}
			else
			{
				tmp += s.at(idx);
			}
			idx++;
		}
		v.push_back(tmp);

	}

	set<string> mySet; 
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i != j)
			{
				string s1 = v.at(i);
				string s2 = v.at(j);
				string word = v.at(i) + v.at(j);
				mySet.insert(word); 
			}
		}
	}

	for (auto elem : mySet)
	{
		cout << elem << endl;
	}

	return 0;
}

