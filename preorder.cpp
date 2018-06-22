#include <iostream>
#include <vector>
using namespace std;
//二叉树的前序遍历
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

vector<int> ret;
vector<int> preorderTraversal(TreeNode *root) //前序遍历递归
{ 
	if (root)
	{
		ret.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
	return ret;
}

#include <stack>
vector<int> preorderTraversal(TreeNode *root)// 前序遍历非递归
{
	vector<int> v;
	if (root == NULL)
		return v;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* pcur = s.top();
		v.push_back(pcur->val);
		s.pop();
		if (pcur->right)
			s.push(pcur->right);
		if (pcur->left)
			s.push(pcur->left);
	}
	return v;
}