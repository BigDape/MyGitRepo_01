#include <iostream>
#include "LinkList.h"

template<typename T>
LinkList<T>::LinkList(const T x)//默认构造函数
{	
	data = x;
	next = NULL;
}

template<typename T>
LinkList LinkList<T>::Creat_LinkList()//头插法建立单链表
{

}