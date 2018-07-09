#include <iostream>
using namespace std;
#include <string>
#include <vector>
// [1,2,3]  ->   [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
void helper(vector<int> &num, int n, vector<int> &visited, vector<int> &out, vector<vector<int>> &res) {
	if (n == 0) {
		res.push_back(out);
	}
	else {
		for (int i = 0; i < num.size(); i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				out.push_back(num[i]);
				helper(num, n-1, visited, out, res);
				out.pop_back();
				visited[i] = 0;
			}
		}
	}
}
vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int>> res;
	vector<int> out;
	vector<int> visited(num.size(), 0);
	int n = num.size();
	helper(num, n, visited, out, res);
	return res;
}

int main()
{
	int arr[] = { 1, 2, 3 };
	vector<int> v(arr, arr+3);
	permute(v);
	return 0;
}