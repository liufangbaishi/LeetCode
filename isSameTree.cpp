#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

// 判断两个二叉树是不是相等的，树的结构相同，数据也要相同
// 递归实现
bool isSameTree(TreeNode *p, TreeNode *q) {
	if (p == NULL && q == NULL)
		return true;
	if (p->val != q->val || (p && q == NULL) || (q&&p == NULL))
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
// 非递归实现，利用二叉树的先序遍历，或者中序、后序遍历
bool isSameTree(TreeNode *p, TreeNode *q) {
	if (p == NULL && q == NULL)
		return true;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(p);
	s2.push(q);
	while (!s1.empty() && !s2.empty()){
		TreeNode* tmp1 = s1.top();
		TreeNode* tmp2 = s2.top();
		s1.pop();
		s2.pop();
		if (tmp1->val != tmp2->val)
			return false;
		if (tmp1->right)
			s1.push(tmp1->right);
		if (tmp2->right)
			s2.push(tmp2->right);
		if (s1.size() != s2.size())
			return false;
		if (tmp1->left)
			s1.push(tmp1->left);
		if (tmp2->left)
			s2.push(tmp2->left);
		if (s1.size() != s2.size())
			return false;
	}
	return s1.size() == s2.size();
}