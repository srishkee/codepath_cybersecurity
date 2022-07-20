#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

char getMedian(std::vector<char> &v)
{
	if (v.size() == 1)
	{
		return v.at(0);
		v.pop_back(); 
	}
	else
	{
		sort(v.begin(), v.end());
		if (v.size() % 2 == 1)
		{
			int idx = (v.size() + 1) / 2 - 1;
			int num = v.at(idx);
			v.erase(v.begin() + idx);
			return num;
		}
		else if (v.size() % 2 == 0)
		{
			int idx = (v.size()) / 2;
			int num = v.at(idx);
			v.erase(v.begin() + idx); 
			return num;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::vector<char> v;
	while (!cin.eof())
	{
		char n = 0;
		cin >> n;

		if (cin.eof()) break;

		if (n != '#') v.push_back(n);

		else
		{
			cout << getMedian(v) << endl;
		}

	}

	return 0;
}