#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#define PFP pair<double, pair<double, double>>

bool lessThan(double a, double b)
{
	return (b - a > pow(10, -10));
}
bool greaterThan(double a, double b)
{
	return (a - b > pow(10, -10));
}

int main()
{
	while (true)
	{
		int numX = -1; int numY = -1;
		double w = -1;
		bool cont = false;

		cin >> numX >> numY >> w;
		
		if (numX == 0 & numY == 0 & w == 0.0) break;

		vector<PFP> X;
		vector<PFP> Y;

		for (int x = 0; x < numX; x++)
		{
			double center;
			cin >> center;
			double lower = center - (w/2);
			double upper = center + (w/2);

			X.push_back(make_pair(center, make_pair(lower, upper)));

		}

		for (int y = 0; y < numY; y++)
		{
			double center;
			cin >> center;
			double lower = center - (w/2);
			double upper = center + (w/2);

			Y.push_back(make_pair(center, make_pair(lower, upper)));

		}

		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());

		double prev = 0;
		int x = 0;
		for (x; x < numX; x++)
		{
			if (greaterThan(X[x].second.first, prev))
			{
				cout << "NO" << endl;
				cont = true;
				break;
			}
			prev = X[x].second.second;
		}
		if (cont) continue;
		if (lessThan(X[x - 1].second.second, 75.0))
		{
			cout << "NO" << endl;
			cont = true;
			break;
		}
		if (cont) continue;

		prev = 0;
		int y = 0;
		for (y; y < numY; y++)
		{
			if (greaterThan(Y[y].second.first, prev))
			{
				cout << "NO" << endl;
				cont = true;
				break;
			}
			prev = Y[y].second.second;
		}
		if (cont) continue;
		if (lessThan(Y[y-1].second.second, 100.0))
		{
			cout << "NO" << endl;
			cont = true;
			break;
		}
		if (cont) continue;
		cout << "YES" << endl;

	}


	return 0;
}