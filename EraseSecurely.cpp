#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	string s1 = "";
	string s2 = "";
	cin >> s1;
	cin >> s2;

	if ((n % 2 != 0))
	{
		for (int i = 0; i < s1.size(); ++i)
		{
			if (s1.at(i) == '0') s1.at(i) = '1';
			else if (s1.at(i) == '1') s1.at(i) = '0';
		}
	}
	if (s1 == s2) cout << "Deletion succeeded" << endl;
	else if (s1 != s2) cout << "Deletion failed" << endl;

	return 0;
}