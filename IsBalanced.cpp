#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 判断一个数是不是平衡二叉树
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};
//第一种方法是递归判断每一个结点的左右子树的高度之差是不是大于2，但是时间复杂度较高
//第二种，用到了后序遍历的思想，降低时间复杂度
bool isBalanced(TreeNode* root, int& depth){ //传引用
	if (root == NULL)
	{
		depth = 0;
		return true;
	}
	int left;
	int right;
	if (isBalanced(root->left, left) && isBalanced(root->right, right)){
		if (left - right < 2 && left - right > -2)
		{
			depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == NULL)
		return true;
	int depth = 0;
	return isBalanced(pRoot, depth);
}

