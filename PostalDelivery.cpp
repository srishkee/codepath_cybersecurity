#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       /* log */
using namespace std;


bool cmp(const std::pair<int, int>& p1, const pair<int, int>&p2)
{
	if (p1.first > p2.first) return true;
	else return false; 
	//else return (p1.second > p2.second); 
}

int main(int argc, char const *argv[])
{
	int N = 0, K = 0;
	cin >> N >> K;
	std::vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i)
	{
		int pos = 0, numLett = 0;
		cin >> pos >> numLett;
		v.push_back(make_pair(pos, numLett));
	}

	sort(v.begin(), v.end());
	int totalDist = 0;
	bool forward = 0, backward = 0; 
	
		int i = 0; 
		int currPos = 0;
		int currLett = K, totalLett = 0;
		while (i < v.size() && totalLett != v.at(i).second)
		{
			if (currPos == 0)
			{
				currLett = K;
				forward = true; 
				totalDist--;
			}
			else if (currPos == v.at(i).first)
			{
				/*totalLett = (currLett < v.at(i).second - totalLett) ? totalLett + currLett : v.at(i).second;
				currLett = (totalLett + currLett < v.at(i).second) ? 0 : totalLett + currLett - v.at(i).second;*/
				if (currLett + totalLett < v.at(i).second)
				{
					totalLett += currLett; 
					currLett = 0; 
					forward = false;
					backward = true;
				}
				else
				{
					totalLett += currLett;
					currLett = totalLett - v.at(i).second;
					totalLett = 0; 
					i++; 
				}
			}
			if (forward) currPos++;
			else if (backward) currPos--;
			totalDist++;
		}
	
		totalDist += abs(v.at(i-1).first);

	cout << totalDist << endl;

	return 0;
}