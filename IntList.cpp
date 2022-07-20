#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

// Parse input
std::list<long long int> parseString(string s)
{
	std::list<long long int> v;

	// Removes []
	s.erase(s.begin());
	s.pop_back();

	long long int i = 0;
	while (i < s.size())
	{
		string myNum = "";
		while ((i < s.size()) && (s.at(i) != ','))
		{
			myNum += s.at(i);
			i++;
		}
		v.push_back(stoi(myNum));
		i++;
	}
	return v;
}

// Print output 
void printList(const list<long long int>& myList)
{
	long long int i = 0;
	cout << "[";
	for (auto elem : myList)
	{
		if (i == myList.size() - 1) cout << elem;
		else cout << elem << ",";
		i++;
	}
	cout << "]" << endl;
}

// Remove duplicates from string (eg: RRD -> RD)
string removeDuplicates(string s)
{
	int i = 0;
	string returnStr = "";
	while (i < s.size())
	{
		if (s.at(i) == 'D') { returnStr += 'D'; i++; }
		else
		{
			int ctr = 0;
			while (i < s.size() && s.at(i) == 'R')
			{
				ctr++;
				i++;
			}
			if (ctr == 1 || ctr % 2 == 1) returnStr += "R";
		}
	}
	return returnStr;
}

// Change list 
bool convertCommand(const string& s, list<long long int> &myList) // F = front, B = back 
{
	string c = "F";
	int r_ctr = 0; // Number of 'R' characters 
	for (int i = 0; i < s.size(); ++i)
	{
		if (s.at(i) == 'D') // If 'drop' command 
		{
			if (myList.size() > 0) // If list isn't empty
			{
				if (c == "F") myList.pop_front();
				else if (c == "B") myList.pop_back();
			}
			else {cout << "error" << endl; return false;}
		}
		else if (s.at(i) == 'R') // If 'R', reverse popping point 
		{
			c = (c == "F") ? "B" : "F";
			r_ctr++; // Increment 'R' count
		}
	}
	if (r_ctr % 2 == 1) reverse(myList.begin(), myList.end()); // If odd number of 'R' characters, reverse list 
	return true;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		string s = "", arr = "";
		int num = 0;
		cin >> s >> num >> arr;

	 	list<long long int> myList = parseString(arr);
		s = removeDuplicates(s); 
	 	if (convertCommand(s, myList)) // If list isn't empty
	 	{
	 		printList(myList); // Print list 
	 	}
	}

	return 0;
}