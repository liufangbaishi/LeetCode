// 判断数组是不是二叉搜索树 后序遍历的结果
bool Verify(vector<int> sequence, int size)
{
	int root = sequence[size - 1];
	int i = 0;
	for (; i<size - 1; i++)
	{
		if (sequence[i] > root)
			break;
	}
	int j = i;
	for (; j<size - 1; j++)
	{
		if (sequence[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0)
		left = Verify(sequence, i);

	bool right = true;
	if (i < size - 1)
	{
		vector<int> tmp(sequence.begin() + i, sequence.end());
		right = Verify(tmp, size-1-i);
	}
	return left && right;
}
bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.empty())
		return false;
	int size = sequence.size();
	return Verify(sequence, size);
}
int main()
{
	vector<int> v{ 5, 7, 6, 9, 11, 10, 8 };
	VerifySquenceOfBST(v);
	return 0;
}