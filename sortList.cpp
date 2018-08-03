// 排序链表，时间复杂度为O(Nlog(N))——使用递归排序，整体思路是先利用递归分离，然后再合并
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x), 
		next(NULL) 
	{}
};

ListNode* findMid(ListNode* head)// 找中间结点
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* pre = NULL; 
	while (fast && fast->next)// 这里一定要返回pre，即：如果结点个数是偶数，返回中间两个的前一个
	// 否则如果当前链表有两个结点，就会造成死循环，只有返回前一个，才能将两个结点分离成两个子链表
	{
		pre = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	return pre;
}
ListNode* Merge(ListNode* first, ListNode* last)// 合并两个结点
{
	if (first == NULL || last == NULL)
		return (first == NULL) ? last : first;
	ListNode* tmp = new ListNode(-1);
	ListNode* head = tmp;
	while (first && last)
	{
		if (first->val > last->val)
		{
			head->next = last;
			last = last->next;
		}
		else
		{
			head->next = first;
			first = first->next;
		}
		head = head->next;
	}
	if (first)
		head->next = first;
	if (last)
		head->next = last;
	return tmp->next;
}
ListNode *sortList(ListNode *head) 
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* mid = findMid(head);
	ListNode* nextmid = NULL;
	nextmid = mid->next;
	mid->next = NULL;
	return Merge(sortList(head), sortList(nextmid));
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
	PushFront(&head, 0);
	PushFront(&head, 1);
	PushFront(&head, 2);
	PushFront(&head, 3);
	PushFront(&head, 4);
	PushFront(&head, 5);
	ListNode* p = sortList(head);
}