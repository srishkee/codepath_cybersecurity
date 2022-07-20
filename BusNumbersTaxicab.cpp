#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int busNum = 0;
	cin >> busNum;

	int max = -1;
	int cube = 100;

	int arr[400000]; // It's not too big!
	for (int i = 0; i < 400000; ++i)
	{
		arr[i] = 0.0;
	}

	for (int i = 0; i <= cube; ++i)
	{
		for (int j = i; j <= cube; ++j) // (j=i) -> don't need to check all cases
		{
			int tmp = (i*i*i) + (j*j*j); //pow() = imprecise 

			if ((tmp <= busNum) && (i != j))
			{
				if (arr[tmp] == 1 && (tmp > max)) 
				{
					max = tmp;
				}
				else arr[tmp] = 1;
			}
		}
	}

	if (max != -1) cout << max << endl;
	else cout << "none" << endl;

	return 0;
}