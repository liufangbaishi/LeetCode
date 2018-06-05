#include<iostream>
#include<string>
using namespace std;
// 数组中的重复数字，长度为n，数字为0到(n-1){ 2, 3, 1, 0, 2, 5, 3 }，返回2或3

// 第一种，额外定义一个数组，初始化为0，如果有元素，相应位置置为1，如果遇到了1，那么就找到重复的数字
bool duplicate(int numbers[], int length, int* duplication) {
	if (NULL == numbers || length <= 1)
	{
		duplication = NULL;
		return false;
	}
	int *index = new int[length]; //开辟长度为length的数组初始化为0
	for (int i = 0; i < length; i++)
	{
		int tmp = numbers[i];
		if (0 == index[tmp])
			index[tmp] = 1;
		else if (1 == index[tmp])
		{
			*duplication = numbers[i];
			delete[] index;
			index = NULL;
			return true;
		}
	}
	delete[] index;
	index = NULL;
	duplication = NULL;
	return false;
}

// 第二种，{ 2, 3, 1, 0, 2, 5, 3 }，循环一次，
// 从第一个数开始，2没有在它应该在的位置，与下标为2的元素互换 { 1, 3, 2, 0, 2, 5, 3 }
// 第一个数字1，仍然不在它该在的位置，与下标为1的元素互换 { 3, 1, 2, 0, 2, 5, 3 }
// 第一个数字3，仍然不在它该在的位置，与下标为3的元素互换 { 0, 1, 2, 3, 2, 5, 3 }
// 此时，第一个数字0在该在的位置，向后走，1,2,3也都在该在的位置，
// 再向后下标为4的元素为2，此时，下标为2的元素和下标为4的元素相等，所以，就找到了重复的数字
// 虽然两层循环，但是第二层循环里，一个数字，最多循环两次，
// 就可以到它应该在的位置中，所以，时间复杂度为O(N)
class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length <= 1)
			return false;
		for (int i = 0; i<length; i++)
		{
			if (numbers[i] < 0 || numbers[i] > length-1)
				return false;
		}
		for (int i=0; i<length; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				// swap(numbers[i], numbers[numbers[i]]);
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}
		}
	}
};
void test()
{
	Solution s;
	int num[] = { 2, 3, 1, 0, 2, 5, 3 };
	int dup = 0;
	s.duplicate(num, 7, &dup);
	cout << dup << endl;
};


