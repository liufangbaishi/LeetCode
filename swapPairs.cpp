// 链表两两结点交换
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) 
	{}
};

ListNode *swapPairs(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pre = dummy;
	while (pre->next)
	{
		ListNode* cur = pre->next;
		ListNode* tmp = cur->next;
		if (tmp == NULL)
			break;
		cur->next = tmp->next;
		tmp->next = cur;
		pre->next = tmp;
		pre = tmp->next;
	}
	return dummy->next;
}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	ListNode* ret = swapPairs(head);
	ListNode* cur = ret;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}