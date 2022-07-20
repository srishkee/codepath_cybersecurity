#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

	string s = "";
	getline(cin, s);

	std::vector<string> v;

	int i = 0;
	while (i < s.size())
	{
		string tmp = "";
		while ((i < s.size()) && (s.at(i) != '-'))
		{
			tmp += s.at(i);
			i++;
		}
		v.push_back(tmp);
		i++;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i).substr(0, 1);
	}
	cout << endl;

	return 0;
}