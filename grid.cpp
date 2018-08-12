#if 0
// 世界杯开幕式会在球场C举行，球场C的球迷看台可以容纳M*N个球迷。
//在球场售票完成后，现官方想统计此次开幕式一共有多少个球队球迷群体，最大的球队球迷群体有多少人。
// 同球队的球迷群体会选择相邻座位，不同球队的球迷群体会选择不相邻的座位。相邻包括前后相邻、左右相邻、斜对角相邻
//给定一个M*N的二维球场，0代表该位置没有坐人，1代表该位置已有球迷，希望输出球队群体个数P，最大的球队群体人数Q


// 深度优先算法
#include <stdio.h>
#include <vector>
using namespace std;
void testDFS(vector<vector<char>> &v, vector<vector<bool>> &visited, int x, int y, int &q)
{
	if (x < 0 || x >= v.size()) // x是竖着的行，y是横着的列
		return;
	if (y < 0 || y >= v[0].size())
		return;
	if (v[x][y] != '1' || visited[x][y])
		return;
	visited[x][y] = true;
	q++;
	testDFS(v, visited, x - 1, y, q);
	testDFS(v, visited, x + 1, y, q);
	testDFS(v, visited, x, y - 1, q);
	testDFS(v, visited, x, y + 1, q);
	testDFS(v, visited, x - 1, y - 1, q);
	testDFS(v, visited, x + 1, y + 1, q);
	testDFS(v, visited, x - 1, y + 1, q);
	testDFS(v, visited, x + 1, y - 1, q);
}
void test(vector<vector<char>> v, int &p, int &q)
{
	if (v.empty() || v[0].empty())
		return;
	int m = v.size();
	int n = v[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false)); //flase是0
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == '1' && !visited[i][j])
			{
				int count = 0;
				testDFS(v, visited, i, j, count);
				p++;
				if (count > q)
					q = count;
			}
		}
	}
}
/*
输入描述：
第一行，2个数字，M及N，使用英文逗号分割; 接下来M行，每行N的数字，使用英文逗号分割;
输出描述:
一行，2个数字，  P及Q，使用英文逗号分割; 其中，P表示球队群体个数，Q表示最大的球队群体人数
*/
int main()
{
	int m, n;
	scanf("%d,%d", &m, &n);
	getchar();
	vector<vector<char>> v;
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			scanf("%c,", &v[i][j]);
		}
		getchar();
	}
	int p = 0; //球队群体个数
	int q = 0; //最大球队的群体个数
	test(v, p, q);
	printf("%d,%d\n", p, q);
	return 0;
}
#endif

/*
leetcode 上类似的 200题 岛屿的个数
*/
/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
可以假设网格的四个边均被水包围。
输入:
11110
11010
11000
00000
输出: 1
*/
#include <vector>
#include <iostream>
using namespace std;
void numbersdfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
{
	if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1' && visited[i][j] == false)
	{
		visited[i][j] = true;
		numbersdfs(grid, visited, i - 1, j);
		numbersdfs(grid, visited, i + 1, j);
		numbersdfs(grid, visited, i, j - 1);
		numbersdfs(grid, visited, i, j + 1);
	}
}
int numIslands(vector<vector<char>>& grid) 
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	int count = 0;
	vector<vector<bool>> visited(m, vector<bool>(n, false)); //没被访问过是false
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false && grid[i][j] == '1')
			{
				numbersdfs(grid, visited, i, j);
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<char>> v; 
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}
	int ret = numIslands(v);
	printf("%d\n", ret);
	return 0;
}