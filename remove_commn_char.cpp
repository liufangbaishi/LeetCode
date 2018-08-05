#include <iostream>
#include <string>
using namespace std;
/// 删除公共字符   s2中出现的字符，s1中不出现的字符串
string RemoveChar(string s1, string s2)
{
	if (s2 == "")
		return s1;
	bool hash[256] = { false };
	int index = 0;
	string res;
	for (int i = 0; i<s2.size(); i++)
		hash[s2[i]] = true;
	for (int i = 0; i < s1.size(); i++)
	{
		if (hash[s1[i]] == false)
			res += s1[i];
	}
	return res;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	fflush(stdin);
	getline(cin, s2);
	string s = RemoveChar(s1, s2);
	cout << s << endl;
}