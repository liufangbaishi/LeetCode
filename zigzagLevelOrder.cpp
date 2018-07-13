#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 之字形打印二叉树
struct TreeNode {
	int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL)
	{}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>> res;
	vector<int> out;
	if (root == NULL)
		return res;
	stack<TreeNode*> s[2];
	int cur = 0; // cur=0的时候，打印奇数层，下一层从左往右入栈
	int next = 1; // cur=1的时候，打印偶数层，下层从右往左入栈
	s[cur].push(root);
	while (!s[cur].empty() || !s[next].empty()) {  // s[cur]打印，s[next]存放数据
		TreeNode *pCur = s[cur].top();
		s[cur].pop();
		out.push_back(pCur->val);
		
		if (cur == 0) 
		{
			if (pCur->left)
				s[next].push(pCur->left);
			if (pCur->right)
				s[next].push(pCur->right);
		}
		else
		{
			if (pCur->right)
				s[next].push(pCur->right);
			if (pCur->left)
				s[next].push(pCur->left);
		}
		if (s[cur].empty())
		{
			res.push_back(out);
			out.clear();
			cur = 1 - cur;
			next = 1 - next;
		}
	}
	return res;
}

int main()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	zigzagLevelOrder(root);
	return 0;
}