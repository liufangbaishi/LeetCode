#include <vector>
#include <iostream>
using namespace std;

// search insert position  找目标值的下标，找不到返回应该插入的位置的下标
int searchInsert(int A[], int n, int target) {
	for (int i = 0; i<n; i++){
		int tmp = A[i];
		if (target == A[i])
			return i;
		else if (target < A[i])
			return i;
		else
			continue;
	}
	return n;
}
int main()
{
	int arr[] = { 5, 7, 8, 8, 8, 10 };
	int ret = searchInsert(arr, 4, 7);
	return 0;
}