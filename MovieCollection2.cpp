#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Implemented via Fenwick Tree! 

void updateFenwickTree(long long int  pos, long long int  val, vector< long long int > &fenwickTree)
{
	pos++;
	while (pos < fenwickTree.size() && pos > 0)
	{
		fenwickTree.at(pos) += val;
		pos += pos & (-pos); // 2's complement
	}
}

// Goes from 0->pos 
// Use query(b)-query(a-1) to search from [a,b] (may need (a-1) because of 1-indexing!)
long long int  query(long long int  pos, vector< long long int > &fenwickTree)
{
	pos++;
	long long int  answer = 0;
	while (pos > 0 && pos < fenwickTree.size())
	{
		answer += fenwickTree.at(pos);
		pos -= pos & (-pos); // 2's complement
	}
	return answer;
}

void buildFenwickTree(std::vector< long long int > A, long long int  totalMovieNum, vector< long long int > &fenwickTree)
{
	for (long long int i = 0; i < totalMovieNum; ++i)
	{
		updateFenwickTree(i, 1, fenwickTree); // Build tree through updates 
	}
}

void printFenwickTree(const vector< long long int > &fenwickTree)
{
	for (long long int i = 0; i < fenwickTree.size(); i++)
	{
		cout << fenwickTree.at(i) << '\t';
	}
	cout << endl << endl;
}

int main(int  argc, char const *argv[]) // Supercomputer code 
{
	long long int  t = 0;
	cin >> t;
	for (long long int k = 0; k < t; k++)
	{
		long long int  totalNumMovie = 0, r = 0;
		cin >> totalNumMovie >> r;

		std::vector< long long int > A(400000); // Base vector
		std::vector< long long int > positionArray(400000); // Position Array
		std::vector< long long int > fenwickTree(400001); // Fenwick Tree!

		for (long long int i = 0; i < totalNumMovie; i++)
		{
			A.at(i) = 1; // Initialize base array 
			positionArray.at(i + 1) = totalNumMovie - i - 1; // Initialize position Array backwards 
		}

		long long int  nextAvailPos = totalNumMovie;
		buildFenwickTree(A, totalNumMovie, fenwickTree);
		for (long long int j = 0; j < r; j++)
		{
			long long int  movieNum = 0;
			cin >> movieNum;

			cout << totalNumMovie - query(positionArray[movieNum], fenwickTree) << " "; // Print number of movies in front

			updateFenwickTree(positionArray[movieNum], -1, fenwickTree); // Remove movie from stack
			positionArray[movieNum] = nextAvailPos; // Update the movie's position (not really removing it from stack)
			nextAvailPos++; // Update most recent position
			updateFenwickTree(positionArray[movieNum], 1, fenwickTree); // Add movie to end of stack 
		}
		cout << endl;
	}

	return 0;
}