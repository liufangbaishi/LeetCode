#include <iostream>
using namespace std;
// 二叉搜索树转换为有序双向链表
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
		: val(x), left(NULL), right(NULL)
	{}
};

void ConvertList(TreeNode* pRoot, TreeNode* &pPre)
{
	if (pRoot == NULL)
		return;
	ConvertList(pRoot->left, pPre);
	pRoot->left = pPre;
	if (pPre)
		pPre->right = pRoot;
	pPre = pRoot;
	ConvertList(pRoot->right, pPre);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;
	TreeNode* pHead = pRootOfTree;
	while (pHead->left)
		pHead = pHead->left;
	TreeNode* pPre = NULL;
	ConvertList(pRootOfTree, pPre);
}

