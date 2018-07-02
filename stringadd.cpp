
// 字符串加法
#include <string>
#include <iostream>
using namespace std;
string addsame(string s1, string s2)
{
	string ret = "";
	int index = 0; // 进位
	if (s1.size() < s2.size()) //保证s1是长度较长的一个
	{
		string s3 = s1;
		s1 = s2;
		s2 = s3;
	}
	int i = s1.size() - 1;
	int j = s2.size() - 1;
	while (j >= 0)
	{
		int tmp = (s2[j] - '0') + (s1[i] - '0') + index;
		if (tmp > 9)
		{
			ret += to_string(tmp % 10);
			index = tmp / 10;
		}
		else
		{
			ret += to_string(tmp);
			index = 0;
		}
		i--;
		j--;
	}
	if (s1.size() > s2.size())
	{
		for (int k = s1.size() - s2.size() - 1; k >= 0; k--)
		{
			int tmp = (s1[k] - '0') + index;
			if (tmp > 9)
			{
				ret += to_string(tmp % 10);
				index = tmp / 10;
			}
			else
			{
				ret += to_string(tmp);
				index = 0;
			}
		}
	}
	if (index != 0)
		ret += to_string(index);
	reverse(ret.begin(), ret.end());
	return ret;
}
string adddiff(string s1, string s2)// 两个数字符号不同，前面的大于0，后面的小于0
{
	string ret = "";
	int index = 0; // s1是正数，s2是负数
	if (s1.length() >= s2.length() || ( s1.length()==(s2.length() - 1) && s2.substr(1) <= s1 ))
	{   // 1000 -999  1             99 -88
		//正数
		s2 = s2.substr(1);
		int i = s1.length() - 1;
		int j = s2.length() - 1;
		while (j >= 0)
		{
			int tmp = s1[i] - s2[j] - index;
			if (tmp >= 0)
				index = 0;
			while (tmp < 0)
			{
				index = 1;
				tmp = index * 10 + tmp;
			}
			ret += to_string(tmp);
			i--;
			j--;
		}
		if (s1.length() >= s2.length())
		{
			for (int k = s1.length() - s2.length() - 1; k >= 0; k--)
			{
				int tmp = (s1[k]-'0') - index;
				if (tmp >= 0)
					index = 0;
				while (tmp < 0)
				{
					index++;
					tmp += index * 10;
				}
				ret += to_string(tmp);
			}
		}
		while (ret[ret.length() - 1] == '0')
			ret = ret.substr(0, ret.length()-1);
		reverse(ret.begin(), ret.end());
		return ret;
	}
	else
	{
		//负数  11-22  -11 22
		string s3 = "-" + s1;
		string s4 = s2.substr(1);
		ret += '-';
		ret += adddiff(s4, s3);
	}
	return ret;
}

string add(string s1, string s2)
{
	string ret = "";
	if (s1[0] == '-')
	{
		if (s2[0] == '-')
		{
			ret += '-';
			ret += addsame(s1.substr(1), s2.substr(1));
		}
		if (s2[0] >= '0' && s2[0] <= '9')
			ret += adddiff(s2, s1);
	}
	if (s1[0] >= '0' && s1[0] <= '9')
	{
		if (s2[0] == '-')
			ret += adddiff(s1, s2);
		if (s2[0] >= '0' && s2[0] <= '9')
			ret += addsame(s1, s2);
	}
	return ret;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << add(s1, s2) << endl;
		//cout << s1.size() << " " << s1.length() << endl;
	return 0;
}
