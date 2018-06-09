// 左右半区间重组链表  1 2 3 4 5 --> 1 2 | 3 4 5 --> 1 3 2 4 5
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), 
		next(NULL) 
	{}
};

ListNode* FindMid(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void relocateList(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
		return;
	ListNode* left = head;
	ListNode* right = FindMid(head);
	ListNode* pright = right;
	ListNode* cur = head;
	while (left != pright)
	{
		ListNode* leftnext = left->next;
		ListNode* rightnext = right->next;
		cur->next = right;
		cur = cur->next;
		cur->next = leftnext;
		left = leftnext;
		if (left != pright)
			cur = cur->next;
		right = rightnext;
	}
	cur->next = right;
}

void pushFront(ListNode** head, int x)
{
	ListNode* newNode = new ListNode(x);
	if (*head == NULL)
		*head = newNode;
	else
	{
		newNode->next = *head;
		*head = newNode;
	}
}
int main()
{
	ListNode* p1 = NULL;
	pushFront(&p1, 5);
	pushFront(&p1, 4);
	pushFront(&p1, 3);
	pushFront(&p1, 2);
	pushFront(&p1, 1);
	relocateList(p1);
}