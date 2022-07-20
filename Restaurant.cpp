#include <iostream>
#include <string>
#include <vector>
#include <stack>
// #include <list>
// #include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	while (true)
	{
		int n = 0;
		cin >> n;

		if (n == 0) break;

		// long long int drop = 0, take = 0;
		stack<int> dropStack;
		stack<int> takeStack;
		for (int i = 0; i < n; ++i)
		{
			string command = "";
			int num = 0;

			cin >> command >> num;

			if (command == "DROP")
			{
				for (int i = 0; i < num; ++i)
				{
					dropStack.push(1);
				}
				cout << "DROP " << 2 << " " << num << endl;
			}
			else if (command == "TAKE")
			{
				if (takeStack.size() < num)
				{
					int dropSz = dropStack.size();
					/*if (dropSz == 10)
					{
						int i = 0;
					}*/
					for (int i = 0; i < dropSz; i++)
					{
						dropStack.pop();
						takeStack.push(1);
					}


					cout << "MOVE" << " 2->1 " << dropSz << endl;

				}
				for (int i = 0; i < num; ++i)
				{
					takeStack.pop();
				}
				cout << "TAKE " << 1 << " " << num << endl;
			}
		}
		cout << endl;
	}
	return 0;
}