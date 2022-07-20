#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
//#include <limits.h>
#include <set>
#include <cmath>
using namespace std;


int main(int argc, char const *argv[])
{

	int t = 0; 
	cin >> t;
	vector<pair<long double, string>> set1;
	vector<pair<long double, string>> set2;
	for (int i = 0; i < t; i++)
	{

		string name = "";
		long double time1 = 0.0, time2 = 0.0;
		cin >> name >> time1 >> time2; 

		set1.push_back(make_pair(time1, name)); 
		set2.push_back(make_pair(time2, name));
	}

	// If size = 4!

	sort(set1.begin(), set1.end());
	sort(set2.begin(), set2.end());

	// If no name overlap 
	string name1 = set1.at(0).second; 
	if (name1 != set2.at(0).second && name1 != set2.at(1).second && name1 != set2.at(2).second && name1 != set2.at(3).second)
	{
		long double minTime = 0.0; 
		minTime = (set1.at(0).first + set2.at(0).first + set2.at(1).first + set2.at(2).first); 
		//printf("%.*f\n", 10, minTime);
		cout << setprecision(10) << (set1.at(0).first + set2.at(0).first + set2.at(1).first + set2.at(2).first) << endl;
		cout << set1.at(0).second << endl;
		cout << set2.at(0).second << endl;
		cout << set2.at(1).second << endl;
		cout << set2.at(2).second << endl;
		return 0; 
	}

	long double minTime = 10000.0;
	vector<string> names(1);
	for (int i = 0; i < set1.size(); i++)
	{
		long double totalTime = set1.at(i).first;
		int ctr = 0;
		for (int j = 0; j < 4; j++)
		{
			if (set1.at(i).second != set2.at(j).second && ctr < 3) // If names are not equal 
			{
				totalTime += set2.at(j).first; 
				ctr++;
			}
		}
		if (totalTime < minTime)
		{
			names.at(0) = (set1.at(i).second); 
			minTime = totalTime; 
		}
	}

	cout << setprecision(10) << minTime << endl;
	//printf("%.*f\n", 10, minTime);
	cout << names.at(0) << endl;
	int ctr = 0; 
	for (int i = 0; i < 4; i++)
	{
		if (set2.at(i).second != names.at(0) && ctr < 3)
		{
			cout << set2.at(i).second << endl;
			ctr++; 
		}
	}

	return 0;
}

