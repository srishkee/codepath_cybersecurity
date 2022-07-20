#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <set>
#include <cmath>
using namespace std;


int main(int argc, char const *argv[])
{
	int m = 0;
	cin >> m;
	vector<string> v{ "add", "sub", "mul", "div" };
	for (int z = 0; z < m; ++z)
	{
		int num = 0;
		cin >> num;

		bool flag = false;

		// Addition
		if (4 + 4 + 4 + 4 == num) { cout << "4 + 4 + 4 + 4 = "; flag = true; }
		else if (4 + 4 + 4 - 4 == num) { cout << "4 + 4 + 4 - 4 = "; flag = true; }
		else if (4 + 4 + 4 * 4 == num) { cout << "4 + 4 + 4 * 4 = "; flag = true; }
		else if (4 + 4 + 4 / 4 == num) { cout << "4 + 4 + 4 / 4 = "; flag = true; }

		else if (4 + 4 - 4 + 4 == num) { cout << "4 + 4 - 4 + 4 = "; flag = true; }
		else if (4 + 4 - 4 - 4 == num) { cout << "4 + 4 - 4 - 4 = "; flag = true; }
		else if (4 + 4 - 4 * 4 == num) { cout << "4 + 4 - 4 * 4 = "; flag = true; }
		else if (4 + 4 - 4 / 4 == num) { cout << "4 + 4 - 4 / 4 = "; flag = true; }

		else if (4 + 4 * 4 + 4 == num) { cout << "4 + 4 * 4 + 4 = "; flag = true; }
		else if (4 + 4 * 4 - 4 == num) { cout << "4 + 4 * 4 - 4 = "; flag = true; }
		else if (4 + 4 * 4 * 4 == num) { cout << "4 + 4 * 4 * 4 = "; flag = true; }
		else if (4 + 4 * 4 / 4 == num) { cout << "4 + 4 * 4 / 4 = "; flag = true; }

		else if (4 + 4 / 4 + 4 == num) { cout << "4 + 4 / 4 + 4 = "; flag = true; }
		else if (4 + 4 / 4 - 4 == num) { cout << "4 + 4 / 4 - 4 = "; flag = true; }
		else if (4 + 4 / 4 * 4 == num) { cout << "4 + 4 / 4 * 4 = "; flag = true; }
		else if (4 + 4 / 4 / 4 == num) { cout << "4 + 4 / 4 / 4 = "; flag = true; }


		// Subtraction
		else if (4 - 4 + 4 + 4 == num) { cout << "4 - 4 + 4 + 4 = "; flag = true; }
		else if (4 - 4 + 4 - 4 == num) { cout << "4 - 4 + 4 - 4 = "; flag = true; }
		else if (4 - 4 + 4 * 4 == num) { cout << "4 - 4 + 4 * 4 = "; flag = true; }
		else if (4 - 4 + 4 / 4 == num) { cout << "4 - 4 + 4 / 4 = "; flag = true; }

		else if (4 - 4 - 4 + 4 == num) { cout << "4 - 4 - 4 + 4 = "; flag = true; }
		else if (4 - 4 - 4 - 4 == num) { cout << "4 - 4 - 4 - 4 = "; flag = true; }
		else if (4 - 4 - 4 * 4 == num) { cout << "4 - 4 - 4 * 4 = "; flag = true; }
		else if (4 - 4 - 4 / 4 == num) { cout << "4 - 4 - 4 / 4 = "; flag = true; }

		else if (4 - 4 * 4 + 4 == num) { cout << "4 - 4 * 4 + 4 = "; flag = true; }
		else if (4 - 4 * 4 - 4 == num) { cout << "4 - 4 * 4 - 4 = "; flag = true; }
		else if (4 - 4 * 4 * 4 == num) { cout << "4 - 4 * 4 * 4 = "; flag = true; }
		else if (4 - 4 * 4 / 4 == num) { cout << "4 - 4 * 4 / 4 = "; flag = true; }

		else if (4 - 4 / 4 + 4 == num) { cout << "4 - 4 / 4 + 4 = "; flag = true; }
		else if (4 - 4 / 4 - 4 == num) { cout << "4 - 4 / 4 - 4 = "; flag = true; }
		else if (4 - 4 / 4 * 4 == num) { cout << "4 - 4 / 4 * 4 = "; flag = true; }
		else if (4 - 4 / 4 / 4 == num) { cout << "4 - 4 / 4 / 4 = "; flag = true; }

		// Multiplication
		else if (4 * 4 + 4 + 4 == num) { cout << "4 * 4 + 4 + 4 = "; flag = true; }
		else if (4 * 4 + 4 - 4 == num) { cout << "4 * 4 + 4 - 4 = "; flag = true; }
		else if (4 * 4 + 4 * 4 == num) { cout << "4 * 4 + 4 * 4 = "; flag = true; }
		else if (4 * 4 + 4 / 4 == num) { cout << "4 * 4 + 4 / 4 = "; flag = true; }

		else if (4 * 4 - 4 + 4 == num) { cout << "4 * 4 - 4 + 4 = "; flag = true; }
		else if (4 * 4 - 4 - 4 == num) { cout << "4 * 4 - 4 - 4 = "; flag = true; }
		else if (4 * 4 - 4 * 4 == num) { cout << "4 * 4 - 4 * 4 = "; flag = true; }
		else if (4 * 4 - 4 / 4 == num) { cout << "4 * 4 - 4 / 4 = "; flag = true; }

		else if (4 * 4 * 4 + 4 == num) { cout << "4 * 4 * 4 + 4 = "; flag = true; }
		else if (4 * 4 * 4 - 4 == num) { cout << "4 * 4 * 4 - 4 = "; flag = true; }
		else if (4 * 4 * 4 * 4 == num) { cout << "4 * 4 * 4 * 4 = "; flag = true; }
		else if (4 * 4 * 4 / 4 == num) { cout << "4 * 4 * 4 / 4 = "; flag = true; }

		else if (4 * 4 / 4 + 4 == num) { cout << "4 * 4 / 4 + 4 = "; flag = true; }
		else if (4 * 4 / 4 - 4 == num) { cout << "4 * 4 / 4 - 4 = "; flag = true; }
		else if (4 * 4 / 4 * 4 == num) { cout << "4 * 4 / 4 * 4 = "; flag = true; }
		else if (4 * 4 / 4 / 4 == num) { cout << "4 * 4 / 4 / 4 = "; flag = true; }

		// Division
		else if (4 / 4 + 4 + 4 == num) { cout << "4 / 4 + 4 + 4 = "; flag = true; }
		else if (4 / 4 + 4 - 4 == num) { cout << "4 / 4 + 4 - 4 = "; flag = true; }
		else if (4 / 4 + 4 * 4 == num) { cout << "4 / 4 + 4 * 4 = "; flag = true; }
		else if (4 / 4 + 4 / 4 == num) { cout << "4 / 4 + 4 / 4 = "; flag = true; }

		else if (4 / 4 - 4 + 4 == num) { cout << "4 / 4 - 4 + 4 = "; flag = true; }
		else if (4 / 4 - 4 - 4 == num) { cout << "4 / 4 - 4 - 4 = "; flag = true; }
		else if (4 / 4 - 4 * 4 == num) { cout << "4 / 4 - 4 * 4 = "; flag = true; }
		else if (4 / 4 - 4 / 4 == num) { cout << "4 / 4 - 4 / 4 = "; flag = true; }

		else if (4 / 4 * 4 + 4 == num) { cout << "4 / 4 * 4 + 4 = "; flag = true; }
		else if (4 / 4 * 4 - 4 == num) { cout << "4 / 4 * 4 - 4 = "; flag = true; }
		else if (4 / 4 * 4 * 4 == num) { cout << "4 / 4 * 4 * 4 = "; flag = true; }
		else if (4 / 4 * 4 / 4 == num) { cout << "4 / 4 * 4 / 4 = "; flag = true; }

		else if (4 / 4 / 4 + 4 == num) { cout << "4 / 4 / 4 + 4 = "; flag = true; }
		else if (4 / 4 / 4 - 4 == num) { cout << "4 / 4 / 4 - 4 = "; flag = true; }
		else if (4 / 4 / 4 * 4 == num) { cout << "4 / 4 / 4 * 4 = "; flag = true; }
		else if (4 / 4 / 4 / 4 == num) { cout << "4 / 4 / 4 / 4 = "; flag = true; }

		if (!flag) cout << "no solution" << endl;
		else cout << num << endl;

	}


	return 0;
}

