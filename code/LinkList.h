#include <iostream>
using namespace std;

template<typename T>//����һ��ģ�������Ҫ������
class LinkList
{
public:
	LinkList(const T x);//Ĭ�Ϲ��캯��
	LinkList* Creat_LinkList();//ͷ�巨����������
	LinkList* Creat_LinkList_R();//β�巨����������
	bool Print_LinkList(LinkList* head);//������ı���
	int LinkList_Length(LinkList* head);//������ĳ���
	LinkList* GetData_LinkList(LinkList *head,int i);//������Ĳ��ң�����ָ��λ�õ�Ԫ�أ�
	LinkList* GetData_LinkList_value(Linklist *head,int value);//������Ĳ��ң���ֵ���ң�
	void InsertBefore_LinkList(LinkList* head,LinkList* p,LinkList* s);//������Ĳ��룬ǰ��
	void InsertAfter_LinkList(LinkList* p,LinkList* s);//������Ĳ��룬���
	bool InsertIndex_LinkList(LinkList* head,LinkList* s,int i);//��������ָ��λ��ǰ�����½ڵ�s
	bool DeleteAfter_LinkList(LinkList *p);//ɾ����̽ڵ�p
private:
	T data;
	LinkList* next;
};