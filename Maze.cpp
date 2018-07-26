#include <iostream>
#include <vector>
using namespace std;
#define VISITED 2
struct mazePoint
{
	mazePoint(int x, int y)
	: _x(x), _y(y)
	{}
	int _x;
	int _y;
};

class Maze
{
public:
	Maze(int n, int m, int p) //n行，m列
		: _m(m), _n(n), _p(p), _finalP(-200)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> _maze[i][j];
		}
	}
	void printPath()
	{
		for (int i = 0; i < minCostPath.size(); i++)
		{
			cout << "[" << minCostPath[i]._x << "," << minCostPath[i]._y << "]";
			if (i < minCostPath.size() - 1)
				cout << ",";
		}
	}
	void search(int x, int y, int cur_p)
	{
		int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };//左右上下走
		int cost[4] = { -1, -1, -3, 0 };// 左 右 上 下
		pathStack.push_back(mazePoint(x, y));
		_maze[x][y] = VISITED;
		//如果当前点为出口
		if (x == 0 && y == _m-1 && cur_p >= 0)
		{
			if (cur_p > _finalP)// 找到最优的路径，即剩余体力最多的
			{
				_finalP = cur_p;
				minCostPath = pathStack;
			}
			pathStack.pop_back(); //回退到上一个节点
			_maze[x][y] = 1;//0表示有障碍
			return;
		}
		if (cur_p > 0)
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dir[i][0];// 下一步
				int ny = y + dir[i][1];
				int np = cur_p + cost[i];
				if (nx >= 0 && nx < _n && ny >= 0 && ny < _m && _maze[nx][ny] == 1)
				{
					search(nx, ny, np);
				}
			}
		}
		pathStack.pop_back();
		_maze[x][y] = 1;
	}
	void IsGood()
	{
		if (_finalP != -200)
			printPath();
		else
			cout << "Can not escape!" << endl;
	}
private:
	int _m;
	int _n;
	int _p;
	int _maze[10][10];
	int _finalP;//剩余体力
	vector<mazePoint> pathStack;//存储遍历路径
	vector<mazePoint> minCostPath;//最优路径
};
int main()
{
	int n, m, p;
	while (cin >> n >> m >> p)
	{
		Maze maze(n, m, p);
		maze.search(0, 0, p);
		maze.IsGood();
	}
}
