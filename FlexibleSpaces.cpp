#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	// Read in input 
	int w = 0, p = 0;
	cin >> w >> p;

	std::vector<int> v;
	v.push_back(0);
	for (int i = 0; i < p; ++i)
	{
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	v.push_back(w);

	set<int> mySet; // Use set because no duplicate elements inserted

					// Iteratively compute length of all possible partition
	for (int i = 0; i < v.size(); ++i) // Pick outer partition
	{
		for (int j = i; j < v.size(); ++j) // Vary inner partition 
		{
			if (i != j) // Don't compare same element 
			{
				int diff = v.at(j) - v.at(i);
				mySet.insert(diff);
			}
		}
	}

	// Print all possibilities (set uses ordered map so elements are in order)
	for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}