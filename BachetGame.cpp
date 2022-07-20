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

int checkItems(const std::vector<int> &v, const std::vector<int> &arr, int pos)
{
	// check for out of bounds! 
	bool stanFlag = true, ollieFlag = true;
	for (int i = 0; i < v.size(); ++i)
	{
		if (pos >= v.at(i) && arr.at(pos - v.at(i)) != 1)
		{
			stanFlag = false;
		}
		if (pos >= v.at(i) && arr.at(pos - v.at(i)) != 0)
		{
			ollieFlag = false;
		}
		if (!stanFlag && !ollieFlag) return 1;
	}

	if (stanFlag) return 0; // All previous entries were won by Stan 
	else if (ollieFlag) return 1; // All previous entries were won by Ollie 
}

int main(int argc, char const *argv[])
{
	while (!cin.eof())
	{
		int n = 0;
		cin >> n;
		if (cin.eof()) break;

		int m = 0;
		cin >> m;
		std::vector<int> v(m);
		std::vector<int> arr(n+1);

		for (int i = 0; i < m; ++i)
		{
			int num = 0;
			cin >> num;
			v.at(i) = num;
			arr.at(num) = 1;
		}

		sort(v.begin(), v.end());

		for (int i = 1; i < arr.size(); ++i)
		{
			int letter = 0; 
			if (arr.at(i) != 1)
			{
				letter = checkItems(v, arr, i);
				arr.at(i) = letter;
			}
		}

		if (arr.at(arr.size() - 1) == 1) cout << "Stan wins" << endl;
		else if (arr.at(arr.size() - 1) == 0) cout << "Ollie wins" << endl;
	}
	return 0;
}