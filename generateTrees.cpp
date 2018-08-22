
// 给定n，求二叉搜索树的个数，动态规划
// 状态方程 res[i] += res[j]*res[i-j-1]

class Solution
{
public:
	int numTree(int n)
	{
		int* res = new int[n + 1];
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
				res[i] += res[j] * res[i - j - 1];
		}
		return res[n];
	}
};



// 给定n，求二叉搜索树
class Solution2 {
public:
	//找到一个数作为根结点，剩余的数分别划入左子树或者右子树
	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode*> res;
		if (n == 0)
			return res;
		return create(1, n);
	}

	vector<TreeNode *>create(int start, int end)
	{
		vector<TreeNode *> res;
		if (start > end)
		{
			res.push_back(NULL);
			return res;
		}
		for (int i = start; i <= end; i++)
		{
			vector<TreeNode *>left = create(start, i - 1);
			vector<TreeNode *>right = create(i + 1, end);
			for (int j = 0; j < left.size(); j++)
			{
				for (int k = 0; k < right.size(); k++)
				{
					TreeNode *r = new TreeNode(i);
					r->left = left[j];
					r->right = right[k];
					res.push_back(r);
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution2 s;
	vector<TreeNode*> v = s.generateTrees(0);
}