#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};
 // 最小的深度
int run(TreeNode *root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL)
		return run(root->right) + 1;
	if (root->right == NULL)
		return run(root->left) + 1;
	int left = run(root->left);
	int right = run(root->right);
	return left > right ? right + 1 : left + 1;
}