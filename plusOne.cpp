#include <iostream>
#include <vector>
using namespace std;
// 加1
vector<int> plusOne(vector<int> &digits)
{
	int size = digits.size();
	for (int i = size - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			digits[i] += 1;
			return digits;
		}
		else
		{
			digits[i] = 0;
			continue;
		}
	}
	if (*(digits.begin()) == 0)
		digits.insert(digits.begin(), 1);
	return digits;
}


int main()
{
	int arr[] = { 9, 9, 9, 9, 9 };
	vector<int> v(arr, arr + 5);
	plusOne(v);
	return 0;
}