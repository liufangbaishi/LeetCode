// 将一句话的单词进行倒置，标点不倒置，标点不倒置。
// 比如I like beijing.  经过函数后变为beijing. like I

//先整体逆序，再将每个单词逆序
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void Reverse(char* start, char* end)
{
	char tmp = 0;
	while (start <= end)
	{
		swap(*start, *end);
		start++;
		end--;
	}
}
void ReverseString(char* str, int size)
{
	if (str == NULL && *str == NULL)
		return;
	char* start = str;
	char* end = str + size - 1;
	Reverse(start, end);
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			end = str + i - 1;  
			Reverse(start, end);
			start = end + 2;
		}
	}
}

// using string 
void Reverse(string &s, int start, int end)
{
	while (start < end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
}
string ReverseSentence(string str) {
	if (str.empty())
		return str;
	Reverse(str, 0, str.size() - 1);
	int start = 0;
	int end = 0;
	while (end <= str.size())
	{
		if (str[end] == ' ' || (end == str.size() && str[end - 1] != ' '))
		{
			Reverse(str, start, end - 1);
			start = end + 1;
		}
		end++;
	}
	return str;
}

int main()
{
	string s = "I am a student.";
	string res = ReverseSentence(s);
	cout << res << endl;
}
int main()
{
	//char str[] = "I like Beijing.";
	char str[100] = { 0 };
	while (gets(str))
	{
		int size = strlen(str);
		ReverseString(str, size);
		printf("%s\n", str);
	}
}