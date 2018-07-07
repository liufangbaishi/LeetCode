//  combinntaions
// 例如，给n=4,k=2，则输出12,13,14,23,24,34;  k=3，则输出123,123,134,234
// 1.递归
void getcombine(int n, int k, int index, vector<int> &tmp, vector<vector<int>> &res)
{
	if (k == tmp.size()) {
		res.push_back(tmp);
		return;
	}
	for (int i = index; i <= n; i++) {
		tmp.push_back(i);
		getcombine(n, k, i + 1, tmp, res);
		tmp.pop_back();
	}
}
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> tmp;
	if (n == 0 || k == 0)
		return res;
	getcombine(n, k, 1, tmp, res);
	return res;
}


// 2. 循环
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> out(k, 0);
	int i = 0;
	while (i >= 0) {
		++out[i];
		if (out[i] > n)
			--i;
		else if (i == k - 1)
			res.push_back(out);
		else 
		{
			++i;
			out[i] = out[i - 1];
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> v;
	v = combine(4, 3);
	return 0;
}