// 栈的压入，弹出序列
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	stack<int> s;
	if (pushV.empty() || popV.empty())
		return false;
	vector<int>::iterator it1 = pushV.begin();
	vector<int>::iterator it2 = popV.begin();
	while (it2 != popV.end())
	{
		while (it1 != pushV.end())
		{
			s.push(*it1);
			if (*it1 == *it2)
			{
				s.pop();
				it1++;
				break;
			}
			it1++;
		}
		it2++;
		if (it1 == pushV.end() && it2 != popV.end())
		{
			if (s.top() == *it2)
				s.pop();
			else
				return false;
		}
	}
	if (s.empty())
		return true;
	else
		return false;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 5, 3, 2, 1 };
	vector<int> s1(arr1, arr1 + 5);
	vector<int> s2(arr2, arr2 + 5);
	if(IsPopOrder(s1, s2))
		cout << "是其弹出序列" << endl;
	return 0;
}