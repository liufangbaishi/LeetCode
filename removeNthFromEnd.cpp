// 删除链表倒数第k个结点
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x), 
		next(NULL) 
	{}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
	if (head == NULL || n <= 0)
		return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (n--)
		fast = fast->next;
	if (fast == NULL)// 说明要删除的是第一个结点
	{
		ListNode* del = head;
		head = head->next;
		delete del;
		del = NULL;
		return head;
	}
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	ListNode* del = slow->next;
	slow->next = del->next;
	delete del;
	del = NULL;
	return head;
}
// 删除倒数第n个结点
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == NULL || n == 0)
		return NULL;
	ListNode* cur = head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	cur = head;
	int num = size - n;
	if (num == 0)
	{
		head = head->next;
		delete cur;
		cur = NULL;
		return head;
	}
	ListNode* pre = NULL;
	while (num--)
	{
		pre = cur;
		cur = cur->next;
	}
	if (pre) //只有一个结点，且删除最后一个结点
		pre->next = cur->next;
	delete cur;
	cur = NULL;
	return head;
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
	ListNode* head = NULL;;
	PushFront(&head, 5);
	PushFront(&head, 4);
	PushFront(&head, 3);
	PushFront(&head, 2);
	PushFront(&head, 1);
	ListNode* ret = removeNthFromEnd(head, 5);
}