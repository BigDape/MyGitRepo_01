#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* pTail = pListHead, * pHead = pListHead;
		for (int i = 1; i < k; i++)
		{
			if (pHead->next != NULL)
				pHead = pHead->next;
			else
				return NULL;
		}
		while (pHead->next != NULL)
		{
			pHead = pHead->next;
			pTail = pTail->next;
		}
		return pTail;
	}
};

void printList(ListNode* pListHead)
{	
	ListNode* p = pListHead->next;
	while (p ->next!= NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << "\n";
}

int main()
{
	Solution s;
	ListNode* pListHead;
	pListHead = (ListNode*)malloc(sizeof(ListNode));
	//��[1,10]��������
	ListNode* q, * p;
	p = pListHead;
	for (int i=1;i<11;i++)
	{
		q = (ListNode*)malloc(sizeof(ListNode));
		q->val = i;
		q->next=NULL;
		p->next = q;
		p = q;
	}
	//�ȴ�ӡ�����б�
	printList(pListHead);
	//Ѱ�ҵ�����k��Ԫ��
	ListNode* aa = s.FindKthToTail(pListHead, 2);
	int a = aa->val;
	cout << a;
}

