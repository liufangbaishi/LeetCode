#include <vector>
#include <set>
void permute(vector<int> &num, int size, vector<int> &visited, vector<int> &out, set<vector<int>> &res)
{
	if (0 == size)
		res.insert(out);
	else
	{
		for (int i = 0; i < num.size(); i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				out.push_back(num[i]);
				permute(num, size-1, visited, out, res);
				out.pop_back();
				visited[i] = 0;
			}
		}
	}
}
//  给定一组数为[1,1,2];   返回结果为[1,1,2],[1,2,1],[2,1,1]
vector<vector<int> > permuteUnique(vector<int> &num) {
	vector<int> out;
	int size = num.size();
	vector<int> visited(size, 0);
	set<vector<int>> s;
	permute(num, size, visited, out, s);
	vector<vector<int>> res(s.begin(), s.end());
	return res;
}
int main()
{
	int arr[] = { 1, 1, 2 };
	vector<int> v(arr, arr + 3);
	permuteUnique(v);
	return 0;
}