// 有序的链表转换为二叉搜索树
#include <iostream>
using namespace std;
struct ListNode 
{
	int val;     
	ListNode *next;
    ListNode(int x) 
		: val(x), next(NULL) 
	{}
};
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) 
		: val(x), left(NULL), right(NULL) 
	{}
};
// convert sorted list to binary search tree
TreeNode* Convert(ListNode* head, ListNode* tail)
{
	if (head == tail)
		return NULL;
	if (head->next == tail)
		return new TreeNode(head->val);

	ListNode* fast = head;
	ListNode* slow = head;
	while (fast!=tail && fast->next!=tail)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	root->left = Convert(head, slow);
	if (fast && fast->next == tail)
		fast = fast->next;
	root->right = Convert(slow->next, fast);
	return root;
}

TreeNode *sortedListToBST(ListNode *head) 
{
	TreeNode* root = Convert(head, NULL);
	return root;
}

// 有序链表转换成 搜索二叉树   另一种写法
TreeNode* buildTree(ListNode* &list, int left, int right)
{
	if (left > right)
		return NULL;

	int mid = (left + right)/2;
	TreeNode* pleft = buildTree(list, left, mid - 1);
	TreeNode* root = new TreeNode(list->val);
	list = list->next;
	TreeNode* pright = buildTree(list, mid + 1, right);
	root->left = pleft;
	root->right = pright;
	return root;
}
TreeNode *sortedListToBST(ListNode *head) {
	int size = 0;
	ListNode* cur = head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	cur = head;
	return buildTree(cur, 1, size);
}


//////////////////////////////测试/////////////////////////////
void PushFront(ListNode* &head, int x)
{
	if (head == NULL)
		head = new ListNode(x);
	else
	{
		ListNode* tmp = new ListNode(x);
		tmp->next = head;
		head = tmp;
	}
}
void test()
{
	ListNode* p = NULL;
	PushFront(p, 16);
	PushFront(p, 14);
	PushFront(p, 12);
	PushFront(p, 10);
	PushFront(p, 6);
	PushFront(p, 4);
	TreeNode* tree = sortedListToBST(p);
}