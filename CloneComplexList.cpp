// 复杂链表的复制
#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), 
		next(NULL), 
		random(NULL) 
	{}
};
void pushFront(RandomListNode** head, int x)
{
	if (*head == NULL)
		*head = new RandomListNode(x);
	else
	{
		RandomListNode* cur = new RandomListNode(x);
		cur->next = *head;
		*head = cur;
	}
}
RandomListNode* Find(RandomListNode* head, int x)
{
	if (head == NULL)
		return NULL;
	RandomListNode* cur = head;
	while (cur)
	{
		if (cur->label == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	RandomListNode* old = pHead;
	while (old)
	{
		RandomListNode* newNode = new RandomListNode(old->label);
		newNode->next = old->next;
		old->next = newNode;
		old = old->next->next;
	}
	old = pHead;
	RandomListNode* pnew = old->next;
	while (old)
	{
		if (old->random != NULL)
			pnew->random = old->random->next;
		old = pnew->next;
		if (old != NULL)
			pnew = old->next;
	}
	old = pHead;
	pnew = old->next;
	RandomListNode* head = pnew;
	while (pnew->next)
	{
		old->next = pnew->next;
		old = pnew->next;
		pnew->next = old->next;
		pnew = pnew->next;
	}
	old->next = NULL;
	return head;
}
int main()
{
	RandomListNode* head = NULL;
	pushFront(&head, 4);
	pushFront(&head, 3);
	pushFront(&head, 2);
	pushFront(&head, 1);
	Find(head, 1)->random = Find(head, 4);
	Find(head, 2)->random = Find(head, 2);
	Find(head, 3)->random = Find(head, 1);
	Find(head, 4)->random = NULL;
	RandomListNode* ret = Clone(head);
	return 0;
}
