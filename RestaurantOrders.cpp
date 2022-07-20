#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <cmath>
#include <limits.h>
#include <math.h>
using namespace std;

// Note: Printing via 1-indexing!
void print(std::vector<long long int> v)
{
	for (long long int j = 0; j < v.size(); ++j)
	{
		cout << v.at(j) << " ";
	}
	cout << endl;
}

void recurFindItems(const vector<long long int> &dp, const vector<long long int> &itemPrices, long long int itemPrice) // j = number of items 
{
	vector<long long int> v(2000, 0);

	// Recursively find items 
	while (itemPrice > 0 && itemPrice < dp.size())
	{
		long long int val = dp.at(itemPrice); // Get DP value
		
		long long int newVal = itemPrice - val; // Get new price (14 - 4 = 10)
			v.at(val)++; // Increment val's position in vector
		itemPrice = newVal; // Reset itemPrice to new price
	}

	// Print items 
	for (long long int i = 0; i < itemPrices.size(); i++)
	{
		if (v.at(itemPrices.at(i)) > 0)
		{
			for (long long int j = 0; j < v.at(itemPrices.at(i)); j++)
			{
				cout << (i + 1) << " ";
			}
		}
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
	long long int n = 0;
	cin >> n;
	std::vector<long long int> itemPrices;
	for (long long int i = 0; i < n; ++i)
	{
		long long int num = 0;
		cin >> num;
		itemPrices.push_back(num);
	}

	long long int m = 0;
	cin >> m;
	std::vector<long long int> orderPrices;
	for (long long int i = 0; i < m; ++i)
	{
		long long int num = 0;
		cin >> num;
		orderPrices.push_back(num);
	}

	std::vector<long long int> dp(40000, 0);

	for (long long int j = 0; j < itemPrices.size(); j++)
	{
		for (long long int i = 0; i < dp.size(); i++)
		{
			if (i >= itemPrices.at(j) && i%itemPrices.at(j) == 0) // Check all multiples
			{
				if (dp.at(i) == 0) dp.at(i) = itemPrices.at(j);
				else
				{
					dp.at(i) = -1; // If the spot is already filled 
					if (i + itemPrices.at(j) < dp.size()) dp.at(i + itemPrices.at(j)) = -1;
				}
			}
			else if (dp.at(i) != 0) // If not a multiple but still nonzero
			{
				if (i + itemPrices.at(j) < dp.size())
				{
					if (dp.at(i) == -1) dp.at(i + itemPrices.at(j)) = -1; 
					else // if greater than 0 
					{
						if (dp.at(i + itemPrices.at(j)) == 0) dp.at(i + itemPrices.at(j)) = itemPrices.at(j);
						else if (dp.at(i + itemPrices.at(j)) > 0) dp.at(i + itemPrices.at(j)) = -1; 
					}
				}
			}
		}
	}

	for (long long int i = 0; i < orderPrices.size(); i++)
	{
		if (orderPrices.at(i) < dp.size())
		{
			if (dp.at(orderPrices.at(i)) == 0) cout << "Impossible" << endl;
			else if (dp.at(orderPrices.at(i)) == -1) cout << "Ambiguous" << endl;
			else recurFindItems(dp, itemPrices, orderPrices.at(i));
		}
	}

	return 0;
}