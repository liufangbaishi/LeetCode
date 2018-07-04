// search in a range   找目标值的下标范围，找不到返回[-1,-1]，要求时间复杂度是logn
#include <vector>
#include <iostream>
using namespace std;
vector<int> searchRange(int A[], int n, int target) {
	vector<int> ret(2, -1);

	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int mid = begin + ((end - begin) >> 1);
		if (A[mid] < target)
			begin = mid + 1;
		else
			end = mid;
	}
	if (A[end] != target)
		return ret;
	ret[0] = end;
	end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (A[mid] <= target)
			begin = mid + 1;
		else
			end = mid;
	}
	ret[1] = end - 1;
	return ret;
}

int main()
{
	int arr[] = { 5, 7, 8, 8, 8, 10 };
	vector<int> v(arr, arr + 6);
	vector<int> ret = searchRange(arr, 6, 10);
	return 0;
}