#include <iostream>
#include <math.h>
// #include <vector>
// #include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{

	while (!cin.eof())
	{
		long long int n1 = 0, n2 = 0;
		cin >> n1;

		if (cin.eof()) break;

		cin >> n2;

		cout << abs(n1 - n2) << endl;
	}
	return 0;
}