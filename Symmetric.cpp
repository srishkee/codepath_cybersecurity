#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       /* log */
using namespace std;


int main(int argc, char const *argv[])
{
	int ctr = 1;
	while (true)
	{
		int n = 0;
		cin >> n;
		if (n == 0) break;
		std::vector<string> v;
		for (int i = 0; i < n; ++i)
		{
			string s = "";
			cin >> s;
			v.push_back(s);
		}

		std::vector<string> v1;
		std::vector<string> v2;

		for (int i = 0; i < v.size(); ++i)
		{
			if (i % 2 == 0) v1.push_back(v.at(i));
			else if (i % 2 == 1) v2.push_back(v.at(i));
		}

		reverse(v2.begin(), v2.end());


		cout << "SET " << ctr << endl;
		for (int i = 0; i < v1.size(); ++i)
		{
			cout << v1.at(i) << endl;
		}

		for (int i = 0; i < v2.size(); ++i)
		{
			cout << v2.at(i) << endl;
		}

		ctr++;
	}

	return 0;
}