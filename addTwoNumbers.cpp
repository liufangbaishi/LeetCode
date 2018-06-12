// add-two-numbers  有两个链表，它们表示逆序的两个非负数。计算出两个数的和之后，同样逆序输出作为一个链表。
// 需要注意一点：有进位
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)  Output: 7 -> 0 -> 8
// 优秀的博客：https://blog.csdn.net/crazy1235/article/details/52914703

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x), 
		next(NULL) 
	{}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
	if (l1 == NULL || l2 == NULL)
		return NULL;
	int value1 = 0;
	int value2 = 0;//求和后的进位
	ListNode* tmp = new ListNode(-1);
	ListNode* head = tmp;
	while (l1 || l2)
	{
		value1 = (l2->val + l1->val + value2) % 10;
		value2 = (l2->val + l1->val + value2) / 10;
		l2->val = value1;
		head->next = l2;
		head = head->next;
		l2 = l2->next;
		l1 = l1->next;
		if (l1 == NULL && l2 == NULL)
			break;
		if (l1 == NULL)
			l1 = new ListNode(0);
		if (l2 == NULL)
			l2 = new ListNode(0);
	}
	if (value2 != 0)
		head->next = new ListNode(value2);
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
	PushFront(&head, 3);
	PushFront(&head, 3);
	PushFront(&head, 4);
	PushFront(&head, 2);
	ListNode* p2 = NULL;
	PushFront(&p2, 6);
	PushFront(&p2, 5);
	ListNode* ret = addTwoNumbers(head, p2);
}