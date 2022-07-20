#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	while (true)
	{
		int n = 0;
		cin >> n;
		if (n == 0) break;

		bool flag = 0;

		if (n > 0) // If positive
		{
			for (int i = 32; i >= 2; i--)
			{
				int num = pow(n, 1.0 / i); 
				if (pow(num, i) == n)
				{
					cout << i << endl;
					flag = true;
					break;
				}
			}
		}
		else if (n < 0) // If negative and odd 
		{
			int max = 1;
			int i = 31;
			for (int i = 31; i >= 3; i-=2)
			{
				float num = pow(abs(n), 1.0 / i);
				float myPow = pow(-num, i);
				if ((int)myPow == (n) && floor(num) == ceil(num))
				{
					if (i > max)
					{
						max = i; 
					}
					flag = true;
				}
			}
			cout << max << endl;
		}

		if(!flag) cout << 1 << endl;
	}

	return 0;
}