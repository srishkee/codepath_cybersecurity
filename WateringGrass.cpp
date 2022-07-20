#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       
using namespace std;

// CHANGE ALL TO LONG DOUBLE!!!

int main(int argc, char const *argv[])
{
	while(!cin.eof())
	{
		long double n = 0, length = 0, width = 0;

		cin >> n;
		if (cin.eof()) break;
		cin >> length >> width;

		std::vector<pair<long double, long double>> sprinklers;
		for (long double i = 0; i < n; ++i)
		{
			long double center = 0, radius = 0;
			cin >> center >> radius;
			long double start = center - sqrt(radius*radius - (width*width / 4));
			long double end = center + sqrt(radius*radius - (width*width / 4));
			sprinklers.push_back(make_pair(start, end));
		}

		sort(sprinklers.begin(), sprinklers.end());

		long double startPos = 0;
		std::vector<pair<long double, long double>> tmp;
		long double i = 0, j = 0;
		long double max = 0;
		long double ctr = 0;
		while (j < sprinklers.size())
		{
			bool flag = false; 
			while (i < sprinklers.size() && sprinklers.at(i).first <= startPos)
			{
				if (sprinklers.at(i).second > max)
				{
					max = sprinklers.at(i).second;
				}
				i++;
				flag = true; 
			}
			if (!flag) break; 
			j = i;
			startPos = max;
			ctr++;
		}

		//if(startPos < length) cout << -1 << endl;
		if (ctr == 0) cout << -1 << endl;
		else cout << ctr << endl;

	}


	return 0;
}