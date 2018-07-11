#include <iostream>
using namespace std;
// 不使用+-*/计算两个数相加
int Add(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	int carry = (num1&num2)<<1;
	int sum = num1^num2;
	sum = Add(sum, carry);  //异或的结果是不算进位，与的结果左移1是进位，两者相加(递归)
	return sum;
}
void test()
{
	// 1010 + 1001 = 0011 + 10000 = 10011 + 00000
	int ret = Add(10, 9);
	cout << ret << endl;
}