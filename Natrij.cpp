#include <iostream>
#include <string>
using namespace std;

string convertToTime(int arg)
{
	string time = to_string(arg);
	time = (time.size() == 1) ? "0" + time : time;
	return time;
}

string parseTime(int diff)
{
	int hours = diff / 3600;
	int remain = diff % 3600;

	int min = remain / 60;
	int sec = remain % 60;

	string time = convertToTime(hours) + ":" + convertToTime(min) + ":" + convertToTime(sec);

	return time;
}

int main(int argc, char const *argv[])
{
	string t1 = "";
	string t2 = "";

	getline(cin, t1);
	getline(cin, t2);

	int t1_hour = stoi(t1.substr(0, 2));
	int t1_min = stoi(t1.substr(3, 2));
	int t1_sec = stoi(t1.substr(6, 2));

	int t2_hour = stoi(t2.substr(0, 2));
	int t2_min = stoi(t2.substr(3, 2));
	int t2_sec = stoi(t2.substr(6, 2));

	int t1_time = (t1_hour * 3600) + (t1_min * 60) + t1_sec;
	int t2_time = (t2_hour * 3600) + (t2_min * 60) + t2_sec;


	int diff = 0;
	if (t2_time > t1_time)
	{
		diff = t2_time - t1_time;
	}
	else
	{
		diff = ((24 * 3600) - t1_time) + t2_time;
	}

	cout << parseTime(diff) << endl;

	return 0;
}