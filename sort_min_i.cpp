#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 数组排成最小的数   
bool cmp(int a, int b)  // 将排序的比较方式改为，连接成字符串后再比较
{
	string ab = to_string(a) + to_string(b);
	string ba = to_string(b) + to_string(a);
	return ab < ba;
}

string PrintMinNumber(vector<int> numbers) 
{
	int size = numbers.size();
	string ret;
	//for (int i = 0; i < size; i++) //冒泡排序
	//{
	//	for (int j = 0; j < size; j++)
	//	{
	//		string s1 = to_string(numbers[i]);
	//		string s2 = to_string(numbers[j]);
	//		if (cmp(s1, s2)) // 3 32 321   
	//		{
	//			swap(numbers[i], numbers[j]);
	//		}
	//	}
	//}
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < size; i++)
		ret += to_string(numbers[i]);
	return ret;
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(32);
	v.push_back(921);
	string s = PrintMinNumber(v);
	cout << s << endl;
	return 0;
}