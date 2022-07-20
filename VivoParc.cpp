#include <iostream>
#include <string>
// #include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>
// #include <map>
using namespace std;

void print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			cout << v.at(i) << " ";
			/* code */
		}
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	std::vector<set<int>> v(n+1);
	while (!cin.eof())
	{
		string s = "";
		cin >> s;

		int num1 = stoi(s.substr(0, 1));
		int num2 = stoi(s.substr(2, 1));

		v.at(num1).insert(num2);
		v.at(num2).insert(num1);
	}

	

	return 0;
}