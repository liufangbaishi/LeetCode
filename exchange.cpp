// 给定两个数字  将第一个数字，转换为第二个数字的进制 7 2 -> 111
#include <iostream>
#include <string>
using namespace std;
string Exchange(int m, int n)
{
	string s;
	string res;
	if (m == 0)
	{
		res += '0';
		return res;
	}
	bool flag = false;
	if (m < 0)
	{
		m = -m;
		flag = true;
	}
	while (m)
	{
		int i = m % n;
		switch (i)
		{
		case 10:
			s += 'A'; break;
		case 11:
			s += 'B'; break;
		case 12:
			s += 'C'; break;
		case 13:
			s += 'D'; break;
		case 14:
			s += 'E'; break;
		case 15:
			s += 'F'; break;
		default:
			s += to_string(i);  break;
		}
		m /= n;
	}
	//std::reverse(res.begin(), res.end());
	if (flag == true)
		s += '-';
	for (int i = s.size()-1; i >= 0; i--)
		res += s[i];
	return res;
}
int main()
{
	int m = 0;
	int n = 0;
	while (cin >> m >> n)
	{
		string s = Exchange(m, n);
		cout << s << endl;
	}
	return 0;
}
