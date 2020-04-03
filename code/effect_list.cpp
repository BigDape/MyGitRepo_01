//实现一个高效的单向链表逆序输出
#define NULL 0
#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
	node(int d):data(d),next(NULL){}
}node;

void reverse(node* head)
{
	if (head == NULL || NULL == head->next)
	{
		return;
	}
	node* prev = NULL;
	node* pcur = head->next;
	node* next;
	while (pcur != NULL)
	{
		if (pcur->next == NULL)
		{
			pcur->next = prev;//链表指针置空释放
			break;
		}
		next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	head->next = pcur;//pcur为尾结点
	node* temp = head->next;
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}