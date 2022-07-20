#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct compare
{
	bool operator()(const string& s1, const string& s2)
	{
		return (s1.size() > s2.size());
	}
};

struct Node
{
	Node() : val(-1), isLeafNode(false), children(10, NULL) {};
	int val;
	bool isLeafNode;
	vector<Node*> children;
};

void insert(Node* root, string str)
{
	Node* curr = root;
	for (int i = 0; i < str.size(); ++i)
	{
		int idx = stoi(str.substr(i, 1));
		if (curr->children[idx] == NULL)
		{
			Node* n = new Node;
			curr->children[idx] = n;
		}
		curr = curr->children[idx];
	}
	curr->isLeafNode = true;
}

bool search(Node* root, string str)
{
	Node* curr = root;
	for (int i = 0; i < str.size(); ++i)
	{
		int idx = stoi(str.substr(i, 1));
		if (!curr->children[idx]) // If child = NULL 
		{
			return false;
		}
		curr = curr->children[idx];
	}
	return (curr == NULL) ? false : true;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		cin >> n;
		vector<string> v(n);
		for (int j = 0; j < n; j++)
		{
			cin >> v.at(j);
		}

		compare c;
		sort(v.begin(), v.end(), c);

		Node* root = new Node;
		bool flag = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (!search(root, v.at(i))) insert(root, v.at(i));
			else
			{
				flag = true;
				cout << "NO" << endl;
				break;
			}
		}

		if (!flag) cout << "YES" << endl;
	}

	return 0;
}