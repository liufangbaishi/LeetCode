struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), 
		next(NULL) 
	{}
};
// 排序链表，删除所有重复结点
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	if (pHead->next == NULL)
		return pHead;
	ListNode* first = new ListNode(-1); //防止头结点被改变
	first->next = pHead;
	ListNode* pcur = pHead;
	ListNode* pnext = pHead->next;
	ListNode* ppre = first;
	while (pcur && pnext)
	{
		if (pcur->val == pnext->val)
		{
			int val = pcur->val;
			while (pcur && pcur->val == val)// 最后一个结点如果删除
			{
				ListNode* del = pcur;
				pcur = pnext;
				if (pnext)  // 如果删除最后一个结点，防止next越界
					pnext = pnext->next;
				delete del;
				del = NULL;
			}
			ppre->next = pcur;
		}
		else
		{
			ppre = pcur;
			pcur = pnext;
			pnext = pcur->next;
		}
	}
	return first->next;
}
int main()
{
	ListNode* p1 = NULL;
	ListNode* p2 = NULL;
	pushFront(&p1, 4);
	pushFront(&p1, 4);
	pushFront(&p1, 4);
	pushFront(&p1, 3);
	pushFront(&p1, 3);
	pushFront(&p1, 3);
	pushFront(&p1, 1);
	pushFront(&p1, 1);
	ListNode* ret = deleteDuplication(p1);
	while (ret)
	{
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}