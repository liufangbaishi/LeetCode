
// 输入一个字符串，能否通过增加一个字符使其变成回文串
// 例如:fpypyp  增加一个字符变成回文串，那么删除一个字符也可以   abeba
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool IsHuiWen(string s)
{
	string tmp = s;
	reverse(s.begin(), s.end()-1);
	return tmp == s;
}
int main()
{
	string s;
	while (cin >> s)
	{
		bool flag = false;
		if (s == "")
			cout << "YES" << endl;
		
		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			string tmp = s;
			for (int j = i; j < len; j++)
				tmp[j] = tmp[j + 1]; 
			if (IsHuiWen(tmp))
				flag = true;
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
