#include <iostream>
#include <string>
using namespace std;
// 数字字符串转整数，如果是数字中有其他字符，返回0
bool STATE = false;
int StrToInt(string str)
{
	string::iterator it = str.begin();
	if (*it == '\0')
		return 0;
	int flag = 1;
	long long ret = 0;
	if (*it == '\0' || str.empty())
		return 0;
	while (*it == ' ')
	{
		it++;
		if (*it == '\0')
			return 0;
	}
	if (*it == '+')
		it++;
	else if (*it == '-')
	{
		it++;
		flag = -1;
	}
	while (it != str.end())
	{
		if (*it > '0' && *it < '9')
		{
			ret = ret * 10 + (*it - '0')*flag;
			it++;
			if (ret > INT_MAX || ret < INT_MIN)
				return 0;//这里可能不一样
		}
		else
			return 0;
	}
	STATE = true;// 正确返回
	return (int)ret;
}
void test()
{
	string s1 = "     -1   a23";
	int ret = StrToInt(s1);
	if (STATE)
		cout << ret << endl;
}
int main()
{
	test();
}