#if 0
// ���籭��Ļʽ������C���У���C�����Կ�̨��������M*N�����ԡ�
//������Ʊ��ɺ��ֹٷ���ͳ�ƴ˴ο�Ļʽһ���ж��ٸ��������Ⱥ�壬�����������Ⱥ���ж����ˡ�
// ͬ��ӵ�����Ⱥ���ѡ��������λ����ͬ��ӵ�����Ⱥ���ѡ�����ڵ���λ�����ڰ���ǰ�����ڡ��������ڡ�б�Խ�����
//����һ��M*N�Ķ�ά�򳡣�0�����λ��û�����ˣ�1�����λ���������ԣ�ϣ��������Ⱥ�����P���������Ⱥ������Q


// ��������㷨
#include <stdio.h>
#include <vector>
using namespace std;
void testDFS(vector<vector<char>> &v, vector<vector<bool>> &visited, int x, int y, int &q)
{
	if (x < 0 || x >= v.size()) // x�����ŵ��У�y�Ǻ��ŵ���
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
	vector<vector<bool>> visited(m, vector<bool>(n, false)); //flase��0
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
����������
��һ�У�2�����֣�M��N��ʹ��Ӣ�Ķ��ŷָ�; ������M�У�ÿ��N�����֣�ʹ��Ӣ�Ķ��ŷָ�;
�������:
һ�У�2�����֣�  P��Q��ʹ��Ӣ�Ķ��ŷָ�; ���У�P��ʾ���Ⱥ�������Q��ʾ�������Ⱥ������
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
	int p = 0; //���Ⱥ�����
	int q = 0; //�����ӵ�Ⱥ�����
	test(v, p, q);
	printf("%d,%d\n", p, q);
	return 0;
}
#endif

/*
leetcode �����Ƶ� 200�� ����ĸ���
*/
/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά���񣬼��㵺���������
һ������ˮ��Χ����������ͨ��ˮƽ�����ֱ���������ڵ�½�����Ӷ��ɵġ�
���Լ���������ĸ��߾���ˮ��Χ��
����:
11110
11010
11000
00000
���: 1
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
	vector<vector<bool>> visited(m, vector<bool>(n, false)); //û�����ʹ���false
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