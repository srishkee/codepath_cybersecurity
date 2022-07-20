#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<vector<char>> v(2000, vector<char>(2000, ' '));

	int i = 1000;
	int j = 1000;

	int min_x = 1000;
	int min_y = 1000;
	int max_x = 1000;
	int max_y = 1000;
	int ctr = 0;

	v.at(i).at(j) = 'S'; // Start
	while (!cin.eof() /*ctr < 21*/) // Check vector ranges?
	{
		string move = "";
		cin >> move;

		if (cin.eof()) break; 
		else if (move == "up") j--;
		else if (move == "down") j++;
		else if (move == "left") i--;
		else if (move == "right") i++;

		if(v.at(i).at(j) != 'S' && v.at(i).at(j) != 'E') v.at(i).at(j) = '*';

		min_x = (i < min_x) ? i : min_x;
		min_y = (j < min_y) ? j : min_y;

		max_x = (i > max_x) ? i : max_x;
		max_y = (j > max_y) ? j : max_y;
		ctr++;
	}
	v.at(i).at(j) = 'E'; // End 

	// #######
	for (int l = min_x; l < max_x + 3; ++l)
	{
		cout << "#";
	}
	cout << endl;

	// Print Path 
	for (int k = min_y; k <= max_y; ++k)
	{
		cout << "#";
		for (int l = min_x; l <= max_x; ++l)
		{
			cout << v.at(l).at(k);
		}
		cout << "#" << endl;
	}

	// #######
	for (int l = min_x; l < max_x + 3; ++l)
	{
		cout << "#";
	}
	cout << endl;

	return 0;
}