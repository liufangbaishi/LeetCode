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

// 判断一个二叉树是不是搜索树，利用中序遍历，结果升序判断
// 不能直接用右子树大于根，左子树小于根判断，这种情况 5 | 4 10 | # # 3 11 就不是搜索树
vector<int> inorder;
bool isValidBST(TreeNode *root) {
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	inOrder(root);
	for (int i = 1; i<inorder.size(); i++){
		if (inorder[i] <= inorder[i - 1])
			return false;
	}
	return true;
}

void inOrder(TreeNode* root){
	if (root){
		inOrder(root->left);
		inorder.push_back(root->val);
		inOrder(root->right);
	}
}