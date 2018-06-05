// 从尾到头打印链表
#include <iostream>
#include <vector>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), 
		next(NULL) 
	{}
};
void printList(ListNode* head, vector<int>& ret)
{
	if (head)
	{
		printList(head->next, ret);
		ret.push_back(head->val);
	}
}
vector<int> printListFromTailToHead(ListNode* head)
{
	vector<int> ret;
	printList(head, ret);
	return ret;
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
	ListNode* head = NULL;
	pushFront(&head, 21);
	pushFront(&head, 31);
	pushFront(&head, 0);
	pushFront(&head, 14);
	vector<int>v = printListFromTailToHead(head);
	return 0;
}
