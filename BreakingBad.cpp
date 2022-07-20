#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <math.h>       
using namespace std;

struct Node
{
	Node() : color(-1), name("") {};
	Node(string name) : color(-1), name(name) {};
	~Node() {};
	int color;
	string name;
	vector<Node*> connections;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0;
	int m = 0;

	map<string, Node> myMap;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string word;
		cin >> word;
		myMap.insert(pair<string, Node>(word, Node(word)));
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string word1;
		string word2;
		cin >> word1 >> word2;
		myMap[word1].connections.push_back(&myMap[word2]);
		myMap[word2].connections.push_back(&myMap[word1]);
	}

	for (map<string, Node>::iterator it = myMap.begin(); it != myMap.end(); it++)
	{
		if (it->second.color == -1)
		{
			queue<Node*> myQueue;
			myQueue.push(&it->second);
			it->second.color = 0;

			while (!myQueue.empty())
			{
				Node* n = myQueue.front();
				myQueue.pop();
				for (int i = 0; i < n->connections.size(); ++i)
				{
					Node* curr = n->connections.at(i);
					if (curr->color == -1)
					{
						myQueue.push(curr);
						curr->color = !(n->color);
					}
					else if (curr->color == n->color)
					{
						cout << "impossible" << endl;
						return 0;
					}
				}
			}
		}
	}

	for (map<string, Node>::iterator it = myMap.begin(); it != myMap.end(); it++)
	{
		if (it->second.color == 0) cout << it->first << " ";
	}
	cout << endl;
	for (map<string, Node>::iterator it = myMap.begin(); it != myMap.end(); it++)
	{
		if (it->second.color == 1) cout << it->first << " ";
	}
}