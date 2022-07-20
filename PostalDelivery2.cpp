#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <cmath>
#include <math.h>       
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
	std::vector<pair<int, int>> vNeg;
	for (int i = 0; i < N; ++i)
	{
		int pos = 0, numLett = 0;
		cin >> pos >> numLett;
		if(pos > 0) v.push_back(make_pair(pos, numLett));
		else if (pos < 0) vNeg.push_back(make_pair(pos, numLett));
	}

	sort(v.begin(), v.end(), cmp); // Greatest to least
	sort(vNeg.begin(), vNeg.end()); // Least to greatest (smaller negative numbers = larger)

	// For positive positions
	std::vector<int> letterPosVect(v.size(), 0);
	int dist = 0;
	int currLett = K;
	int i = 0; 
	for (i = 0; i < v.size(); ++i)
	{
		if(i != 0) dist += abs(v.at(i - 1).first - v.at(i).first);
		else if (i == 0) dist += abs(v.at(i).first); 

		letterPosVect.at(i) += currLett;
		while (letterPosVect.at(i) < v.at(i).second)
		{
			dist += abs(v.at(i).first * 2);
			currLett = K;
			letterPosVect.at(i) += currLett;
		}
		if (letterPosVect.at(i) >= v.at(i).second)
		{
			currLett = letterPosVect.at(i) - v.at(i).second;
			letterPosVect.at(i) -= currLett; 
		}
	}
	if (v.size() > 0) dist += abs(v.at(i - 1).first);

	// For negative positions
	std::vector<int> letterPosVect_Neg(vNeg.size(), 0);
	currLett = K;
	for (i = 0; i < vNeg.size(); ++i)
	{
		if (i != 0) dist += abs(vNeg.at(i - 1).first - vNeg.at(i).first);
		else if (i == 0) dist += abs(vNeg.at(i).first);

		letterPosVect_Neg.at(i) += currLett;
		while (letterPosVect_Neg.at(i) < vNeg.at(i).second)
		{
			dist += abs(vNeg.at(i).first * 2);
			currLett = K;
			letterPosVect_Neg.at(i) += currLett;
		}
		if (letterPosVect_Neg.at(i) >= vNeg.at(i).second)
		{
			currLett = letterPosVect_Neg.at(i) - vNeg.at(i).second;
			letterPosVect_Neg.at(i) -= currLett;
		}
	}
	if(vNeg.size() > 0) dist += abs(vNeg.at(i - 1).first);




	cout << dist << endl;

	return 0;

}