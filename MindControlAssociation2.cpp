#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parentArr[500002], myNumbers[500002];

int findParent(int x) 
{ 
	return parentArr[x] == x ? x : findParent(parentArr[x]);
}

int main()
{
	int n = 0, m = 0, answer = 0;
	cin >> n;
	for (int z = 0; z < n; z++)
	{
		answer = 0;
		for (int i = 0; i <= 500002; i++)
		{
			myNumbers[i] = 1;
			parentArr[i] = i;
		}

		while (n--)
		{
			cin >> m;
			vector<int> a(m, 0);
			int sum = 0;
			for (int i = 0; i<m; i++)
			{
				int val = 0;
				cin >> val;
				a[i] = findParent(val + 1);
			}

			sort(a.begin(), a.end());
			a.erase(unique(a.begin(), a.end()), a.end());

			for (int i = 0; i < a.size(); i++)
			{
				sum += myNumbers[a[i]];
			}
			
			if (sum == m)
			{
				answer++;
				int x = a[0], y;
				for (int i = 1; i < a.size(); i++)
				{
					y = a[i];
					parentArr[y] = x;
					myNumbers[x] += myNumbers[y];
					myNumbers[y] = 0;
				}
			}
		}

	}

	cout << answer << endl;
	return 0;
}