#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "";
	cin >> s;

	long long int sum = 0;
	long long int pos0 = 0;
	long long int pos1 = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s.at(i) == '0')
		{
			sum += (i - pos0);
			pos0++;
			pos1++;
		}
		else if (s.at(i) == '1')	
		{
			sum += (i - pos1);
			pos1++;
		}
	}

	cout << sum << endl;
		return 0;
}