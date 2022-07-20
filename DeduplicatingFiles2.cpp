#include <iostream>
#include <string>
#include <vector>
#include <map>
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

int main()
{
	while (true)
	{
		//int n = 0;
		//cin >> n;
		string n = "";
		getline(cin, n);
		if (stoi(n) == 0) break;

		map<int, vector<string>> m; // Hash, pair<file, count>
		int hashCtr = 0, uniqueFileCtr = 0, totalFileCtr = 0;
		for (int i = 0; i < stoi(n); i++)
		{
			string s = "";
			bool flag = false;
			getline(cin, s);
			int hash = getHash(s);

			auto it = m.find(hash);
			if (it != m.end()) // If hash exists
			{
				vector<string> v = m[hash];
				for (int i = 0; i < v.size(); i++) // Search vector
				{
					if (v.at(i) != s) hashCtr++; // Increment collisions if not same file
					if (v.at(i) == s) flag = true; // Set flag if same file
				}
				if (!flag) // If file not found
				{
					uniqueFileCtr++; // Increment number of unique files 
				}
				m[hash].push_back(s);
			}
			else // If hash doesn't exist (neither collision nor duplicate found) 
			{
				vector<string> v;
				v.push_back(s);
				m[hash] = v;
				uniqueFileCtr++; // Increment number of unique files 
			}

		}
		cout << uniqueFileCtr << " " << hashCtr << endl;
	}
	return 0;
}