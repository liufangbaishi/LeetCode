// 包含min函数的栈
#include <iostream>
#include <stack>
using namespace std;
class Solution 
{
public:
	stack<int> mins, s;
	void push(int value) 
	{
		s.push(value);
		if (mins.empty())
		{
			mins.push(value);
		}
		else
		{
			if (mins.top() > value)
				mins.push(value);
			else
				mins.push(mins.top());
		}
	}
	void pop() 
	{
		if (!s.empty())
		{
			mins.pop();
			s.pop();
		}
	}
	int top() 
	{
		if (!s.empty())
			return s.top();
		return 0;
	}
	int min() 
	{
		if (!mins.empty())
			return mins.top();
		return 0;
	}
};
int main()
{
	Solution s; 
	s.push(1);
	s.push(2);
	s.push(0);
	s.push(-1);
	s.pop();
	cout << s.min() << endl;
	cout << s.top() << endl;
	return 0;
}

