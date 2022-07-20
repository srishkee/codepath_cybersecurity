#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	for (int k = 0; k < t; ++k)
	{
		map<string, vector<string>> italianMap; // name, pizza
		map<string, vector<string>> englishMap; // name, pizza

		int n = 0;
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			string name = "";
			cin >> name;
			int n1 = 0, n2 = 0;
			cin >> n1;
			for (int i = 0; i < n1; ++i)
			{
				string s = "";
				cin >> s;
				italianMap[s].push_back(name);
			}

			cin >> n2;
			for (int i = 0; i < n2; ++i)
			{
				string s = "";
				cin >> s;
				englishMap[s].push_back(name);
			}
		}

		vector<std::pair<string, string>> finalVect;
		for (auto italian : italianMap)
		{
			for (auto english : englishMap)
			{
				if (italian.second.size() == english.second.size())
				{
					bool flag = 0;

					sort(italian.second.begin(), italian.second.end());
					sort(english.second.begin(), english.second.end());

					for (int i = 0; i < italian.second.size(); i++)
					{
						string s1 = italian.second.at(i);
						string s2 = english.second.at(i);
						if (italian.second.at(i) != english.second.at(i))
						{
							flag = 1;
							break; 
						}
					}
					if (!flag) finalVect.push_back(make_pair(italian.first, english.first));
				}
			}
		}

		for (int i = 0; i < finalVect.size(); i++)
		{
			cout << "(" << finalVect.at(i).first << ", " << finalVect.at(i).second << ")" << endl;
		}

		cout << endl;

	}
	return 0;
}