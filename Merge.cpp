//合并两个有序链表
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), 
		next(NULL) 
	{}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return (pHead1 == NULL) ? pHead2 : pHead1;
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	ListNode* newHead = NULL;
	ListNode* newTail = NULL;
	if (cur1->val < cur2->val)
	{
		newHead = cur1;
		newTail = newHead;
		cur1 = cur1->next;
	}
	else
	{
		newHead = cur2;
		newTail = newHead;
		cur2 = cur2->next;
	}
	newTail->next = Merge(cur1, cur2);
	return newHead;
}
void test()
{
	ListNode* p1 = NULL;
	ListNode* p2 = NULL;
	pushFront(&p1, 7);
	pushFront(&p1, 5);	
	pushFront(&p1, 3);
	pushFront(&p1, 1);
	pushFront(&p2, 8);
	pushFront(&p2, 4);
	pushFront(&p2, 2);
	pushFront(&p2, 0);
	ListNode* ret = Merge(p1, p2);
}