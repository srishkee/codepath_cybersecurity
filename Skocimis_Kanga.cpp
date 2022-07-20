#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       /* log */
using namespace std;


int main(int argc, char const *argv[])
{
	int start = 0, end = 0, mid = 0;
	cin >> start >> mid >> end;
	int dist = 0;
	while (true)
	{
		if (start + 1 == mid && end == mid + 1)
		{
			cout << dist << endl;
			return 0;
		}
		else
		{
			if (mid - start < end - mid)
			{
				start = mid;
				mid++;
			}
			else
			{
				end = mid;
				mid--;
			}
			dist++;
		}
	}
	return 0;
}