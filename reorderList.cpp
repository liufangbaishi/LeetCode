// 题目描述：Given a singly linked list L: L 0→L 1→…→L n-1→L n,
// reorder it to: L 0→L n →L 1→L n-1→L 2→L n-2→…
// You must do this in-place without altering the nodes' values.
// For example, Given{1,2,3,4}, reorder it to{1,4,2,3}.
// 有三步：第一步找到中间结点，将链表分为前后两部分；
// 第二步，将后半部分的链表逆置
// 第三步：将后半部分链表按照规则插入到前半部分的链表中
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x), next(NULL) {}
};

void reorderList(ListNode *head) 
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* mid = slow->next;
	slow->next = NULL;
	ListNode* cur = mid;
	ListNode* pre = NULL;
	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	// 将一个链表插入到另一个链表中 pre && head
	cur = head;
	while (pre && cur)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = pre->next;
		cur->next->next = next;
		cur = next;
	}
}