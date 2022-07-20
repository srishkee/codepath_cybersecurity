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
// Use query(b)-query(a-1) to search from [a,b] (may need (a-1) because of 1-indexing!)
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

void buildFenwickTree(std::vector<int> A, int totalMovieNum) 
{
	fenwickTree.resize(A.size() + 1, 0); // Fenwick Tree is 1-indexed! Needs 1 extra bit 

	for (int i = 0; i < totalMovieNum; ++i)
	{
		updateFenwickTree(i, 1); // Build tree through updates 
	}
}

void printFenwickTree()
{
	for (int i = 0; i < fenwickTree.size(); i++)
	{
		cout << fenwickTree.at(i) << '\t';
	}
	cout << endl;
}

int main(int argc, char const *argv[]) // Supercomputer code 
{

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int totalNumMovie = 0, r = 0;
		cin >> totalNumMovie >> r;

		std::vector<int> A((totalNumMovie+1) * 4); // Base vector
		std::vector<int> positionArray((totalNumMovie+1) * 4);
		for (int i = 0; i < totalNumMovie; i++)
		{
			A.at(i) = 1; 
			positionArray.at(i+1) = totalNumMovie - i - 1; 
		}
		
		int movieNum = 4; 
		int nextAvailPos = totalNumMovie;
		
		buildFenwickTree(A, totalNumMovie); 
		printFenwickTree(); 

		cout << totalNumMovie - query(positionArray[movieNum]) << endl;
		//cout << totalNumMovie - query(positionArray[3]) << endl;
		//cout << totalNumMovie - query(positionArray[2]) << endl;
		//cout << totalNumMovie - query(positionArray[1]) << endl;

		updateFenwickTree(positionArray[movieNum], -1);
		positionArray[movieNum] = nextAvailPos;
		nextAvailPos++; 
		updateFenwickTree(positionArray[movieNum], 1);

		//int zz = fenwickTree[0];

		
		/*cout << totalNumMovie - query(positionArray[1]) << endl;
		cout << totalNumMovie - query(positionArray[2]) << endl;
		cout << totalNumMovie - query(positionArray[3]) << endl;
		cout << totalNumMovie - query(positionArray[4]) << endl;*/

		//int z = 0;

		//for (int i = 0; i < r; i++)
		//{
		//	int movieNum = 0;
		//	cin >> movieNum;
		//	int numMoviesFront = totalNumMovie - query(totalNumMovie - movieNum); // -2 = -1 (Fenwick Querying) -1(1-indexing)
		//	cout << numMoviesFront << endl;

			//updateFenwickTree(positionArray.at(totalNumMovie - movieNum), -1);
			//updateFenwickTree(nextAvailPos - 1, 1); 
			//positionArray.at(movieNum) = nextAvailPos; 
			//nextAvailPos++; 

			//int c = fenwickTree[0];

		//}
	}

	/*int n = 0, k = 0;
	cin >> n >> k;
	std::vector<int> A(n + 1);
	buildFenwickTree(A);*/

	//for (int i = 0; i < k; i++)
	//{
	//	string command = "";
	//	int n1 = 0, n2 = 0;
	//	cin >> command >> n1;

	//	if (command == "F")
	//	{
	//		A.at(n1 - 1) = !A.at(n1 - 1); // Toggle bit 
	//		int actualVal = (A.at(n1 - 1) == 0) ? -1 : 1;
	//		updateFenwickTree(n1 - 1, actualVal);
	//	}
	//	else if (command == "C")
	//	{
	//		cin >> n2;
	//		int bitSet = query(n2 - 1) - query(n1 - 2); // -2 = -1 (Fenwick) -1(1-indexing)
	//		cout << bitSet << endl;
	//	}

	//}

	return 0;
}