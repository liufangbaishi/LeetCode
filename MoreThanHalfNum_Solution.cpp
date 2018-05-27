// 数组中一个数字出现次数超过数组长度的一半，求该数字
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int MoreThanHalfNum_1(vector<int> numbers)
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

int MoreThanHalfNum_2(vector<int> numbers)
{
	vector<int>::iterator it = numbers.begin(); //先排序，该数字一定是中位数，
	sort(it, numbers.end());                   // 再统计该数字出现的次数，判断是否满足超过数组长度的一半
	int mid = numbers.size() / 2;
	int count = 0;
	int size = numbers.size();
	for (int i = 0; i < size; i++)
	{
		if (numbers[mid] == numbers[i])
			count++;
		if (count > size/2)
			return numbers[mid];
	}
	return 0;
}

#include <unordered_map>
int MoreThanHalfNum_3(vector<int> numbers)
{
	unordered_map<int, int> hp;
	int size = numbers.size();
	for (int i = 0; i < size; i++)
	{
		if (hp.find(numbers[i]) != hp.end())//找到了，出现次数+1
			hp.insert(make_pair(numbers[i], hp[numbers[i]]+=1));
		else//没找到，出现次数为1
			hp.insert(make_pair(numbers[i], 1));
		if (hp[numbers[i]] > size / 2)
			return numbers[i];
	}
	return 0;
}

int MoreThanHalfNum_4(vector<int> numbers)
{
	int size = numbers.size();
	int num = numbers[0];
	int count = 1;
	for (int i = 1; i < size; i++)
	{
		if (numbers[i] == num)
			count++;
		else
			count--;
		if (count == 0)
		{
			num = numbers[i];
			count = 1;
		}
	}//第二个数字和第一个不一样，相当于抵消了。因为所求的数字是一半以上的个数，这样抵消，
	 // 最后count如果大于0，那么一定可以得到出现次数最多的数字
	count = 0; // 然后再统计一下这个数字出现的次数，判断是不是超过数组长度的一半
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == num)
			count++;
	}
	if (count * 2 > size)
		return num;
	return 0;
}

int Partion(vector<int>& v, int left, int right)//找中位数
{
	int key = v[right-1];
	int index = left;
	int small = index - 1;
	for (index = left; index < right; index++)
	{
		if (v[index] < key)
		{
			++small;
			if (small != index)
				swap(v[small], v[index]);
		}
	}
	++small;
	swap(v[small], v[right - 1]);
	return small;
}
int MoreThanHalfNum_5(vector<int> numbers)
{
	int left = 0;
	int right = numbers.size();
	int div = Partion(numbers, left, right);
	int mid = right >> 1;
	while (div != mid)//选中的数字经过处理，左边的都比他小，右边都比他大，如果他的位置是n/2，就是中位数
	{
		if (div > mid)
		{
			right = div;
			div = Partion(numbers, left, right);
		}
		else
		{
			left = div + 1;
			div = Partion(numbers, left, right);
		}
	}
	int num = numbers[mid];
	int count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (num == numbers[i])
			count++;
		if (count > numbers.size() / 2)
			return num;
	}
	return 0;
}
int main()
{
	int arr[9] = { 1, 2, 3, 2, 2, 2, 5, 2, 4 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	int ret = MoreThanHalfNum_1(v);
	ret = MoreThanHalfNum_2(v);
	ret = MoreThanHalfNum_3(v);
	ret = MoreThanHalfNum_4(v);
	ret = MoreThanHalfNum_5(v);
	cout << ret << endl;
	return 0;
}