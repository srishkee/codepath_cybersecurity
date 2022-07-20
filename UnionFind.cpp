
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

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0, q = 0;
	cin >> n;
	std::vector<int> parent(n);
	for (int i = 0; i < n; ++i)
	{
		parent.at(i) = i;
	}

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		char type = ' ';
		int idx1 = 0, idx2 = 0;
		cin >> type >> idx1 >> idx2;

		if (type == '=') unionSet(idx1, idx2, parent);
		else if (type == '?')
		{
			string ans = (isSameSet(idx1, idx2, parent)) ? "yes" : "no";
			cout << ans << endl;
		}
	}

	return 0;
}