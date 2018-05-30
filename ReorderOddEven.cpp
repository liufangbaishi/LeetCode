// 奇数前，偶数后，相对位置不变
// 如果没有要求相对位置不变，可以采用前后指针的方法，从前向后，遇到偶数停下，从后往前，遇到奇数停下，交换两个数字
#include <iostream>
#include <vector>
#include "juzhen.h"
using namespace std;
// 开辟一个空间，遍历两遍，第一遍找到奇数，第二遍找到偶数
// 也可以开辟两个空间，遍历一遍，最后将偶数放到奇数的后面
void reOrderArray(vector<int> &array) 
{
	if (array.empty())
		return;
	int size = array.size();
	vector<int> ret(size);
	int index = 0;
	for (int i = 0; i<size; i++)
	{
		if (array[i] % 2 == 1)
			ret[index++] = array[i];
	}
	for (int i = 0; i<size; i++)
	{
		if (array[i] % 2 == 0)
			ret[index++] = array[i];
	}
	for (int i = 0; i < size; i++)
		array[i] = ret[i];
}


int main()
{
	test();
	/*vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	reOrderArray(v);*/
}