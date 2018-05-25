// 数组中一个数字出现次数超过数组长度的一半，求该数字
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
// 创建一个数组，记录原数组出现的次数，找到题目要求的数字
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int size = numbers.size();
	int max = numbers[0];
	int min = numbers[0];
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] < min)
			min = numbers[i];
		if (numbers[i] > max)
			max = numbers[i];
	}
	vector<int> v(max - min + 2);
	for (int i = 0; i < size; i++)
		v[numbers[i]]++;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > size / 2)
			return i;
	}
	return 0;
}
// 排序后，统计出现次数，出现次数超过数组大小的数字应该在数组中间
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	vector<int>::iterator it = numbers.begin();
	sort(it, numbers.end());
	
	for(int i=0; i<numbers.size(); i++)
	{
		
	}
	int mid = numbers.size() / 2;
	if (numbers[mid] == numbers[mid - 1] || numbers[mid] == numbers[mid + 1])
		return numbers[mid];
	else
		return 0;
}
int main()
{
	int arr[9] = { 1, 2, 3, 2, 2, 2, 5, 2, 4 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	int ret = MoreThanHalfNum_Solution(v);
	cout << ret << endl;
	return 0;
}