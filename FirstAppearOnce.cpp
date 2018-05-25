// 字符串中第一个只出现一次的字符
#include <string>
#include <iostream>
using namespace std;
// 用一个数组记录每个字符出现的次数，遍历原数组，看其字符出现了几次
int FirstAppearOnce(string str)
{
	string::iterator it = str.begin();
	int arr[256] = { 0 };
	for (; it != str.end(); it++)
		arr[*it]++;
	for (it = str.begin(); it != str.end(); it++)
	{
		if (arr[*it] == 1)
			return *it;
	}
	return -1;
}
int main()
{
	string s;
	while (cin >> s)
	{
		char c = FirstOnce(s);
		if (c == -1)
			cout << "-1" << endl;
		else
			cout << c << endl;
	}
	return 0;
}
