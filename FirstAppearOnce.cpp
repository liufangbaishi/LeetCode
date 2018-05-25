// �ַ����е�һ��ֻ����һ�ε��ַ�
#include <string>
#include <iostream>
using namespace std;
// ��һ�������¼ÿ���ַ����ֵĴ���������ԭ���飬�����ַ������˼���
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
