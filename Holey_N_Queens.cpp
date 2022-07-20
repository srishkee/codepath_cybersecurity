#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//#define N 8

bool canPlace(const vector<vector<int>> &board, int r, int c, int N)
{
	for (int i = 0; i <= c; ++i) // Re-added '<=' sign here!
	{
		if (board[r][c - i] == true) return false; // already queen there in that spot, behind horizonally
		if ((r - i >= 0) && board[r - i][c - i] == true) return false; // already queen there in that spot, diagonally left & up
		if ((r + i<N) && board[r + i][c - i] == true) return false; // already queen there in that spot, diagonally left & down 

	}
	return true; //found a place
}

int placeQueens(vector<vector<int>> &board, int c, int N)
{
	if (c == N) return 1; // reached end of board successfully! (have placed all queens), print here 
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (board[i][c] != 3 && canPlace(board, i, c, N))
		{
			board[i][c] = true;
			sum += placeQueens(board, c + 1, N);
			board[i][c] = false; // restore the board to initial postition!
		}
	}
	return sum;
}


int main(int argc, char const *argv[])
{
	while (true)
	{
		int N = 0, m = 0;
		cin >> N >> m;

		if (N == 0 && m == 0) break;
		else
		{
			vector<vector<int>> board(N, vector<int>(N, 0));
			for (int z = 0; z < m; z++)
			{
				int row = 0, col = 0;
				cin >> row >> col;
				board[row][col] = 3;
			}

			cout << placeQueens(board, 0, N) << endl;
		}
	}

	/*int N = 8;
	vector<vector<int>> board(N, vector<int>(N, 0));
	cout << placeQueens(board, 0, N) << endl;*/

	return 0;
}