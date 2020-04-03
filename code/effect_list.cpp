//ʵ��һ����Ч�ĵ��������������
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
			pcur->next = prev;//����ָ���ÿ��ͷ�
			break;
		}
		next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	head->next = pcur;//pcurΪβ���
	node* temp = head->next;
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}