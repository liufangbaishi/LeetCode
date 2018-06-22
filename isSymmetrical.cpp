#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};
// 判断二叉树是不是对称的,前序遍历的结果和对称前序遍历结果相同，就是对称的
bool isSymmetrical(TreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}
bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL && pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;
	return isSymmetrical(pRoot1->left, pRoot2->right)
		&& isSymmetrical(pRoot1->right, pRoot2->left);
}