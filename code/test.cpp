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
	int i = 0;
	cout << "i = " << i << endl;
	int x = i++;
	cout << "i++" << i << x << endl;
	int y = ++i;
	cout << "++i" << i << y << endl;
	return 0;
	
}

