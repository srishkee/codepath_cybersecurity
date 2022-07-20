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
	int k = 0;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int n = 0;
		cin >> n;
		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int num = 0;
			cin >> num;
			v.push_back(num);
		}

		int ctr = 0;
		int pos = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v.at(i) != i - pos + 1)
			{
				ctr++;
				pos++;
			}
		}

		cout << ctr << endl;
	}
	return 0;
}