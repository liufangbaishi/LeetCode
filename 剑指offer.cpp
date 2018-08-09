#include <iostream>
using namespace std;
#include <vector>
#include <string>
#if 0
//////////////////////////////替换空格///////////////////////////
void replaceSpace(char *str, int length) 
{
	int blankCount = 0;
	int oldlength = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		oldlength++;
		if (isspace(str[i]))
			blankCount++;
	}
	int newlength = oldlength + 2 * blankCount;
	while (newlength >= 0 && newlength > oldlength)
	{
		if (!isspace(str[oldlength]))
			str[newlength--] = str[oldlength--];
		else
		{
			str[newlength--] = '0';
			str[newlength--] = '2';
			str[newlength--] = '%';
			oldlength--;
		}
	}
}
void test()
{
	char str[1024] = "hello world";
	replaceSpace(str, 1024);
	cout << str << endl;
}

///////////////////前序和中序重构二叉树//////////////////////
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) 
		: val(x), left(NULL), right(NULL) 
	{}
};
class Solution {
public:
	TreeNode* Construct(vector<int> &pre, vector<int> &vin, int &start, int &end, int &index)
	{
		if (start >= end || pre.empty() || vin.empty())
			return NULL;
		TreeNode* root = new TreeNode(pre[index]);
		int i = 0;
		for (i = start; i < end; i++)
		{
			if (vin[i] == pre[index])
				break;
		}
		index++;
		int tmp = i + 1;
		root->left = Construct(pre, vin, start, i, index);
		root->right = Construct(pre, vin, tmp, end, index);
		return root;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		if (pre.empty() || vin.empty())
			return NULL;
		int start = 0;
		int end = pre.size();
		int index = 0;
		return Construct(pre, vin, start, end, index);
	}
};
void test_tree()
{
	Solution s;
	int pre[] = { 1, 2, 3, 4, 5, 6, 7 };
	int in[] = { 3, 2, 4, 1, 6, 5, 7 };
	vector<int> preorder(pre, pre + 7);
	vector<int> inorder(in, in + 7);
	TreeNode* root = s.reConstructBinaryTree(preorder, inorder);
}

///////////////////////////////////////机器人的运动范围////////////////////////////////////
class Solution {
public:
	int getDigit(int num)
	{
		int sum = 0;
		while (num)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
	bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
	{
		if (row >= 0 && col >= 0 && row < rows && col < cols && !visited[row*cols + col]\
			&& getDigit(row) + getDigit(col) <= threshold)
			return true;
		return false;
	}
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
	{
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited))
		{
			visited[row*cols + col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)\
				+ movingCountCore(threshold, rows, cols, row, col - 1, visited)\
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited)\
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
		}
		return count;
	}
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows <= 0 || cols <= 0)
			return 0;
		bool* visited = new bool[rows * cols];
		for (int i = 0; i < rows*cols; i++)
			visited[i] = false;
		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		delete[] visited;
		return count;
	}
};

///////////////////////////////////旋转数组中最小的数字///////////////////////////
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int begin = 0;
		int end = rotateArray.size() - 1;
		int mid = begin;
		while (rotateArray[begin] >= rotateArray[end])
		{
			if (end - begin == 1)
			{
				mid = end;
				break;
			}
			mid = (begin + end) / 2;
			if (rotateArray[begin] == rotateArray[end] && rotateArray[mid] == rotateArray[end]) 
				return MinInOrder(rotateArray, begin, end);  // 数组中第一个数字，最后一个数字，中间的数字都相等，
			                                                 // 比如1,1,1,0,1和1,0,1,1,1
			if (rotateArray[mid] >= rotateArray[begin])
				begin = mid;
			else if (rotateArray[mid] <= rotateArray[end])
				end = mid;
		}
		return rotateArray[mid];
	}
	int MinInOrder(vector<int> rotateArray, int begin, int end)
	{
		int num = rotateArray[0];
		for (int i = begin + 1; i <= end; i++)
		{
			if (num > rotateArray[i])
				num = rotateArray[i];
		}
		return num;
	}
};
void test()
{
	Solution s;
	int arr[] = { 6501, 6828, 6963, 7036, 7422, 7674, 8146, 8468, 8704, 8717,
		9170, 9359, 9719, 9895, 9896, 9913, 9962, 154, 293, 334, 492, 1323, 1479,
		1539, 1727, 1870, 1943, 2383, 2392, 2996, 3282, 3812, 3903, 4465, 4605, 4665,
		4772, 4828, 5142, 5437, 5448, 5668, 5706, 5725, 6300, 6335 };
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> v(arr, arr + size);
	int num = s.minNumberInRotateArray(v);
}
#endif

/////////////////////////////////////二维数组的最小路径///////////////////////////////
#include <algorithm>
int minimumTotal(vector<vector<int>>& triangle)//从上到下，改变数组中的值
{
	int size = triangle.size();
	for (int i = 1; i<size; i++)
	{
		for (int j = 0; j<triangle[i].size(); j++)
		{
			if (j == 0)
				triangle[i][j] += triangle[i - 1][j];
			else if (j == triangle[i].size() - 1)
				triangle[i][j] += triangle[i - 1][j - 1];
			else
				triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}
	int ret = triangle[size - 1][0];
	for (int i = 1; i<size; i++)
	{
		if (ret > triangle[size - 1][i])
			ret = triangle[size - 1][i];
	}
	return ret;
}
	
//int minimumTotal(vector<vector<int> > &triangle) //从下到上，没有改变数组中的值
//{
//	int n = triangle.size();
//	vector<int> minlen(triangle.back());
//	for (int layer = n - 2; layer >= 0; layer--) // For each layer
//	{
//		for (int i = 0; i <= layer; i++) // Check its every 'node'
//		{
//			minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
//		}
//	}
//	return minlen[0];
//}
//void test()
//{
//	vector<vector<int>> v;
//	int arr[][4] = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 0, 1, 8, 3 } };
//	v.resize(4);
//	for (int i = 0; i < v.size(); i++)
//	{
//		v[i].resize(i + 1);
//		for (int j = 0; j < v[i].size(); j++)
//			v[i][j] = arr[i][j];
//	}
//	int ret = minimumTotal(v);
//	cout << ret << endl;
//}

#if 0
// 合并两个链表
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{}
};
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return (pHead1 == NULL) ? pHead2 : pHead1;
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	ListNode* pNewHead = NULL;
	ListNode* pTail = NULL;
	if (cur1->val > cur2->val)
	{
		pNewHead = cur2;
		pTail = pNewHead;
		cur2 = cur2->next;
	}
	else
	{
		pNewHead = cur1;
		pTail = pNewHead;
		cur1 = cur1->next;
	}
	pTail->next = Merge(cur1, cur2);
	return pNewHead;
}
void test()
{
	ListNode* cur1 = new ListNode(2);
	ListNode* cur2 = new ListNode(3);
	Merge(cur1, cur2);
}

#endif

#if 0
///////////////////////////////////////给定两个数，求一个数的另一个数次方///////////////////////////
bool flag = false; //如果出错0的负数次方，flag为true
double PowerWithExponent(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; i++)
		result *= base;
	return result;
}
double Power(double base, int exponent) {
	if (abs(base)<0.0000001 && exponent<0)
	{
		flag = true;
		return 0.0;
	}
	int tmp = exponent;
	if (exponent < 0)
		tmp = -exponent;
	double result = PowerWithExponent(base, tmp);
	if (exponent < 0)
		result = (1.0 / result);
	return result;
}
void test()
{
	Power(2, -3);
}
#endif
#if 0
/////////////////////////////判断一个二叉树是不是另一个树的子树////////////////////////////////////////////
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL)
	{}
};
bool SubTree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (!(pRoot1->val == pRoot2->val))
		return false;
	return SubTree(pRoot1->left, pRoot2->left) && SubTree(pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;
	if (pRoot2 == NULL || pRoot1 == NULL)
		return false;
	if (pRoot1->val == pRoot2->val)
		result = SubTree(pRoot1, pRoot2);
	if (!result)
		result = HasSubtree(pRoot1->left, pRoot2);
	if(!result)
		result = HasSubtree(pRoot1->right, pRoot2);
	return result; 
}

int main()
{
	TreeNode* pRoot1 = new TreeNode(8);
	pRoot1->left = new TreeNode(8);
	pRoot1->right = new TreeNode(7);
	pRoot1->left->left = new TreeNode(9);
	pRoot1->left->right = new TreeNode(2);
	pRoot1->left->right->left = new TreeNode(4);
	pRoot1->left->right->right = new TreeNode(7);
	TreeNode* pRoot2 = new TreeNode(8);
	pRoot2->left = new TreeNode(9);
	pRoot2->right = new TreeNode(2);
	bool res = HasSubtree(pRoot1, pRoot2);
	cout << res << endl;
	//test();
}

#endif

// 顺时针打印矩阵
void print(vector<vector<int> > matrix, int cols, int rows, int start, vector<int> &res, int &index)
{
	int endx = cols - 1 - start;
	int endy = rows - 1 - start;
	for (int i = start; i <= endx; i++)
		res[index++] = matrix[start][i];
	if (start < endy)
	{
		for (int i = start + 1; i <= endy; i++)
			res[index++] = matrix[i][endx];
	}
	if (start < endx && start < endy)
	{
		for (int i = endx - 1; i >= start; i--)
			res[index++] = matrix[endy][i];
	}
	if (start < endx && start < endy - 1)
	{
		for (int i = endy - 1; i > start; i--)
			res[index++] = matrix[i][start];
	}
}
vector<int> printMatrix(vector<vector<int> > matrix)
{
	vector<int> res;
	if (matrix.empty())
		return res;
	int rows = matrix.size();
	int cols = matrix[0].size();
	int start = 0;
	int index = 0;
	res.resize(rows*cols);
	while (rows > start * 2 && cols > start * 2)
	{
		print(matrix, cols, rows, start, res, index);
		++start;
	}
	return res;
}

int main()
{
	vector<vector<int>> v{ { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 } };
	vector<int> res = printMatrix(v);
}
