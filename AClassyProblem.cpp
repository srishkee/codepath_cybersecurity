#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool cmp(const std::pair<string, string>& lhs, const std::pair<string, string>& rhs) 
{
	if (lhs.first == rhs.first) return lhs.second < rhs.second;
	else return lhs.first < rhs.first; 
}

string getPerson(string s)
{
	int idx = 0;
	string returnStr = "";
	while (idx < s.size())
	{
		if (s.at(idx) == ':')
		{
			return returnStr;
		}
		else
		{
			returnStr += s.at(idx);
			idx++;
		}
	}
}

string getClass(string s)
{
	int idx = 0;
	string returnStr = "";
	while (idx < s.size())
	{
		if (s.at(idx) == ':')
		{
			idx += 2;
			while (idx < s.size())
			{
				returnStr += s.at(idx);
				idx++;
			}
			return returnStr;
		}
		else idx++;
	}
}

string getNumRep(string s)
{
	if (s == "upper") return "1";
	else if (s == "middle") return "2";
	else if (s == "lower") return "3";
}

string parseClass(string s)
{
	int idx = 0;
	string finalStr = "";
	string returnStr = "";
	while (idx < s.size())
	{
		if (s.at(idx) == '-')
		{
			finalStr += getNumRep(returnStr);
			returnStr = "";
		}
		else
		{
			returnStr += s.at(idx);
		}
		idx++;
	}
	finalStr += getNumRep(returnStr);
	return finalStr;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	for (int j = 0; j < t; ++j)
	{
		int n = 0;
		cin >> n;
		vector<pair<string, string>> v; 
		for (int i = 0; i < n; ++i)
		{
 			string s;
			getline(cin >> std::ws, s);

			for (int q = 0; q < 6; q++)
			{
				s.pop_back(); // Remove 6 characters: " class" 
			}

			string person = getPerson(s);
			string personClass = getClass(s);
			string numStr = parseClass(personClass);
			reverse(numStr.begin(), numStr.end());
			int sz = numStr.size();
			for (int w = 0; w < 10 - sz; w++)
			{
				numStr += "2"; 
			}
			v.push_back(make_pair(numStr, person));
		}

		sort(v.begin(), v.end(), cmp); 

		// Print answer 
		for (auto elem : v)
		{
			cout << elem.second << endl;
		}

		// Print ==========
		for (int z = 0; z < 30; z++)
		{
			cout << "=";
		}
		cout << endl;

	}
	return 0;
}