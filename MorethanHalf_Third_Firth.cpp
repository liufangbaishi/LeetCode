#include <iostream>
#include <vector>
using namespace std;
// 出现次数超过1/2的一个数
int MorethanHalf(vector<int> nums)
{
	int count = 1;
	int res = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (count == 0)
		{
			res = nums[i];
			count = 1;
		}
		else if (nums[i] == res)
			count++;
		else
			count--;
	}
	return res;
}
// 出现次数超过1/3的两个数
pair<int, int> majorityElement(const vector<int>& nums) {
	int m, n; //最多存在2个出现次数超过 1/3 的元素
	int cm = 0, cn = 0; //对应 m 和 n 的统计
	for (auto num : nums) {
		if (cm == 0 || num == m) {
			m = num;
			++cm;
		}
		else if (cn == 0 || num == n) {
			n = num;
			++cn;
		}
		else {
			--cm;
			--cn;
		}
	}
	return make_pair(m, n);
}
// 出现次数超过1/4的三个数
void findMoreThanHNumber(int arr[], int *result, int n){
	int count1 = 0, count2 = 0, count3 = 0;
	int a = -1, b = -1, c = -1;

	for (int i = 0; i < n; i++){
		if (arr[i] == a){
			count1++;
		}
		else if (arr[i] == b){
			count2++;
		}
		else if (arr[i] == c){
			count3++;
		}
		else if (count1 == 0){
			a = arr[i];
			count1 = 1;
		}
		else if (count2 == 0){
			b = arr[i];
			count2 = 1;
		}
		else if (count3 == 0){
			c = arr[i];
			count3 = 1;
		}
		else{
			count1--;
			count2--;
			count3--;
		}
	}
	result[0] = a;
	result[1] = b;
	result[2] = c;
}

int main()
{
	int arr1[] = { 1, 2, 2, 2, 2, 2, 3, 4, 5 };
	vector<int> v(arr1, arr1 + 9);
	int ret1 = MorethanHalf(v);

	int arr2[] = { 1, 2, 1, 2, 1, 2, 1, 2, 5 };
	vector<int> v2(arr2, arr2 + 9);
	pair<int, int> ret2 = majorityElement(v2);

	int arr3[] = { 1, 2, 3, 1, 1, 2, 3, 2, 1, 2, 3, 3, 5 };
	int *result = new int[3];
	findMoreThanHNumber(arr3, result, 13);
	return 0;
}


