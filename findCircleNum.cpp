
/*
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道
输出所有学生中的已知的朋友圈总数。
示例 1:
输入: 
[[1,1,0],
[1,1,0],
[0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
*/
#include <vector>
using namespace std;
#if 1
// dfs深度优先遍历
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int m = M.size();
		if (m == 0) 
			return 0;
		vector<bool>flag(m, false);
		int circle = 0; // 朋友圈个数
		for (int i = 0; i < m; i++) // 第一次就把和这个人有关系的都遍历了，置为true

		{
			if (flag[i] == false)  // 没有遍历的再去遍历；已经遍历的
			{
				mark(M, flag, i);
				circle++;
			}
 		}
		return circle;
	}
	void mark(vector<vector<int>>& M, vector<bool>&flag, int k)
	{
		flag[k] = true;
		for (int i = 0; i < M.size(); i++)
		{
			if (flag[i] == false && M[k][i] == 1) // 没有遍历的，并且有朋友圈关系的，再去遍历
				mark(M, flag, i);
		}
	}
};
#endif
#if 0
// 并查集的方法
class Solution {
public:
	int FindRoot(vector<int> &fathers, int index)
	{
		while (fathers[index] >= 0)
			index = fathers[index];
		return index;
	}
	void Union(vector<int> &fathers, int i, int j)
	{
		int root1 = FindRoot(fathers, i);
		int root2 = FindRoot(fathers, j);
		if (root1 != root2)
		{
			fathers[root1] += fathers[root2];
			fathers[root2] = root1;
		}
	}
	int Count(vector<int> &fathers)
	{
		int count = 0;
		for (int i = 0; i < fathers.size(); i++)
		{
			if (fathers[i] < 0)
				count++;
		}
		return count;
	}
	int findCircleNum(vector<vector<int>>& M)
	{
		int n = M.size(); 
		vector<int> fathers(n, 0); 
		for (int i = 0; i < n; i++)
			fathers[i] = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (M[i][j] == 1 && i != j)
					Union(fathers, i, j);
			}
		}
		return Count(fathers);
	}
};
#endif

int main()
{
	Solution s;
	vector<vector<int>> v{ 
	{ 1, 0, 1, 0, 1},
	{ 0, 1, 0, 0, 0},
	{ 1, 0, 1, 0, 0},
	{ 0, 0, 0, 1, 0},
	{ 1, 0, 0, 0, 1} };
	s.findCircleNum(v);
}