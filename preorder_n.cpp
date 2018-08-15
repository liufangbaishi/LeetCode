#include <stack>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL)
	{}
};
vector<int> preorderTraversal(TreeNode *root) {
	vector<int> res;
	if (root == NULL)
		return res;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* cur = s.top();
		s.pop();
		res.push_back(cur->val);
		if (cur->right)
			s.push(cur->right);
		if (cur->left)
			s.push(cur->left);
	}
	return res;
}

int main()
{
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(6);
	root->right = new TreeNode(10);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(7);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);
	vector<int> v = postorderTraversal(root);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}