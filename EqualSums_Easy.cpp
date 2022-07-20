#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

void print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	for (int z = 0; z < t; ++z)
	{
		int n = 0;
		cin >> n;
		std::vector<int> v(n);
		std::vector<vector<int>> map(pow(2, 20));
		bool flag = false; 

		for (int i = 0; i < n; ++i)
		{
			cin >> v.at(i);
		}

		for (int i = 1; i < pow(2, 20); ++i)
		{
			long long int sum = 0;
			std::vector<int> tmp;
			std::bitset<20> myBitset(i);
			for (int j = 0; j < 20; ++j)
			{
				if (myBitset[j] == 1)
				{
					sum += v.at(j);
					tmp.push_back(v.at(j));
				}
			}
			if (map.at(sum).size() != 0)
			{
				cout << "Case #" << (z+1) << ":" << endl;
				print(map.at(sum));
				print(tmp); 
				flag = true;
				break;
			}
			else
			{
				map.at(sum) = tmp;
			}
		}
		if(!flag) cout << "Impossible" << endl;
	}
	

	return 0;
}