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

int main(int argc, char const *argv[])
{
	long long int N = 0, K = 0;
	cin >> N >> K;

	//std::vector<long long int> houses(N, 0);
	std::vector<long long int> v;

	for (long long int i = 0; i < K; ++i)
	{
		long long int num = 0;
		cin >> num;
		v.push_back(num);
		//houses.at(num - 1) = 1; 
	}

	if (K == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	long long int ctr = 0;
	ctr += (v.at(0)) * (N - v.at(0) + 1);

	for (long long int i = 1; i < v.size(); i++)
	{
		long long int diff = v.at(i) - v.at(i - 1);
		long long int path = (N - v.at(i) + 1);

		ctr += (diff * path);
	}
	
	cout << ctr << endl;


	return 0;
}