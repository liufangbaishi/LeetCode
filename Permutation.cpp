// 字符串的全排列
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
#include <stdio.h>
void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
		printf("%s\n", pStr);
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			Permutation(pStr, pBegin + 1);
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}
void Permutation(char * pStr)
{
	if (pStr == NULL)
		return;
	Permutation(pStr, pStr);
}

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> a;
		if (str.empty())
			return a;
		Permutation(a, str, 0);
		sort(a.begin(), a.end());//按照字典序输出
		return a;
	}
	void Permutation(vector<string> &res, string str, int begin)//遍历第begin位的所有可能性
	{
		//一次遍历的结束条件
		if (begin == str.size() - 1)
		{
			res.push_back(str);
			return;
		}
		for (int i = begin; i<str.size(); i++)
		{
			if (i != begin && str[i] == str[begin])
			{
				continue;//有与begin位重复的字符串不进行交换，跳过
			}
			swap(str[i], str[begin]);
			//当i==begin时，也要遍历其后面的所有字符
			//当i!=begin时，先交换，使第begin位取到不同的可能字符，再遍历后面的字符
			Permutation(res, str, begin + 1);
			swap(str[i], str[begin]);//为了防止重复的情况，还需要将begin处的元素重新换回来
		}
	}
};
int main()
{
	char str[] = "abc";
	Permutation(str);
	Solution s;
	string str1 = "abc";
	s.Permutation(str1);
	return 0;
}