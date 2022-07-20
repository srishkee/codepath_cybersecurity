#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>   
#include <set>
#include <cmath>
#include <math.h>       
using namespace std;


int main(int argc, char const *argv[])
{
	int n = 0, t = 0;
	cin >> n >> t;

	std::vector<vector<int>> v(t);
	for (int i = 0; i < n; i++)
	{
		int c = 0, time1 = 0;
		cin >> c >> time1;

		v.at(time1).push_back(c);
	}

	// Don't need to sort this!
	/*for (int i = 0; i < v.size(); i++)
	{
		sort(v.at(i).begin(), v.at(i).end()); 
	}*/

	vector<int> maxVector;
	for (int i = 0; i < v.size(); i++)
	{
		vector<int> bankVect = v.at(i); 
		if (bankVect.size() > 0) // Can't have empty vector! 
		{
			maxVector.insert(maxVector.end(), bankVect.begin(), bankVect.end());  
			sort(maxVector.begin(), maxVector.end(), std::greater<int>()); // Sort from greatest to least 
			vector<int> tmpMaxVector;
			for (int j = 0; j <= i; j++)
			{
				if (j < maxVector.size())
				{
					tmpMaxVector.push_back(maxVector.at(j)); 
				}
			}
			maxVector = tmpMaxVector; 
		}
	}

	long long int sum = 0;
	for (int i = 0; i < maxVector.size(); i++)
	{
		sum += maxVector.at(i);
	}

	cout << sum << endl;
	
	return 0;
}



