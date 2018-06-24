#include <iostream>
#include <vector>
using namespace std;
//二叉树的后序遍历
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

vector<int> v;
vector<int> postorderTraversal(TreeNode *root) //后序遍历
{ 
	if (root)
	{
		preorderTraversal(root->left);
		preorderTraversal(root->right);
		v.push_back(root->val);
	}
	return v;
}

