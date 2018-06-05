// 翻转链表
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), 
		next(NULL) 
	{}
};

ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == NULL)
		return NULL;
	if (pHead->next == NULL)
		return pHead;
	ListNode* pcur = pHead;
	ListNode* pnewhead = NULL;
	ListNode* pnext = NULL;
	while (pcur)
	{
		pnext = pcur->next;
		pcur->next = pnewhead;
		pnewhead = pcur;
		pcur = pnext;
	}
	return pnewhead;
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
	ListNode* ret1 = ReverseList(p1);
	ListNode* ret2 = ReverseList(p2);
}