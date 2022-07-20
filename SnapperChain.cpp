#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <map>
// #include <list>
// #include <algorithm>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n1 = 0, n2 = 0;
		cin >> n1 >> n2;

		std::bitset<(30)> b(n2);
		string s = b.to_string();
		bool flag = false;
		for (int j = s.size() - 1; j >= (30 - n1); j--)
		{
			if (s.at(j) != '1')
			{
				flag = true;
				cout << "Case #" << (i+1) << ": OFF" << endl;
				break;
			}
		}
		if (!flag) cout << "Case #" << (i+1) << ": ON" << endl;
	}
	return 0;
}