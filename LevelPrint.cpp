#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 二叉树的层序遍历
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int>> ret;
	if (pRoot == NULL)
		return ret;
	queue<TreeNode*> q;
	q.push(pRoot);
	while (!q.empty()){
		vector<int> v;
		size_t tmp = 0;
		size_t size = q.size();
		while (tmp++ < size)
		{
			TreeNode* pCur = q.front();
			v.push_back(pCur->val);
			q.pop();

			if (pCur->left)
				q.push(pCur->left);
			if (pCur->right)
				q.push(pCur->right);
		}
		ret.push_back(v);
	}
	return ret;
}