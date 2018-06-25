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
 // 由中序遍历结果和后续遍历结果，重构二叉树
TreeNode* build(vector<int> &inorder, int &first, int &last, vector<int> &postorder, int &index){
	if (inorder.empty() || postorder.empty() || first >= last)
		return NULL;
	TreeNode* root = new TreeNode(postorder[index]);
	int i = 0;
	for (i = first; i < last; i++){
		if (inorder[i] == postorder[index])
			break;
	}
	index--;
	int tmp = i + 1;
	root->right = build(inorder, tmp, last, postorder, index);
	root->left = build(inorder, first, i, postorder, index);
	return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
	if (inorder.empty() || postorder.empty())
		return NULL;
	int size = postorder.size();
	int i = 0;
	int index = size-1;
	return build(inorder, i, size, postorder, index);
}