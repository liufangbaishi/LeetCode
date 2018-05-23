#include <iostream>
#include <vector>
#include <unordered_map>
// 一个数组中有两个数，这两个数之和等于指定的数字，将这两个数对应的索引存放在第二个参数中
using namespace std;
#include "MergeArr.hpp"


//第一种，两层循环，时间复杂度太高
void TwoSum(vector<int>& v1, vector<int>& v2, int key)
{
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v1.size(); j++)
		{
			if (v1[i] + v1[j] == key)
			{
				v2.push_back(i);
				v2.push_back(j);
				return;
			}
		}
	}
}
// 第二种，对于排好序的数组(升序)，如果第一个数字加上最后一个数字等于key，则找到，如果大于key，则指向最后一个数字的
// 指针向前移动，如果小于，则指向第一个数字的指针向后移动
void TwoSum(vector<int>& v1, vector<int>& v2, int key)//这个必须是有序的
{
	int begin = 0;
	int end = v1.size() - 1;
	while (begin < end)
	{
		if (v1[begin] + v1[end] == key)
		{
			v2.push_back(begin);
			v2.push_back(end);
			return;
		}
		else if (v1[begin] + v1[end] < key)
			begin++;
		else
			end--;
	}
}

// 使用哈希先创建一个unordered_map，假设题目给的数组是v1，我们用key减去v1[0]，
// 如果得到的结果在map中，那说明我们找到了题目要求的两个数，如果得到的结果不在map中，
// 我们把v1[0]和它的索引一起插入map中。循环下去，就可以得到结果了。 
// 因为在哈希中查找的效率是O（1）是非常高的
void TwoSum(vector<int>& v1, vector<int>& v2, int key)
{//哈希
	unordered_map<int, int> m;
	for (int i = 0; i < v1.size(); i++)
	{
		unordered_map<int, int>::iterator it = m.find(key - v1[i]);
		if (it != m.end())//找到了
		{
			v2.push_back(m[key - v1[i]]);
			v2.push_back(i);
		}
		else//没找到插入
			m.insert({ v1[i], i });
	}
}

void test()
{
	int arr[] = { 2, 7, 11, 15 };
	int key = 9;
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> v1(arr, arr + size);
	vector<int> v2;
	TwoSum(v1, v2, key);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
}

int main()
{
	test();
}

