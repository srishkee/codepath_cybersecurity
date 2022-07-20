#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int people = 0;
	int budget = 0;
	int hotelNum = 0;
	int weeks = 0;

	cin >> people >> budget >> hotelNum >> weeks; 

	int money = -1;
	for (int i = 0; i < hotelNum; ++i)
	{
		int price = 0;
		cin >> price;

		for (int i = 0; i < weeks; ++i)
		{
			int num = 0;
			cin >> num;

			if (num >= people)
			{
				if (money == -1) money = people * price;
				money = (people*price < money) ? people * price : money;
			}
		}
	}

	if (money != -1 && money < budget) cout << money << endl;
	else cout << "stay home" << endl;

	return 0;
}