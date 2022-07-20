#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int r = 0;
		int e = 0;
		int c = 0;

		cin >> r >> e >> c;

		if (e - c > r) cout << "advertise" << endl;
		else if (e - c == r) cout << "does not matter" << endl;
		else if (e - c < r) cout << "do not advertise" << endl;
	}
	return 0;
}