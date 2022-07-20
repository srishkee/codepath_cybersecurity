#include <iostream>
#include <string>
#include <vector>
//#include <map>
// #include <list>
//#include <algorithm>
using namespace std;

void initSet(int sz, vector<int> &parent)
{
	for (int i = 0; i < sz; ++i)
	{
		parent.at(i) = i;
	}
}

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

	parent.at(idx2) = idx1;
}

bool isSameSet(int i, int j, vector<int> &parent)
{
	int idx1 = findSet(i, parent);
	int idx2 = findSet(j, parent);

	return(idx1 == idx2);
}

//void moveSet(int p, int q, vector<int> &parent)
//{
//	if (findSet(p, parent) == findSet(q, parent)) return;
//	parent[p] = p;
//	unionSet(p, q, parent);
//}


int main(int argc, char const *argv[])
{
	int n = 0, m = 0;
	cin >> n >> m;

	vector<int> parent(n);
	initSet(n, parent);

	vector<int> balance(n);
	for (int i = 0; i < n; i++)
	{
		cin >> balance.at(i); 
	}

	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		
		int balanceA = balance.at(findSet(a, parent));
		int balanceB = balance.at(findSet(b, parent));
		balance.at(findSet(b, parent)) = 0;

		unionSet(a, b, parent);

		balance.at(findSet(a, parent)) += balanceB;
		//if(parent.at(b) != parent.at(parent.at(b))) balance.at(parent.at(b)) = 0;
		//else 
	}

	for (int i = 0; i < balance.size(); i++)
	{
		if (balance.at(i) != 0)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0; 
		}
	}

	cout << "POSSIBLE" << endl;

	return 0; 
}