// 小红找子串，找到多出几个，少了几个
// 到底买不买
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2){
		int hash[256] = { 0 };
		int gap = 0;
		for (int i = 0; i < s1.length(); i++)
			hash[s1[i]] += 1;
		for (int i = 0; i < s2.length(); i++)
		{
			if (hash[s2[i]] == 0)
				gap++;
			else             
				hash[s2[i]]--;   //如果结果是no,还有次数的问题
		}
		if (gap == 0)
			cout << "Yes " << s1.length() - s2.length() << endl;
		else
			cout << "No " << gap << endl;
	}
	return 0;
}