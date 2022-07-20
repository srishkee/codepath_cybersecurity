#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;

	std::vector<int> pivotVect(100000, 0);
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		int num = 0;
		cin >> num;
		v.push_back(num);
	}

	int max = v.at(0);
	for (int i = 0; i < v.size(); ++i)
	{
		int elem = v.at(i);
		if (elem >= max)
		{
			pivotVect.at(elem)++;
			max = elem;
		}
	}

	int min = v.at(v.size() - 1);
	int pivotCtr = 0;
	for (int i = v.size() - 1; i >= 0; --i)
	{
		int elem = v.at(i);
		if (elem <= min)
		{
			min = elem;
			pivotVect.at(elem)++;
			if (pivotVect.at(elem) == 2) pivotCtr++;
		}
	}

	printf("%d\n", pivotCtr);

	return 0;
}