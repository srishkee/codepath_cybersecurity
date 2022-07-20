#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char**argv)
{
	string s = "";
	cin >> s;

	vector<char> v;
	for (int i = 0; i < s.size(); i++)
	{
		//cout << s.at(i) << endl;
		if (s.at(i) == '<') v.pop_back();
		else v.push_back(s.at(i)); 
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i);
	}

	return 0;
}