// 将字符串中的空格替换为%20
// 由于空格只占一个字符，替换后的%20占三个字符，每遇到一个空格，就会多两个字符
// 如果从前向后遍历，替换空格，那么移动次数将会很多，遍历多次字符串
// 不妨从后向前遍历，遇到空格，替换为%20，只需要遍历一次字符串

#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string iniString, int length)
{
	int blankCount = 0;
	for (int i = 0; iniString[i] != '\0'; i++)
	{
		if (iniString[i] == ' ')
			blankCount++;
	}
	int newCount = length + blankCount * 2;
	int oldCount = length;
	iniString.resize(newCount);
	while (newCount != oldCount && newCount >= 0)
	{
		if (iniString[oldCount] != ' ')
		{
			iniString[newCount--] = iniString[oldCount--];
		}
		else
		{
			iniString[newCount--] = '0';
			iniString[newCount--] = '2';
			iniString[newCount--] = '%';
			oldCount--;
		}
	}
	return iniString;
}

int main()
{
	string str = "Hello  world";
	string ret = replaceSpace(str, str.length());
	cout << ret << endl;
}