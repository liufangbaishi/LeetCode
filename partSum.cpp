#include<iostream>
using namespace std;
#define MAX 15
// 输入5 15  5 5 10 2 3
// 输入数字5表示有5个元素的数组，15表示部分和为15，后面5个为数组元素
// 类似于背包问题的动态规划 dp[i][j]表示数组前i个数中和为j的方案数，dp[4][15]表示数组前4个数中，和为15的方案数
// 初始条件：dp[i][0] = 1，如果和为0，那么一个也不选，也是一种方案，所以是1
// j<arr[i] 当前和为j 小于数组中第i个数，和比第i个数还小，只能不选择这第i个数，dp[i][j] = dp[i-1][j]
// j>=arr[i] 当前和为j 大于等于数组中第i个数，那么这时和可以容得下第i个数，前i个数的方案数=前i-1个数的方案(同上)+加上arr[i]的方案数
// 加上arr[i]，那么就是找 前i-1个数中和为(和-arr[i])的方案数，所以dp[i-1][j]+dp[i-1][j-arr[i]]

int main()
{
	int n, m;
	int arr[MAX];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	long long dp[MAX][MAX];
	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		for (int j = 0; j <= m; j++)
		{
			if (j < arr[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
// 用递归的方法
#include<iostream>
#include<vector>
using namespace std;
int n, sum;
void help(vector<int>& a, int pos, int part, int &count)
{
	if (part == sum)
	{
		count++;
		return;
	}
	if (part > sum)
		return;
	for (int i = pos; i < n; i++)
	{
		part += a[i];
		help(a, i + 1, part, count);
		part -= a[i];
	}
}
int main()
{
	cin >> n >> sum;
	vector<int> a(n);
	for (int i = 0; i<n; i++)
		cin >> a[i];
	int count = 0;
	help(a, 0, 0, count);
	cout << count << endl;
	return 0;
}
