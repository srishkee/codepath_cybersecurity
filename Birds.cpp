#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int l = 0, d = 0, n = 0;
	cin >> l >> d >> n;
	vector<long long int> v;
	for (int i = 0; i < n; ++i)
	{
		long long int num = 0;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long int ctr = 0;
	if (l < 12) ctr = 0; 
	else if (n == 0)
	{
		ctr = (l - 12) / d + 1; 
	}
	else
	{
		long long int first = ((v.at(0) - 6) / d); // are bird positions before 6in? 
		long long int last = ((l - 6 - v.at(v.size() - 1)) / d);

		for (int i = 0; i < v.size() - 1; i++)
		{
			long long int tmp = 0;
			tmp = ((v.at(i + 1) - v.at(i)) / d) - 1;
			tmp = (tmp < 0) ? 0 : tmp;
			ctr += tmp; 
		}
		ctr += (first + last); 
	}

	cout << ctr << endl;

	return 0;
}