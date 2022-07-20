#include <iostream>
#include <string>
#include <vector>
#include <map>
// #include <list>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;

	int ctr = 0;

	if (n <= 3) cout << 1 << endl;

	else
	{
		while (n - 3 >= 0)
		{
			n--;
			ctr++;
		}

		cout << (ctr) << endl;
	}


	return 0;
}