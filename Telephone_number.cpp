///////////////////////////////////////////题目如下///////////////////////////////////////////
//上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。
//例如公司的Help Desk号码是4357，因为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。
//同理，TUT - GLOP就代表888 - 4567、310 - GINO代表310 - 4466。
//NowCoder刚进入外企，并不习惯这样的命名方式，现在给你一串电话号码列表，请你帮他转换成数字形式的号码，并去除重复的部分。
//
//测试用例：
//12
//4873279
//ITS-EASY
//888-4567
//3-10-10-10
//888-GLOP
//TUT-GLOP
//967-11-11
//310-GINO
//F101010
//888-1200
//-4-8-7-3-2-7-9-
//487-3279
////////////////////////////////////////////////////////////////////////////////////////////////
#include <set>
#include <iostream>
#include <string>
using namespace std;
set<string> TelephoneNumber(int n)
{
	set<string> s;
	string str = "";
	string cur = "22233344455566677778889999";
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		string out = "";
		for (int j = 0; j < str.size(); j++)
		{
			if (isdigit(str[j]))
				out += str[j];
			else if (isalpha(str[j]))
				out += cur[str[j] - 'A'];
		}
		out.insert(out.begin() + 3, '-');
		if (out.size() != 8)
			continue;
		s.insert(out);
	}
	return s;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		set<string> s = TelephoneNumber(n);
		for (string str : s)
			cout << str << endl;
		cout << endl;
	}
	return 0;
}