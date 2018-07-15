#include <iostream>
using namespace std;
#include <vector>
// 最大子串
int FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.size() == 1)
		return array[0];
	int sum = 0;
	int cur = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (cur < 0)
			cur = 0;
		cur += array[i];
		if (cur > sum)
			sum = cur;
	}
	return sum;
}
int main()
{
	int arr[] = { 6, -2, -3, 7, -15, 1, 2, 2 };
	vector<int> v(arr, arr + 8);
	FindGreatestSumOfSubArray(v);
	return 0;
}

// 回文串
#include <string>
bool IsHuiwen(string s)
{
	if (s.empty())
		return true;
	int len = s.size();
	for (int i = 0; i < len/2; i++)
	{
		if (s[i] == s[len - i - 1])
			continue;
		else
		{
			string::iterator iter = s.begin() + i;
			s.insert(iter, s[len - i - 1]);
			break;
		}
	}
	len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == s[len - i - 1])
			continue;
		else
			return false;
	}
	return true;
}
int main()
{
	string s;
	while (cin >> s)
	{
		if (IsHuiwen(s))
			cout << "YES" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}


// Fib斐波那契数列，给定一个n值，求斐波那契数列中的数离给定数据最近的步数
#include <iostream>
using namespace std;
int Fib(int n)
{
	if (n == 0 || n == 1)
		return 0;
	int ret = 0;
	int first = 0;
	int second = 1;
	while (1)
	{
		int num = first + second;
		first = second;
		second = num;

		if (n - num > 0)
		{
			ret = n - num;
			continue;
		}
		if (num - n > ret)
			return ret;
		else
			return num - n;
	}
	return ret;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << Fib(n) << endl;
	}
	return 0;
}

#if 0 
// 给n个牛分配苹果，一次只能移动两个苹果，要求n个牛分配相同数量的苹果，求要移动几步
#include <iostream>
using namespace std;
#include <vector>

int GetApple(vector<int> v)
{
	int sum = 0;
	int count = 0;
	int n = v.size();
	for (int i = 0; i<n; i++)
		sum += v[i];
	if (sum < n || sum%n != 0)
		return -1;
	int avg = sum / n;
	for (int i = 0; i<n; i++)
	{
		while (v[i] > avg)
		{
			v[i] -= 2;
			count++;
		}
		if (avg - v[i] == 1)
			return -1;
		while (v[i] < avg)
		{
			v[i] += 2;
			count++;
		}
		if (v[i] - avg == 1)
			return -1;
	}
	return count / 2;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		int ret = GetApple(v);
		cout << ret << endl;
	}
	return 0;
}
#endif
