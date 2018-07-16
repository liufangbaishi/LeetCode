#include <iostream>
using namespace std;
#include <string>
//void sortColors(int A[], int n) {
//	int count[3] = { 0 };
//	int index = 0;
//	for (int i = 0; i<n; i++)
//		count[A[i]]++;
//	for (int i = 0; i<3; i++)
//	{
//		for (int j = 0; j<count[i]; j++)
//			A[index++] = i;
//	}
//}

void sortColors(int A[], int n)
{
	int start = 0;
	int end = n - 1;
	for (int i = 0; i <= end; i++)
	{
		if (A[i] == 0)
			swap(A[i], A[start++]);
		else if (A[i] == 2)
			swap(A[i--], A[end--]);
	}
}
void test()
{
	int A[] = { 2, 1, 1, 1, 1, 0, 2, 0 ,1 };
	sortColors(A, 9);
	for (int i = 0; i < 9; i++)
		cout << A[i] << " ";
	cout << endl;
}