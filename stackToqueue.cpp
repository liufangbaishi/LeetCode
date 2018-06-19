#include <iostream>
#include <stack>
using namespace std;
// 使用两个栈实现一个队列，要求插入的元素是整型
class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		int data = 0;
		if (stack2.size() == 0)
		{
			while (!stack1.empty())
			{
				int tmp = stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
		}
		
		data = stack2.top();
		stack2.pop();
		return data;
	}

private:
	stack<int> stack1;  
	stack<int> stack2;  
};
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int ret[5] = { 0 };
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.pop();
	s.push(4);
	s.pop();
	s.push(5);
	s.pop();
	s.pop();
}