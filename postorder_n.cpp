struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL)
	{}
};
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> res;
	if (root == NULL)
		return res;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	TreeNode* prev = NULL;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* top = s.top();
		if (top->right == NULL || prev == top->right)
		{
			res.push_back(top->val);
			prev = top;
			s.pop();
		}
		else
			cur = top->right;
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