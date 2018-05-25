#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
// 旋转字符串 ABCDEFGH -> FGHABCDE
// 用循环直接搬移元素
string rotateString(string A, int n, int p)
{
	int length = A.length();
	string tmp;
	tmp.resize(length);
	int index = 0;
	for (int i = 0; i < n - p - 1; i++)
		tmp[index++] = A[i + p + 1];
	for (int i = 0; i <= p; i++)
		tmp[i + p - 1] = A[i];
	return tmp;
}
// 用迭代器拷贝元素
string rotateString(string A, int n, int p)
{
	if (p > n)
		p %= n;
	string::iterator it = A.begin();
	string ret(it+p+1,A.end());
	ret.insert(ret.end(), it, it + p + 1);
	//for (; p >= 0; p--)
	//	ret.push_back(*it++);
	return ret;
}
// 一次一次的旋转
string rotateString(string A, int n, int p)
{
	int length = A.length();
	for (int i = 0; i <= p; i++)
	{
		char tmp = A[0];
		int index = 0;
		for (index = 0; index < length-1; index++)
			A[index] = A[index + 1];
		A[index] = tmp;
	}
	return A;
}
int main()
{
	string s1 = "ABCDEFGH";
	string ret = rotateString(s1,8,4);
	cout << ret << endl;
}