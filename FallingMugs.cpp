#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int D = 0;
	cin >> D;

	if (D == 0) cout << 0 << " " << 0 << endl;
	else if (D == 1) cout << 0 << " " << 1 << endl; // 1 number
	else if (D%2 == 0 && D % 4 != 0 && D > 4) // If even D is not divisible by 4
	{
		cout << "impossible" << endl;
	}
	else if(D%2 == 1) // If odd
	{
		int n = (D - 1) / 2;
		cout << (n) << " " << (n + 1) << endl;
	}
	else if (D % 2 == 0 && D > 2)
	{
		int n = (D - 4) / 4;
		cout << (n) << " " << (n + 2) << endl;
	}
	else
	{
		cout << "impossible" << endl;
	}

	return 0;
}