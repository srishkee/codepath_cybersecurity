#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	// Read user input 
	int cx = 0, cy = 0, n = 0;
	cin >> cx >> cy >> n;

	int dist = 0;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x = 0, y = 0, r = 0;
		cin >> x >> y >> r;

		dist = sqrt(pow((cx - x), 2) + pow((cy - y), 2)); // dist = Pythagorean distance 
		if (dist < r) // If point lies within circle 
		{
			dist = 0;
		}
		else // subtract radius from total distance 
		{
			dist -= r;
		}
		v.push_back(dist);
	}

	sort(v.begin(), v.end()); // sort allowable radius vector

	cout << v.at(2) << endl; // 3rd radius is too large 

	return 0;
}