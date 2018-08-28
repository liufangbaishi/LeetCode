// 逆序对
class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.empty())
			return 0;
		int n = data.size();
		vector<int> copy;
		for (int i = 0; i < n; i++)
			copy[i] = data[i];
		long long count = InversePairsCore(data, copy, 0, n-1);
		return count % 1000000007;
	}
	long long InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end)
	{
		if (start == end)
		{
			copy[start] = data[start];
			return 0;
		}
		int mid = (end + start) / 2;  
		long long left = InversePairsCore(copy, data, start, mid);
		long long right = InversePairsCore(copy, data, mid + 1, end);

		int i = mid;
		int j = end;
		int index = end;
		long long count = 0;
		while (i >= start&&j >= mid + 1)
		{
			if (data[i]>data[j])
			{
				copy[index--] = data[i--];
				count += + j - mid;        
			}
			else
				copy[index--] = data[j--];
		}
		for (; i >= start; i--)
			copy[index--] = data[i];
		for (; j >= mid + 1; j--)
			copy[index--] = data[j];
		return left + right + count;
	}
};
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 0 };
	Solution s;
	cout << s.InversePairs(v);
}