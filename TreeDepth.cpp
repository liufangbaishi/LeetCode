#include <iostream>
using namespace std;
////求二叉树的高度 
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};
int TreeDepth(TreeNode* pRoot) 
{
	if (pRoot == NULL)
		return 0;
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	return left>right ? left + 1 : right + 1;
}