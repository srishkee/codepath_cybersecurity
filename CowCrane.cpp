#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;


int main(int argc, char const *argv[])
{
	long long int c1 = 0, c2 = 0;
	long long int p1 = 0, p2 = 0;
	long long int t1 = 0, t2 = 0;

	cin >> c1 >> c2;
	cin >> p1 >> p2;
	cin >> t1 >> t2;

	long long int d1 = 0, d2 = 0, d3 = 0, d4 = 0; 
	
	d1 = (abs(c1) + abs(p1 - c1)); 
	d2 = (abs(c2) + abs(p2 - c2));

	d3 = (abs(c1) + abs(c2 - c1) + abs(p2 - c2)); // c2
	d4 = (abs(c2) + abs(c1 - c2) + abs(p1 - c1)); // c1

	bool flag = false;

	if (d1 <= t1)
	{
		if ((d1 + abs(c2-p1) + abs(p2 - c2)) <= t2) // Case#1
		{
			cout << "possible" << endl;
			flag = true;
		}
	}
	if (d2 <= t2)
	{
		if ((d2 + abs(c1 - p2) + abs(p1 - c1)) <= t1) // Case#2
		{
			if(!flag) cout << "possible" << endl;
			flag = true;
		}
	}
	if (d3 <= t2) // Case#3
	{
		if ((d3 + abs(p2 - c2) + abs(p1 - c2)) <= t1)
		{
			if (!flag) cout << "possible" << endl;
			flag = true;
		}
	}
	if (d4 <= t1) // Case#4 
	{
		if ((d4 + abs(p1 - c1) + abs(p2 - c1)) <= t2)
		{
			if (!flag) cout << "possible" << endl;
			flag = true;
		}
	}
	if(flag == false)
	{
		cout << "impossible" << endl;
	}

	return 0;
}