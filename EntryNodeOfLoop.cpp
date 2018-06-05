// 环的入口点
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), 
		next(NULL) 
	{}
};

ListNode* Find(ListNode* head, int x)
{
	if (head == NULL)
		return NULL;
	ListNode* cur = head;
	while (cur)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

ListNode* HasLoop(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* cur = pHead;
	ListNode* meet = HasLoop(pHead);
	if (pHead == NULL || meet == NULL)
		return NULL;
	if (cur == meet)// 只有一个结点
		return cur;
	while (cur != meet)
	{
		cur = cur->next;
		meet = meet->next;
		if (cur == meet)
			return cur;
	}
	return NULL;
}

void test()
{
	ListNode* p1 = NULL;
	ListNode* p2 = NULL;
	pushFront(&p1, 7);
	pushFront(&p1, 6);
	pushFront(&p1, 5);
	pushFront(&p1, 4);
	pushFront(&p1, 3);
	pushFront(&p1, 2);
	pushFront(&p1, 1);
	pushFront(&p1, 0);
	Find(p1, 7)->next = Find(p1, 3);
	EntryNodeOfLoop(p1);
}

