#include <iostream>
using namespace std;
#include <vector>
// 二维数组，从左到右，从上到下，都有序，找一个数在不在数组里
bool Find(int target, vector<vector<int>> array) {
	int rows = array.size();
	int cols = array[0].size();
	int row = rows - 1;
	int col = 0;

	while (row >= 0 && col < cols)
	{
		if (target == array[row][col])
			return true;
		else if (target < array[row][col])
			row--;
		else
			col++;
	}
	return false;
}
int main()
{
	int arr[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } };

	vector<vector<int>> array(3);
	for (int i = 0; i < array.size(); i++)
		array[i].resize(3);
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[0].size(); j++)
		{
			array[i][j] = arr[i][j];
		}
	}

	int ret = Find(4, array);
	return 0;
}

