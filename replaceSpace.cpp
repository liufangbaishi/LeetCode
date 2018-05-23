// ���ַ����еĿո��滻Ϊ%20
// ���ڿո�ֻռһ���ַ����滻���%20ռ�����ַ���ÿ����һ���ո񣬾ͻ�������ַ�
// �����ǰ���������滻�ո���ô�ƶ���������ܶ࣬��������ַ���
// �����Ӻ���ǰ�����������ո��滻Ϊ%20��ֻ��Ҫ����һ���ַ���

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