#include <iostream>
#include <vector>
#include <list>
#include <iterator>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//1���ж�pHead1��pHead2��Ϊ��
		if (pHead1 == NULL)
			return pHead2;
		else if (pHead2 == NULL)
			return pHead1;
		//2��ȡ��Сֵ��ͷ���Ϊͷ���
		ListNode* head;
		if (pHead1->val >= pHead2->val) 
		{
			head = pHead2;
			pHead2 = pHead2->next;
		}
		else
		{
			head = pHead1;
			pHead1 = pHead1->next;
		}
		//3���ϲ�
		ListNode* p = head;//head��Ϊ����ֵ
		while (pHead1 && pHead2)
		{
			if (pHead1->val >= pHead2->val) 
			{
				p->next = pHead2;
				p = p->next;
				pHead2 = pHead2->next;
			}
			else
			{
				p->next = pHead1;
				p = p->next;
				pHead1 = pHead1->next;
			}
		}
		//4����ʣ��ڵ�ȡ��
		if (pHead1 == NULL)//pHead2����ʣ��Ԫ��
		{
			while (pHead2 != NULL) {
				p->next = pHead2;
				p = p->next;
				pHead2 = pHead2->next;
			}
			
		}
		else if (pHead2 == NULL)//pHead1����ʣ��Ԫ��
		{
			while (pHead1 != NULL) {
				p->next = pHead1;
				p = p->next;
				pHead1 = pHead1->next;
			}
		}
		return head;
	}
};