#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
	TreeNode(int _val)
	: val(_val)
	, left(NULL)
	, right(NULL)
	{}
	int val;
	TreeNode* left;
	TreeNode* right;
};

// 最大路径和 从任意结点到任意结点
class S
{
public:
	int max = INT_MIN;
	int maxPathSum(TreeNode* root){
		slove(root);
		return max;
	}
	int slove(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int leftVal = slove(root->left); //root以左的最大路径
		int rightVal = slove(root->right);//root以右的最大路径
		int curMax = root->val;
		if (leftVal > 0)
			curMax += leftVal;
		if (rightVal > 0)
			curMax += rightVal;
		if (curMax > max)
			max = curMax;	
		int ret = root->val; // 选择root和root以左较大的一个
		ret = ret>(root->val + leftVal) ? ret : (root->val + leftVal); // 如果leftVal是负数,ret>root->val+leftVal,返回ret
		ret = ret>(root->val + rightVal) ? ret : (root->val + rightVal);
		return ret;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(-10);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(6);
	S s;
	s.maxPathSum(root);
}
