#include <iostream>
#include <string>
#include <vector>
#include <map>
// #include <list>
// #include <algorithm>
using namespace std;

int getHash(string s)
{
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res = res ^ (int)s.at(i);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	while (true)
	{
		//int n = 0;
		//cin >> n;
		string n = "";
		getline(cin, n);
		if (stoi(n) == 0) break;

		int duplicateFileCtr = 0;
		int hashCtr = 0;

		map<int, vector<std::pair<string, int>>> m; // hash, <filename, count> 
		for (int i = 0; i < stoi(n); ++i)
		{
			string file = "";
			getline(cin, file);

			int hash = getHash(file);

			map<int, std::vector<std::pair<string, int>>>::iterator mapIt;
			mapIt = m.find(hash);
			if (mapIt != m.end()) // If hash code exists
			{
				std::vector<pair<string, int>> v = mapIt->second;
				std::vector<pair<string, int>>::iterator vectIt;
				bool flag = false;
				for (int i = 0; i < v.size(); i++) // Check if files also match
				{
					if (v.at(i).first == file) // If files match
					{
						duplicateFileCtr++;
						//hashCtr -= v.at(i).second; // If files match, decrease hashCtr
						mapIt->second.at(i).second = v.at(i).second + 1;
						flag = true;
					}
					else hashCtr += v.at(i).second; // Keep adding to hashCtr
				}
				if (!flag) // If files don't match, add file 
				{
					//hashCtr += (v.size());
					m[hash].push_back(make_pair(file, 1));
				}
			}
			else // If hash doesn't exist
			{
				vector<pair<string, int>> tmp;
				tmp.push_back(make_pair(file, 1));
				m.insert(make_pair(hash, tmp)); // Add hash and file 
			}
		}

		cout << (stoi(n) - duplicateFileCtr) << " " << hashCtr << endl;

	}
	return 0;
}