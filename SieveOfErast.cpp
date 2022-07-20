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
	int n = 0;
	cin >> n;

	// Boolean vector containing all prime numbers
	vector<bool> isPrime(n);

	// Start at 2 because 2 = first prime number!
	for (int i = 2; i < n; i++) // Initialize all numbers as PRIME
	{
		isPrime.at(i) = true;
	}

	for (int i = 2; i < n; i++) // Loop through all n numbers
	{
		// If already set as "not prime", then continue looping 
		if (!isPrime.at(i)) continue;

		// Otherwise (if prime) mark all multiples of number as "not prime"
		for (int j = i*i; j < n; j+=i)
		{
			isPrime.at(j) = false; 
		}
		cout << i << endl;
	}

	return 0;
}