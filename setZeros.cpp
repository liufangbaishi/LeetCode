#include <vector>
using namespace std;
// 矩阵中有0的那一行那一列置为0，要求空间复杂度为常数阶
void setZeroes(vector<vector<int> > &matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return;
	int row = matrix.size();
	int col = matrix[0].size();
	bool isZero = false;

	for (int j = 0; j < col; j++)//找第一行第一列中是否有0
	{
		if (matrix[0][j] == 0)
		{
			isZero = true;  //第一行有0
			break;
		}
	}
	for (int i = 0; i < row; i++)
	{
		if (matrix[i][0] == 0)
		{
			matrix[0][0] = 0;  //第一列有0
			break;
		}
	}
	for (int i = 1; i < row; i++) //找除第一行第一列是否有0
	{
		for (int j = 1; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for (int i = 1; i < row; i++) //第一行除了第一个元素，其他有0，将那一列置为0，
	                              //第一列除了第一个元素，其他有0，将那一行置为0，
								  //除了第一行第一列，其他位置有0的，行列置为0
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1; j < col; j++)
				matrix[i][j] = 0;
		}
	}
	for (int j = 1; j < col; j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 1; i < row; i++)
				matrix[i][j] = 0;
		}
	}

	if (matrix[0][0] == 0)   
	{
		for (int i = 0; i < row; i++)
			matrix[i][0] = 0;
	}
	if (isZero)
	{
		for (int j = 0; j < col; j++)
			matrix[0][j] = 0;
	}
}

int main()
{
	int arr[4][4] = {
		{1,2,3,4},
		{0,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
	};
	vector<vector<int>> v;
	v.resize(4);
	for (int i = 0; i < 4; i++)
	{
		v[i].resize(4);
		for (int j = 0; j < 4; j++)
			v[i][j] = arr[i][j];
	}
	setZeroes(v);
}