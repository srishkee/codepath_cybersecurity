#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <map>
using namespace std;

bool cmp(const string& s1, const string& s2)
{
	if (s1.at(0) == s2.at(0)) return (s1.at(1) < s2.at(1));
	else return (s1.at(0) < s2.at(0));
}


int main(int argc, char const *argv[])
{
	while (true)
	{
		int n = 0;
		cin >> n;
		if (n == 0) break;

		std::vector<string> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v.at(i);
		}

		stable_sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); ++i)
		{
			cout << v.at(i) << endl;
		}
		cout << endl;
	}
	return 0;
}