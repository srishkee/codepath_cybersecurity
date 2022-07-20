#include <iostream>
//#include <fstream>
#include <string>
//#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define N 8

bool canPlace(bool board[N][N], int r, int c)
{
	for (int i = 0; i <= c; ++i)
	{
		if (board[r][c - i] == true) return false; // already queen there in that spot, behind horizonally
		if ((r - i >= 0) && board[r - i][c - i] == true) return false; // already queen there in that spot, diagonally left & up
		if ((r + i<N) && board[r + i][c - i] == true) return false; // already queen there in that spot, diagonally left & down 

	}
	return true; //found a place
}

int placeQueens(bool board[N][N], int c)
{
	if (c == N) return 1; // reached end of board successfully! (have placed all queens), print here 
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (canPlace(board, i, c))
		{
			board[i][c] = true;
			sum += placeQueens(board, c+1); 
			board[i][c] = false; // restore the board to initial postition!
		}
	}
	return sum; 
}


int main(int argc, char const *argv[])
{
	bool board[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			board[i][j] = false;
		}
	}

	cout << placeQueens(board, 0) << endl;
	return 0;
}