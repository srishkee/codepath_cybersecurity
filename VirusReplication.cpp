#include <iostream>
#include <string>
#include <cmath>
#include <math.h>       /* log */
using namespace std;

long long int iterateF(const string &s1, const string &s2)
{
	long long int i = 0;
	long long int pos1 = -1;
	while (i < s1.size() && i < s2.size())
	{
		if (s1.at(i) != s2.at(i))
		{
			pos1 = i;
			break;
		}
		i++;
	}
	return pos1;
}

long long int iterateB(const string &s1, const string &s2)
{
	long long int i = s1.size() - 1;
	long long int j = s2.size() - 1;
	long long int pos2 = -1;
	while (i >= s1.size() && j >= s2.size())
	{
		if (s1.at(i) != s2.at(j))
		{
			pos2 = j + 1;
			break;
		}
		i--;
		j--;
	}
	return pos2;
}

int main(int argc, char const *argv[])
{
	string s1 = "";
	string s2 = "";

	cin >> s1 >> s2;

	long long int pos1 = iterateF(s1, s2);
	long long int pos2 = iterateB(s1, s2);
	if (pos1 == -1 || pos2 == -1)
	{
		if (s2.size() < s1.size())
		{
			cout << 0 << endl;
			return 0;
		}
		else
		{
			long long int diff_sz = s2.size() - s1.size();
			cout << abs(diff_sz) << endl;
		}
	}
	else
	{
		long long int diff_pos = abs(pos2 - pos1);
		if (pos1 >= pos2) cout << diff_pos + 1 << endl; // overlap!
		else cout << diff_pos << endl; // no overlap
	}

	return 0;
}
