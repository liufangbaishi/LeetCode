#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};
// 二叉搜索树，有两个数字的顺序反了，调整过来
// 利用中序线索化类似的顺序，先将两个出错的位置找到，然后交换
void InOrder(TreeNode* root, TreeNode* &p, TreeNode* &q, TreeNode* &pre){
	if (root == NULL)
		return;
	InOrder(root->left, p, q, pre);
	if (pre != NULL && pre->val > root->val){
		if (p == NULL){
			p = pre;
			q = root;
		}
		else
			q = root;
	}
	pre = root;
	InOrder(root->right, p, q, pre);
}
void recoverTree(TreeNode *root) {
	TreeNode* p = NULL;
	TreeNode* q = NULL;
	TreeNode* pre = NULL;
	InOrder(root, p, q, pre);
	int tmp = p->val;
	p->val = q->val;
	q->val = tmp;
}
