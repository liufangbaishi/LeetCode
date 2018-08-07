// rotate list  1->2->3->4->5->N && k==2   4->5->1->2->3->N
struct ListNode 
{
	int val;     
	ListNode *next;
    ListNode(int x) 
		: val(x), next(NULL) 
	{}
};
ListNode *rotateRight(ListNode *head, int k)  
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* p = head;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	k %= count;
	if (k == 0)
		return head;
	ListNode* cur = head;
	ListNode* pre = head;
	int num = count - k;
	while (num--) // 移动count-k次，下一个结点就是旋转后的头结点
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	ListNode* pHead = cur;
	while (cur->next)
		cur = cur->next;
	cur->next = head;
	return pHead;
}


// 右旋转链表   快慢指针法，与删除倒数第k个结点的题类似
ListNode* rotateRight(ListNode* head, int k)
{
	if (head == NULL || head->next == NULL || k == 0)
		return head;
	int size = 0;
	ListNode* cur = head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	k %= size;
	ListNode* fast = head;
	ListNode* slow = head;
	while (k--)
		fast = fast->next;
	if (fast == NULL)
		return head;
	while (fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}
	fast->next = head;
	fast = slow->next;
	slow->next = NULL;
	return fast;
}

// 测试
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
	PushFront(p, 5);
	PushFront(p, 4);
	PushFront(p, 3);
	PushFront(p, 2);
	PushFront(p, 1);
	ListNode* newhead = rotateRight(p, 5);
}