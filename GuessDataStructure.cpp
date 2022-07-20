#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int tmp = 0;
	while (/*tmp < 6*/ !cin.eof())
	{
		int n = 0;
		cin >> n;
		if (cin.eof()) break; // break if EOF; 

		stack<int> myStack;
		queue<int> myQueue;
		priority_queue<int> myPriorityQueue;

		string answer = "";
		bool stackFlag = true, queueFlag = true, PQFlag = true, breakFlag = false;
		for (int i = 0; i < n; ++i)
		{
			int type = 0, num = 0;
			cin >> type >> num;

			if (type == 1)
			{
				myStack.push(num);
				myQueue.push(num);
				myPriorityQueue.push(num);
			}
			else if (type == 2)
			{
				if (myStack.size() == 0) // Can't pop from empty structure!
				{
					answer = "impossible"; 
					breakFlag = true;
				}
				else
				{
					if (num != myStack.top()) stackFlag = false;
					if (num != myQueue.front()) queueFlag = false;
					if (num != myPriorityQueue.top()) PQFlag = false;

					myStack.pop();
					myQueue.pop();
					myPriorityQueue.pop();
				}
			}
		}

		if (!breakFlag)
		{
			if (!stackFlag && !queueFlag && !PQFlag) answer = "impossible";
			else if ((stackFlag && queueFlag) || (stackFlag && PQFlag) || (queueFlag && PQFlag)) answer = "not sure";
			else if (stackFlag) answer = "stack";
			else if (queueFlag) answer = "queue";
			else if (PQFlag) answer = "priority queue"; 
		}
		
		cout << answer << endl;
	}

	return 0;
}