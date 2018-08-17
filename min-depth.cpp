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

// 二叉树的最小深度
// 递归  
int run(TreeNode *root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	if (root->right == NULL)
		return run(root->left) + 1;
	else if (root->left == NULL)
		return run(root->right) + 1;
	else
	{
		int left = run(root->left);
		int right = run(root->right);
		return (left > right) ? (right + 1) : (left + 1);
	}
}
// 类似于层序遍历的非递归
int run(TreeNode *root) {
	if (root == NULL)
		return 0;
	queue<TreeNode*> q;
	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		level++;
		for (int i = 0; i < size; i++)
		{
			TreeNode* cur = q.front();
			q.pop();
			if (cur->left == NULL && cur->right == NULL)
				return level;
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
	}
	return level;
}
