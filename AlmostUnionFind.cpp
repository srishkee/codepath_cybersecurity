#include <iostream>
#include <string>
#include <vector>
// #include <list>
// #include <algorithm>
using namespace std;

//void initSet(int sz, vector<int> &parent)
//{
//	for (int i = 0; i < sz; ++i)
//	{
//		parent.at(i) = i;
//	}
//}

int findSet(int i, vector<int> &parent)
{
	if (parent.at(i) == i) return i;
	else
	{
		parent.at(i) = findSet(parent.at(i), parent);
		return parent.at(i);
	}
}

void unionSet(int i, int j, vector<int> &parent)
{
	int idx1 = findSet(i, parent);
	int idx2 = findSet(j, parent);

	parent.at(idx1) = idx2;
}

bool isSameSet(int i, int j, vector<int> &parent)
{
	int idx1 = findSet(i, parent);
	int idx2 = findSet(j, parent);

	return(idx1 == idx2);
}

void moveSet(int p, int q, vector<int> &parent)
{
	if (findSet(p,parent) == findSet(q,parent)) return;
	parent[p] = p;
	unionSet(p, q, parent);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string strIn;
	while (!cin.eof()) // maybe 
	{
		int n, m;
		cin >> n;

		if (cin.eof()) break;

		cin >> m; 
		
		std::vector<int> parent(n+1);
		for (int i = 1; i <= n; ++i)
		{
			parent.at(i) = i;
		}

		for (int i = 0; i < m; i++)
		{
			int command, p, q;
			cin >> command >> p;
			if (command == 1)
			{
				cin >> q;
				unionSet(p, q, parent);
			}
			else if (command == 2)
			{
				cin >> q;
				moveSet(p, q, parent);
			}
			else if (command == 3)
			{
				int parentP = findSet(p, parent);
				int sum = 0;
				int count = 0;
				for (int k = 1; k <= n; k++)
				{
					if (findSet(k, parent) == parentP)
					{
						count++;
						sum += k;
					}
				}
				cout << count << " " << sum << endl;
			}
		}
	}

	return 0;
}