struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{}
};
//判断链表是否带环，快慢指针法，一个走一步，一个走两步，如果有相遇
// 则一定有带环，另一种方法，借助哈希存储 
bool hasCycle(ListNode *head)
{
	if (head == NULL)
		return false;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}	