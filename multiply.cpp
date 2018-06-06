#include <vector>
#include <iostream>
using namespace std;
// 构建乘积数组
// B[0] = 1 * A[1] * A[2] * A[3] * A[4]
// B[1] = A[0] * 1 * A[2] * A[3] * A[4]
// B[2] = A[0] * A[1] * 1 * A[3] * A[4]
// B[3] = A[0] * A[1] * A[2] * 1 * A[4]
// B[4] = A[0] * A[1] * A[2] * A[3] * 1
// 假设是五个数字，构建方法如上所示，以斜着的1为分界线，先从上到下计算，在从下到上计算
vector<int> multiply(const vector<int>& A) 
{
	int length = A.size();
	vector<int> B(length);
	B[0] = 1;
	for (int i = 1; i < length; i++)
		B[i] = B[i - 1] * A[i - 1];
	int tmp = 1;
	for (int i = length - 2; i >= 0; i--)
	{
		tmp *= A[i + 1];
		B[i] *= tmp;
	}
	return B;
}

void test()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> ret = multiply(v);
}
