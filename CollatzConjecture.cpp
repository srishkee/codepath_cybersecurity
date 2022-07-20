#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       /* log */
using namespace std;

int main(int argc, char const *argv[])
{
	while (true)
	{
		long long int AA = 0, BB = 0;
		cin >> AA >> BB;

		if (AA == 0 && BB == 0) break;

		long long int A = AA;
		long long int B = BB;

		std::vector<long long int> v1;
		std::vector<long long int> v2;

		v1.push_back(AA);
		v2.push_back(BB);

		while (A != 1)
		{
			if (A % 2 == 0) A = A / 2;
			else if (A % 2 == 1) A = 3 * A + 1;
			v1.push_back(A);
		}

		while (B != 1)
		{
			if (B % 2 == 0) B = B / 2;
			else if (B % 2 == 1) B = 3 * B + 1;
			v2.push_back(B);
		}

		bool flag = false; 
		if (v1.size() > v2.size())
		{
			for (long long int i = 0; i < v2.size(); ++i)
			{
				for (long long int j = 0; j < v1.size(); ++j)
				{
					if (v2.at(i) == v1.at(j))
					{
						//printf("%d needs %d steps, %d needs %d steps, they meet at %d\n", AA, j, BB, i, v2.at(i));
						cout << AA << " needs " << j << " steps, " << BB << " needs " << i << " steps, they meet at " << v2.at(i) << endl;
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}
		else
		{
			for (long long int i = 0; i < v1.size(); ++i)
			{
				for (long long int j = 0; j < v2.size(); ++j)
				{
					if (v2.at(j) == v1.at(i))
					{
						//printf("%d needs %d steps, %d needs %d steps, they meet at %d\n", AA, i, BB, j, v2.at(j));
						cout << AA << " needs " << i << " steps, " << BB << " needs " << j << " steps, they meet at " << v2.at(j) << endl;
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}
	}

	return 0;
}