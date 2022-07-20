#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

	int n = 0, m = 0;
	cin >> n >> m;

	std::vector<int> parent(n+1);
	for (int i = 0; i <= n; ++i)
	{
		parent.at(i) = i;
	}

	for (int i = 0; i < m; ++i)
	{
		int idx1 = 0, idx2 = 0;
		cin >> idx1 >> idx2; 

		unionSet(idx1, idx2, parent);
	}

	bool connected = true;
	for (int i = 1; i < parent.size(); ++i)
	{
		if (!isSameSet(1, i, parent))
		{
			cout << i << endl;
			connected = false; 
		}
	}

	if (connected) cout << "Connected" << endl;

	
	return 0;
}