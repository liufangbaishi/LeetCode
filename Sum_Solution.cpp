#include <iostream>
#include <vector>
using namespace std;
//计算1+2+n,不使用for if 等
int Sum_Solution(int n)   
{
	int i = 1;
	(n>1) && (i = Sum_Solution(n - 1) + n);
	return i;
}
// 或者
int Sum(int n, int& sum)
{
	n&&Sum(n - 1, sum);
	return sum += n;
}
int Sum_Solution(int n)
{
	int sum = 0;
	Sum(n, sum);
	return sum;
}
void test()
{
	Sum_Solution(5);
}