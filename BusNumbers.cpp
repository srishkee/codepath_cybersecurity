#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
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

	sort(v.begin(), v.end());

	int i = 0;
	while (i < v.size() - 1)
	{
		int ctr = 1;
		string first = to_string(v.at(i));
		while ((i < v.size() - 1) && (v.at(i) + 1 == v.at(i + 1)))
		{
			ctr++;
			i++;
		}
		string last = to_string(v.at(i));

		if (ctr > 2) cout << first << "-" << last << " ";
		else if (first != last) cout << first << " " << last << " ";
		else cout << first << " "; 
		i++;
	}
	if (i == v.size() - 1)
	{
		cout << v.at(i) << endl;
	}
	else cout << endl;

	return 0;
}