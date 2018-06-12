// 将链表小于x的结点放到链表后 Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x), 
		next(NULL) 
	{}
};

// 将链表小于x的结点放到链表后 Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
ListNode *partition(ListNode *head, int x) {
	if (head == NULL)
		return head;
	ListNode* tmp = new ListNode(-1);
	tmp->next = head;
	ListNode* cur = head;
	ListNode* pre = tmp;
	while (pre->next && pre->next->val < x)
		pre = pre->next;
	cur = pre;
	while (cur->next)
	{
		if (cur->next->val < x)  //小于x的pre和大于x的cur交换位置
		{
			ListNode* p = cur->next;
			cur->next = p->next;
			p->next = pre->next;
			pre->next = p;
			pre = pre->next;
		}
		else
			cur = cur->next;
	}
	return tmp->next;
}

void PushFront(ListNode** p, int x)
{
	ListNode* node = new ListNode(x);
	if (*p == NULL)
	{
		*p = node;
	}
	else
	{
		node->next = *p;
		*p = node;
	}
}
void test()
{
	ListNode* head = NULL;
	PushFront(&head, 2);
	PushFront(&head, 5);
	PushFront(&head, 2);
	PushFront(&head, 3);
	PushFront(&head, 4);
	PushFront(&head, 1);
	partition(head, 3);
}