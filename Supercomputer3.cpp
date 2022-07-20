#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<int> fenwickTree;

// Fenwick Tree! 

void updateFenwickTree(int pos, int val)
{
	pos++;

	while (pos < fenwickTree.size())
	{
		fenwickTree.at(pos) += val;
		pos += pos & (-pos); // 2's complement
	}

}

// Goes from 0->pos 
int query(int pos)
{
	pos++;
	int answer = 0;
	while (pos > 0)
	{
		answer += fenwickTree.at(pos);
		pos -= pos & (-pos); // 2's complement
	}
	return answer;
}

void buildFenwickTree(std::vector<int> A)
{
	fenwickTree.resize(A.size() + 1, 0); // Fenwick Tree is 1-indexed! Needs 1 extra bit 

	for (int i = 0; i < A.size(); ++i)
	{
		updateFenwickTree(i, A.at(i)); // Build tree through updates 
	}
}

int main(int argc, char const *argv[])
{

	//buildFenwickTree(A);
	//cout << query(4)-query(2) << endl;

	int n = 0, k = 0;
	cin >> n >> k; 
	std::vector<int> A(n+1);
	buildFenwickTree(A); 

	for (int i = 0; i < k; i++)
	{
		string command = "";
		int n1 = 0, n2 = 0;
		cin >> command >> n1;

		if (command == "F")
		{
			A.at(n1 - 1) = !A.at(n1 - 1); // Toggle bit 
			int actualVal = (A.at(n1 - 1) == 0) ? -1 : 1; 
			updateFenwickTree(n1 - 1, actualVal); 
		}
		else if (command == "C")
		{
			cin >> n2;
			int bitSet = query(n2 - 1) - query(n1 - 2); // -2 = -1 (Fenwick) -1(1-indexing)
			cout << bitSet << endl;
		}

		int c = fenwickTree[0];

	}

	return 0;
}