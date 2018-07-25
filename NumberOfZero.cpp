
// 阶乘末尾0的个数 https://blog.csdn.net/surp2011/article/details/51168272
#include <iostream>
using namespace std;
int NumberOfZero(int n)
{
	int count = 0;
	while (n)
	{
		n /= 5;
		count += n;
	}
	return count;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int ret = NumberOfZero(n);
		cout << ret << endl;
	}
	return 0;
}