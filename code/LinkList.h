#include <iostream>
using namespace std;

template<typename T>//定义一个模板类必须要的声明
class LinkList
{
public:
	LinkList(const T x);//默认构造函数
	LinkList* Creat_LinkList();//头插法建立单链表
	LinkList* Creat_LinkList_R();//尾插法建立单链表
	bool Print_LinkList(LinkList* head);//单链表的遍历
	int LinkList_Length(LinkList* head);//单链表的长度
	LinkList* GetData_LinkList(LinkList *head,int i);//单链表的查找（返回指定位置的元素）
	LinkList* GetData_LinkList_value(Linklist *head,int value);//单链表的查找（按值查找）
	void InsertBefore_LinkList(LinkList* head,LinkList* p,LinkList* s);//单链表的插入，前插
	void InsertAfter_LinkList(LinkList* p,LinkList* s);//单链表的插入，后插
	bool InsertIndex_LinkList(LinkList* head,LinkList* s,int i);//在链表中指定位置前插入新节点s
	bool DeleteAfter_LinkList(LinkList *p);//删除后继节点p
private:
	T data;
	LinkList* next;
};