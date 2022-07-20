#include <iostream>
//#include <string>
#include <vector>
//#include <map>
//#include <set>
// #include <list>
// #include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int recipeCtr = 0;

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int q = 0;
		cin >> q;
		vector<int> v; 
		vector<int> ingredVect(6, 0);
		vector<int> accVect(6, 0);
		vector<int> expVect(6, 0);
		for (int j = 0; j < q; ++j) // O(n)  
		{
			int ingred = 0;
			cin >> ingred;
			v.push_back(ingred);
		}

		for (int j = 0; j < v.size(); j++)
		{
			if ((ingredVect).at(v.at(j)) > 0)
			{
				expVect.at(v.at(j))++; 
			}
		}

		bool flag = 0; 
		for (int j = 0; j < expVect.size(); j++)
		{
			if (expVect.at(j) != accVect.at(j))
			{
				flag = 1;
				break; 
			}
		}
		
		if (!flag)
		{
			for (int j = 0; j < v.size(); j++)
			{
				ingredVect.at(v.at(j)) = i;
				accVect.at(v.at(j)) = 0;
			}
			accVect.at(i) = v.size();
			recipeCtr++;
		}
	}

	cout << recipeCtr << endl;


	return 0;
}