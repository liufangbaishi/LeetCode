#include <iostream>
#include <vector>
using namespace std;
//连续子数组最大和
// 例如{ 3,1,-2,6,-3 }返回8
int GetMax(int a, int b)
{
	return a > b ? a : b;
}
int GetMaxArray(vector<int> arr)// 动态规划的思想  Max(dp[i]) = getMax(Max(dp[i-1])+arr[i], arr[i])
		          //从头开始遍历数组，遍历到数组元素 arr[i] 时，连续的最大的和可能为 Max(dp[i-1])+arr[i]，
		       	  //也可能为 arr[i]，做比较即可得出哪个更大，取最大值。时间复杂度为 n
{
	int size = arr.size();
	int sum = arr[0];
	int max = arr[0];
	for (int i = 1; i < size; i++)
	{                                        
		sum = GetMax(sum + arr[i], arr[i]);  
		if (sum > max)
			max = sum;
	}
	return max;
}

int MaxArray(vector<int> arr) //遍历一遍，当前元素相加，如果小于0，则从重新开始累加，
                              //同时保存之前相加最大的数。
{
	int size = arr.size();
	int max = arr[0];
	int cur = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (cur < 0)
			cur = 0;
		cur = cur + arr[i];
		if (cur > max)
			max = cur;
	}
	return max;
}
int main()
{
	int num = 0;
	cin >> num;
	vector<int> arr;
	arr.resize(num);
	for (size_t i = 0; i < num; i++)
		cin >> arr[i];
	int i = GetMaxArray(arr);
	//int i = MaxArray(arr);
	cout << i << endl;
}