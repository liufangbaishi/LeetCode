#include <iostream>
#include <vector>
using namespace std;
struct Point {
	int x;
	int y;
	Point() 
		: x(0), y(0) {}
	Point(int a, int b) 
		: x(a), y(b) {}
};
void check(int &max, int num)
{
	if (max < num)
		max = num;
}
// 线上点的最大个数
int maxPoints(vector<Point> &points)
{
	if (points.size() < 3)
		return points.size();
	int max = 2;
	int size = points.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			int count = 2;
			for (int k = 0; k < size; k++)
			{
				if (k == i || k == j)
					continue;
				// 与两点之一重叠
				if ((points[k].x == points[i].x && points[k].y == points[i].y) ||  
					(points[k].x == points[j].x && points[k].y == points[j].y))
				{
					count++;
					check(max, count);
					continue;
				}
				// 横坐标相等，不能计算斜率
				if (points[k].x == points[j].x)
				{
					if (points[k].x == points[i].x)
					{
						count++;
						check(max, count);
					}
					continue;
				}
				// 计算斜率
				if ((points[k].y - points[j].y) / (float)(points[k].x - points[j].x) ==
					(points[j].y - points[i].y) / (float)(points[j].x - points[i].x))
				{
					count++;
					check(max, count);
				}
			}
		}
	}
	return max;
}
int main()
{
	vector<Point> v;
	v.push_back({ 0, 0 });
	v.push_back({ 1, 1 });
	v.push_back({ 1, -1 });
	maxPoints(v);
	return 0;
}